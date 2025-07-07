################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/wisse/Desktop/tpe/tpe_09_04/Drivers/BSP/Components/ft5336/ft5336.c \
C:/Users/wisse/Desktop/tpe/tpe_09_04/Drivers/BSP/Components/ft5336/ft5336_reg.c \
C:/Users/wisse/Desktop/tpe/tpe_09_04/Drivers/BSP/Components/mx25lm51245g/mx25lm51245g.c 

C_DEPS += \
./Drivers/BSP/Components/ft5336.d \
./Drivers/BSP/Components/ft5336_reg.d \
./Drivers/BSP/Components/mx25lm51245g.d 

OBJS += \
./Drivers/BSP/Components/ft5336.o \
./Drivers/BSP/Components/ft5336_reg.o \
./Drivers/BSP/Components/mx25lm51245g.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/ft5336.o: C:/Users/wisse/Desktop/tpe/tpe_09_04/Drivers/BSP/Components/ft5336/ft5336.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DUSE_BPP=24 -DSTM32H7B3xxQ -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../TouchGFX/generated/gui_generated/include -I../../Drivers/BSP -I../../TouchGFX/target -I../../TouchGFX/App -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/target/generated -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../TouchGFX/gui/include -I../../Drivers/BSP/Components/Common -I../../TouchGFX/generated/texts/include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../TouchGFX/generated/images/include -I../../Drivers/BSP/STM32H7B3I-DK -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/BSP/Components/mx25lm51245g -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../LIBJPEG/App -I../../LIBJPEG/Target -I../../Utilities/JPEG -I../../Middlewares/Third_Party/LibJPEG/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/ft5336_reg.o: C:/Users/wisse/Desktop/tpe/tpe_09_04/Drivers/BSP/Components/ft5336/ft5336_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DUSE_BPP=24 -DSTM32H7B3xxQ -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../TouchGFX/generated/gui_generated/include -I../../Drivers/BSP -I../../TouchGFX/target -I../../TouchGFX/App -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/target/generated -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../TouchGFX/gui/include -I../../Drivers/BSP/Components/Common -I../../TouchGFX/generated/texts/include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../TouchGFX/generated/images/include -I../../Drivers/BSP/STM32H7B3I-DK -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/BSP/Components/mx25lm51245g -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../LIBJPEG/App -I../../LIBJPEG/Target -I../../Utilities/JPEG -I../../Middlewares/Third_Party/LibJPEG/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/mx25lm51245g.o: C:/Users/wisse/Desktop/tpe/tpe_09_04/Drivers/BSP/Components/mx25lm51245g/mx25lm51245g.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DUSE_BPP=24 -DSTM32H7B3xxQ -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../TouchGFX/generated/gui_generated/include -I../../Drivers/BSP -I../../TouchGFX/target -I../../TouchGFX/App -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/target/generated -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../TouchGFX/gui/include -I../../Drivers/BSP/Components/Common -I../../TouchGFX/generated/texts/include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../TouchGFX/generated/images/include -I../../Drivers/BSP/STM32H7B3I-DK -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/BSP/Components/mx25lm51245g -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/videos/include -I../../LIBJPEG/App -I../../LIBJPEG/Target -I../../Utilities/JPEG -I../../Middlewares/Third_Party/LibJPEG/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components

clean-Drivers-2f-BSP-2f-Components:
	-$(RM) ./Drivers/BSP/Components/ft5336.cyclo ./Drivers/BSP/Components/ft5336.d ./Drivers/BSP/Components/ft5336.o ./Drivers/BSP/Components/ft5336.su ./Drivers/BSP/Components/ft5336_reg.cyclo ./Drivers/BSP/Components/ft5336_reg.d ./Drivers/BSP/Components/ft5336_reg.o ./Drivers/BSP/Components/ft5336_reg.su ./Drivers/BSP/Components/mx25lm51245g.cyclo ./Drivers/BSP/Components/mx25lm51245g.d ./Drivers/BSP/Components/mx25lm51245g.o ./Drivers/BSP/Components/mx25lm51245g.su

.PHONY: clean-Drivers-2f-BSP-2f-Components

