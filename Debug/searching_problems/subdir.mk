################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../searching_problems/puzzle8.cpp 

CPP_DEPS += \
./searching_problems/puzzle8.d 

OBJS += \
./searching_problems/puzzle8.o 


# Each subdirectory must supply rules for building sources it contributes
searching_problems/%.o: ../searching_problems/%.cpp searching_problems/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-searching_problems

clean-searching_problems:
	-$(RM) ./searching_problems/puzzle8.d ./searching_problems/puzzle8.o

.PHONY: clean-searching_problems

