/*
 * Manager_t_test.cpp
 *
 *  Created on: Jun 25, 2017
 *      Author: uv
 */

#include "gtest.h"
#include "Manager_t.h"

using namespace std;

static string _flightNum = "EY002";
static string _departure = "TLV";
static string _destination = "LAX";
static string _plane = "LAX";
static string _when = "LAX";

static uint flightBaseId = 0;

static uint seatNum = 100;
static uint ticketNum = 54321;

static uint passengerID = 39850706;
static string name = "yuval";
static string address = "TelAviv";
static string phone = "054-6379917";
static string preferanceSeating = "next to a windows";

static uint ticketProducedNum = 0;

TEST(Manager_t, init)
{
	Manager_t m1();
	Manager_t m2;
	Manager_t m3(0);
	EXPECT_NO_FATAL_FAILURE( Manager_t m1() );
	EXPECT_NO_FATAL_FAILURE( Manager_t m2 );
	EXPECT_NO_FATAL_FAILURE( Manager_t m3(0) );
}

TEST(Manager_t, addFlight)
{
	Manager_t m(0);
	flightBaseId = m.addFlight(_flightNum, _departure, _destination, _when, _plane);
	EXPECT_EQ( m.addFlight(_flightNum, _departure, _destination, _when, _plane) , ++flightBaseId );
}

TEST(Manager_t, removeFlight)
{
	Manager_t m(0);
	EXPECT_EQ( m.addFlight(_flightNum, _departure, _destination, _when, _plane) , ++flightBaseId );
	EXPECT_EQ( m.addFlight(_flightNum, _departure, _destination, _when, _plane) , ++flightBaseId );

	EXPECT_TRUE( m.removeFlight(flightBaseId) );
	EXPECT_FALSE( m.removeFlight(flightBaseId) );
	EXPECT_NO_THROW( m.removeFlight(flightBaseId + 30 ) );
}

TEST(Manager_t, updateFlight)
{
	Manager_t m(0);
	EXPECT_EQ( m.addFlight(_flightNum, _departure, _destination, _when, _plane) , ++flightBaseId );
	EXPECT_EQ( m.addFlight(_flightNum, _departure, _destination, _when, _plane) , ++flightBaseId );

	EXPECT_TRUE( m.updateFlight(flightBaseId, _flightNum, _departure, _departure, _when) );
	EXPECT_FALSE( m.updateFlight(flightBaseId + 30, _flightNum, _departure, _departure, _when)  );
	EXPECT_EQ ( m.getDestination(flightBaseId) , _departure);
	EXPECT_EQ ( m.getDeparture(flightBaseId) , _departure);
}


TEST(Manager_t, order)
{
	Manager_t m(0);
	EXPECT_ANY_THROW( m.order(flightBaseId, seatNum, passengerID) );
	EXPECT_EQ( m.addFlight(_flightNum, _departure, _destination, _when, _plane) , ++flightBaseId );
	EXPECT_ANY_THROW( m.order(flightBaseId, seatNum, passengerID) );

	EXPECT_TRUE( m.removeFlight(flightBaseId) );
	EXPECT_NO_THROW( m.passenger(passengerID, name, address, phone, preferanceSeating) );
	EXPECT_ANY_THROW( m.order(flightBaseId, seatNum, passengerID) );

	EXPECT_EQ( m.addFlight(_flightNum, _departure, _destination, _when, _plane) , ++flightBaseId );
	EXPECT_NO_THROW( ticketProducedNum = m.order(flightBaseId, seatNum, passengerID) );

	EXPECT_EQ( m.countTickets() , (uint) 1 );
	EXPECT_ANY_THROW( m.order(flightBaseId, seatNum, passengerID) );

	EXPECT_EQ( m.countTickets() , (uint) 1 );
}

TEST(Manager_t, cancelTicket)
{
	Manager_t m(0);
	EXPECT_ANY_THROW( m.cancelTicket(ticketNum) );
	EXPECT_EQ( m.addFlight(_flightNum, _departure, _destination, _when, _plane) , ++flightBaseId );
	EXPECT_NO_THROW( m.passenger(passengerID, name, address, phone, preferanceSeating) );
	EXPECT_ANY_THROW( m.cancelTicket(ticketNum) );

	EXPECT_NO_THROW( ticketProducedNum = m.order(flightBaseId, seatNum, passengerID) );
	EXPECT_EQ( m.countTickets() , (uint) 1 );

	EXPECT_TRUE( m.cancelTicket(ticketProducedNum) );
	EXPECT_EQ( m.countTickets() , (uint) 0 );
	EXPECT_THROW( m.cancelTicket(ticketNum) , const char* );

}

TEST(Manager_t, passenger)
{
	Manager_t m(0);
	EXPECT_FALSE( m.isPassengerExist(passengerID) );
	EXPECT_FALSE( m.removePassenger(passengerID) );
	EXPECT_NO_THROW( m.passenger(passengerID, name, address, phone, preferanceSeating) );
	EXPECT_EQ( m.getName(passengerID) , name);
	EXPECT_NO_THROW( m.passenger(passengerID, "not Yuval", address, phone, preferanceSeating) );
	EXPECT_EQ( m.getName(passengerID) , "not Yuval");
	EXPECT_TRUE( m.isPassengerExist(passengerID) );

}

TEST(Manager_t, passengerRemove)
{
	Manager_t m(0);
	EXPECT_NO_THROW( m.passenger(passengerID, name, address, phone, preferanceSeating) );

	EXPECT_TRUE( m.removePassenger(passengerID) );
	EXPECT_FALSE( m.removePassenger(passengerID) );
	EXPECT_FALSE( m.isPassengerExist(passengerID) );
	EXPECT_FALSE( m.isPassengerExist(passengerID) );
}



