################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SW/subdir.mk
-include SSD/subdir.mk
-include DIO/subdir.mk
-include CLCD/subdir.mk
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
Project1_HAZARD.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Project1_HAZARD.elf secondary-outputs

# Tool invocations
Project1_HAZARD.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Project1_HAZARD.map -mmcu=atmega32 -o "Project1_HAZARD.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Project1_HAZARD.lss: Project1_HAZARD.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Project1_HAZARD.elf  >"Project1_HAZARD.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Project1_HAZARD.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Project1_HAZARD.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Project1_HAZARD.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
