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
Pot_Buzzer.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Pot_Buzzer.elf secondary-outputs

# Tool invocations
Pot_Buzzer.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Pot_Buzzer.map -mmcu=atmega32 -o "Pot_Buzzer.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Pot_Buzzer.lss: Pot_Buzzer.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Pot_Buzzer.elf  >"Pot_Buzzer.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Pot_Buzzer.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t Pot_Buzzer.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Pot_Buzzer.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
