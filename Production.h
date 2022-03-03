/*
 * Production.h
 *
 *  Created on: Apr 26, 2020
 *      Author: theresesmith
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdio.h>
#include <stdbool.h>
#include <string.h>//strncpy
#include <stdlib.h>//strtol
#include "AdjMat.h"
//#include "Room.h"
#include "Terminal.h"
#include "LinkedList.h"
#include "Seas.h"
#include "Fleets.h"

#include <stdio.h>
#define FILENAMELENGTHALLOWANCE (50)



class Production {
public:
	Production();
	virtual ~Production();
	bool prod(int argc, char* argv[]);

	bool getYesNo(char* query);
	void getHumanSetup(Seas* Cs, Fleets* fleets);
	void doPlacing(Seas* Cs, Fleets* fleets, PlayerType);
	bool isFeasible(Seas*, int row, int col, int horiz, ShipType s, PlayerType );
	bool hasWon(Fleets* fleet);

private:
	void showMax();

};

#endif /* PRODUCTION_H_ */
