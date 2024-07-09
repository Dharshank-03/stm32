################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../st7789/fonts.c 

OBJS += \
./st7789/fonts.o 

C_DEPS += \
./st7789/fonts.d 


# Each subdirectory must supply rules for building sources it contributes
st7789/%.o st7789/%.su: ../st7789/%.c st7789/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../Core/Inc -I"C:/Users/Admin/OneDrive/Desktop/embedded c/instructor/host/LCD_SPI/st7789" -I"C:/Users/Admin/OneDrive/Desktop/embedded c/instructor/host/LCD_SPI/st7789" -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-st7789

clean-st7789:
	-$(RM) ./st7789/fonts.d ./st7789/fonts.o ./st7789/fonts.su

.PHONY: clean-st7789

