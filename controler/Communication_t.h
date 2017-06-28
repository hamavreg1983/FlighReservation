/*
 * Communication_t.h
 *
 *  Created on: Jun 26, 2017
 *      Author: yuval
 */

#ifndef COMMUNICATION_T_H_
#define COMMUNICATION_T_H_

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

// TODO remove when Communication_t is working
#include "Manager_t.h"

typedef unsigned int uint;
using namespace std;

class Channel_t;

class Communication_t
{

	public:
		/* Default Constructor */
		Communication_t();

		/* Deconstructor */
		virtual ~Communication_t();

		bool connect(Channel_t* _Tx, Channel_t* _Rx);
		bool disconnct();

		string send(const string& _command);
		string read();

	private:

		vector<Channel_t*> m_Tx;
		vector<Channel_t*> m_Rx;


		/* Disable the following by default */
		Communication_t(const Communication_t& other);
		Communication_t& operator=(const Communication_t&);

};

#endif /* ifndef COMMUNICATION_T_H_ */
