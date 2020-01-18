

/*
Position.h
Stephanie Irish Paladin
last revise: March 10 11pm
*/


//
//  Player.h
//
//  Encapsulates a module to represent the player in a
//    grid-based game.
//



#include "Position.h"
#include "Player.h"


static const int STARTING_HEALTH = 40;
static const int DAMAGE = 2;

Player::Player() {
	health = 0;
	damage = 0;
	position.row = -1;
	position.column = -1;
	score = 0;
	total_move_cost = 0;
}

//
//  Player
//
//  Purpose: To initialize a Player at a specific position.
//  Parameter(s):
//    <1> start: The starting position for player
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: Player player is initialized to have default
//               values and to be at the position start.
//
Player::Player(const Position& start)
:position(start),
health(STARTING_HEALTH),
damage(DAMAGE),
score(0),
total_move_cost(0)
{
	
}

//
//  isDead
//
//  Purpose: To determine if a Player is dead.
//  Parameter(s):N/A
//  Precondition(s): N/A
//  Returns: Whether Player player is dead
//  Side Effect: N/A
//
bool Player::isDead()const {
	if (health <= 0) {
		return true;
	}
	else {
		return false;
	}
}

//
//  getHealth
//
//  Purpose: To determine a Player's current health.
//  Parameter(s):N/A
//  Precondition(s): N/A
//  Returns: Player player's current health.
//  Side Effect: N/A
//
int Player::getHealth() const {
	return health;
}

//
//  getDamage
//
//  Purpose: To determine how much damage a Player deals when
//           attacking.
//  Parameter(s):N/A
//  Precondition(s): N/A
//  Returns: How much damage Player player deals when attacking.
//  Side Effect: N/A
//
int Player::getDamage() const {
	return damage;
}

//
//  getScore
//
//  Purpose: To determine a Player's current score.
//  Parameter(s):N/A
//  Precondition(s): N/A
//  Returns: Player player's current score.
//  Side Effect: N/A
//
unsigned int Player::getScore() const {
	return score;
}

//
//  getTotalMoveCost
//
//  Purpose: To determine a Player's total movement cost.
//  Parameter(s):N/A
//  Precondition(s): N/A
//  Returns: Player player's total movement cost.
//  Side Effect: N/A
//
unsigned int Player::getTotalMoveCost()const {
	return total_move_cost;
}

//
//  getPosition
//
//  Purpose: To determine a Player's current position.
//  Parameter(s):N/A
//  Precondition(s): N/A
//  Returns: Player player's current position.
//  Side Effect: N/A
//
const Position& Player::getPosition()const {
	return position;
}

//
//  playerSetPosition
//
//  Purpose: To change a Player's current position.
//  Parameter(s):
//    <1> p: The new position
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The current position of Player player is set to
//               p.
//
void Player::setPosition(const Position& p) {
	position = p;
}

//
//  playerReceiveDamage
//
//  Purpose: To reduce a Player's health.
//  Parameter(s):
//    <1> amount: The amount to reduce player's health by
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The health of Player player is reduced by
//               amount.
//
void Player::receiveDamage(int amount) {
	health -= amount;
}

//
//  playerIncreaseScore
//
//  Purpose: To increase a Player's current score.
//  Parameter(s):
//    <1> amount: The amount to increase player's current score
//                by
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The current score of Player player is increased
//               by amount.
//
void Player::increaseScore(unsigned int amount) {
	score += amount;
}

//
//  playerIncreaseTotalMoveCost
//
//  Purpose: To increase a Player's total move cost.
//  Parameter(s):
//    <1> amount: The amount to increase player's total move
//                cost by
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The total move cost of Player player is
//               increased by amount.
//
void Player::increaseTotalMoveCost(unsigned int amount) {
	total_move_cost += amount;
}