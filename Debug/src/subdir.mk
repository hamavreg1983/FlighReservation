################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FlightManager_t.cpp \
../src/FlightReservationSys.cpp \
../src/Flight_t.cpp \
../src/PassengerManagert.cpp \
../src/Passenger_t.cpp \
../src/Seat_t.cpp \
../src/Tier_t.cpp 

OBJS += \
./src/FlightManager_t.o \
./src/FlightReservationSys.o \
./src/Flight_t.o \
./src/PassengerManagert.o \
./src/Passenger_t.o \
./src/Seat_t.o \
./src/Tier_t.o 

CPP_DEPS += \
./src/FlightManager_t.d \
./src/FlightReservationSys.d \
./src/Flight_t.d \
./src/PassengerManagert.d \
./src/Passenger_t.d \
./src/Seat_t.d \
./src/Tier_t.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


