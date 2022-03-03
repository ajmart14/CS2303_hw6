/*
 * Fleets.cpp
 *
 *  Created on: Feb 14, 2022
 *      Author: theresesmith
 */

#include "Fleets.h"


Fleets::Fleets() {
	// TODO Auto-generated constructor stub
	howManyCarriersA =1;//player a or player 0
	howManyCarriersB=1;//player b or player 1
	howManySubmarinesA=1;
	howManySubmarinesB=1;
	howManyBattleshipsA=1;
	howManyBattleshipsB=1;
	howManyCruisersA=1;
	howManyCruisersB=1;
	howManyDestroyersA=1;
	howManyDestroyersB=1;
	c0 = new Carrier();
	c1 = new Carrier();
	b0 = new Battleship();
	b1 = new Battleship();
	cr0 = new Cruiser();
	cr1 = new Cruiser();
	d0 = new Destroyer();
	d1 = new Destroyer();
	s0 = new Submarine();
	s1 = new Submarine();

}

Fleets::~Fleets() {
	// TODO Auto-generated destructor stub
}

int Fleets::getHowMany(int player, ShipType s)
{

	int answer = -1;
	if(player == 0 ){

		switch(s)
		{
		case EMPTY:
			answer = 0;
			break;
		case CARRIER:
			answer = howManyCarriersA;
			break;
		case BATTLESHIP:
			answer = howManyBattleshipsA;
			break;
		case CRUISER:
			answer = howManyCruisersA;
			break;
		case SUBMARINE:
			answer = howManySubmarinesA;
			break;
		case DESTROYER:
			answer = howManyDestroyersA;
			break;
		}

	}
	else{
		switch(s)
		{
		case EMPTY:
			answer = 1;
			break;
		case CARRIER:
			answer = howManyCarriersB;
			break;
		case BATTLESHIP:
			answer = howManyBattleshipsB;
			break;
		case CRUISER:
			answer = howManyCruisersB;
			break;
		case SUBMARINE:
			answer = howManySubmarinesB;
			break;
		case DESTROYER:
			answer = howManyDestroyersB;
			break;
		}
	}
	return answer;
}

void Fleets::sinkShips(int player)
{
	int sunkShipsA = 0;
	int sunkShipsB = 0;

	switch(player){
	case 0:

		if(c0->hitsSustained >= 5){
			howManyCarriersA = 0;
		}
		if(b0->hitsSustained >= 4){
			howManyBattleshipsA = 0;
		}
		if(cr0->hitsSustained >= 3){
			howManyCruisersA = 0;
		}
		if(s0->hitsSustained >= 3){
			howManySubmarinesA = 0;
		}
		if(d0->hitsSustained >= 2){
			howManyDestroyersA = 0;
		}
		break;
	case 1:

		if(c1->hitsSustained >= 5){
			howManyCarriersB = 0;
		}
		if(b1->hitsSustained >= 4){
			howManyBattleshipsB = 0;
		}
		if(cr1->hitsSustained >= 3){
			howManyCruisersB = 0;
		}
		if(s1->hitsSustained >= 3){
			howManySubmarinesB = 0;
		}
		if(d1->hitsSustained >= 2){
			howManyDestroyersB = 0;
		}
		break;
	}


	sunkShipsA = howManyCarriersA + howManyBattleshipsA + howManyCruisersA + howManySubmarinesA + howManyDestroyersA;
	sunkShipsB = howManyCarriersB + howManyBattleshipsB + howManyCruisersB + howManySubmarinesB + howManyDestroyersB;

	sunkShipsA = 5 - sunkShipsA;
	sunkShipsB = 5 - sunkShipsB;

	printf("%i of Player 0's ships sunk \n", sunkShipsA);
	printf("%i of Player 1's ships sunk \n", sunkShipsB);
}

void Fleets::lostHull(int player, Pair* pP, Location* loc){

	if(player == 1){

		switch(loc->x)
		{
		case EMPTY:
			loc->hasBeenShot = true;
			break;
		case CARRIER:
			c0->hitsSustained+=1;
			loc->hasBeenShot = true;
			break;
		case BATTLESHIP:
			b0->hitsSustained+=1;
			loc->hasBeenShot = true;
			break;
		case CRUISER:
			cr0->hitsSustained+=1;
			loc->hasBeenShot = true;
			break;
		case SUBMARINE:
			s0->hitsSustained+=1;
			loc->hasBeenShot = true;
			break;
		case DESTROYER:
			d0->hitsSustained+=1;
			loc->hasBeenShot = true;

			break;

		}
	}
	if(player == 0){

		switch(loc->x)
		{
		case EMPTY:
			loc->hasBeenShot = true;
			break;
		case CARRIER:
			c1->hitsSustained+=1;
			loc->hasBeenShot = true;
			break;
		case BATTLESHIP:
			b1->hitsSustained+=1;
			loc->hasBeenShot = true;
			break;
		case CRUISER:
			cr1->hitsSustained+=1;
			loc->hasBeenShot = true;
			break;
		case SUBMARINE:
			s1->hitsSustained+=1;
			loc->hasBeenShot = true;
			break;
		case DESTROYER:
			d1->hitsSustained+=1;
			loc->hasBeenShot = true;
		//	printf("Destroyer has %i hits", d1->hitsSustained);
			break;
		}
	}
}
//void Fleets::setSeasPtr(Seas* s)
//{
//	sPtr=s;
//}
