//
//  Drone.cpp
//
//  Updated by Stephanie Irish Paladin, 2019-04-08, 3am


#include <cassert>
#include <iostream>

#include "Position.h"
#include "Game.h"
#include "Drone.h"

using namespace std;

static const          int STARTING_HEALTH = 50;
static const          int DAMAGE = 5;
static const unsigned int POINTS = 10;

static const bool DEBUGGING_MONSTER_ALLOCATION = false;
static int allocated = 0;



Drone::Drone():Monster()
{
	allocated++;
	health = 0;
	damage = DAMAGE;
	points = POINTS;
	direction = 'N';
	if (DEBUGGING_MONSTER_ALLOCATION)
		cout << "Default constructor: now " << allocated << " monsters allocated" << endl;
}

Drone::Drone(const Position& start)
	: Monster(start)
{
	assert(isValid(start));

	health = STARTING_HEALTH;
	damage = DAMAGE;
	points = POINTS;
	direction = 'N';

	allocated++;
	if (DEBUGGING_MONSTER_ALLOCATION)
		cout << "Constructor: now " << allocated << " monsters allocated" << endl;
}


// put in Monster copy constructor to test memory allocations
//	allocated++;
//	if(DEBUGGING_MONSTER_ALLOCATION)
//		cout << "Copy Constructor: now " << allocated << " monsters allocated" << endl;

// put in Monster destructor to test memory allocations
//	allocated--;
//	if(DEBUGGING_MONSTER_ALLOCATION)
//		cout << "Destructor: now " << allocated << " monsters allocated" << endl;
Drone::Drone(const Drone& original): Monster(original){
	health = original.health;
	damage = original.damage;
	points = original.points;
	direction = original.direction;
}

Drone::~Drone() {
}

Drone& Drone::operator= (const Drone& original) {
	health = original.health;
	damage = original.damage;
	points = original.points;
	direction = original.direction;
	return *this;
}


char Drone::getDisplayChar() const {
	return 'D';
}


Monster* Drone::getClone() const {
	return new Drone(*this);
}


Position Drone::calculateMove(const Game& game,
	const Position& player_position) {
	Position p = getPosition();

	Position north = p;
	north.row--;
	Position south = p;
	south.row++;
	Position east = p;
	east.column++;
	Position west = p;
	west.column--;

	switch (direction) {
	case 'N':
		if (isValid(north) && !game.isBlockedForMonster(north))
			direction = 'N';
		else if (isValid(east) && !game.isBlockedForMonster(east))
			direction = 'E';
		else if (isValid(south) && !game.isBlockedForMonster(south))
			direction = 'S';
		else if (isValid(west) && !game.isBlockedForMonster(west))
			direction = 'W';
		else direction = ' ';
		break;
	case 'W':
		if (isValid(west) && !game.isBlockedForMonster(west))
			direction = 'W';
		else if (isValid(north) && !game.isBlockedForMonster(north))
			direction = 'N';
		else if (isValid(east) && !game.isBlockedForMonster(east))
			direction = 'E';
		else if (isValid(south) && !game.isBlockedForMonster(south))
			direction = 'S';
		break;
	case 'S':
		if (isValid(south) && !game.isBlockedForMonster(south))
			direction = 'S';
		else if (isValid(west) && !game.isBlockedForMonster(west))
			direction = 'W';
		else if (isValid(north) && !game.isBlockedForMonster(north))
			direction = 'N';
		else if (isValid(east) && !game.isBlockedForMonster(east))
			direction = 'E';
		break;
	case 'E':
		if (isValid(east) && !game.isBlockedForMonster(east))
			direction = 'E'; 
		else if (isValid(south) && !game.isBlockedForMonster(south))
			direction = 'S';
		else if (isValid(west) && !game.isBlockedForMonster(west))
			direction = 'W';
		else if (isValid(north) && !game.isBlockedForMonster(north))
			direction = 'N';
		
		break;
			
	}
	if (direction == 'N')return north;
	else if (direction == 'S')return south;
	else if (direction == 'E')return east;
	else if(direction=='W')return west;
	else return p;
}

