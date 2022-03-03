/*
 * Seas.cpp
 *
 *  Created on: Feb 15, 2022
 *      Author: theresesmith
 */

#include "Seas.h"

Seas::Seas() {
	// TODO Auto-generated constructor stub
	size = 10;
	fp = NULL;

	seasP = (Location**) malloc (2*size*size*sizeof(Location*));//2 players, square board
	Location** seasP0 = seasP;  //for player 0, computer
	Location** seasP1 = seasP+100; //for player 1, human
	for(int player = 0; player<2; player++)
	{
		for(int row= 0; row<size; row++)
		{
			for(int col = 0; col<size; col++)
			{
				PlayerType pt = HUMAN;
				if (player == 1) pt = COMPUTER;
				if (pt== COMPUTER)
				{
					seasP0 = seasP1;
				}
				Location** where = seasP0 + row*size+col;
				Location* x = (Location*) malloc(sizeof(Location));
				*where = x;
				x->setSymbol('~');
			}
		}

	}

}
//There are addresses, and addresses have content,
//we can put content at an address.    *address=content;
//we can get content from an address.     content = *address;
//think of the address as the number written on the mailbox, e.g. 45
//hey postal carrier, put this letter to 45.   *45 = letter;
//hey, postal carrier, pick up my outgoingMail   outgoingMail = *45;
Seas::~Seas() {
	// TODO Auto-generated destructor stub
}

int Seas::getSize()
{
	int answer = -1;
	answer = size;
	return answer;
}
void Seas::setSize(int s)
{
	size = s;
}
void Seas::displaySeas()
{
	Location** seasP0 = seasP;  //for player 0
	Location** seasP1 = seasP+100; //for player 1
	for(int player = 0; player<2; player++)
	{
		for(int row= 0; row<size; row++)
		{
			for(int col = 0; col<size; col++)
			{
				PlayerType pt = HUMAN;
				if (player == 1) pt = COMPUTER;
				if (pt== COMPUTER)
				{
					seasP0 = seasP1;
				}
				Location** where = seasP0 + row*size+col;
				Location* x = *where; //take the location pointer from the address we calculated
				char symbol = x->getSymbol();
				printf("|%c", symbol);
			}
			printf("|\n");
		}
		printf("Finished player %d.\n", player); fflush(stdout);
	}

}
void Seas::takeCoordinates(Pair* pP, int player)//shooting
{
	//do what?
	//calculate where, using player
	Location** seasP0 = seasP;  //for player 0
	Location** seasP1 = seasP+100; //for player 1

	PlayerType pt = HUMAN;
	if (player == 1) pt = COMPUTER;
	if (pt== HUMAN)
	{
		seasP0 = seasP1;
	}
	Location** where = seasP0 + pP->row*size+pP->col;
	//is there a ship there?
	Location* x = *where;
	if(x->getSymbol()== '~')
	{
		//not a ship
		puts("It's a miss.");
		char missSymbol = 'm';
		x->setSymbol(missSymbol);
		x->waterOrNot = true;
		fp->lostHull(player, pP, x);
	}
	else
	{
		//something got hit
		puts("It's a hit!");
		//have to tell fleets about it
		char hitSymbol = '*';
		char shipSymbol = x->getSymbol();
		x->setSymbol(hitSymbol);
		fp->lostHull(player, pP, x);



	}

}
void Seas::place(Carrier* c, PlayerType player, int row, int col, bool dir)
{
	Location** seasP0 = seasP;
	if(player == COMPUTER)
	{
		seasP0+=100;
	}
	if(dir) //horizontal
	{
		for(int c= col; c<col+5; c++)
		{
			Location** where = seasP0 + row*size+c;
			Location* x = *where;
			//TODO x->setShipP((Ship*) c);
			x->setSymbol('C');
			x->x = CARRIER;
		}
	}
	else
	{
		for(int r= row; r<row+5; r++)
		{
			Location** where = seasP0 + r*size+col;
			Location* x = *where;
			//x->setShipP((Ship*) c);
			x->setSymbol('C');
			x->x = CARRIER;
		}
	}


}
void Seas::place(Battleship* b, PlayerType player, int row, int col, bool dir)
{
	Location** seasP0 = seasP;
	if(player == COMPUTER)
	{
		seasP0+=100;
	}
	if(dir) //horizontal
	{
		for(int c= col; c<col+4; c++)
		{
			Location** where = seasP0 + row*size+c;
			Location* x = *where;
			//x->setShipP((Ship*) b);
			x->setSymbol('B');
			x->x = BATTLESHIP;
		}
	}
	else
	{
		for(int r= row; r<row+4; r++)
		{
			Location** where = seasP0 + r*size+col;
			Location* x = *where;
			//x->setShipP((Ship*) b);
			x->setSymbol('B');
			x->x = BATTLESHIP;
		}
	}

}
void Seas::place(Cruiser* c, PlayerType player, int row, int col, bool dir)
{
	Location** seasP0 = seasP;
	if(player == COMPUTER)
	{
		seasP0+=100;
	}
	if(dir) //horizontal
	{
		for(int c= col; c<col+3; c++)
		{
			Location** where = seasP0 + row*size+c;
			Location* x = *where;//seas can go to fleets, and ask which ship is at this spot
			//TODO
			//x->setShipP(player, CRUISER);//the cruiser of human
			x->setSymbol('c');
			x->x = CRUISER;
		}
	}
	else
	{
		for(int r= row; r<row+3; r++)
		{
			Location** where = seasP0 + r*size+col;
			Location* x = *where;
			//x->setShipP((Ship*) c);
			x->setSymbol('c');
			x->x = CRUISER;
		}
	}

}
void Seas::place(Submarine* s, PlayerType player, int row, int col, bool dir)
{
	Location** seasP0 = seasP;
	if(player == COMPUTER)
	{
		seasP0+=100;
	}
	if(dir) //horizontal
	{
		for(int c= col; c<col+3; c++)
		{
			Location** where = seasP0 + row*size+c;
			Location* x = *where;
			//x->setShipP((Ship*) s);
			x->setSymbol('S');
			x->x = SUBMARINE;
		}
	}
	else
	{
		for(int r= row; r<row+3; r++)
		{
			Location** where = seasP0 + r*size+col;
			Location* x = *where;
			//x->setShipP((Ship*) s);
			x->setSymbol('S');
			x->x = SUBMARINE;

		}
	}
}
void Seas::place(Destroyer* d, PlayerType player, int row, int col, bool dir)
{
	Location** seasP0 = seasP;
	if(player == COMPUTER)
	{
		seasP0+=100;
	}
	if(dir) //horizontal
	{
		for(int c= col; c<col+2; c++)
		{
			Location** where = seasP0 + row*size+c;
			Location* x = *where;
			//x->setShipP((Ship*) d);
			x->setSymbol('D');
			x->x = DESTROYER;
		}
	}
	else
	{
		for(int r= row; r<row+2; r++)
		{
			Location** where = seasP0 + r*size+col;
			Location* x = *where;
			//x->setShipP((Ship*) d);
			x->setSymbol('D');
			x->x = DESTROYER;

		}
	}
}

