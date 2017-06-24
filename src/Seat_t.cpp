/*
 * Seat_t.cpp
 *
 *  Created on: Jun 20, 2017
 *      Author: Yuval Hamberg
 */

#include "Seat_t.h"

#include <iostream>
#include <sstream>
#include <string>


uint Seat_t::m_seatNumItr = 1;

Seat_t::Seat_t(uint _seatNum) : m_seatNum(_seatNum), m_seatName("SeatName:" + itos(_seatNum) )
{
	m_seatNumItr = _seatNum + 1;
	m_occupancy = false;
	m_ticket = 0;
}

//Seat_t::Seat_t() : m_seatNum(Seat_t::m_seatNumItr++), m_seatName("NAME_NOT_IMPLAMENTED")
//{
//	m_occupancy = false;
//	m_ticket = 0;
//}

Seat_t::~Seat_t()
{
}

const std::string& Seat_t::getSeatName() const
{
	return m_seatName;
}

bool Seat_t::setOccupancy(bool _occupancyStatus)
{
	m_occupancy = _occupancyStatus;
	return m_occupancy;
}

uint Seat_t::getTicket() const
{
	return m_ticket;
}

uint Seat_t::setTicket(uint _ticketNum)
{
	m_ticket = _ticketNum;
	return m_ticket;
}

const uint Seat_t::getSeatNum() const
{
	return m_seatNum;
}

bool Seat_t::isOccupied() const
{
	return m_occupancy;
}

bool Seat_t::operator== (const Seat_t& _other) const
{
	return (m_seatName == _other.m_seatName);
}

bool Seat_t::orderSeat(uint _ticketNum)
{
	if (isOccupied())
	{
		return false;
	}
	setOccupancy(true);
	setTicket(_ticketNum);
	return true;
}

bool Seat_t::cancelSeat()
{
	if (!isOccupied())
	{
		return false;
	}
	setOccupancy(false);
	setTicket(0);
	return true;
}

std::string Seat_t::itos(int _num)
{
	ostringstream convert;   // stream used for the conversion
	convert << _num;      // insert the textual representation of 'Number' in the characters in the stream
	return convert.str(); // set 'Result' to the contents of the stream
}
