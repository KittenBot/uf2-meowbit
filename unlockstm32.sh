#!/bin/sh
openocd -f /usr/share/openocd/scripts/interface/stlink-v2.cfg -f /usr/share/openocd/scripts/target/stm32f4x.cfg -c init -c "reset halt" -c "flash write_image erase $(BINARY) 0x08000000" -c "reset run" -c shutdown

