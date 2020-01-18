//
//  Monster.h
//
//  Encapsulates a module to represent an (enemy) monster in a
//    grid-based game.
//

#pragma once

#include "Position.h"

class Game;



class Monster
{
public:
	//
	//  Default Constructor
	//
	//  Purpose: To create a dead Monster.
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: A new Monster is initialized to have 0 health
	//               at position (0, 0).
	//
	Monster();

	//
	//  Constructor
	//
	//  Purpose: To create a Monster at a specific position.
	//  Parameter(s):
	//    <1> start: The starting position for the monster
	//  Precondition:
	//    <1> isValid(start)
	//  Returns: N/A
	//  Side Effect: A new Monster is initialized to have default
	//               values and be at position start.
	//
	Monster(const Position& start);
	Monster(const Position& start,
		int health1,
		int damage1,
		unsigned int points1);

	//
	//  Copy Constructor
	//
	//  Purpose: To create a Monster base on exixting Monster
	//  Parameter(s):
	//    <1> original: Monster that will be copied
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: The Monster will be initialized based on 'original' monster
	//
	Monster(const Monster& original);

	//
	//  Destructor
	//
	//  Purpose: Return all the used memory
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: N/A
	//
	virtual ~Monster();

	//
	//  Assignment Operator
	//
	//  Purpose: To reinitialize Monster base on existing Monster
	//  Parameter(s):
	//    <1> original: Monster that will be copied
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: 'original' player will be copied to the current player
	Monster& operator= (const Monster& original);

	//
	//  isDead
	//
	//  Purpose: To determine if this Monster is dead.
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: Whether this Monster is dead.
	//  Side Effect: N/A
	//
	bool isDead() const;

	//
	//  getDamage
	//
	//  Purpose: To determine how much damage this Monster deals
	//           when attacking.
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: How much damage this Monster deals when attacking.
	//  Side Effect: N/A
	//
	int getDamage() const;

	//
	//  getPoints
	//
	//  Purpose: To determine how many points the player gets for
	//           killing this Monster.
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: How many points are awarded for killing this
	//           Monster.
	//  Side Effect: N/A
	//
	unsigned int getPoints() const;

	//
	//  getPosition
	//
	//  Purpose: To determine current position of this Monster.
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: This Monster's current position.
	//  Side Effect: N/A
	//
	const Position& getPosition() const;

	//
	//  getDisplayChar
	//
	//  Purpose: To display the indicated character for the monster
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: The character to be used to display this Monster
	//  Side Effect: N/A
	//
	virtual char getDisplayChar() const = 0;

	//
	//  getClone
	//
	//  Purpose: To create a dynamically allocated copy of the current Monster, using the override in the correct subclass
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: A pointer to a monster
	//  Side Effect: N/A
	//
	virtual Monster* getClone() const = 0;

	//
	//  setPosition
	//
	//  Purpose: To change a Monster's current position.
	//  Parameter(s):
	//    <1> p: The new position
	//  Precondition:
	//    <1> isValid(p)
	//  Returns: N/A
	//  Side Effect: This Monster is set to be at position p.
	//
	void setPosition(const Position& p);

	//
	//  receiveDamage
	//
	//  Purpose: To reduce the current health of this Monster.
	//  Parameter(s):
	//    <1> amount: The amount to reduce the Monster's health by
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: This Monster's health is reduced by amount.
	//
	void receiveDamage(int amount);

	//
	//  calculateMove
	//
	//  Purpose: To calculate this Monster's next move.
	//  Parameter(s):
	//    <1> Game: The Game that this Monster is moving around in
	//    <2> player_position: The player's current position
	//  Precondition: N/A
	//  Returns: The new position for this Monster.  If this is the
	//           same as player_position, this Monster is attacking
	//           the player instead of moving.
	//  Side Effect: N/A
	//
	virtual Position calculateMove(const Game& game,
		const Position& player_position) = 0;


protected:
	//
	//  calculateToPosition
	//
	//  Purpose: To calculate this Monster's next move.
	//  Parameter(s):
	//    <1> Game: The Game that this Monster is moving around in
	//    <2> player_position: The player's current position
	//  Precondition: N/A
	//  Returns: The new position for this Monster.  If this is the
	//           same as player_position, this Monster is attacking
	//           the player instead of moving.
	//  Side Effect: N/A
	//
	Position calculateToPosition(
		const Game& game,
		const Position& player_position) const;
	int health;
	int damage;
	unsigned int points;
	

private:
	Position position;
};
