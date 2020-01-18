
/*
Position.h
Stephanie Irish Paladin
last revise: March 10 11pm
*/


//
//  Monster.h
//
//  Encapsulates a module to represent an (enemy) monster in a
//    grid-based game.
//





//#include "Position.h"
//#include "Monster.h"
//#include "Level.h"
#include "Game.h"




static const int STARTING_HEALTH = 20;
static const int DAMAGE = 3;
static const int POINTS = 50;

Monster::Monster() 
{
	health = 0;
	damage = 0;
	position = toPosition(-1, -1);
	points = 0;
}

//
//  Monster
//
//  Purpose: To initialize a monster at a specific position.
//  Parameter(s):
//    <1> start: The starting position for the monster
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: The Monster monster is initialized to have
//               default values and to be at position start.
//
Monster::Monster(const Position& start) 
:position(start),
health(STARTING_HEALTH),
damage(DAMAGE),
points(POINTS)
{
	
}

//
//  isDead
//
//  Purpose: To determine if a monster is dead.
//  Parameter(s):N/A
//  Precondition: N/A
//  Returns: Whether the Monster is dead.
//  Side Effect: N/A
//
bool Monster::isDead() const {
	if (health <= 0) {
		return true;
	}
	else {
		return false;
	}
}

//
//  getDamage
//
//  Purpose: To determine how much damage a Monster deals when
//           attacking.
//  Parameter(s):N/A
//  Precondition: N/A
//  Returns: How much damage Monster monster deals when
//           attacking.
//  Side Effect: N/A
//
int Monster::getDamage() const {
	return damage;
}

//
//  getPoints
//
//  Purpose: To determine how many points are awarded for
//           killing a monster.
//  Parameter(s):N/A
//  Precondition: N/A
//  Returns: How many points are awarded for killing Monster
//           monster.
//  Side Effect: N/A
//
unsigned int Monster::getPoints()const {
	return points;
}

//
//  getPosition
//
//  Purpose: To determine a Monster's current position.
//  Parameter(s):N/A
//  Precondition: N/A
//  Returns: Monster monster's current position.
//  Side Effect: N/A
//
const Position&  Monster::getPosition() const {
	return position;
}

//
//  setPosition
//
//  Purpose: To change a Monster's current position.
//  Parameter(s):
//    <1> p: The new position
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: The current position of Monster monster is set
//               to p.
//
void  Monster::setPosition(const Position& p) {
	position = p;
}

//
//  monsterReceiveDamage
//
//  Purpose: To reduce an Monster's health.
//  Parameter(s):
//    <1> amount: The amount to reduce the Monster's health by
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: Monster monster's health is reduced by amount.
//
void  Monster::receiveDamage(int amount) {
	health -= amount;
}

//
//  calculateMove
//
//  Purpose: To calculate a monster's next move in the game.
//  Parameter(s):
//    <1> level: The level
//    <2> player_position: The player's current position
//  Precondition: N/A
//  Returns: The new position for Monster monster.  If this is
//           the same as the player's position, monster is
//           attacking the player instead of moving.
//  Side Effect: N/A
//
Position  Monster::calculateMove(const Game& game, const Position& player_position) const {
	//stores position
	Position p_north, p_south, p_east, p_west, f_pos;
	//where to store the distance
	double north, south, east, west, f_distance;

	//initialize the positions tomonster position
	p_north = position;
	p_south = position;
	p_east = position;
	p_west = position;
	f_pos = position;

	//change the row/column
	p_north.row--;
	p_south.row++;
	p_east.column++;
	p_west.column--;

	//initialize the distance in current position
	f_distance = calculateDistance(position, player_position);

	//finding the best move
	if (!game.isBlockedForMonster(p_north)) {
		north = calculateDistance(p_north, player_position);
		if (f_distance >= north) {
			f_distance = north;
			f_pos = p_north;
		}
	}
	if (!game.isBlockedForMonster(p_south)) {
		south = calculateDistance(p_south, player_position);
		if (f_distance >= south) {
			f_distance = south;
			f_pos = p_south;
		}
	}
	if (!game.isBlockedForMonster(p_east)) {
		east = calculateDistance(p_east, player_position);
		if (f_distance >= east) {
			f_distance = east;
			f_pos = p_east;
		}
	}

	if (!game.isBlockedForMonster(p_west)) {
		west = calculateDistance(p_west, player_position);
		if (f_distance >= west) {
			f_distance = west;
			f_pos = p_west;
		}
	}


	return f_pos;


}
