################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include UART/subdir.mk
-include SPI_Protocol/subdir.mk
-include LCD/subdir.mk
-include KeyPad/subdir.mk
-include INT/subdir.mk
-include DIO/subdir.mk
-include 7SEG/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AVR_Final_Project_Slave_KIT.lss \

FLASH_IMAGE += \
AVR_Final_Project_Slave_KIT.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: AVR_Final_Project_Slave_KIT.elf secondary-outputs

# Tool invocations
AVR_Final_Project_Slave_KIT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AVR_Final_Project_Slave_KIT.map -mmcu=atmega32 -o "AVR_Final_Project_Slave_KIT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AVR_Final_Project_Slave_KIT.lss: AVR_Final_Project_Slave_KIT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AVR_Final_Project_Slave_KIT.elf  >"AVR_Final_Project_Slave_KIT.lss"
	@echo 'Finished building: $@'
	@echo ' '

AVR_Final_Project_Slave_KIT.hex: AVR_Final_Project_Slave_KIT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AVR_Final_Project_Slave_KIT.elf  "AVR_Final_Project_Slave_KIT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AVR_Final_Project_Slave_KIT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AVR_Final_Project_Slave_KIT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AVR_Final_Project_Slave_KIT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
