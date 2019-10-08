################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../buddy.cpp \
../food.cpp \
../main.cpp \
../relaxation.cpp \
../relaxplan.cpp \
../restaurant.cpp \
../workout.cpp \
../workoutenvironment.cpp 

OBJS += \
./buddy.o \
./food.o \
./main.o \
./relaxation.o \
./relaxplan.o \
./restaurant.o \
./workout.o \
./workoutenvironment.o 

CPP_DEPS += \
./buddy.d \
./food.d \
./main.d \
./relaxation.d \
./relaxplan.d \
./restaurant.d \
./workout.d \
./workoutenvironment.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


