/*
 * UI_supervisor_t_test.cpp
 *
 *  Created on: Jun 26, 2017
 *      Author: yuval
 */

#include "UI_supervisor_t.h"
#include "Manager_t.h"
#include "gtest.h"

using namespace std;

TEST(UI_supervisor, init)
{
	UI_supervisor_t ui;
}

TEST(UI_supervisor, init2)
{
	UI_supervisor_t ui;
	Manager_t man;
	ui.connect(&man);

//	ui.UI_do();
}


