/*
 * Production.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: theresesmith
 */

#include "Production.h"
#include <time.h>

Production::Production() {
	// TODO Auto-generated constructor stub

}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

bool Production::prod(int argc, char* argv[])
{
	bool answer = true;
	bool whoGoesFirst = true;

	if(argc <=1) //no interesting information
	{
		puts("Usage: Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d interesting arguments.\n", argc-1);
		fflush(stdout);


		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string
			//in this program our arguments are NR, NC, gens, filename, print and pause
			//because pause is optional, argc could be 6 or 7
			//because print is optional (if print is not present, neither is pause) argc could be 5
			switch(i)
			{
			case 1:
				//this is

				if(strlen(argv[i])>=2)
				{
					puts("string is too long.");
					fflush(stdout);
					answer = false;
				}
				else
				{
					whoGoesFirst = (bool)strtol(argv[i], NULL, 10);
					printf("result of who goes first was was %d.\n", whoGoesFirst);
					fflush(stdout);
				}
				break;


			default:
				puts("Unexpected argument count."); fflush(stdout);
				answer = false;
				break;
			}//end of switch
		}//end of for loop on argument count
		puts("after reading arguments"); fflush(stdout);


		//be the Battleship agent
		bool whoseTurn = whoGoesFirst;
		//Create the seas
		Seas* Cs = new Seas();
		//create the fleets
		Fleets* fleets = new Fleets();
		Cs->setFleetsPtr(fleets);
		//fleets->setSeasPtr(Cs);
		//get the ships placed, both human and computer
		bool humanPlacing = getYesNo("Do you want to place your own ships");


		if(humanPlacing)
		{
			getHumanSetup(Cs, fleets);
		}
		else
		{
			doPlacing(Cs, fleets, HUMAN); //for human
		}
		puts("Finished Human Placement");
		fflush(stdout);

		doPlacing(Cs, fleets, COMPUTER); //for computer

		puts("Finished Computer Placement");
		fflush(stdout);
		//display before each turn
		Cs->displaySeas();
		//commence taking turns -- sounds like a while loop, because this game is guaranteed to end
		bool done = false;
		int pickRow = -1;
		int pickCol = -1;
		while(!done) //take turns
		{
			if(whoseTurn) //human?
			{
				puts("Prepare to fire!"); fflush(stdout);

				Pair* pP = new Pair();
				//ask the user for coordinates
				puts("Give the row (from 0 to 9 inclusive)");
				scanf("%d", &pickRow);
				puts("Give the column (from 0 to 9 inclusive)");
				scanf("%d", &pickCol);
				//scanf
				//double check they are reasonable

				pP->row = pickRow;//whatever the user said
				pP->col = pickCol;//whatever the user said
				//tell the seas about the coordinates
				Cs->takeCoordinates(pP, 0);//0 means human player
				//Pair* newP = Cs->getCoordinates();
				//find out whether any ship was sunk

				fleets->sinkShips(0);
				//find out whether the computer has now lost
				done = hasWon(fleets);
				//if so, done
				//did we become done?

			}
			else
			{
				puts("Computer firing"); fflush(stdout);
				//did we become done?
				Pair* pP = new Pair();
				//randomly generate coordinates (will be reasonable)
				pP->row = rand()%9;//whatever the user said
				pP->col = rand()%9;//whatever the user said
				//tell the seas about the coordinates
				Cs->takeCoordinates(pP, 1);//0 means computer player
				//find out whether any ship was sunk
				fleets->sinkShips(1);
				//find out whether the human has now lost
				//if so, done
				done = hasWon(fleets); //because all the ships are sunk
			}
			Cs->displaySeas();
			whoseTurn = !whoseTurn;


		}//now done


		//print who won when done
		puts("Game ended");
		Cs->displaySeas();

	}//end of else we have good arguments

	return whoGoesFirst;
}

