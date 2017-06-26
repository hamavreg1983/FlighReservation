/*
 * ReportFormatter_t.cpp
 *
 *  Created on: Jun 25, 2017
 *      Author: yuval
 */

#include <iostream>
#include <sstream>

#include "ReportFormatter_t.h"
#include "Manager_t.h"

ReportFormatter_t::ReportFormatter_t(const Manager_t& _manger) : m_manger(_manger)
{
}

ReportFormatter_t::~ReportFormatter_t()
{
}

const vector<vector<string> > ReportFormatter_t::reportFreeSeat(uint _flightID, const vector<uint>& _seatIdContiner) const
{
	vector<vector<string> > output;
	int column;

	for (uint i = 0 ; i < _seatIdContiner.size() ; ++i)
	{
		column = 0;
		// first item is SeatID
		output[i][column++] = _seatIdContiner[i];
		// second item is seatName
		output[i][column++] = m_manger.getSeatName(_flightID, _seatIdContiner[i]);
		// thired is Tier Name
		output[i][column++] = m_manger.getTierName(_flightID, _seatIdContiner[i]);
	}

	return output;
}

const vector<string> ReportFormatter_t::reportTicket(uint _ticketNum) const
{
	vector<string> output;

	output.push_back( itos(_ticketNum) );

	uint flightID = m_manger.getBookingFlighId(_ticketNum);
	output.push_back( itos(flightID) );
	output.push_back( m_manger.getFlightNum(flightID) );
	output.push_back( m_manger.getDeparture(flightID) );
	output.push_back( m_manger.getDestination(flightID) );
	output.push_back( m_manger.getTimeDeparture(flightID) );

	uint seatID = m_manger.getSeatOfBooking(_ticketNum);
	output.push_back( itos(seatID) );
	output.push_back( m_manger.getSeatName(flightID, seatID));
	output.push_back( m_manger.getTierName(flightID, seatID));

	uint passengerID = m_manger.getBookingPassangerId(_ticketNum);
	output.push_back( m_manger.getName(passengerID) ) ;

	output.push_back( itos ( m_manger.getBookingCost(_ticketNum) ) );
	output.push_back( itos ( m_manger.isTicketActive(_ticketNum) ) );

	return output;
}




string ReportFormatter_t:: itos(int _num) const
{
	ostringstream convert;   // stream used for the conversion
	convert << _num;      // insert the textual representation of 'Number' in the characters in the stream
	return convert.str(); // set 'Result' to the contents of the stream
}

const vector<string> ReportFormatter_t::reportPassenger(uint _passenger) const
{
}