int Seas::imminent(int partner)
{
	int answer = -1;

	//	[ captures ] ( params ) specs requires(optional) { body }
	//captures	-	a comma-separated list of zero or more captures, optionally beginning with a capture-default.
	//params	-	The list of parameters, as in named functions.
	//specs	-	consists of specifiers, exception, attr and trailing-return-type in order, every component is optional
	//requires	-	(since C++20) adds constraints to operator() of the closure type  IS OPTIONAL
	//body	-	Function body

	// (params) {body}   SIMPLEST
	// e.g. (Fleet* fleet, int partner){//statements as in functions}

	//	auto glambda = [](auto a, auto&& b) { return a < b; };
	//	bool b = glambda(3, 3.14); // ok

	return answer;

}
void Seas::setFleetsPtr(Fleets* fleets)
{
	fp=fleets;
}
Location** Seas::getSeasP()
{
	return seasP;
}
bool Seas::isFeasible(ShipType s, PlayerType player, int row, int col, bool dir)
{
	bool answer = true;
	Location** seasP0 = seasP;
	int ssize = -1;
	if(player == COMPUTER)
	{
		seasP0+=100;
	}
	switch(s)
	{
	case CARRIER:
		ssize = 5;
		break;
	case BATTLESHIP:
		ssize = 4;
		break;
	case CRUISER:
		ssize = 3;
		break;
	case SUBMARINE:
		ssize = 3;
		break;
	case DESTROYER:
		ssize = 2;
		break;
	default:
		puts("Unexpected ship type");
	}
	if(dir) //horizontal
	{
		for(int c= col; c<col+ssize; c++)
		{
			Location** where = seasP0 + row*size+c;
			Location* x = *where;
			//TODO x->setShipP((Ship*) c);
			if(x->getSymbol() != '~')
			{
				answer = false;
			}
		}
	}
	else
	{
		for(int r= row; r<row+ssize; r++)
		{
			Location** where = seasP0 + r*size+col;
			Location* x = *where;
			//x->setShipP((Ship*) c);
			if(x->getSymbol()!= '~')
			{
				answer = false;
			}
		}
	}
	return answer;
}
