/*
 * Location.cpp
 *
 *  Created on: Feb 15, 2022
 *      Author: theresesmith
 */

#include "Location.h"

Location::Location() {
	// TODO Auto-generated constructor stub
	waterOrNot = true;
	x = EMPTY;  //NULL if water
	hasBeenShot = false;
	symbol = '~';
	sp = 0;
}

Location::~Location() {
	// TODO Auto-generated destructor stub
}

char Location::getSymbol()
{
	return symbol;
}
void Location::setSymbol(char s)
{
	symbol = s;
}
void Location::setShipP(Ship* s)
{
    sp = s;
}
Ship* Location::getShipP()
{
	return sp;
}
