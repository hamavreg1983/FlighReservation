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
	// TODO m.get flight data
}













TEST(Manager_t, order)
{
	Manager_t m(0);
//	m.
}

// TODO cancel
// TODO pessenger
// TODO remove passenger



