/*
 * Bookingt_test.cpp
 *
 *  Created on: Jun 25, 2017
 *      Author: uv
 */

#include "gtest.h"
#include "Booking_t.h"

using namespace std;

static uint _flighID = 66666;
static uint _seat = 13;
static uint _passangerId = 398507060;
static uint _cost = 999;

static uint ticketID = 0;

TEST(Booking_t, init)
{
	ticketID = Booking_t::getStaticUniqeTicketNum();

	Booking_t B1;
	++ticketID;
	Booking_t B2(_flighID, _seat, _passangerId, _cost);
	++ticketID;

}

TEST(Booking_t, basic)
{

	Booking_t B(_flighID, _seat, _passangerId, _cost);
	++ticketID;
	EXPECT_EQ( B.getTicketNum() , ticketID);

}
