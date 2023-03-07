################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BankAccount.cpp \
../src/Practice03_BankAccount.cpp 

CPP_DEPS += \
./src/BankAccount.d \
./src/Practice03_BankAccount.d 

OBJS += \
./src/BankAccount.o \
./src/Practice03_BankAccount.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/BankAccount.d ./src/BankAccount.o ./src/Practice03_BankAccount.d ./src/Practice03_BankAccount.o

.PHONY: clean-src

