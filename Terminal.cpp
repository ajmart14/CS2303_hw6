/*
 * Terminal.cpp
 *
 *  Created on: Feb 7, 2022
 *      Author: theresesmith
 */

#include "Terminal.h"

Terminal::Terminal() {
	// TODO Auto-generated constructor stub
	nodeNumber = -1;
	colors[0] = false;
	colors[1] = false;
	colors[2] = false;
	colors[3] = false;
    visited = false;
}

Terminal::~Terminal() {
	// TODO Auto-generated destructor stub
}

bool Terminal::getColor(int which)
{
	bool answer = false;
	if(which>= 0 && which <= 3)
	{
		answer = colors[which];
	}
	return answer;
}
bool Terminal::getVisited()
{
	return visited;
}
void Terminal::setVisited(bool b)
{
	visited = b;
}
int Terminal::getNodeNumber()
{
	return nodeNumber;
}
void Terminal::setNodeNumber(int b)
{
	nodeNumber = b;
}
