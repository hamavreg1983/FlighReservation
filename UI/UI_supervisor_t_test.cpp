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

//TEST(UI_supervisor, testWithFlightAndPassnger)
//{
//	UI_supervisor_t ui;
//	Manager_t man;
//	ui.connect(&man);
//
//	man.addFlight("elal1", "tlv", "LAX", "23:59", "blaPlane");
//	man.addFlight("elal1", "tlv", "SFO", "23:59", "blaPlane");
//	man.passenger(666, "Yuval", "Kfa", "55555", "window Seat");
//
//	ui.UI_do();
//}


