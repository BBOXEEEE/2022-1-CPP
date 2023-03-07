################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Chap07_MonthlyWalkLog.cpp \
../src/MonthlyWalkLog.cpp 

CPP_DEPS += \
./src/Chap07_MonthlyWalkLog.d \
./src/MonthlyWalkLog.d 

OBJS += \
./src/Chap07_MonthlyWalkLog.o \
./src/MonthlyWalkLog.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Chap07_MonthlyWalkLog.d ./src/Chap07_MonthlyWalkLog.o ./src/MonthlyWalkLog.d ./src/MonthlyWalkLog.o

.PHONY: clean-src

