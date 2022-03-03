/*
 * Cruiser.h
 *
 *  Created on: Feb 16, 2022
 *      Author: theresesmith
 */

#ifndef CRUISER_H_
#define CRUISER_H_

#include "Ship.h"

class Cruiser: public Ship {
public:
	Cruiser();
	virtual ~Cruiser();
	int hitsSustained;
};

#endif /* CRUISER_H_ */