bool Production::getYesNo(char* query)
{
	bool answer = true; //so far
	char said = 'x';
	do
	{
		printf("%s (y/n):",query);
		fflush(stdout);
		fflush(stdin);
		scanf("%c",&said);
	}while((said!= 'y')&&(said!='n'));
	if(said=='n')
	{
		answer=false;
	}


	return answer;
}
void Production::getHumanSetup(Seas* Cs, Fleets* fleets)  //don't allow overlapping ships
{
	//get from the human, where they want to place their ships
	int col = -1;
	int row = -1;
	puts("We're placing the carrier now.");
	Carrier* c = new Carrier();
	bool horizontal = getYesNo("Is this ship horizontal?");
	if(horizontal)
	{
		puts("Give the westernmost column (from 0 to 5 inclusive)");
		scanf("%d", &col);
		puts("Give the row");
		scanf("%d", &row);
		//set as many columns eastward for the size of a battleship
	}
	else
	{
		puts("Give the northernmost row (from 0 to 5 inclusive)");
		scanf("%d", &row);
		puts("Give the column");
		scanf("%d", &col);
		//set as many rows southward for the size of a battleship
	}
	//place the ship
	Cs->place(c, HUMAN, row, col, horizontal);
	Cs->displaySeas();

	Battleship* b = new Battleship();
	do
	{
		puts("We're placing the battleship now.");
		horizontal = getYesNo("Is this ship horizontal?");
		if(horizontal)
		{
			puts("Give the westernmost column (from 0 to 6 inclusive)");
			scanf("%d", &col);
			puts("Give the row");
			scanf("%d", &row);
			//set as many columns eastward for the size of a battleship
			//place the ship

		}
		else
		{
			puts("Give the northernmost row (from 0 to 6 inclusive)");
			scanf("%d", &row);
			puts("Give the column");
			scanf("%d", &col);
			//set as many rows southward for the size of a battleship
		}
	}
	while(!Cs->isFeasible(BATTLESHIP, HUMAN,row, col, horizontal));
	Cs->place(b, HUMAN, row, col, horizontal);
	Cs->displaySeas();

	Cruiser* cr = new Cruiser();
	do
	{
		puts("We're placing the cruiser now.");
		horizontal = getYesNo("Is this ship horizontal?");
		if(horizontal)
		{
			puts("Give the westernmost column (from 0 to 7 inclusive)");
			scanf("%d", &col);
			puts("Give the row");
			scanf("%d", &row);
			//set as many columns eastward for the size of a battleship
			//place the ship

		}
		else
		{
			puts("Give the northernmost row (from 0 to 7 inclusive)");
			scanf("%d", &row);
			puts("Give the column");
			scanf("%d", &col);
			//set as many rows southward for the size of a battleship
		}
	}while(!Cs->isFeasible(CRUISER, HUMAN,row, col, horizontal)); //why when not feasible, do we print 3 times?
	Cs->place(cr, HUMAN, row, col, horizontal);
	Cs->displaySeas();

	Submarine* s = new Submarine();
	do
	{
		puts("We're placing the submarine now.");
		horizontal = getYesNo("Is this ship horizontal?");
		if(horizontal)
		{
			puts("Give the westernmost column (from 0 to 7 inclusive)");
			scanf("%d", &col);
			puts("Give the row");
			scanf("%d", &row);
			//set as many columns eastward for the size of a battleship
			//place the ship

		}
		else
		{
			puts("Give the northernmost row (from 0 to 7 inclusive)");
			scanf("%d", &row);
			puts("Give the column");
			scanf("%d", &col);
			//set as many rows southward for the size of a battleship
		}
	}while(!Cs->isFeasible(SUBMARINE, HUMAN,row, col, horizontal)); //why when not feasible, do we print 3 times?
	Cs->place(s, HUMAN, row, col, horizontal);
	Cs->displaySeas();
	Destroyer* d = new Destroyer();
	do
	{
		puts("We're placing the destroyer now.");
		horizontal = getYesNo("Is this ship horizontal?");
		if(horizontal)
		{
			puts("Give the westernmost column (from 0 to 8 inclusive)");
			scanf("%d", &col);
			puts("Give the row");
			scanf("%d", &row);
			//set as many columns eastward for the size of a battleship
			//place the ship

		}
		else
		{
			puts("Give the northernmost row (from 0 to 8 inclusive)");
			scanf("%d", &row);
			puts("Give the column");
			scanf("%d", &col);
			//set as many rows southward for the size of a battleship
		}
	}while(!Cs->isFeasible(DESTROYER, HUMAN,row, col, horizontal)); //why when not feasible, do we print 3 times?
	Cs->place(d, HUMAN, row, col, horizontal);
	Cs->displaySeas();
	puts("done placing human's ships.");

}
void Production::doPlacing(Seas* Cs, Fleets* fleets, PlayerType x)
{
	//random choice of horizontal/vertical
	int col = -1;
	int row = -1;
	Carrier* c = new Carrier();

	bool horizontal = rand()%2; // 0 is vertical 1 is horizontal
	if(horizontal)
	{

		col = rand()%6;
		row = rand()%9;
	}
	else
	{
		row = rand()%6;
		col = rand()%9;
	}
	while(!Cs->isFeasible(CARRIER, x,row, col, horizontal));
	Cs->place(c, x, row, col, horizontal);

	srand((time(NULL)));
	Battleship* b = new Battleship();
	do
		{

		bool horizontal = rand()%2;

			if(horizontal) // 0 is vertical 1 is horizontal
			{
				col = rand()%7;

				row = rand()%9;
				//set as many columns eastward for the size of a battleship
				//place the ship

			}
			else
			{
				row = rand()%7;

				col = rand()%9;
				//set as many rows southward for the size of a battleship
			}
		}
	while(!Cs->isFeasible(BATTLESHIP, x,row, col, horizontal));
	Cs->place(b, x, row, col, horizontal);
	// Cs->displaySeas();

	srand((time(NULL)));
	Cruiser* cr = new Cruiser();
		do
		{

			bool horizontal = rand()%2;
			if(horizontal)
			{
				col = rand()%8;
				row = rand()%9;
				//set as many columns eastward for the size of a battleship
				//place the ship

			}
			else
			{
				row = rand()%8;
				col = rand()%9;
				//set as many rows southward for the size of a battleship
			}
		}while(!Cs->isFeasible(CRUISER, x,row, col, horizontal)); //why when not feasible, do we print 3 times?
		Cs->place(cr, x, row, col, horizontal);

		srand((time(NULL)));
		Submarine* s = new Submarine();
			do
			{

				bool horizontal = rand()%2;
				if(horizontal)
				{
					col = rand()%8;
					row = rand()%9;
					//set as many columns eastward for the size of a battleship
					//place the ship

				}
				else
				{
					row = rand()%8;
					col = rand()%9;
					//set as many rows southward for the size of a battleship
				}
			}while(!Cs->isFeasible(SUBMARINE, x,row, col, horizontal)); //why when not feasible, do we print 3 times?
			Cs->place(s, x, row, col, horizontal);

			srand((time(NULL)));
			Destroyer* d = new Destroyer();
				do
				{

					bool horizontal = rand()%2;
					if(horizontal)
					{
						col = rand()%9;
						row = rand()%9;
						//set as many columns eastward for the size of a battleship
						//place the ship

					}
					else
					{
						row = rand()%9;
						col = rand()%9;
						//set as many rows southward for the size of a battleship
					}
				}while(!Cs->isFeasible(DESTROYER, x,row, col, horizontal)); //why when not feasible, do we print 3 times?
				Cs->place(d, x, row, col, horizontal);
				Cs->displaySeas();
				puts("done auto placing ships.");

}

