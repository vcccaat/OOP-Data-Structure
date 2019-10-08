################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../hydrogen.cpp \
../laughingGasMain.cpp \
../nitrogen.cpp \
../oxygen.cpp \
../waterMain.cpp 

OBJS += \
./hydrogen.o \
./laughingGasMain.o \
./nitrogen.o \
./oxygen.o \
./waterMain.o 

CPP_DEPS += \
./hydrogen.d \
./laughingGasMain.d \
./nitrogen.d \
./oxygen.d \
./waterMain.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


