################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/wisse/Desktop/tpe/tpe_09_04/LIBJPEG/App/libjpeg.c 

C_DEPS += \
./Application/User/LIBJPEG/App/libjpeg.d 

OBJS += \
./Application/User/LIBJPEG/App/libjpeg.o 


# Each subdirectory must supply rules for building sources it contributes
Application/User/LIBJPEG/App/libjpeg.o: C:/Users/wisse/Desktop/tpe/tpe_09_04/LIBJPEG/App/libjpeg.c Application/User/LIBJPEG/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DUSE_BPP=24 -DSTM32H7B3xxQ -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../TouchGFX/generated/gui_generated/include -I../../Drivers/BSP -I../../TouchGFX/target -I../../TouchGFX/App -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/target/generated -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../TouchGFX/gui/include -I../../Drivers/BSP/Components/Common -I../../TouchGFX/generated/texts/include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../TouchGFX/generated/images/include -I../../Drivers/BSP/STM32H7B3I-DK -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/BSP/Components/mx25lm51245g -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../LIBJPEG/App -I../../LIBJPEG/Target -I../../Utilities/JPEG -I../../Middlewares/Third_Party/LibJPEG/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-LIBJPEG-2f-App

clean-Application-2f-User-2f-LIBJPEG-2f-App:
	-$(RM) ./Application/User/LIBJPEG/App/libjpeg.cyclo ./Application/User/LIBJPEG/App/libjpeg.d ./Application/User/LIBJPEG/App/libjpeg.o ./Application/User/LIBJPEG/App/libjpeg.su

.PHONY: clean-Application-2f-User-2f-LIBJPEG-2f-App

