/*
 * Booking_t.cpp
 *
 *  Created on: Jun 25, 2017
 *      Author: uv
 */

#include "Booking_t.h"

uint Booking_t::m_staticUniqeTicketNum = 0;

Booking_t::Booking_t() : m_ticketNum(++m_staticUniqeTicketNum)
{
	// TODO should user be allowed to create with no data?
	m_flighID = 0;
	m_seat = 0;
	m_passangerId = 0;
	m_cost = 0;
	m_isActiveTicket = true;
}

Booking_t::Booking_t(uint _flighID, uint _seat, uint _passangerId, float _cost) : m_ticketNum(++m_staticUniqeTicketNum)
{
	m_flighID = _flighID;
	m_seat = _seat;
	m_passangerId =_passangerId;
	m_cost = _cost;
	m_isActiveTicket = true;
}

Booking_t::~Booking_t()
{
	// TODO Auto-generated destructor stub
}

float Booking_t::getCost() const
{
	return m_cost;
}

float Booking_t::setCost(float cost)
{
	m_cost = cost;
	return m_cost;
}

uint Booking_t::getFlighId() const
{
	return m_flighID;
}

uint Booking_t::setFlighId(uint flighId)
{
	m_flighID = flighId;
	return m_flighID;
}

uint Booking_t::getPassangerId() const
{
	return m_passangerId;
}

uint Booking_t::setPassangerId(uint passangerId)
{
	m_passangerId = passangerId;
	return m_passangerId;
}

uint Booking_t::getSeat() const
{
	return m_seat;
}

uint Booking_t::setSeat(uint seat)
{
	m_seat = seat;
	return m_seat;
}

uint Booking_t::getStaticUniqeTicketNum()
{
	return m_staticUniqeTicketNum;
}

bool Booking_t::isTicketActive() const
{
	return m_isActiveTicket;
}

bool Booking_t::activateTicket()
{
	m_isActiveTicket = true;
	return m_isActiveTicket;
}

bool Booking_t::deActivateTicket()
{
	m_isActiveTicket = false;
	return m_isActiveTicket;
}

uint Booking_t::getTicketNum() const
{
	return m_ticketNum;
}
