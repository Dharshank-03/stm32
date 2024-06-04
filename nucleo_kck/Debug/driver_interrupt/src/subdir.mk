################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver_interrupt/src/inc.c 

OBJS += \
./driver_interrupt/src/inc.o 

C_DEPS += \
./driver_interrupt/src/inc.d 


# Each subdirectory must supply rules for building sources it contributes
driver_interrupt/src/%.o driver_interrupt/src/%.su: ../driver_interrupt/src/%.c driver_interrupt/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"C:/Users/Admin/OneDrive/Desktop/embedded c/instructor/host/nucleo_kck/driver_interrupt/inc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-driver_interrupt-2f-src

clean-driver_interrupt-2f-src:
	-$(RM) ./driver_interrupt/src/inc.d ./driver_interrupt/src/inc.o ./driver_interrupt/src/inc.su

.PHONY: clean-driver_interrupt-2f-src

