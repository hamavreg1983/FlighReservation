/*
 * I_UI_t.h
 *
 *  Created on: Jun 26, 2017
 *      Author: yuval
 */

#ifndef I_UI_T_H_
#define I_UI_T_H_

#include <string>
#include <sstream>
#include <iostream>
#include "Communication_t.h"

typedef unsigned int uint;
using namespace std;

class I_UI_t
{

	public:
		/* Default Constructor */
		I_UI_t() : m_comm(0) { }

		/* Deconstructor */
		virtual ~I_UI_t() { }

		virtual void UI_do() = 0;

		virtual void connect(const Manager_t* _comm) = 0; // TODO remove. this is a temp workaroud
		void connect(const Communication_t* _comm);
		void disconnct() { m_comm = 0; return; }

		string transmit(const string _command);
		string receive ();

	protected:
		bool is_digitsOnly(const std::string& _str) const;
		std::string itos(int _num) const;
		Communication_t* m_comm;

	private:

		/* Disable the following by default */
		I_UI_t(const I_UI_t& other);
		I_UI_t& operator=(const I_UI_t&);

};



#endif /* ifndef I_UI_T_H_ */
