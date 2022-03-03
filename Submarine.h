/*
 * Submarine.h
 *
 *  Created on: Feb 16, 2022
 *      Author: theresesmith
 */

#ifndef SUBMARINE_H_
#define SUBMARINE_H_
#include "Ship.h"

class Submarine: public Ship {
public:
	Submarine();
	virtual ~Submarine();
	int hitsSustained;
};

#endif /* SUBMARINE_H_ */
