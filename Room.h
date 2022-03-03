/*
 * Room.h
 *
 *  Created on: Apr 28, 2020
 *      Author: theresesmith
 */

#ifndef ROOM_H_
#define ROOM_H_


class Room {
public:
	Room();
	virtual ~Room();
	int getRoomNumber();
	void setRoomNumber(int r);
	float getTreasure();
	void setTreasure(float t);
	bool getSearched();
	void setSearched(bool s);

private:
	int roomNumber;
	float treasure;
	bool searched;
};


#endif /* ROOM_H_ */
