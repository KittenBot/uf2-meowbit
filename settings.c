#include "bl.h"

__attribute__((section(".config"))) __attribute__((used)) //
const uint32_t configData[] = {
    /* CF2 START */
    513675505, 539130489, // magic
    47, 100,  // used entries, total entries
    1, 0x2e, // PIN_ACCELEROMETER_INT = PC14
    2, 0x16, // PIN_ACCELEROMETER_SCL = PIN_D6
    3, 0x17, // PIN_ACCELEROMETER_SDA = PIN_D7
    4, 0x19, // PIN_BTN_A = PB01 PB_9
    5, 0x23, // PIN_BTN_B = PB00 PC_3
    13, 0x14, // PIN_LED = PC09 PB4
    14, 0x22, // PIN_LIGHT PC2
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
    60, 0x9, // PIN_JACK_TX = PA09
    //61, 0x6, // PIN_JACK_SENSE = PA06
    //62, 0x4, // PIN_JACK_HPEN = PA04
    // 63, 0x18, // PIN_JACK_BZEN = PA10 PB8
    // 64, 0x7, // PIN_JACK_PWREN = PA07
    65, 0x18, // PIN_JACK_SND = PA08 PB_8
    // 66, 0x28, // PIN_JACK_BUSLED = PC08
    // 67, 0x29, // PIN_JACK_COMMLED = PC09
    70, 0x38, // ACCELEROMETER_TYPE = MMA8453
    151, 0x2, // PIN_D1 = PA02
    152, 0x3, // PIN_D2 = PA03
    153, 0x13, // PIN_D3 = PB03
    154, 0x14, // PIN_D4 = PB04
    155, 0x15, // PIN_D5 = PB05
    156, 0x16, // PIN_D6 = PB06
    157, 0x17, // PIN_D7 = PB07
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

extern const char infoUf2File[];
__attribute__((section(".settings"))) __attribute__((used)) //
const struct Settings settings = {
    .magic0 = SETTINGS_MAGIC_0,
    .magic1 = SETTINGS_MAGIC_1,
    .configValues = configData + 4,
    .hseValue = OSC_FREQ * 1000000,
    .infoUF2 = infoUf2File,
    .manufacturer = USBMFGSTRING,
    .device = USBDEVICESTRING,
};
