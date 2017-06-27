/*
 * Channel_t.h
 *
 *  Created on: Jun 27, 2017
 *      Author: uv
 */

#ifndef CHANNEL_T_H_
#define CHANNEL_T_H_

#include <string>
#include <sstream>
#include <iostream>
#include <queue>

using namespace std;

class Channel_t
{

	public:

		/* Default Constructor */
		Channel_t();

		/* Deconstructor */
		virtual ~Channel_t();

		void write(const string& _msg);
		string read();

		bool isEmpty() const;

	private:
		queue<string> m_ch; // cant be stringstream becouse private?

		/* Disable the following by default */
		Channel_t(const Channel_t& other);
		Channel_t& operator=(const Channel_t&);

};

#endif /* ifndef CHANNEL_T_H_ */
