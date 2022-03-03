/*
 * Carrier.h
 *
 *  Created on: Feb 14, 2022
 *      Author: theresesmith
 */

#ifndef CARRIER_H_
#define CARRIER_H_

#include "Ship.h"

class Carrier: public Ship {
public:
	Carrier();
	virtual ~Carrier();
	int hitsSustained;

private:
	int compartments;//how much space in the sea
	//also how hits it can sustain
	 //initially 0, but can count up
	char symbol;
};

#endif /* CARRIER_H_ */
