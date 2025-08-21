 #!/usr/bin/env bash


#------------------------------------------------------------------
# --- Compile main.c into object file --- 
 arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -O2 -g -Wall -Werror \
	-I./include \
	-I./include/cmsis \
	-I./include/hal \
	-I./include/hal/legacy \
	-ffunction-sections -fdata-sections \
	-DSTM32H755xx -DUSE_HAL_DRIVER \
	-DCORE_CM7 \
	-c main.c \
	-o ./objfiles/main.o



#------------------------------------------------------------------
# --- Take all (HAL) src files and compile them to object files ---

SOURCE_FILES=("startup_stm32h755zitx.s" \
	"system_stm32h755xx.c" \
	"./hal_src/stm32h7xx_it.c" \
	"./hal_src/stm32h7xx_hal.c" \
	"./hal_src/stm32h7xx_hal_rcc.c" \
	"./hal_src/stm32h7xx_hal_rcc_ex.c" \
	"./hal_src/stm32h7xx_hal_gpio.c" \
	"./hal_src/stm32h7xx_hal_cortex.c" \
	) 

for src_file in "${SOURCE_FILES[@]}"; do
	# Strip away file path from src file name
	# and replace ".c" with ".o"
	obj_file="${src_file##*/}"
	obj_file="${obj_file%.*}.o"

	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -O2 -g -Wall -Werror \
		-I./include \
		-I./include/cmsis \
		-I./include/hal \
		-I./include/hal/legacy \
		-ffunction-sections -fdata-sections \
		-DSTM32H755xx -DUSE_HAL_DRIVER \
		-DCORE_CM7 \
		-c "$src_file" \
		-o ./objfiles/"$obj_file"
done

#------------------------------------------------------------------
# --- Linking all object files ---
arm-none-eabi-gcc \
  -T STM32H755ZITX_FLASH.ld \
  -mcpu=cortex-m7 -mthumb -O2 -g \
  -Wl,--verbose,--gc-sections \
  ./objfiles/*.o \
  -o main.elf

#------------------------------------------------------------------
# --- Converting ELF to binary format  ---
arm-none-eabi-objcopy -O binary main.elf main.bin
# For hex:
#arm-none-eabi-objcopy -O ihex   main.elf main.hex


#------------------------------------------------------------------
# --- Writing binary to flash memory ---
st-flash write main.bin 0x8000000
# For hex (address not needed):
# st-flash write main.hex

echo "Flashed!"
