/*
 * PassengerManagert.h
 *
 *  Created on: Jun 20, 2017
 *      Author: Yuval Hamberg
 */

#ifndef PASSENGERMANAGERT_H_
#define PASSENGERMANAGERT_H_

#include <set>
#include <string>
#include <list>
#include <algorithm>

using namespace std;
typedef unsigned int uint;

class Passenger_t;

class PassengerManager_t
{
	public:
		PassengerManager_t();
		virtual ~PassengerManager_t();

		bool addPassenger(uint _id);
		bool addPassenger(uint _id, const string _name, const string _address, const string _phone, const string _preferanceSeating);
		bool removePassenger(uint _id);

		bool isEmpty();
		uint count() const;

		const string& getAddress(uint _passengerID) const;
		const string& getName(uint _passengerID) const;
		const string& setName(uint _passengerID, const string& name);
		const string& getPhone(uint _passengerID) const;
		const string& setPhone(uint _passengerID, const string& phone);
		const string& getPreferanceSeating(uint _passengerID) const;
		const string& setPreferanceSeating(uint _passengerID, const string& preferanceSeating);

		void addTicket(uint _passengerID, uint _ticketNum);
		uint removeTicket(uint _passengerID, uint _ticketNum);
		const list<uint>& getTickets(uint _passengerID) const;

		bool isPassengerExist(uint _passengerID) const;

	private:
		bool Add(const Passenger_t& _source);
		Passenger_t& findPassenger(uint _id) const ;
		set<Passenger_t> m_passengers;
};

#endif /* PASSENGERMANAGERT_H_ */
