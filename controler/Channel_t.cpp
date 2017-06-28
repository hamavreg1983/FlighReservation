/*
 * Channel_t.cpp
 *
 *  Created on: Jun 27, 2017
 *      Author: uv
 */

#include "Channel_t.h"

Channel_t::Channel_t()
{
	// TODO Auto-generated constructor stub
}

Channel_t::~Channel_t()
{
	// TODO Auto-generated destructor stub
}

void Channel_t::write(const string& _msg)
{
	m_ch.push( _msg );
}

string Channel_t::read()
{
	if ( this->isEmpty() )
	{
		throw "reading from an empty channel";
	}
	string msg;
	msg = m_ch.front();
	m_ch.pop() ;

	return msg;
}

bool Channel_t::isEmpty() const
{
	return m_ch.empty();
}
