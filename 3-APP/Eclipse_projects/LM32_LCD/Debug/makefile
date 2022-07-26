################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
LM32_LCD.lss \

FLASH_IMAGE += \
LM32_LCD.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: LM32_LCD.elf secondary-outputs

# Tool invocations
LM32_LCD.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LM32_LCD.map -mmcu=atmega32 -o "LM32_LCD.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LM32_LCD.lss: LM32_LCD.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LM32_LCD.elf  >"LM32_LCD.lss"
	@echo 'Finished building: $@'
	@echo ' '

LM32_LCD.hex: LM32_LCD.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LM32_LCD.elf  "LM32_LCD.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LM32_LCD.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t LM32_LCD.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LM32_LCD.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
