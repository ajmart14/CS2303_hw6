/*
 * Room.cpp
 *
 *  Created on: Apr 28, 2020
 *      Author: theresesmith
 */

#include "Room.h"



Room::Room() {
	// TODO Auto-generated constructor stub
	searched=false;
	treasure = 0;
	roomNumber = -1;
}

Room::~Room() {
	// TODO Auto-generated destructor stub
}

int Room::getRoomNumber()
{
	return roomNumber;
}
void Room::setRoomNumber(int r)
{
	if(r>=0)
	{
		roomNumber = r;
	}
}
float Room::getTreasure()
{
	return treasure;
}
void Room::setTreasure(float t)
{
	treasure = t;
}
bool Room::getSearched()
{
	return searched;
}
void Room::setSearched(bool s)
{
	searched = s;
}


