/*
 * Tier_t_test.cpp
 *
 *  Created on: Jun 21, 2017
 *      Author: yuval
 */

#include <iostream>
#include "gtest.h"
#include "Tier_t.h"

using namespace std;


static string tierID = "first";
static uint firstSeatNum = 10;
static uint capacity = 5;
static uint price = 999;
static uint ticketNum = 54321;

TEST(Tier, init)
{
	Tier_t T(tierID, firstSeatNum, capacity, price);
	EXPECT_EQ(T.getLastSeatNum(), firstSeatNum + capacity - 1);
//	EXPECT_EQ(num, S.getSeatNum());
}

TEST(Tier, orderSeat)
{
	Tier_t T(tierID, firstSeatNum, capacity, price);
	EXPECT_TRUE(T.orderSeat(firstSeatNum + 1, ticketNum));

	EXPECT_EQ(ticketNum, T.getTicket(firstSeatNum + 1) );

	// seat dosent exsist
	EXPECT_THROW( T.orderSeat(firstSeatNum - 1, ticketNum) , const char* );
}

TEST(Tier, orderSeat_that_is_not_free)
{
	Tier_t T(tierID, firstSeatNum, capacity, price);
	EXPECT_TRUE(T.orderSeat(firstSeatNum + 1, ticketNum));
	EXPECT_EQ(ticketNum, T.getTicket(firstSeatNum + 1) );

	EXPECT_FALSE(T.orderSeat(firstSeatNum + 1, ticketNum - 5));
	EXPECT_EQ(ticketNum, T.getTicket(firstSeatNum + 1) );
}

TEST(Tier, cancelSeat)
{
	Tier_t T(tierID, firstSeatNum, capacity, price);
	EXPECT_TRUE(T.orderSeat(firstSeatNum + 1, ticketNum));

	EXPECT_TRUE(T.cancelSeat(firstSeatNum + 1) );
	EXPECT_FALSE(T.cancelSeat(firstSeatNum + 1) ); // re cancel a seat
	EXPECT_FALSE(T.cancelSeat(firstSeatNum + 2) ); // cancel and unorder seat

	EXPECT_FALSE ( T.isOccupied(firstSeatNum + 1) );
}

