################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c 

OBJS += \
./lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.o 

C_DEPS += \
./lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.d 


# Each subdirectory must supply rules for building sources it contributes
lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x/%.o: ../lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F10X_MD -DSTM32F103 -DSTM32F10X -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/inc" -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/lib/CMSIS/CM3/CoreSupport" -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x" -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/lib/STM32F10x_StdPeriph_Driver/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


