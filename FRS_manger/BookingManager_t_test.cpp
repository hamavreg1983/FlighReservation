/*
 * BookingManager_t_test.cpp
 *
 *  Created on: Jun 25, 2017
 *      Author: uv
 */

#include "BookingManager_t.h"
#include "gtest.h"

using namespace std;



static uint _flighID = 66666;
static uint _seat = 13;
static uint _passangerId = 398507060;
static uint _cost = 999;

static uint ticketID;

TEST(BookingManager_t, init)
{
	BookingManager_t BM;
	ticketID = BM.getTotalTicketNum();
}

TEST(BookingManager_t, addTicket)
{
	BookingManager_t BM;

	EXPECT_TRUE( BM.isEmpty() );
	EXPECT_EQ( BM.count() , (uint) 0);

	EXPECT_EQ( BM.addTicket(_flighID, _seat, _passangerId, _cost) , ++ticketID);

	EXPECT_FALSE( BM.isEmpty() );
	EXPECT_EQ( BM.count() , (uint) 1);

	EXPECT_EQ( BM.addTicket(_flighID, _seat, _passangerId, _cost) , ++ticketID);
	EXPECT_EQ( BM.count() , (uint) 2);
}

TEST(BookingManager_t, removeTicket)
{
	BookingManager_t BM;
	EXPECT_EQ( BM.addTicket(_flighID, _seat, _passangerId, _cost) , ++ticketID);
	EXPECT_EQ( BM.addTicket(_flighID, _seat, _passangerId, _cost) , ++ticketID);
	EXPECT_EQ( BM.count() , (uint) 2);

	EXPECT_TRUE ( BM.removeTicket(ticketID) );
	EXPECT_THROW ( BM.removeTicket(ticketID) , const char* );
	EXPECT_THROW ( BM.removeTicket(ticketID+1) , const char* );
	EXPECT_TRUE ( BM.removeTicket(ticketID-1) );

	EXPECT_TRUE( BM.isEmpty() );
	EXPECT_EQ( BM.count() , (uint) 0);
}

TEST(BookingManager_t, basicGetSet)
{
	BookingManager_t BM;
	EXPECT_EQ( BM.addTicket(_flighID, _seat, _passangerId, _cost) , ++ticketID);
	EXPECT_EQ( BM.addTicket(_flighID, _seat, _passangerId, _cost) , ++ticketID);
	EXPECT_EQ( BM.count() , (uint) 2);

	EXPECT_TRUE( BM.isTicketActive(ticketID) );
	EXPECT_ANY_THROW( BM.isTicketActive(ticketID + 1) );

	EXPECT_NO_THROW( BM.deActivateTicket(ticketID) );
	EXPECT_FALSE( BM.isTicketActive(ticketID) );

}
