/*
 * FRS.h
 *
 *  Created on: Jun 28, 2017
 *      Author: uv
 */

#ifndef FRS_H_
#define FRS_H_

class Manager_t;
class I_UI_t;

using namespace std;

class FRS
{

	public:

		/* Default Constructor */
		FRS();

		/* Deconstructor */
		virtual ~FRS();

		I_UI_t* UI_start();
		void UI_stop(I_UI_t* _ui);

	private:
		I_UI_t* chooseUI() const;

		Manager_t* m_mngr;

		/* Disable the following by default */
		FRS(const FRS& other);
		FRS& operator=(const FRS&);

};

#endif /* ifndef FRS_H_ */



