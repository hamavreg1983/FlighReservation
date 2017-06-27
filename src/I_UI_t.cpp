/*
 * I_UI_t.cpp
 *
 *  Created on: Jun 26, 2017
 *      Author: yuval
 */

#include "I_UI_t.h"



void I_UI_t:: connect(const Communication_t* _comm)
{
	m_comm = (Communication_t*) _comm;
	return;
}



bool I_UI_t:: is_digitsOnly(const std::string& _str) const
{
    return _str.find_first_not_of("0123456789") == std::string::npos;
}

string I_UI_t::transmit(const string _command)
{

}

string I_UI_t::receive()
{

}

std::string I_UI_t:: itos(int _num) const
{
	ostringstream convert;   // stream used for the conversion
	convert << _num;      // insert the textual representation of 'Number' in the characters in the stream
	return convert.str(); // set 'Result' to the contents of the stream
}
