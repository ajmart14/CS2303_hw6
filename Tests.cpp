/*
 * Tests.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: theresesmith
 */

#include "Tests.h"

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}
bool Tests::tests() {
	bool answer = true;
	// This will invoke the other tests
	//bool ok1 = testWhoGoesFirst(); //about command line argument
	bool ok2 = testCreateSeas();
	bool ok5 = testGetYesNo(); //place own fleet
	bool ok3 = testDisplaySeasInConsole();
	bool ok4 = testCreateFleets();
	bool ok6 = testEnterCoordinates();// same for placing ships and shooting ships
	bool ok7 = testLostHull();
	bool ok8 = testLostGame();
	bool ok9 = testAnnounceWinner();
	bool ok10 = testGetHumanSetup();
	bool ok11 = testDoHumanSetup();
	bool ok12 = testFeasibilityCheck();
	answer = ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 &&ok11&&ok12;
	return answer;
}
//bool Tests::testWhoGoesFirst()  // needs update****
//{
//
//	puts("starting testWhoGoesFirst"); fflush(stdout);
//	bool ok = false;
//	bool  rightAnswer = true;
//	int argc =2;
//	char** argv = (char**) malloc (2*sizeof(char*));
//	char* part0 = "Battleship";
//	char* part1 = "1";  //whoGoesFirst 1 is true, 0 is false
//	argv[0] = part0;
//	argv[1] = part1;
//	Production* pP = new Production();
//	//set arc, set argv to known command line, so we know the right answer
//	//make argv so that the right answer is in it (as a string)
//	//trial
//	bool answer = pP->prod(argc, argv);  //returns the whose turn boolean
//	ok = (rightAnswer == answer);
//	//render judgment
//	if(ok)
//	{
//		puts("who goes first passed its test");
//	}
//	else
//	{
//		puts("who goes first did not pass its test");
//	}
//
//	return ok;
//}
bool Tests::testCreateSeas()//constructs seas, it has a known size 10x10 per player (2 players),
//give it an attribute of its size, and ask its size
{
	bool ok = true;
	puts("starting testCreateSeas"); fflush(stdout);
	//setup

	//trial --n always invoke the function thts we are testing
	Seas* Cs = new Seas();
	//check something, such as the size
	int answer = Cs->getSize();
	int rightAnswer = 10;

	ok = (rightAnswer == answer);
	//render judgment
	if(ok)
	{

		puts("create seas passed its test");
	}
	else
	{
		puts("create seas did not pass its test");
	}
	return ok;
}
bool Tests::testGetYesNo()
{
	bool ok = true;
	puts("starting testgetYesNo"); fflush(stdout);

	//setup
	Production* pP = new Production();
	char* query1 = "Type y";
	char* query2 = "Type n";
	bool rightAnswer = true;

	//trial
	bool answer = pP->getYesNo(query1);
	bool ok1 = (answer == rightAnswer);
	answer = pP->getYesNo(query2);
	rightAnswer = false;
	bool ok2 = (answer == rightAnswer);
	ok = ok1 && ok2;
	//render judgment
	if(ok)
	{
		puts("getYesNo passed its test");
	}
	else
	{
		puts("getYesNo did not pass its test");
	}
	return ok;
}
bool Tests::testDisplaySeasInConsole()//usual 2D display
{
	bool ok = true;
	puts("starting testDisplaySeas");fflush(stdout);

	//test case 1, seas are empty
	//setup
	Seas* Cs = new Seas(); //fills the sea with ~

	//trial
	Cs->displaySeas();
	Production* prodP = new Production();
	ok = prodP->getYesNo("Does it look like two seas of 10 x 10 of ~ ?");
	//tests case2, there should be something there
	//test case 2:
	//TODO more test cases here
	//render judgment
	if(ok)
	{

		puts("display seas passed its test");
	}
	else
	{
		puts("display seas did not pass its test");
	}

	return ok;
}

