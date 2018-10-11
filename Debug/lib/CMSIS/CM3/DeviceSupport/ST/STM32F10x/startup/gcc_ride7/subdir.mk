################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/startup_stm32f10x_md.S 

OBJS += \
./lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/startup_stm32f10x_md.o 

S_UPPER_DEPS += \
./lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/startup_stm32f10x_md.d 


# Each subdirectory must supply rules for building sources it contributes
lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/%.o: ../lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -DSTM32F10X_MD -DSTM32F103 -DSTM32F10X -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/inc" -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/lib/CMSIS/CM3/CoreSupport" -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x" -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/lib/STM32F10x_StdPeriph_Driver/inc" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


