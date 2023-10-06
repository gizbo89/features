################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../utils/dualdouble.cpp \
../utils/nvector.cpp \
../utils/tensor.cpp 

CPP_DEPS += \
./utils/dualdouble.d \
./utils/nvector.d \
./utils/tensor.d 

OBJS += \
./utils/dualdouble.o \
./utils/nvector.o \
./utils/tensor.o 


# Each subdirectory must supply rules for building sources it contributes
utils/%.o: ../utils/%.cpp utils/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/gizbo89/Desktop/eigen-3.3.9 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-utils

clean-utils:
	-$(RM) ./utils/dualdouble.d ./utils/dualdouble.o ./utils/nvector.d ./utils/nvector.o ./utils/tensor.d ./utils/tensor.o

.PHONY: clean-utils

