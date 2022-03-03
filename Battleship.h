/*
 * Battleship.h
 *
 *  Created on: Feb 16, 2022
 *      Author: theresesmith
 */

#ifndef BATTLESHIP_H_
#define BATTLESHIP_H_
#include "Ship.h"

class Battleship: public Ship {
public:
	Battleship();
	virtual ~Battleship();
	int hitsSustained;

private:
	char symbol;
	int compartments;
};

#endif /* BATTLESHIP_H_ */
