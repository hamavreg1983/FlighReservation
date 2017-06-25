################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BookingManager_t.cpp \
../src/BookingManager_t_test.cpp \
../src/Booking_t.cpp \
../src/Bookingt_test.cpp \
../src/FlightManager_t.cpp \
../src/FlightManager_t_test.cpp \
../src/Flight_t.cpp \
../src/Fligth_t_test.cpp \
../src/PassengerManagert.cpp \
../src/PassengerManagert_test.cpp \
../src/Passenger_t.cpp \
../src/Seat_t.cpp \
../src/Tier_t.cpp \
../src/Tier_t_test.cpp \
../src/allUnitTest.cpp 

OBJS += \
./src/BookingManager_t.o \
./src/BookingManager_t_test.o \
./src/Booking_t.o \
./src/Bookingt_test.o \
./src/FlightManager_t.o \
./src/FlightManager_t_test.o \
./src/Flight_t.o \
./src/Fligth_t_test.o \
./src/PassengerManagert.o \
./src/PassengerManagert_test.o \
./src/Passenger_t.o \
./src/Seat_t.o \
./src/Tier_t.o \
./src/Tier_t_test.o \
./src/allUnitTest.o 

CPP_DEPS += \
./src/BookingManager_t.d \
./src/BookingManager_t_test.d \
./src/Booking_t.d \
./src/Bookingt_test.d \
./src/FlightManager_t.d \
./src/FlightManager_t_test.d \
./src/Flight_t.d \
./src/Fligth_t_test.d \
./src/PassengerManagert.d \
./src/PassengerManagert_test.d \
./src/Passenger_t.d \
./src/Seat_t.d \
./src/Tier_t.d \
./src/Tier_t_test.d \
./src/allUnitTest.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../googleTest/gtest -I../gtest -I./gtest/ -I../../gtest -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


