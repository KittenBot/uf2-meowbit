# UF2 Bootloaders for STM32

This implements USB mass storage flashing using [UF2 format](https://github.com/Microsoft/uf2)

## Build instructions

Build all targets:

```make```

The binaries will be in `build_BOARDNAME/BOARDNAME.elf`. Two files are built: ELF files for use with JTAG adapters and BIN files for direct onboard upgrading.

Build a specific board: Please check the `Makefile` for specific build targets.

## License

License: LGPL for libopencm3, BSD for what was left of the PX4 bootloader (see LICENSE.md),
MIT for the UF2 stuff, and ISC for the bits from dapboot.

## Credits

This repo was forked from https://github.com/PX4/Bootloader

It contains small bits from https://github.com/devanlai/dapboot,
mostly the WebUSB stuff that isn't yet used

The UF2 stuff was mostly lifted from https://github.com/Microsoft/uf2-samdx1
by way of (non-working) https://github.com/Microsoft/uf2-nrf5

The dmesg subsystem is adapted from https://github.com/lancaster-university/codal-core

```
	arm-none-eabi-gdb --eval "target remote | openocd -f interface/stlink-v2.cfg -f target/stm32f4x.cfg -f gdb.cfg" build/braingames_revb_bl/braingames_revb_bl.elf
	
	make TARGETS=stm32/f4 all
	
	dfu-util -a 0 -s 0x08000000 -v -D build/braingames_revb_bl/braingames_revb_bl.bin
	
	d:\dfutil\dfu-util.exe  -a 0 -s 0x08000000 -v -D build/braingames_revb_bl/braingames_revb_bl.bin

    // riven, adapt to meowbit
    CFG_PIN_DISPLAY_CS,      PB_12,
    CFG_PIN_DISPLAY_SCK,     PB_13,
    CFG_PIN_DISPLAY_MOSI,    PB_15,
    CFG_PIN_DISPLAY_MISO,    PB_14,
    CFG_PIN_DISPLAY_DC,      PA_8,
    CFG_PIN_DISPLAY_RST,     PB_10,
    CFG_DISPLAY_WIDTH,       160,
    CFG_DISPLAY_HEIGHT,      128,
    CFG_DISPLAY_CFG0,        0x00000040, // 0x00020140 0x00000080
    CFG_DISPLAY_CFG1,        0x000603, // 0x000603
    CFG_DISPLAY_CFG2,        22,

    CFG_PIN_BTN_UP,          PA_6, //PA_5,
    CFG_PIN_BTN_LEFT,        PA_7, //PA_15,
    CFG_PIN_BTN_DOWN,        PA_5, //PB_10,
    CFG_PIN_BTN_RIGHT,       PB_2, //PC_13,
    CFG_PIN_BTN_A,           PB_9,// PB_1,
    CFG_PIN_BTN_B,           PC_3,// PB_0,
    CFG_PIN_BTN_MENU,        PC_15, // PC_10,
    CFG_PIN_DISPLAY_BL,      PB_3, // origin PC_7, riven
```