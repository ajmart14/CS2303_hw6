/*
 * Fleets.h
 *
 *  Created on: Feb 14, 2022
 *      Author: theresesmith
 */

#ifndef FLEETS_H_
#define FLEETS_H_

#include <stdio.h>
#include "Battleship.h"
#include "Carrier.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Submarine.h"
#include "Location.h"




class Fleets {
public:
	Fleets();
	virtual ~Fleets();
	int getHowMany(int player, ShipType s);
	void sinkShips(int player);
	void lostHull(int player, Pair*, Location*);
	Battleship* b0;
	Battleship* b1;
	Carrier* c0;
	Carrier* c1;
	Cruiser* cr0;
	Cruiser* cr1;
	Destroyer* d0;
	Destroyer* d1;
	Submarine* s0;
	Submarine* s1;


private:
	int howManyCarriersA;//player a or player 0
	int howManyCarriersB;//player b or player 1
	int howManySubmarinesA;
	int howManySubmarinesB;
	int howManyBattleshipsA;
	int howManyBattleshipsB;
	int howManyCruisersA;
	int howManyCruisersB;
	int howManyDestroyersA;
	int howManyDestroyersB;

	//Seas* sPtr;

};

#endif /* FLEETS_H_ */
