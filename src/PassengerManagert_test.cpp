/*
 * PassengerManagert_test.cpp
 *
 *  Created on: Jun 24, 2017
 *      Author: yuval
 */

#include <iostream>
#include "gtest.h"
#include "PassengerManagert.h"

using namespace std;

static uint id = 39850706;
static string _name = "yuval";
static string _address = "telAviv, bialik";
static string _phone = "054-545454";
static string _preferanceSeating = "next to window";
static uint ticketNum = 54321;

TEST(PassengerManger, init)
{
	PassengerManager_t PM;
}

TEST(PassengerManger, add_basic_test)
{
	PassengerManager_t pm;

	EXPECT_TRUE(pm.isEmpty() );
	EXPECT_TRUE(pm.addPassenger(id) );
	EXPECT_FALSE(pm.isEmpty() );
	EXPECT_TRUE(pm.addPassenger(id + 1) );
	EXPECT_EQ(pm.count() , (uint) 2);

	EXPECT_EQ( pm.getName(id) , "");
	EXPECT_EQ( pm.setName(id, _name) , _name);
	EXPECT_EQ( pm.getName(id) , _name);

}

TEST(PassengerManger, add_test)
{
	PassengerManager_t pm;

	EXPECT_EQ(pm.count() , (uint) 0);
	EXPECT_TRUE(pm.addPassenger(id, _name, _address, _phone, _preferanceSeating) );
	EXPECT_TRUE(pm.addPassenger(id+ 1, _name, _address, _phone, _preferanceSeating) );
	EXPECT_EQ(pm.count() , (uint) 2);

	EXPECT_FALSE(pm.addPassenger(id, _name, _address, _phone, _preferanceSeating) );
	EXPECT_EQ(pm.count() , (uint) 2);

	EXPECT_EQ( pm.getName(id) , _name);
	EXPECT_EQ( pm.setName(id, "hamberg") , "hamberg");
	EXPECT_EQ( pm.getName(id) , "hamberg");

}

TEST(PassengerManger, remove)
{
	PassengerManager_t pm;

	EXPECT_TRUE(pm.addPassenger(id, _name, _address, _phone, _preferanceSeating) );
	EXPECT_TRUE(pm.addPassenger(id+ 1, _name, _address, _phone, _preferanceSeating) );
	EXPECT_EQ(pm.count() , (uint) 2);

	EXPECT_TRUE( pm.removePassenger(id) );
	EXPECT_TRUE( pm.removePassenger(id+1) );
	EXPECT_EQ(pm.count() , (uint) 0);
	EXPECT_FALSE( pm.removePassenger(id) );

}

TEST(PassengerManger, ticketFunc)
{
	PassengerManager_t pm;
	list<uint> tickets;

	EXPECT_TRUE(pm.addPassenger(id, _name, _address, _phone, _preferanceSeating) );
	EXPECT_TRUE(pm.addPassenger(id+ 1, _name, _address, _phone, _preferanceSeating) );
	EXPECT_EQ(pm.count() , (uint) 2);

	EXPECT_THROW( pm.removeTicket(1, ticketNum) , const char*);
	EXPECT_THROW( pm.removeTicket(id, ticketNum) , const char*);
	EXPECT_EQ( pm.getTickets(id) , tickets);

	EXPECT_NO_THROW( pm.addTicket(id, ticketNum) );
	EXPECT_NO_THROW( pm.getTickets(id));
	EXPECT_NO_THROW( pm.addTicket(id, ticketNum+1) );

	tickets.push_back(ticketNum+1);
	tickets.push_back(ticketNum);
	EXPECT_EQ( pm.getTickets(id) , tickets);

	EXPECT_EQ( pm.removeTicket(id, ticketNum) , ticketNum);
	tickets.clear();
	tickets.push_back(ticketNum+1);
	EXPECT_EQ( pm.getTickets(id) , tickets);
	EXPECT_THROW( pm.removeTicket(id, ticketNum) , const char*);
	EXPECT_EQ( pm.removeTicket(id, ticketNum+1) , ticketNum+1);
}

TEST(PassengerManger, isPassengerExist_TEST)
{
	PassengerManager_t pm;
	EXPECT_FALSE( pm.isPassengerExist(id) );

	EXPECT_TRUE(pm.addPassenger(id+1, _name, _address, _phone, _preferanceSeating) );
	EXPECT_FALSE( pm.isPassengerExist(id) );
	EXPECT_TRUE( pm.isPassengerExist(id + 1) );
}


