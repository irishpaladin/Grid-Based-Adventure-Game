//
//  Attacker.cpp
//
//  Updated by Stephanie Irish Paladin, 2019-04-08, 3am


#include <cassert>
#include <iostream>

#include "Position.h"
#include "Game.h"
#include "Attacker.h"

using namespace std;

static const          int STARTING_HEALTH = 10;
static const          int DAMAGE = 2;
static const unsigned int POINTS = 20;

static const bool DEBUGGING_MONSTER_ALLOCATION = false;
static int allocated = 0;



Attacker::Attacker() :Monster()
{
	allocated++;
	health = 0;
	damage = DAMAGE;
	points = POINTS;
	if (DEBUGGING_MONSTER_ALLOCATION)
		cout << "Default constructor: now " << allocated << " monsters allocated" << endl;
}

Attacker::Attacker(const Position& start)
	: Monster(start)
{
	assert(isValid(start));

	health = STARTING_HEALTH;
	damage = DAMAGE;
	points = POINTS;

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
Attacker::Attacker(const Attacker& original) : Monster(original) {
	health = original.health;
	damage = original.damage;
	points = original.points;
}

Attacker::~Attacker() {
}

Attacker& Attacker::operator= (const Attacker& original) {
	health = original.health;
	damage = original.damage;
	points = original.points;
	return *this;
}


char Attacker::getDisplayChar() const {
	return 'A';
}


Monster* Attacker::getClone() const {
	return new Attacker(*this);
}


Position Attacker::calculateMove(const Game& game,
	const Position& player_position) {
	//MAKE THIS
	return calculateToPosition(game, player_position);
}

