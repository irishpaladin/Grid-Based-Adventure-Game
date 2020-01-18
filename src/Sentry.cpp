//  Updated by Stephanie Irish Paladin, 2019-04-08, 3am

#include <cassert>
#include <iostream>

#include "Position.h"
#include "Game.h"
#include "Sentry.h"

using namespace std;

static const          int STARTING_HEALTH = 20;
static const          int DAMAGE = 3;
static const unsigned int POINTS = 50;

static const bool DEBUGGING_MONSTER_ALLOCATION = false;
static int allocated = 0;

Sentry::Sentry()
	: Monster()
{
	health = 0;
	damage = DAMAGE;
	points = POINTS;
	allocated++;
	position = getPosition();
	if (DEBUGGING_MONSTER_ALLOCATION)
		cout << "Default constructor: now " << allocated << " monsters allocated" << endl;
}


Sentry::Sentry(const Position& start)
	: Monster(start)
{
	assert(isValid(start));
	health = STARTING_HEALTH;
	damage = DAMAGE;
	points = POINTS;
	position = getPosition();

	allocated++;
	if (DEBUGGING_MONSTER_ALLOCATION)
		cout << "Constructor: now " << allocated << " monsters allocated" << endl;
}



Sentry::Sentry(const Sentry& original) :Monster(original) {
	health = original.health;
	damage = original.damage;
	points = original.points;
	position = original.position;
}

Sentry::~Sentry() {
}

Sentry& Sentry::operator= (const Sentry& original) {
	health = original.health;
	damage = original.damage;
	points = original.points;
	position = original.position;
	return *this;
}

char Sentry::getDisplayChar() const {
	return 'S';
}


Monster* Sentry::getClone() const {
	return new Sentry(*this);
}


Position Sentry::calculateMove(const Game& game,
	const Position& player_position) {
	Position curr = getPosition();
	double d1 = calculateDistance(curr, player_position);
	double d2 = calculateDistance(curr, position);

	if (d1 + d2 > 6) {
		return calculateToPosition(game, position);
	}
	else {
		return calculateToPosition(game, player_position);
	}
	
}