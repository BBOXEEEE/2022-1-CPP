################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Chap10_Fraction.cpp \
../src/Fraction.cpp 

CPP_DEPS += \
./src/Chap10_Fraction.d \
./src/Fraction.d 

OBJS += \
./src/Chap10_Fraction.o \
./src/Fraction.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Chap10_Fraction.d ./src/Chap10_Fraction.o ./src/Fraction.d ./src/Fraction.o

.PHONY: clean-src

