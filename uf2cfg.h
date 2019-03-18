#define UF2_VERSION "2.3.6"
#define BOARD_ID "STM32F401-MEOWBIT"
#define INDEX_URL "https://arcade.makecode.com"
#define UF2_NUM_BLOCKS 8000
#define VOLUME_LABEL "MEOWBIT"
// where the UF2 files are allowed to write data - we allow MBR, since it seems part of the softdevice .hex file
#define USER_FLASH_START (uint32_t)(APP_LOAD_ADDRESS)
#define USER_FLASH_END (0x08000000+BOARD_FLASH_SIZE)

