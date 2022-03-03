/*
 * Location.h
 *
 *  Created on: Feb 15, 2022
 *      Author: theresesmith
 */

#ifndef LOCATION_H_
#define LOCATION_H_

#include "Ship.h"

typedef struct
{
	int row;
	int col;
}Pair;
typedef enum
{
    EMPTY,
	CARRIER,
	SUBMARINE,
	BATTLESHIP,
	CRUISER,
	DESTROYER
}ShipType;
class Location {
public:
	Location();
	virtual ~Location();
    char getSymbol();
    void setSymbol(char s);
    void setShipP(Ship*);
    Ship* getShipP();
    bool waterOrNot;
    bool hasBeenShot;
    ShipType x;

private:

	  //NULL if water

	char symbol;
	Ship* sp;
};

#endif /* LOCATION_H_ */
