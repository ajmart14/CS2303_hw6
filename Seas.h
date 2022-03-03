/*
 * Seas.h
 *
 *  Created on: Feb 15, 2022
 *      Author: theresesmith
 */

#ifndef SEAS_H_
#define SEAS_H_

#include "Location.h"
#include <stdlib.h>
#include <stdio.h>
#include "Carrier.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Submarine.h"
#include "Destroyer.h"
#include "Fleets.h"

typedef enum
{
	HUMAN,
	COMPUTER
}PlayerType;

//#include "clang/AST/ExprCXX.h" //for lambda functions

class Seas {
public:
	Seas();
	virtual ~Seas();
	int getSize();
	void setSize(int);
	void displaySeas();
	void takeCoordinates(Pair* pP, int player);
	void place(Carrier*, PlayerType, int, int, bool);
	void place(Battleship*, PlayerType, int, int, bool);
	void place(Cruiser*, PlayerType, int, int, bool);
	void place(Submarine*, PlayerType, int, int, bool);
	void place(Destroyer*, PlayerType, int, int, bool);
	int imminent(int partner);
	void setFleetsPtr(Fleets* fleets);
	Location** getSeasP();
	bool isFeasible(ShipType s, PlayerType player, int row, int col, bool dir);
	int size;
	Location** seasP;

private:
	Fleets* fp;

};

#endif /* SEAS_H_ */
