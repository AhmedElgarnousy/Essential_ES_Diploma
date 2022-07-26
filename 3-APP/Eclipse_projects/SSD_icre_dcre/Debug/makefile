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
SSD_icre_dcre.lss \

FLASH_IMAGE += \
SSD_icre_dcre.hex \

EEPROM_IMAGE += \
SSD_icre_dcre.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: SSD_icre_dcre.elf secondary-outputs

# Tool invocations
SSD_icre_dcre.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SSD_icre_dcre.map -mmcu=atmega32 -o "SSD_icre_dcre.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SSD_icre_dcre.lss: SSD_icre_dcre.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SSD_icre_dcre.elf  >"SSD_icre_dcre.lss"
	@echo 'Finished building: $@'
	@echo ' '

SSD_icre_dcre.hex: SSD_icre_dcre.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SSD_icre_dcre.elf  "SSD_icre_dcre.hex"
	@echo 'Finished building: $@'
	@echo ' '

SSD_icre_dcre.eep: SSD_icre_dcre.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex SSD_icre_dcre.elf  "SSD_icre_dcre.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SSD_icre_dcre.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t SSD_icre_dcre.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SSD_icre_dcre.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
