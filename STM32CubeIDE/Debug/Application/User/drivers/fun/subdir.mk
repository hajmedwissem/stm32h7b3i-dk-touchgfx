################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/USER/Desktop/pfa_final/tpe_29_04V2/tpe_27_04_v2/Core/drivers/fun/fun.c 

C_DEPS += \
./Application/User/drivers/fun/fun.d 

OBJS += \
./Application/User/drivers/fun/fun.o 


# Each subdirectory must supply rules for building sources it contributes
Application/User/drivers/fun/fun.o: C:/Users/USER/Desktop/pfa_final/tpe_29_04V2/tpe_27_04_v2/Core/drivers/fun/fun.c Application/User/drivers/fun/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_BPP=24 -DSTM32H7B3xxQ -DDEBUG -DUSE_BPP=24 -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/BSP -I../../TouchGFX/target -I../../TouchGFX/App -I../../TouchGFX/target/generated -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/BSP/Components/Common -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/BSP/STM32H7B3I-DK -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/BSP/Components/mx25lm51245g -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/gui/include -I../../TouchGFX/generated/videos/include -I../../LIBJPEG/App -I../../LIBJPEG/Target -I../../Utilities/JPEG -I../../Middlewares/Third_Party/LibJPEG/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-drivers-2f-fun

clean-Application-2f-User-2f-drivers-2f-fun:
	-$(RM) ./Application/User/drivers/fun/fun.cyclo ./Application/User/drivers/fun/fun.d ./Application/User/drivers/fun/fun.o ./Application/User/drivers/fun/fun.su

.PHONY: clean-Application-2f-User-2f-drivers-2f-fun

