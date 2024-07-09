################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/source/i2c.c 

OBJS += \
./driver/source/i2c.o 

C_DEPS += \
./driver/source/i2c.d 


# Each subdirectory must supply rules for building sources it contributes
driver/source/%.o driver/source/%.su: ../driver/source/%.c driver/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"C:/Users/Admin/OneDrive/Desktop/embedded c/instructor/host/SENSOR INTEGRATION/driver/header" -I"C:/Users/Admin/OneDrive/Desktop/embedded c/instructor/host/SENSOR INTEGRATION/driver/source" -I"C:/Users/Admin/OneDrive/Desktop/embedded c/instructor/host/SENSOR INTEGRATION/driver" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-driver-2f-source

clean-driver-2f-source:
	-$(RM) ./driver/source/i2c.d ./driver/source/i2c.o ./driver/source/i2c.su

.PHONY: clean-driver-2f-source

