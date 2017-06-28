/*
 * Passenger_t.h
 *
 *  Created on: Jun 20, 2017
 *      Author: Yuval Hamberg
 */

#ifndef PASSENGER_T_H_
#define PASSENGER_T_H_

#include <string>
#include <list>
typedef unsigned int uint;
using namespace std;


class Passenger_t
{
	public:
		Passenger_t(uint _id);
		Passenger_t(uint _id, string _name, string _address, string _phone, string _preferanceSeating);
		virtual ~Passenger_t();

		// object is copy-able.

		const string& getAddress() const;
		const string& setAddress(const string& address);
		const uint getId() const;
		const string& getName() const;
		const string& setName(const string& name);
		const string& getPhone() const;
		const string& setPhone(const string& phone);
		const string& getPreferanceSeating() const;
		const string&  setPreferanceSeating(const string& preferanceSeating);

		void addTicket(uint _ticketNum);
		uint removeTicket(uint _ticketNum);
		void removeAllTicket();
		const list<uint>& getTickets() const;

		bool operator< (const Passenger_t& _other) const;
		bool operator== (const Passenger_t& _other) const;

	private:
		const uint m_id;
		string m_name;
		string m_address;
		string m_phone;
		string m_preferanceSeating;
		list<uint> m_tickets;

};

#endif /* PASSENGER_T_H_ */
