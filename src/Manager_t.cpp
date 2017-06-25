/*
 * Manager_t.cpp
 *
 *  Created on: Jun 25, 2017
 *      Author: uv
 */

#include "Manager_t.h"
#include "FlightManager_t.h"
#include "PassengerManagert.h"
#include "BookingManager_t.h"


Manager_t::Manager_t()
{
	m_flightMngPtr = new FlightManager_t();
	m_passengerMngPtr = new PassengerManager_t();
	m_bookingMngPtr = new BookingManager_t();
}

Manager_t::~Manager_t()
{
	delete m_bookingMngPtr;
	delete m_passengerMngPtr;
	delete m_flightMngPtr;
}

