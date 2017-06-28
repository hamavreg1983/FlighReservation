################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BookingManager_t.cpp \
../src/Booking_t.cpp \
../src/Channel_t.cpp \
../src/Communication_t.cpp \
../src/FRS.cpp \
../src/FlightManager_t.cpp \
../src/Flight_t.cpp \
../src/I_UI_t.cpp \
../src/Manager_t.cpp \
../src/PassengerManagert.cpp \
../src/Passenger_t.cpp \
../src/ReportFormatter_t.cpp \
../src/Seat_t.cpp \
../src/Tier_t.cpp \
../src/UI_supervisor_t.cpp \
../src/mainFlightReservationSys.cpp 

OBJS += \
./src/BookingManager_t.o \
./src/Booking_t.o \
./src/Channel_t.o \
./src/Communication_t.o \
./src/FRS.o \
./src/FlightManager_t.o \
./src/Flight_t.o \
./src/I_UI_t.o \
./src/Manager_t.o \
./src/PassengerManagert.o \
./src/Passenger_t.o \
./src/ReportFormatter_t.o \
./src/Seat_t.o \
./src/Tier_t.o \
./src/UI_supervisor_t.o \
./src/mainFlightReservationSys.o 

CPP_DEPS += \
./src/BookingManager_t.d \
./src/Booking_t.d \
./src/Channel_t.d \
./src/Communication_t.d \
./src/FRS.d \
./src/FlightManager_t.d \
./src/Flight_t.d \
./src/I_UI_t.d \
./src/Manager_t.d \
./src/PassengerManagert.d \
./src/Passenger_t.d \
./src/ReportFormatter_t.d \
./src/Seat_t.d \
./src/Tier_t.d \
./src/UI_supervisor_t.d \
./src/mainFlightReservationSys.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


