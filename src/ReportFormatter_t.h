/*
 * ReportFormatter_t.h
 *
 *  Created on: Jun 25, 2017
 *      Author: yuval
 */

#ifndef REPORTFORMATTER_T_H_
#define REPORTFORMATTER_T_H_

#include <string>
#include <vector>

typedef unsigned int uint;
using namespace std;

class Manager_t;

class ReportFormatter_t
{

	public:

		/* Default Constructor */
		ReportFormatter_t(const Manager_t& _manger);
		// TODO defualt constracutr and set function

		/* Deconstructor */
		virtual ~ReportFormatter_t();

		const vector<vector<string> > reportFreeSeat(uint _flightID, const vector<uint>& _seatIdContiner) const;
		const vector<string> reportTicket(uint _ticketNum) const;
		const vector<string> reportPassenger(uint _passenger) const; // TODO
		const vector<string> reportFlight(uint _ticketNum) const; // TODO

	private:
		const Manager_t& m_manger;

		/* Disable the following by default */
		ReportFormatter_t(const ReportFormatter_t& other);
		ReportFormatter_t& operator=(const ReportFormatter_t&);

		string itos(int _num) const;
};

#endif /* ifndef REPORTFORMATTER_T_H_ */
