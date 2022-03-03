/*
 * AdjMat.cpp
 *
 *  Created on: Apr 28, 2020
 *      Author: theresesmith
 */

#include "AdjMat.h"

AdjMat::AdjMat() {
	// TODO Auto-generated constructor stub
	AdjMat(0);
}

AdjMat::AdjMat(int pn) {
	// TODO Auto-generated constructor stub
	n = pn;
	edgesP = (int*)0; //these values need to be updated
}

AdjMat::~AdjMat() {
	// TODO Auto-generated destructor stub
}

int AdjMat::getN()
{
	return n;
}
void AdjMat::setN(int num)
{
	if(num>0)
	{
		n=num;
	}
}
int* AdjMat::getEdgesP()
{
	return edgesP;
}
void AdjMat::setEdgesP(int* eP)
{
	edgesP = eP;
}

void AdjMat::init()
{
	for(int row = 0; row<n; row++)
	{
		for(int col = 0; col<n; col++)
		{
			*(edgesP+(row*n)+col)= 0;
		}
	}
}

void AdjMat::setEdge(int row, int col)//only sets to one, assumes symmetric matrix
{

	int ncols = n;
	int* arrayBeginning = edgesP;
	//printf("about to set edges with n = %d", n);fflush(stdout);
	*(arrayBeginning + (ncols*row) + col) = 1;
	//puts("Set first edge"); fflush(stdout);
	*(arrayBeginning + (ncols*col) + row) = 1;
	//puts("Set second edge"); fflush(stdout);
}
int AdjMat::getEdge(int row, int col)
{
	int ncols = n;
	int* arrayBeginning = edgesP;
	return *(arrayBeginning + (ncols*row) +col);
}


