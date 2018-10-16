################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ws2812.c 

CPP_SRCS += \
../src/animations.cpp \
../src/basic_animation.cpp \
../src/cube.cpp \
../src/delay.cpp \
../src/main.cpp 

OBJS += \
./src/animations.o \
./src/basic_animation.o \
./src/cube.o \
./src/delay.o \
./src/main.o \
./src/ws2812.o 

C_DEPS += \
./src/ws2812.d 

CPP_DEPS += \
./src/animations.d \
./src/basic_animation.d \
./src/cube.d \
./src/delay.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F10X_MD -DSTM32F103 -DSTM32F10X -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/inc" -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/lib/CMSIS/CM3/CoreSupport" -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x" -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/lib/STM32F10x_StdPeriph_Driver/inc" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F10X_MD -DSTM32F103 -DSTM32F10X -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/inc" -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/lib/CMSIS/CM3/CoreSupport" -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x" -I"/home/johannes/Documents/Programmierung/eclipse-workspace/InfinityCube/lib/STM32F10x_StdPeriph_Driver/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


