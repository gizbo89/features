################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cryptosystems/SPN.cpp \
../cryptosystems/cipher.cpp \
../cryptosystems/rsa.cpp 

CPP_DEPS += \
./cryptosystems/SPN.d \
./cryptosystems/cipher.d \
./cryptosystems/rsa.d 

OBJS += \
./cryptosystems/SPN.o \
./cryptosystems/cipher.o \
./cryptosystems/rsa.o 


# Each subdirectory must supply rules for building sources it contributes
cryptosystems/%.o: ../cryptosystems/%.cpp cryptosystems/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-cryptosystems

clean-cryptosystems:
	-$(RM) ./cryptosystems/SPN.d ./cryptosystems/SPN.o ./cryptosystems/cipher.d ./cryptosystems/cipher.o ./cryptosystems/rsa.d ./cryptosystems/rsa.o

.PHONY: clean-cryptosystems

