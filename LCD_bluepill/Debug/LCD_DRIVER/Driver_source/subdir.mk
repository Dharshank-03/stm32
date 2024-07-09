################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD_DRIVER/Driver_source/fonts.c \
../LCD_DRIVER/Driver_source/st7789.c 

OBJS += \
./LCD_DRIVER/Driver_source/fonts.o \
./LCD_DRIVER/Driver_source/st7789.o 

C_DEPS += \
./LCD_DRIVER/Driver_source/fonts.d \
./LCD_DRIVER/Driver_source/st7789.d 


# Each subdirectory must supply rules for building sources it contributes
LCD_DRIVER/Driver_source/%.o LCD_DRIVER/Driver_source/%.su: ../LCD_DRIVER/Driver_source/%.c LCD_DRIVER/Driver_source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I"C:/Users/Admin/OneDrive/Desktop/embedded c/instructor/host/LCD_bluepill/LCD_DRIVER/Driver_source" -I"C:/Users/Admin/OneDrive/Desktop/embedded c/instructor/host/LCD_bluepill/LCD_DRIVER/Driver_header" -I"C:/Users/Admin/OneDrive/Desktop/embedded c/instructor/host/LCD_bluepill/LCD_DRIVER" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-LCD_DRIVER-2f-Driver_source

clean-LCD_DRIVER-2f-Driver_source:
	-$(RM) ./LCD_DRIVER/Driver_source/fonts.d ./LCD_DRIVER/Driver_source/fonts.o ./LCD_DRIVER/Driver_source/fonts.su ./LCD_DRIVER/Driver_source/st7789.d ./LCD_DRIVER/Driver_source/st7789.o ./LCD_DRIVER/Driver_source/st7789.su

.PHONY: clean-LCD_DRIVER-2f-Driver_source