bool Tests::testCreateFleets()//born with 5 ship types, some numbers of each type, so test by asking how many of each type
{
	bool ok = true;
	puts("starting testCreateFleets"); fflush(stdout);
	//set up
	//Seas* Cs = new Seas();

	//trial
	Fleets* fleets = new Fleets(); //how do we know whether this worked?
	//right number of ships?//should be one of each
	//test case 1: when the fleet is new
	int answer0 = 0;
	int answer1 = fleets->getHowMany(0, CARRIER);
	int answer2 = fleets->getHowMany(0, BATTLESHIP);
	int answer3 = fleets->getHowMany(0, CRUISER);
	int answer4 = fleets->getHowMany(0, SUBMARINE);
	int answer5 = fleets->getHowMany(0, DESTROYER);
	int rightAnswer = 5;
	answer0 = answer1 + answer2 + answer3 + answer4 + answer5;
	ok = (answer0 == rightAnswer);
	//use a method in fleets, for asking report how many ships of each type
	//compare with the right answer

	//render judgment
	if(ok)
	{

		puts("create fleets passed its test");
	}
	else
	{
		puts("create fleets did not pass its test");
	}

	//test case 2: after some hull damage has occurred, some sinking has occurred
	return ok;
}


bool Tests:: testEnterCoordinates()// same for placing ships and shooting ships
{
	bool ok = true;
	Seas* Cs = new Seas();

	Location** seasP0 = Cs->seasP;
	Location** seasP1 = Cs->seasP+100;

	int testPlayer0 = 0;
	int testPlayer1 = 1;
	Pair* nP = new Pair();
	nP->col = 3;
	nP->row = 3;
	puts("Starting testEnterCoordinates");
	// set up

	Cs->takeCoordinates(nP, testPlayer0);
	Location** where = seasP1 + nP->row*Cs->size+nP->col;
	Location* x = *where;

	bool answer0 = x->waterOrNot;

	Cs->takeCoordinates(nP, testPlayer1);
		Location** where1 = seasP0 + nP->row*Cs->size+nP->col;
		Location* x1 = *where1;
	bool answer1 = x1->waterOrNot;

	bool rightAnswer = true;

	ok = (answer0 && answer1 && rightAnswer);

	if(ok)
		{

			puts("enterCoordinates passed its test");
		}
		else
		{
			puts("enterCoordinates did not pass its test");
		}



	return ok;
}
bool Tests::testLostHull()
{
	bool ok = true;
	Seas* Cs = new Seas();

	Location** seasP0 = Cs->seasP;  //for player 0, computer
	Location** seasP1 = Cs->seasP+100;

	int testPlayer0 = 0;
	int testPlayer1 = 1;
	Pair* nP = new Pair();
	nP->col = 3;
	nP->row = 3;
	puts("Starting testLostHull");
	// set up

	Cs->takeCoordinates(nP, testPlayer0);
	Location** where = seasP1 + nP->row*Cs->size+nP->col;
	Location* x = *where;

	bool answer0 = x->hasBeenShot;

	Cs->takeCoordinates(nP, testPlayer1);
	Location** where1 = seasP0 + nP->row*Cs->size+nP->col;
	Location* x1 = *where1;
	bool answer1 = x1->hasBeenShot;

	bool rightAnswer = true;

	ok = (answer0 && answer1 && rightAnswer);

	if(ok)
	{

		puts("lostHull passed its test");
	}
	else
	{
		puts("lostHull did not pass its test");
	}
	return ok;
}
bool Tests::testLostGame()
{
	bool answer = true;
	return answer;
}
bool  Tests::testAnnounceWinner()
{
	bool answer = true;
	return answer;
}
bool  Tests::testGetHumanSetup()
{
	bool ok = true;
	return ok;
}
bool  Tests::testDoHumanSetup()
{
	bool ok = true;

	//TODO

	return ok;
}
bool Tests::testFeasibilityCheck()
{
	bool ok = true;
	return ok;
}
