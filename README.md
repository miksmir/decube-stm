# decube-stm
A simple, light CLI tool for building STM32 projects from scratch without any CubeIDE bloat or set-up confusion.

### Notes:
At the moment, this is just a single Bash script that you run to build your project. This also only works only on STM32CubeH755 and is only compatible on Linux, but you can always modify the dependencies to include the files for your specific board instead. There are plans to make this tool work for other boards in the future.

This tool supports both CMSIS and HAL for the STM32H755 MCU.

Decube-STM is not intended to be used as a tool for building large projects, but rather for smaller-scale bare-metal projects with as few dependencies as possible.

### Dependencies:
- [stlink](https://github.com/stlink-org/stlink)
- arm-none-eabi-gcc
- binutils-arm-none-eabi

### Usage:
Download this repository, edit ```main.c``` and run the Bash script to build the binary, that's it! Modify the Bash script yourself if necessary.
At a bare minimum, you need your board-specific CMSIS files, the start-up assembly file, your board-specific linker script, and a ```main.c``` file.

### Future Goals
- [ ] Support for building for STM32H755's secondary core
- [ ] Support for linking custom libraries
- [ ] GDB & OpenOCD Implementation
- [ ] Support for other STM32 boards
- [ ] Cross-platform compatibility
