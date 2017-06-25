/*
 * FlightManager_t_test.cpp
 *
 *  Created on: Jun 24, 2017
 *      Author: yuval
 */

#include <iostream>
#include "gtest.h"
#include "FlightManager_t.h"

using namespace std;


static string _flightNum = "EY002";
static string _departure = "TLV";
static string _destination = "LAX";
static string _plane = "LAX";
static string _when = "LAX";

static uint flightBaseId = 0;

static uint seatNum = 100;
static uint ticketNum = 54321;

TEST(FlightManager_t, init)
{
	FlightManager_t FM;
}

TEST(FlightManager_t, addFlight_test)
{
	FlightManager_t FM;
	EXPECT_TRUE(FM.isEmpty() );
	EXPECT_EQ(FM.count(), (uint) 0 );

	EXPECT_FALSE( FM.isFlightExsists(flightBaseId - 1) );
	EXPECT_EQ( FM.addFlight(_flightNum, _departure, _destination, _when, _plane) , ++flightBaseId);
	EXPECT_FALSE(FM.isEmpty() );
	EXPECT_EQ(FM.count(), flightBaseId );
	EXPECT_TRUE( FM.isFlightExsists(flightBaseId) );

	EXPECT_EQ( FM.addFlight(_flightNum, _departure, _destination, _when, _plane) , ++flightBaseId);
	EXPECT_FALSE(FM.isEmpty() );
	EXPECT_EQ(FM.count(), flightBaseId );

}

TEST(FlightManager_t, removeFlight_test)
{
	FlightManager_t FM;
	EXPECT_TRUE(FM.isEmpty() );
	EXPECT_EQ(FM.count(), (uint) 0 );

	EXPECT_EQ( FM.addFlight(_flightNum, _departure, _destination, _when, _plane) , ++flightBaseId);
	EXPECT_EQ( FM.addFlight(_flightNum, _departure, _destination, _when, _plane) , ++flightBaseId);
	EXPECT_EQ(FM.count(), (uint) 2 );

	EXPECT_TRUE( FM.removeFlight(flightBaseId - 1) );
	EXPECT_EQ(FM.count(), (uint) 1 );

	EXPECT_ANY_THROW( FM.removeFlight(flightBaseId - 1) );
	EXPECT_EQ(FM.count(), (uint) 1 );

	EXPECT_TRUE( FM.removeFlight(flightBaseId) );
	EXPECT_EQ(FM.count(), (uint) 0 );

	EXPECT_ANY_THROW( FM.removeFlight(flightBaseId) );
}

TEST(FlightManager_t, handelSeat)
{
	FlightManager_t FM;
	EXPECT_EQ( FM.addFlight(_flightNum, _departure, _destination, _when, _plane) , ++flightBaseId);
	EXPECT_TRUE( FM.orderSeat(flightBaseId, seatNum, ticketNum) );
	EXPECT_EQ( FM.getTicket(flightBaseId, seatNum), ticketNum);
	EXPECT_EQ( FM.getTicket(flightBaseId, seatNum+1), (uint) 0); // TODO should an empty seat return ticket 0 or throw ?
	EXPECT_THROW( FM.getTicket(flightBaseId + 1, seatNum), const char*);


	// TODO more tests
}





