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


void W25X_Read_Sector(uint32_t addr, uint8_t* pBuffer, uint32_t size)
{
    uint16_t i;

    pin_set(CFG_PIN_FLASH_CS, 0);
    spi_send(SPI2, W25X_ReadData);
    spi_send(SPI2, (uint8_t)(addr >> 16));
    spi_send(SPI2, (uint8_t)(addr>> 8));
    spi_send(SPI2, (uint8_t) addr);

    for(i=0;i<size;i++)
    {
        pBuffer[i] = spi_read(SPI2);
    }
    pin_set(CFG_PIN_FLASH_CS, 1);
}

int read_block_flash(uint32_t block_no, uint8_t *data) {
    memset(data, 0, 512);
    uint32_t addr = block_no * 512;
    DMESG("read block %d", block_no);
    W25X_Read_Sector(addr, data, 512);
    return 0;
}

int write_block_flash(uint32_t lba, const uint8_t *copy_from) {

    return 0;
}

