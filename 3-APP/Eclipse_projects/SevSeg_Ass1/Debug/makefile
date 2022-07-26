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
SevSeg_Ass1.lss \

FLASH_IMAGE += \
SevSeg_Ass1.hex \

EEPROM_IMAGE += \
SevSeg_Ass1.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: SevSeg_Ass1.elf secondary-outputs

# Tool invocations
SevSeg_Ass1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SevSeg_Ass1.map -mmcu=atmega32 -o "SevSeg_Ass1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SevSeg_Ass1.lss: SevSeg_Ass1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SevSeg_Ass1.elf  >"SevSeg_Ass1.lss"
	@echo 'Finished building: $@'
	@echo ' '

SevSeg_Ass1.hex: SevSeg_Ass1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SevSeg_Ass1.elf  "SevSeg_Ass1.hex"
	@echo 'Finished building: $@'
	@echo ' '

SevSeg_Ass1.eep: SevSeg_Ass1.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex SevSeg_Ass1.elf  "SevSeg_Ass1.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SevSeg_Ass1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t SevSeg_Ass1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SevSeg_Ass1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
