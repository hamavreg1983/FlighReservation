/*
 * Manager_t_test.cpp
 *
 *  Created on: Jun 25, 2017
 *      Author: uv
 */

#include "gtest.h"
#include "Manager_t.h"

using namespace std;

TEST(Manager_t, init)
{
	EXPECT_NO_FATAL_FAILURE( Manager_t m1() );
	EXPECT_NO_FATAL_FAILURE( Manager_t m2 );
}






