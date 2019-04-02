#ifndef BOARD_H
#define BOARD_H

#define OSC_FREQ 8
#define USBDEVICESTRING "BrainPad Arcade"
#define USBMFGSTRING "GHI Electronics"
#define BOARD_FLASH_SECTORS 8
#define BOARD_FLASH_SIZE (512 * 1024)
#define BOARD_ID "STM32F401-BrainPad-Arcade-RevA"

#ifdef DEFINE_CONFIGDATA
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

#ifdef DEFINE_CUSTOM_LOGO
const uint8_t brain_A0[] = {32,  32,  60,  191, 182, 31,  152, 200, 151, 202, 149, 204, 143,
                            209, 142, 210, 141, 211, 141, 211, 139, 214, 137, 215, 136, 216,
                            136, 216, 135, 217, 64,  217, 64,  217, 96,  217, 96,  218, 120,
                            217, 124, 217, 124, 217, 124, 217, 124, 217, 124, 216, 120, 217,
                            124, 217, 124, 217, 124, 217, 124, 217, 120, 217, 0};

const uint8_t brain_A1[] = {
    32,  32,  108, 191, 191, 153, 7,   151, 63,  152, 200, 151, 202, 148, 204, 144, 206, 145, 1,
    120, 3,   139, 1,   135, 7,   139, 49,  135, 15,  136, 13,  99,  120, 139, 15,  96,  120, 139,
    31,  138, 15,  64,  63,  138, 31,  135, 201, 4,   62,  136, 63,  199, 112, 1,   112, 19,  124,
    94,  1,   60,  31,  79,  31,  88,  201, 136, 63,  56,  118, 15,  96,  7,   31,  126, 1,   120,
    96,  107, 63,  126, 15,  28,  123, 115, 95,  64,  59,  62,  76,  13,  16,  79,  71,  65,  97,
    108, 3,   120, 25,  76,  121, 205, 6,   123, 126, 206, 135, 95,  63,  66,  7};

const uint8_t brain_B0[] = {32,  32,  60,  126, 216, 124, 218, 126, 217, 126, 217, 126, 216,
                            124, 217, 124, 217, 120, 218, 124, 217, 124, 217, 124, 217, 124,
                            217, 124, 217, 124, 216, 112, 217, 112, 217, 96,  217, 136, 216,
                            137, 215, 137, 215, 137, 214, 138, 213, 140, 212, 142, 210, 147,
                            205, 149, 203, 150, 201, 152, 199, 154, 31,  191, 165};

const uint8_t brain_B1[] = {
    32, 32,  111, 112, 31,  79,  96,  64,  126, 121, 104, 108, 104, 79,  79,  77, 15,  125, 125,
    89, 125, 17,  79,  31,  64,  15,  118, 125, 7,   112, 64,  76,  55,  136, 3,  137, 31,  3,
    62, 96,  112, 206, 14,  30,  30,  115, 119, 97,  111, 33,  135, 31,  124, 25, 4,   112, 67,
    63, 103, 135, 31,  112, 109, 202, 62,  96,  89,  203, 62,  64,  125, 203, 62, 137, 202, 135,
    31, 137, 63,  3,   124, 139, 63,  7,   120, 140, 79,  113, 27,  138, 81,  99, 31,  139, 31,
    3,  28,  141, 111, 1,   7,   145, 203, 151, 201, 152, 199, 153, 63,  155, 7,  191, 191, 0};

const uint8_t pad0[] = {32,  31,  63,  140, 206, 145, 206, 145, 206, 145, 206, 145, 206, 145,
                        201, 150, 201, 151, 200, 152, 63,  153, 95,  7,   147, 201, 149, 202,
                        149, 202, 149, 202, 149, 202, 149, 202, 149, 202, 149, 202, 150, 201,
                        151, 200, 151, 200, 150, 201, 150, 201, 150, 201, 150, 201, 145, 206,
                        145, 206, 145, 206, 145, 206, 145, 206, 191, 0};

const uint8_t pad1[] = {32,  31,  59,  172, 204, 147, 204, 147, 99,  31,  145, 99,  152,
                        99,  152, 199, 153, 31,  153, 15,  190, 3,   148, 123, 151, 119,
                        1,   145, 19,  1,   145, 17,  1,   145, 19,  1,   145, 200, 152,
                        63,  153, 63,  184, 15,  151, 63,  151, 199, 152, 99,  152, 99,
                        152, 99,  147, 203, 148, 204, 147, 204, 191, 164};

const uint8_t tm[] = {16, 16,  21, 179, 1, 137, 1, 137, 15, 137, 1,  137,
                      1,  153, 15, 138, 1, 138, 1, 136, 1,  136, 15, 166};

static void customLogo() {
    printicon(2, 10, 15, brain_A0);
    printicon(2, 10, 3, brain_A1);
    printicon(34, 10, 15, brain_B0);
    printicon(34, 10, 3, brain_B1);
    printicon(65, 9, 15, pad0);
    printicon(65, 9, 1, pad1);
    printicon(93, 18, 15, tm);
}

#define CUSTOM_LOGO customLogo()

#endif

#endif /* BOARD_H */
