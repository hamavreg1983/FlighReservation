/*
 * Channel_t_test.cpp
 *
 *  Created on: Jun 27, 2017
 *      Author: uv
 */

#include "Channel_t.h"
#include <iostream>
#include "gtest.h"

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

TEST(Channel_t, init)
{
	Channel_t c1();
	Channel_t c2;
}

TEST(Channel_t, write)
{
	string command;
	command = "hello";

	Channel_t c;
	EXPECT_TRUE( c.isEmpty() );
	c.write(command);
	EXPECT_FALSE( c.isEmpty() );

}

TEST(Channel_t, read)
{
	Channel_t c;

	{
		string command;
		command = "hello";
		c.write(command);

		command = " world.";
		c.write(command);
	}
	EXPECT_FALSE( c.isEmpty() );

	string output;
	output = c.read();
	EXPECT_EQ(output , "hello");
	output = c.read();
	EXPECT_EQ(output , " world.");
	EXPECT_TRUE( c.isEmpty() );

	EXPECT_ANY_THROW( output = c.read() );

}
