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
SWC_KPD.lss \

FLASH_IMAGE += \
SWC_KPD.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SWC_KPD.elf secondary-outputs

# Tool invocations
SWC_KPD.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SWC_KPD.map -mmcu=atmega32 -o "SWC_KPD.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SWC_KPD.lss: SWC_KPD.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SWC_KPD.elf  >"SWC_KPD.lss"
	@echo 'Finished building: $@'
	@echo ' '

SWC_KPD.hex: SWC_KPD.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SWC_KPD.elf  "SWC_KPD.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SWC_KPD.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t SWC_KPD.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SWC_KPD.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
