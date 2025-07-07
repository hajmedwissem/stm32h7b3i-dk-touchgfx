################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/wisse/Desktop/tpe/tpe_09_04/Utilities/JPEG/jpeg_utils.c 

C_DEPS += \
./Utilities/jpeg_utils.d 

OBJS += \
./Utilities/jpeg_utils.o 


# Each subdirectory must supply rules for building sources it contributes
Utilities/jpeg_utils.o: C:/Users/wisse/Desktop/tpe/tpe_09_04/Utilities/JPEG/jpeg_utils.c Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DUSE_BPP=24 -DSTM32H7B3xxQ -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../TouchGFX/generated/gui_generated/include -I../../Drivers/BSP -I../../TouchGFX/target -I../../TouchGFX/App -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/target/generated -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../TouchGFX/gui/include -I../../Drivers/BSP/Components/Common -I../../TouchGFX/generated/texts/include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../TouchGFX/generated/images/include -I../../Drivers/BSP/STM32H7B3I-DK -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/BSP/Components/mx25lm51245g -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../LIBJPEG/App -I../../LIBJPEG/Target -I../../Utilities/JPEG -I../../Middlewares/Third_Party/LibJPEG/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Utilities

clean-Utilities:
	-$(RM) ./Utilities/jpeg_utils.cyclo ./Utilities/jpeg_utils.d ./Utilities/jpeg_utils.o ./Utilities/jpeg_utils.su

.PHONY: clean-Utilities

