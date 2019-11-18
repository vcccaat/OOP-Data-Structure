################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../buddy.cpp \
../dining.cpp \
../main.cpp \
../workout.cpp 

OBJS += \
./buddy.o \
./dining.o \
./main.o \
./workout.o 

CPP_DEPS += \
./buddy.d \
./dining.d \
./main.d \
./workout.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


