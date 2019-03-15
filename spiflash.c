#include <string.h>
#include <libopencm3/cm3/scb.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/gpio.h>

#include "bl.h"
#include "pins.h"

//Flash相关参数
#define FLASH_PAGE_SIZE			256
#define FLASH_SECTOR_SIZE		4096
#define FLASH_SECTOR_COUNT		512
#define FLASH_BLOCK_SIZE		65536
#define FLASH_PAGES_PER_SECTOR	FLASH_SECTOR_SIZE/FLASH_PAGE_SIZE

/****************************************
	W25X32	命令
****************************************/
#define W25X32_CHIPID				0xEF3016

#define W25X_WriteEnable			0x06
#define W25X_WriteDisable			0x04
#define W25X_ReadStatusReg			0x05
#define W25X_WriteStatusReg			0x01
#define W25X_ReadData				0x03
#define W25X_FastReadData			0x0B
#define W25X_FastReadDual			0x3B
#define W25X_PageProgram			0x02
#define W25X_BlockErase				0xD8
#define W25X_SectorErase			0x20
#define W25X_ChipErase				0xC7
#define W25X_SetPowerDown			0xB9
#define W25X_SetReleasePowerDown	0xAB
#define W25X_DeviceID				0xAB
#define W25X_ManufactDeviceID		0x90
#define W25X_JedecDeviceID			0x9F

// assuming all usb msc in 512 block, spi flash op in 4096 sector size
// so every 8 block assmeble 1 flash sector
static uint8_t secBuf[FLASH_SECTOR_SIZE];
static volatile uint32_t opSector;
static volatile bool secDirty = false;
static volatile uint32_t secDirtyCounter = 0;

uint8_t W25X_Read_StatusReg(void)
{
    uint8_t ret = 0;
    pin_set(CFG_PIN_FLASH_CS, 0);
    spi_xfer(SPI2, W25X_ReadStatusReg);
    ret = spi_xfer(SPI2, 0xff);
    pin_set(CFG_PIN_FLASH_CS, 1);
    return ret;
}

void W25X_Write_Cmd(uint8_t cmd)
{
    pin_set(CFG_PIN_FLASH_CS, 0);
    spi_xfer(SPI2, cmd);
    pin_set(CFG_PIN_FLASH_CS, 1);
    // DMESG("WRN");
}

void W25X_Wait_Busy(void)
{
    while(W25X_Read_StatusReg() == 0x03){
        // DMESG("@ %x", W25X_Read_StatusReg());
        // delay(1);
    }
}

void dump_sector(uint32_t sec)
{
    uint16_t i;
    uint32_t addr = sec * FLASH_SECTOR_SIZE;
    pin_set(CFG_PIN_FLASH_CS, 0);
    spi_xfer(SPI2, W25X_ReadData);
    spi_xfer(SPI2, (uint8_t)(addr >> 16));
    spi_xfer(SPI2, (uint8_t)(addr>> 8));
    spi_xfer(SPI2, (uint8_t) addr & 0xff);

    for(i=0;i<FLASH_SECTOR_SIZE;i++)
    {
        secBuf[i] = spi_xfer(SPI2, 0xff);
    }
    pin_set(CFG_PIN_FLASH_CS, 1);
}

void erase_sector(uint32_t sec){
    W25X_Write_Cmd(W25X_WriteEnable);
    uint32_t addr = sec * FLASH_SECTOR_SIZE;
    pin_set(CFG_PIN_FLASH_CS, 0);
    spi_xfer(SPI2, W25X_SectorErase);
    spi_xfer(SPI2, (uint8_t)(addr >> 16));
    spi_xfer(SPI2, (uint8_t)(addr>> 8));
    spi_xfer(SPI2, (uint8_t) addr & 0xff);
    pin_set(CFG_PIN_FLASH_CS, 1);
    W25X_Wait_Busy();
    //DMESG("Erase Sector %d", sec);
}

int flush_current_sector()
{
    uint16_t i,j;
    erase_sector(opSector);
    uint32_t addr = opSector * FLASH_SECTOR_SIZE;
    uint8_t * pBuffer = secBuf;
    led_on(LED_BOOTLOADER);
    for(j=0;j<FLASH_PAGES_PER_SECTOR;j++)
    {
        W25X_Write_Cmd(W25X_WriteEnable);
        pin_set(CFG_PIN_FLASH_CS, 0);
        spi_xfer(SPI2, W25X_PageProgram);
        spi_xfer(SPI2, (uint8_t)(addr >> 16));
        spi_xfer(SPI2, (uint8_t)(addr>> 8));
        spi_xfer(SPI2, (uint8_t) addr & 0xff);
        for(i=0;i<FLASH_PAGE_SIZE;i++)
        {
            spi_xfer(SPI2, pBuffer[i]);
        }

        pBuffer += FLASH_PAGE_SIZE;
        addr += FLASH_PAGE_SIZE;

        pin_set(CFG_PIN_FLASH_CS, 1);
        W25X_Wait_Busy();
    }
    led_off(LED_BOOTLOADER);
    //DMESG("flush %d %x", opSector, addr);
    secDirty = false;
    secDirtyCounter = 0;
    return 0;
}

int read_block_flash(uint32_t block_no, uint8_t *data) {
    uint32_t secIdx = block_no / 8;
    uint8_t blkIdx = block_no % 8;
    //DMESG("rd: %d", block_no);
    if (secIdx != opSector){
        if (secDirty){
            flush_current_sector();
        }
        opSector = secIdx;
        dump_sector(opSector);
        //DMESG("#1 dump %d", opSector);
        //DMESG("Dump new sector %d", opSector);
        //DMESG("read block %d %x %x %x %x %x %x", block_no, secBuf[0], secBuf[1], secBuf[2], secBuf[3], secBuf[4], secBuf[5]);
    }
    memcpy(data, secBuf + blkIdx*512, 512);
    return 0;
}

int write_block_flash(uint32_t block_no, const uint8_t *data) {
    uint32_t secIdx = block_no / 8;
    uint8_t blkIdx = block_no % 8;
    //DMESG("wr: %d", block_no);
    if (secIdx != opSector){
        if (secDirty){
            flush_current_sector();
        }
        opSector = secIdx;
        dump_sector(opSector);
       // DMESG("#2 dump %d", opSector);
    }
    memcpy(secBuf+blkIdx*512, data, 512);
    secDirty = true;
    return 0;
}

void flush_1ms() {
    if (secDirty){
        if (++secDirtyCounter > 200){
            DMESG("Time out flush");
            flush_current_sector();
        }
    }
}

void spi_test(){
    opSector = 0;
    dump_sector(opSector);
    DMESG("T1 %x %x %x %x %x %x", secBuf[0], secBuf[1], secBuf[2], secBuf[3], secBuf[4], secBuf[5]);
    erase_sector(opSector);
    dump_sector(opSector);
    DMESG("T2 %x %x %x %x %x %x", secBuf[0], secBuf[1], secBuf[2], secBuf[3], secBuf[4], secBuf[5]);
    for (int i=0;i<255;i++){
        secBuf[i] = i;
    }
    flush_current_sector();
    dump_sector(opSector);
    DMESG("T3 %x %x %x %x %x %x", secBuf[0], secBuf[1], secBuf[2], secBuf[3], secBuf[4], secBuf[5]);
    while(1);
}

