################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/src/driver_gpio_kck.c \
../driver/src/driver_spi_kck.c \
../driver/src/i2c.c 

OBJS += \
./driver/src/driver_gpio_kck.o \
./driver/src/driver_spi_kck.o \
./driver/src/i2c.o 

C_DEPS += \
./driver/src/driver_gpio_kck.d \
./driver/src/driver_spi_kck.d \
./driver/src/i2c.d 


# Each subdirectory must supply rules for building sources it contributes
driver/src/%.o driver/src/%.su: ../driver/src/%.c driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/Admin/OneDrive/Desktop/embedded c/instructor/host/driver kck/driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-driver-2f-src

clean-driver-2f-src:
	-$(RM) ./driver/src/driver_gpio_kck.d ./driver/src/driver_gpio_kck.o ./driver/src/driver_gpio_kck.su ./driver/src/driver_spi_kck.d ./driver/src/driver_spi_kck.o ./driver/src/driver_spi_kck.su ./driver/src/i2c.d ./driver/src/i2c.o ./driver/src/i2c.su

.PHONY: clean-driver-2f-src

