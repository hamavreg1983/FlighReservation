/*
 * Tier_t_test.cpp
 *
 *  Created on: Jun 21, 2017
 *      Author: yuval
 */

#include <iostream>
#include "gtest.h"
#include "Flight_t.h"

using namespace std;

static string flightNum = "EY002";
static string des = "TLV";
static string dep = "LAX";
static string plane = "LAX";
static string when = "LAX";

static uint seatNum = 100;
static uint ticketNum = 54321;

static uint baseFlightIDnum;

TEST(Flight, init)
{
	//Flight_t(const string& _flightNum, const string& _departure, const string& _destination, const string& _timeDeparture, const string& _plane );
	Flight_t F(flightNum, des, dep, when, plane);
}

TEST(Flight, flightUniqeNumbers)
{
	baseFlightIDnum = Flight_t::getFlightStaticID();
	//Flight_t(const string& _flightNum, const string& _departure, const string& _destination, const string& _timeDeparture, const string& _plane );
	Flight_t F0("10", des, dep, when, plane);
	Flight_t F1("11", des, dep, when, plane);
	Flight_t F2("12", des, dep, when, plane);
	Flight_t F3("13", des, dep, when, plane);

	EXPECT_EQ( F2.getFlightId() , baseFlightIDnum + 3);

}

TEST(Flight, getBasic)
{
	baseFlightIDnum = Flight_t::getFlightStaticID();
	//Flight_t(const string& _flightNum, const string& _departure, const string& _destination, const string& _timeDeparture, const string& _plane );
	Flight_t F(flightNum, des, dep, when, plane);

	EXPECT_EQ(F.getFlightNum() , flightNum);
	EXPECT_EQ(F.getFlightId() , baseFlightIDnum + 1);
	EXPECT_EQ(F.getSeatName(2) , "SeatName:2") ;
	EXPECT_THROW(F.getSeatName(300) , const char*) ; // seat not on flight

	EXPECT_EQ( F.getTiersName()[1] , "tier2" ) ;

}

TEST(Flight, orderSeat)
{
	Flight_t F(flightNum, des, dep, when, plane);

	EXPECT_FALSE(F.isFlightFull() );
	EXPECT_FALSE(F.isTierFull(F.getTiersName()[1]) );

	EXPECT_EQ( F.numberOfSeatAvalibul() , (uint) 160);

	EXPECT_TRUE( F.orderSeat(seatNum, ticketNum) );
	EXPECT_EQ( F.numberOfSeatAvalibul() , (uint) 159);

	EXPECT_FALSE( F.orderSeat(seatNum, ticketNum) );
	EXPECT_EQ( F.numberOfSeatAvalibul() , (uint) 159);


}

TEST(Flight, orderSeatUntilDone)
{
	Flight_t F(flightNum, des, dep, when, plane);

	for (int i = 1; i < 160 ; i++)
	{
		EXPECT_TRUE( F.orderSeat(i, ticketNum) );
	}
	EXPECT_EQ( F.numberOfSeatAvalibul() , (uint) 1);
	EXPECT_TRUE( F.orderSeat(160, ticketNum) );

	EXPECT_THROW( F.orderSeat(161, ticketNum), const char* );

	EXPECT_TRUE(F.isFlightFull() );
	EXPECT_TRUE(F.isTierFull(F.getTiersName()[1]) );
}

TEST(Flight, cancelSeat)
{
	Flight_t F(flightNum, des, dep, when, plane);

	EXPECT_FALSE(F.cancelSeat(seatNum) );

	EXPECT_TRUE( F.orderSeat(seatNum, ticketNum) );

	EXPECT_FALSE(F.cancelSeat(seatNum +1 ) );
	EXPECT_TRUE(F.cancelSeat(seatNum ) );
	EXPECT_FALSE(F.cancelSeat(seatNum ) );

	EXPECT_EQ( F.numberOfSeatAvalibul() , (uint) 160);

}
