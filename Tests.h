/*
 * Tests.h
 *
 *  Created on: Apr 26, 2020
 *      Author: theresesmith
 */

#ifndef TESTS_H_
#define TESTS_H_

#include <stdio.h>
#include "Production.h"
#include "LinkedList.h"
#include "Fleets.h"


class Tests {
public:
	Tests();//constructor
	virtual ~Tests();
	bool tests();

private:
	bool  testWhoGoesFirst();
	bool  testCreateSeas();
	bool testDisplaySeasInConsole();
	bool testCreateFleets();
	bool testGetYesNo(); //place owh fleet
	bool  testEnterCoordinates();// same for placing ships and shooting ships
	bool  testLostHull();
	bool  testLostGame();
	bool  testAnnounceWinner();
	bool  testGetHumanSetup();
	bool  testDoHumanSetup();
	bool testFeasibilityCheck();
};
#endif /* TESTS_H_ */
