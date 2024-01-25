################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../INT/EXTI_program.c \
../INT/Global_Interrupt_program.c 

OBJS += \
./INT/EXTI_program.o \
./INT/Global_Interrupt_program.o 

C_DEPS += \
./INT/EXTI_program.d \
./INT/Global_Interrupt_program.d 


# Each subdirectory must supply rules for building sources it contributes
INT/%.o: ../INT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


