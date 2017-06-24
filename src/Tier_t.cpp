/*
 * Tier_t.cpp
 *
 *  Created on: Jun 21, 2017
 *      Author: yuval
 */

#include "Tier_t.h"
#include "Seat_t.h"

using namespace std;

Tier_t::Tier_t(string _tierID, uint _firstSeatNum, uint _capacity, uint _price) : m_tierID(_tierID),  m_firstSeatNum(_firstSeatNum), m_capacity(_capacity),  m_price(_price)
{
	m_occupiedNum = 0;
	// create all seat in tier with the correct number
	for (uint i = 0; i < m_capacity; i++)
	{
		m_seats.push_back(_firstSeatNum + i);
	}
}

Tier_t::~Tier_t()
{
}

uint Tier_t::getCapacity() const
{
	return m_capacity;
}

uint Tier_t::getOccupiedNum() const
{
	return m_occupiedNum;
}

uint Tier_t::getPrice() const
{
	return m_price;
}

uint Tier_t::setPrice(uint price)
{
	m_price = price;
	return m_price;
}

const string& Tier_t::getTierId() const
{
	return m_tierID;
}

bool Tier_t::orderSeat(uint _seatNum, uint _ticketNum)
{
	if  ( getSeat(_seatNum).orderSeat(_ticketNum) )
	{
		m_occupiedNum++;
		return true;
	}
	return false;
}

bool Tier_t::cancelSeat(uint _seatNum)
{
	if  ( getSeat(_seatNum).cancelSeat() )
	{
		m_occupiedNum--;
		return true;
	}
	return false;
}

uint Tier_t::numSeatsAvalibul() const
{
	return (getCapacity() - getOccupiedNum() );
}

Seat_t& Tier_t::getSeat(uint _seatNum) const
{
	if (!isSeatNumInTier(_seatNum))
	{
		throw "Seat number doesn't exist in this Tier";
	}
	return (Seat_t&) m_seats[_seatNum - m_firstSeatNum]; // remove const
}

bool Tier_t::isOccupied(uint _seatNum) const
{
	return getSeat(_seatNum).isOccupied();
}

uint Tier_t::getTicket(uint _seatNum) const
{
	return getSeat(_seatNum).getTicket();
}

const std::string& Tier_t::getSeatName(uint _seatNum) const
{
	return getSeat(_seatNum).getSeatName();
}

Tier_t::Tier_t(const Tier_t& _source) : m_tierID(_source.m_tierID),  m_firstSeatNum(_source.m_firstSeatNum), m_capacity(_source.m_capacity),  m_price(_source.m_price)
{
	m_occupiedNum = _source.m_occupiedNum;
	m_seats = _source.m_seats;

}

bool Tier_t:: operator== (const string& _id) const
{
	return (_id == this->m_tierID);
}

bool Tier_t:: isSeatNumInTier(uint _seat) const
{
	return (_seat >= m_firstSeatNum && _seat <= getLastSeatNum() );
}

uint Tier_t::getFirstSeatNum() const
{
	return m_firstSeatNum;
}

uint Tier_t::getLastSeatNum() const
{
	return (m_firstSeatNum + m_capacity - 1);
}

