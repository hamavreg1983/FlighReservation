/*
 * BookingManager_t.cpp
 *
 *  Created on: Jun 25, 2017
 *      Author: uv
 */

#include "BookingManager_t.h"
#include "Booking_t.h"

BookingManager_t::BookingManager_t()
{
	// TODO Auto-generated constructor stub

}

BookingManager_t::~BookingManager_t()
{
	// TODO Auto-generated destructor stub

	// TODO make sure all items where del

	std::map<uint, Booking_t*>::iterator itr = m_bookings.end();
	while (!m_bookings.empty())
	{
		itr--;
		delete (*itr).second;
		m_bookings.erase(itr);
	}
}

uint BookingManager_t::addTicket(uint _flighID, uint _seat, uint _passangerId, float _cost)
{
	Booking_t* tmpBooking = new Booking_t(_flighID, _seat, _passangerId, _cost);
	uint tmpBookingID = tmpBooking->getTicketNum();

	std::pair<std::map<uint,Booking_t*>::iterator,bool> ret;
	ret = m_bookings.insert( pair<uint,Booking_t*>(tmpBookingID, tmpBooking) );
	if (!ret.second)
	{
		throw "could not add flight";
	}

	return tmpBookingID;
}

bool BookingManager_t::removeTicket(uint _ticketNum)
{
	// checks if ticket exist and return a pointer for del.
	Booking_t* bookingPtr;
	bookingPtr = this->findTicket(_ticketNum); // throw in did not find

	delete bookingPtr;
	m_bookings.erase(_ticketNum);
	return true;
}

bool BookingManager_t::isEmpty() const
{
	return m_bookings.empty();
}

uint BookingManager_t::count() const
{
	return m_bookings.size();
}

float BookingManager_t::getCost(uint _ticketNum) const
{
	return this->findTicket(_ticketNum)->getCost();
}

float BookingManager_t::setCost(uint _ticketNum, float cost)
{
	return this->findTicket(_ticketNum)->setCost(cost);
}

uint BookingManager_t::getFlighId(uint _ticketNum) const
{
	return this->findTicket(_ticketNum)->getFlighId();
}

uint BookingManager_t::getPassangerId(uint _ticketNum) const
{
	return this->findTicket(_ticketNum)->getPassangerId();
}

uint BookingManager_t::getSeat(uint _ticketNum) const
{
	return this->findTicket(_ticketNum)->getSeat();
}

bool BookingManager_t::isTicketActive(uint _ticketNum) const
{
	return this->findTicket(_ticketNum)->isTicketActive();
}

void BookingManager_t::activateTicket(uint _ticketNum)
{
	this->findTicket(_ticketNum)->activateTicket();
	return;
}

void BookingManager_t::deActivateTicket(uint _ticketNum)
{
	this->findTicket(_ticketNum)->deActivateTicket();
	return;
}

Booking_t* BookingManager_t::findTicket(uint _ticketNum) const
{
	map<uint,Booking_t*>::const_iterator itr;

	itr = m_bookings.find(_ticketNum);

	if (itr == m_bookings.end() )
	{
		throw "did not find fight asked";
	}
	return (itr == m_bookings.end() ) ? 0 : (*itr).second;
}
