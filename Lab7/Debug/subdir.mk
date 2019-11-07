################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Car.cpp \
../DeliveryCar.cpp \
../Engine.cpp \
../PoliceCar.cpp \
../Vehicle.cpp \
../main_A.cpp \
../main_B.cpp 

OBJS += \
./Car.o \
./DeliveryCar.o \
./Engine.o \
./PoliceCar.o \
./Vehicle.o \
./main_A.o \
./main_B.o 

CPP_DEPS += \
./Car.d \
./DeliveryCar.d \
./Engine.d \
./PoliceCar.d \
./Vehicle.d \
./main_A.d \
./main_B.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