bool Production::isFeasible(Seas* Cs, int row, int col, int horiz, ShipType s, PlayerType pt)
{
	bool answer = true;

	//based on ship type, we know how many places to check
	//for each of those places, if they not symbol ~, then it's not feasible
	int size = -1;
	Location** seasP0 = Cs->getSeasP();  //for player 0
	Location** seasP1 = seasP0+100; //for player 1
	if (pt==COMPUTER)
	{
		seasP0 = seasP1;
	}
	switch(s)
	{
	case CARRIER:
		size = 5;
		break;
	case BATTLESHIP:
		size = 4;
		break;
	case CRUISER:
		size = 3;
		break;
	case SUBMARINE:
		size = 3;
		break;
	case DESTROYER:
		size = 2;
		break;
	default:
		puts("Unexpected ship type");
	}
	for(int i = 0; i<size; i++)
	{
		if(horiz)
		{
			col = col+i;
		}
		else
		{
			row = row+1;
		}
		Location** where = seasP0 + row*size+col;
		//is there anything other than ~ there for symbol?
		Location* x = *where;
		if(x->getSymbol() != '~')
		{
			answer = false;
		}
	}
	fflush(stdin);
	fflush(stdout);
	printf("For that ship of size %d, placement is(1) / is not(0) %d feasible.\n", size, answer);
	return answer;
}

bool Production::hasWon(Fleets* fleet){

	bool ok = false;
	int howManyShips0 = 0;
	int howManyShips1 = 0;
	int howManyCarrier0 = 0;
	int howManyBattleship0 = 0;
	int howManyCruiser0 = 0;
	int howManySub0 = 0;
	int howManyDestroyer0 = 0;

	int howManyCarrier1 = 0;
	int howManyBattleship1 = 0;
	int howManyCruiser1 = 0;
	int howManySub1 = 0;
	int howManyDestroyer1 = 0;

		howManyCarrier0 = fleet->getHowMany(0, CARRIER);
		howManyBattleship0 = fleet->getHowMany(0, BATTLESHIP);
		howManyCruiser0 = fleet->getHowMany(0, CRUISER);
		howManySub0 = fleet->getHowMany(0, SUBMARINE);
		howManyDestroyer0 = fleet->getHowMany(0, DESTROYER);

		howManyShips0 = howManyCarrier0 + howManyBattleship0 + howManyCruiser0 + howManySub0 + howManyDestroyer0;


	printf("%i \n", howManyShips0); fflush(stdout);


		howManyCarrier1 = fleet->getHowMany(1, CARRIER);
		howManyBattleship1 = fleet->getHowMany(1, BATTLESHIP);
		howManyCruiser1 = fleet->getHowMany(1, CRUISER);
		howManySub1 = fleet->getHowMany(1, SUBMARINE);
		howManyDestroyer1 = fleet->getHowMany(1, DESTROYER);

	howManyShips1 = howManyCarrier1 + howManyBattleship1 + howManyCruiser1 + howManySub1 + howManyDestroyer1;

	printf("%i \n", howManyShips1); fflush(stdout);

	if(howManyShips0 == 0){

		ok = true;
		printf("Player 0 is the winner!");
	}
	if(howManyShips1 == 0){

		ok = true;
		printf("Player 1 is the winner!");
	}

	else{
		ok = false;
	}

	return ok;
}
