/*
 * Destroyer.h
 *
 *  Created on: Feb 16, 2022
 *      Author: theresesmith
 */

#ifndef DESTROYER_H_
#define DESTROYER_H_
#include "Ship.h"

class Destroyer: public Ship {
public:
	Destroyer();
	virtual ~Destroyer();
	int hitsSustained;
};

#endif /* DESTROYER_H_ */
