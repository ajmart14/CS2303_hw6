/*
 * AdjMat.h
 *
 *  Created on: Apr 28, 2020
 *      Author: theresesmith
 */

#ifndef ADJMAT_H_
#define ADJMAT_H_

#include <stdbool.h>
#include <stdio.h>

class AdjMat {
public:
	AdjMat();
	AdjMat(int n);
	virtual ~AdjMat();
	void setEdge(int row, int col);
	int getEdge(int row, int col);
	void init();
	int getN();
	void setN(int num);
	int* getEdgesP();
	void setEdgesP(int* eP);

private:
	int n;
	int* edgesP;
};

#endif /* ADJMAT_H_ */
