################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../btree-create-delete.cpp \
../btree-main.cpp \
../btree-print.cpp 

OBJS += \
./btree-create-delete.o \
./btree-main.o \
./btree-print.o 

CPP_DEPS += \
./btree-create-delete.d \
./btree-main.d \
./btree-print.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


