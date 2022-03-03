/*
 * Terminal.h
 *
 *  Created on: Feb 7, 2022
 *      Author: theresesmith
 */

#ifndef TERMINAL_H_
#define TERMINAL_H_

class Terminal {
public:
	Terminal();
	virtual ~Terminal();
	int* getColors();
	bool getColor(int);
	void setColor(int);
	void setColors(bool*);
	int getNodeNumber();
	void setNodeNumber(int);
	bool getVisited();
	void setVisited(bool);


private:
	int nodeNumber;
	bool colors[4];
	bool visited;
};

#endif /* TERMINAL_H_ */
