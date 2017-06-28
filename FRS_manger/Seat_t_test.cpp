/*
 * Seat_t_test.cpp
 *
 *  Created on: Jun 23, 2017
 *      Author: yuval
 */

#include "gtest.h"
#include "Seat_t.h"

TEST(Seat, num)
{
	uint num = 5;
	Seat_t S(num);
	EXPECT_EQ(num, S.getSeatNum());
}

TEST(Seat, buy)
{
	uint num = 5;
	uint ticketNum = 54321;
	Seat_t S(num);
	ASSERT_FALSE(S.isOccupied());
	ASSERT_TRUE( S.orderSeat(ticketNum) );
	ASSERT_TRUE(S.isOccupied());
	EXPECT_EQ ( S.getTicket() , ticketNum );
}

TEST(Seat, cancel)
{
	uint num = 5;
	uint ticketNum = 54321;
	Seat_t S(num);

	// new test
	ASSERT_FALSE( S.cancelSeat() );

	ASSERT_FALSE(S.isOccupied());
	ASSERT_TRUE( S.orderSeat(ticketNum) );
	ASSERT_TRUE(S.isOccupied());
	EXPECT_EQ ( S.getTicket() , ticketNum );

	// new test from here
	ASSERT_TRUE( S.cancelSeat() );
	ASSERT_FALSE(S.isOccupied());
	EXPECT_EQ ( S.getTicket() , (uint) 0 );

}

