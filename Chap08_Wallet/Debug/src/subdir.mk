################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Chap08_Wallet.cpp \
../src/Wallet.cpp 

CPP_DEPS += \
./src/Chap08_Wallet.d \
./src/Wallet.d 

OBJS += \
./src/Chap08_Wallet.o \
./src/Wallet.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Chap08_Wallet.d ./src/Chap08_Wallet.o ./src/Wallet.d ./src/Wallet.o

.PHONY: clean-src

