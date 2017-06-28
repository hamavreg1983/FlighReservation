################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FRS.cpp \
../src/mainFlightReservationSys.cpp 

OBJS += \
./src/FRS.o \
./src/mainFlightReservationSys.o 

CPP_DEPS += \
./src/FRS.d \
./src/mainFlightReservationSys.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../src -I../FRS_manger -I../gtest -I../UI -I../controler -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


