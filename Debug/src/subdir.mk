################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/delay.c \
../src/main.c \
../src/ws2812.c 

OBJS += \
./src/delay.o \
./src/main.o \
./src/ws2812.o 

C_DEPS += \
./src/delay.d \
./src/main.d \
./src/ws2812.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F10X_MD -DSTM32F103 -DSTM32F10X -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/inc" -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/lib/CMSIS/CM3/CoreSupport" -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x" -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/lib/STM32F10x_StdPeriph_Driver/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


