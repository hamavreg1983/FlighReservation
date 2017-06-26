/*
 * FlightManager_t.h
 *
 *  Created on: Jun 24, 2017
 *      Author: yuval
 */

#ifndef FLIGHTMANAGER_T_H_
#define FLIGHTMANAGER_T_H_

#include <map>
#include <string>
#include <vector>

typedef unsigned int uint;
using namespace std;
class Flight_t;

class FlightManager_t
{

	public:

		/* Default Constructor */
		FlightManager_t();

		/* Deconstructor */
		virtual ~FlightManager_t();

		bool isEmpty() const;
		uint count() const;

		uint addFlight(const string& _flightNum, const string& _departure, const string& _destination, const string& _timeDeparture, const string& _plane ); 		// TODO <<friend>> SupervisorUI
		bool removeFlight(uint _flightID); 		// TODO <<friend>> SupervisorUI
		bool isFlightExsists(uint _flightID) const;

		uint getCapacity(uint _flightID) const;
		const string& getDeparture(uint _flightID) const;
		void setDeparture(uint _flightID, const string& departure);
		const string& getDestination(uint _flightID) const;
		void setDestination(uint _flightID, const string& destination);
		const string& getFlightNum(uint _flightID) const;
		void setFlightNum(uint _flightID, const string& flightNum);
		const string& getTimeDeparture(uint _flightID) const;
		void setTimeDeparture(uint _flightID, const string& timeDeparture);

		bool isTierFull(uint _flightID, const string& _tier) const;
		uint numberOfSeatAvalibul(uint _flightID) const;
		bool isFlightFull(uint _flightID) const;
		const vector<uint> getFreeSeats(uint _flightID, const string& _tier) const;
		uint getTierPrice(uint _flightID, const string& _tier) const;
		uint getSeatPrice(uint _flightID, uint _seatNum) const;
		uint setTierPrice(uint _flightID, const string& _tier, uint price);
		const vector<string> getTiersName(uint _flightID) const;
		const string& getTierName(uint _flightID, uint _SeatNum) const;

		bool isSeatOccupancy(uint _flightID, uint _seatNum) const;
		uint getTicket(uint _flightID, uint _seatNum) const;
		const std::string& getSeatName(uint _flightID, uint _seatNum) const;

		bool orderSeat(uint _flightID, uint _seatNum, uint _ticketNum) const;
		bool cancelSeat(uint _flightID, uint _seatNum) const;


	protected:

		//Flight_t* findFlight(const string _flightNum) const;
		Flight_t* findFlight(uint _flightID) const;

	private:
		map<uint, Flight_t*> m_flights;



		/* Disable the following by default */
		FlightManager_t(const FlightManager_t& other);
		FlightManager_t& operator=(const FlightManager_t&);

};

#endif /* ifndef FLIGHTMANAGER_T_H_ */
