//
//  Attacker.h
//
//  Encapsulates a module to represent a type of (enemy) monster in a
//    grid-based game.
//

#pragma once

#include "Position.h"
#include "Monster.h"

class Game;



class Sentry :public Monster
{
private:
	Position position;
public:
	//
	//  Default Constructor
	//
	//  Purpose: To create a dead Sentry
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: A new Sentry is initialized to have 0 health
	//               at position (0, 0).
	//
	Sentry();

	//
	//  Constructor
	//
	//  Purpose: To create a Sentry at a specific position.
	//  Parameter(s):
	//    <1> start: The starting position for the Sentry
	//  Precondition:
	//    <1> isValid(start)
	//  Returns: N/A
	//  Side Effect: A new Sentry is initialized to have default
	//               values and be at position start.
	//
	Sentry(const Position& start);

	//
	//  Copy Constructor
	//
	//  Purpose: To create a Sentry base on existing Sentry
	//  Parameter(s):
	//    <1> original: Sentry that will be copied
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: The Sentry will be initialized based on 'original' Sentry
	//
	Sentry(const Sentry& original);

	//
	//  Destructor
	//
	//  Purpose: Return all the used memory
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: N/A
	//
	virtual ~Sentry();

	//
	//  Assignment Operator
	//
	//  Purpose: To reinitialize Sentry base on existing Sentry
	//  Parameter(s):
	//    <1> original: Sentry that will be copied
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: 'original' Sentry will be copied to the current Sentry
	
	Sentry& operator= (const Sentry& original);

	//
	//  getDisplayChar
	//
	//  Purpose: To display the indicated character for the Sentry
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: The character to be used to display this Sentry
	//  Side Effect: N/A
	//
	virtual char getDisplayChar() const;

	//
	//  getClone
	//
	//  Purpose: To create a dynamically allocated copy of the current Monster, using the override in the correct subclass
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: A pointer to a Sentry
	//  Side Effect: N/A
	//
	virtual Monster* getClone() const;

	//
	//  calculateMove
	//
	//  Purpose: To calculate this Sentry's next move.
	//  Parameter(s):
	//    <1> Game: The Game that this Sentry is moving around in
	//    <2> player_position: The player's current position
	//  Precondition: N/A
	//  Returns: The new position for this Sentry.  If this is the
	//           same as player_position, this Sentry is attacking
	//           the player instead of moving.
	//  Side Effect: N/A
	//
	virtual Position calculateMove(const Game& game,
		const Position& player_position);


};
