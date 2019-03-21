#ifndef BOARD_H
#define BOARD_H

#define OSC_FREQ 12
#define USBDEVICESTRING "MeowBit V1"
#define USBMFGSTRING "Kittenbot"
#define BOARD_FLASH_SECTORS 8
#define BOARD_FLASH_SIZE (512 * 1024)
#define BOARD_ID "STM32F401-MEOWBIT"


#ifdef DEFINE_CONFIGDATA
__attribute__((section(".config"))) __attribute__((used)) //
const uint32_t configData[] = {
    /* CF2 START */
    513675505, 539130489, // magic
    57, 100,  // used entries, total entries
    1, 0x2e, // PIN_ACCELEROMETER_INT = PC14
    2, 0x16, // PIN_ACCELEROMETER_SCL = PIN_D6
    3, 0x17, // PIN_ACCELEROMETER_SDA = PIN_D7
    4, 0x19, // PIN_BTN_A = PB01 PB_9
    5, 0x23, // PIN_BTN_B = PB00 PC_3
    9, 0x11, // PIN_FLASH_CS = PB_1
    13, 0x14, // PIN_LED = PC09 PB4
    14, 0x22, // PIN_LIGHT PC2
    24, 0x16, // PIN_SCL
    25, 0x17, // PIN_SDA
    27, 0x25, // TEMPERATURE = PC5
    32, 0x1d, // PIN_DISPLAY_SCK = PB13
    33, 0x1e, // PIN_DISPLAY_MISO = PB14
    34, 0x1f, // PIN_DISPLAY_MOSI = PB15
    35, 0x1c, // PIN_DISPLAY_CS = PB12
    36, 0x08, // PIN_DISPLAY_DC = PC05 PA08
    37, 0xa0, // DISPLAY_WIDTH = 160
    38, 0x80, // DISPLAY_HEIGHT = 128
    39, 0x40, // DISPLAY_CFG0 = 0x80
    40, 0x603, // DISPLAY_CFG1 = 0x603
    41, 0x16, // DISPLAY_CFG2 = 0x16
    43, 0x1A, // PIN_DISPLAY_RST = PC04 PB10
    44, 0x13, // PIN_DISPLAY_BL = PC07 PB03
    //45, 0x1, // PIN_SERVO_1 = PA01
    //46, 0x0, // PIN_SERVO_2 = PA00
    47, 0x07, // PIN_BTN_LEFT = PA15 PA_7
    48, 0x12, // PIN_BTN_RIGHT = PC13 PB_2
    49, 0x06, // PIN_BTN_UP = PA05 PA_6
    50, 0x05, // PIN_BTN_DOWN = PB10 PA_5
    51, 0x2F, // PIN_BTN_MENU = PC10 PC_15
    55, 0x15, // PIN_LED1 = PC08 PB5
    59, 255, // speaker volume
    60, 0x9, // PIN_JACK_TX = PA09
    //61, 0x6, // PIN_JACK_SENSE = PA06
    //62, 0x4, // PIN_JACK_HPEN = PA04
    // 63, 0x18, // PIN_JACK_BZEN = PA10 PB8
    // 64, 0x7, // PIN_JACK_PWREN = PA07
    65, 0x18, // PIN_JACK_SND = PA08 PB_8
    // 66, 0x28, // PIN_JACK_BUSLED = PC08
    // 67, 0x29, // PIN_JACK_COMMLED = PC09
    70, 0x68, // ACCELEROMETER_TYPE = MPU6050
    103, 0x10, // PIN_A3 PB0
    100, 0x00, // PIN_A0 PA0
    104, 0x20, // PIN_A4 PC0
    154, 0x15, // PIN_D4 PB5  LED act
    159, 0x27, // PIN_D9 PC7
    152, 0x0A, // PIN_D2 PA10
    101, 0x01, // PIN_A1 PA1
    102, 0x04, // PIN_A2 PA4
    // U6 tx 
    105, 0x20, // PIN_A5 PC0
    153, 0x26, // PIN_D3 PC6
    150, 0x03, // PIN_D0 PA3
    151, 0x02, // PIN_D1 PA2
    // external spi
    23, 0x2A, // PIN_SCK PC10
    18, 0x2B, // PIN_MISO PC11
    19, 0x2C, // PIN_MOSI PC12
    163, 0x0F, // PIN_SS, PIN_D13 PA_15

    204, 0x80000, // FLASH_BYTES = 0x80000
    205, 0x18000, // RAM_BYTES = 0x18000
    208, 0x16e42d61, // BOOTLOADER_BOARD_ID = 0x16e42d61
    209, 0x57755a57, // UF2_FAMILY = STM32F401
    210, 0x10, // PINS_PORT_SIZE = PA_16
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* CF2 END */
};
#endif

#endif /* BOARD_H */
