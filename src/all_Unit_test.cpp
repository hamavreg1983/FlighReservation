/*
 * allUnitTest.cpp
 *
 *  Created on: Jun 23, 2017
 *      Author: yuval
 */

#include "gtest.h"
#include "Seat_t_test.cpp" //why? TODO

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


