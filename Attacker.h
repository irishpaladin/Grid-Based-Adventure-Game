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



class Attacker:public Monster
{
public:
	//
	//  Default Constructor
	//
	//  Purpose: To create a dead Attacker
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: A new Attacker is initialized to have 0 health
	//               at position (0, 0).
	//
	Attacker();

	//
	//  Constructor
	//
	//  Purpose: To create a Attacker at a specific position.
	//  Parameter(s):
	//    <1> start: The starting position for the Attacker
	//  Precondition:
	//    <1> isValid(start)
	//  Returns: N/A
	//  Side Effect: A new Attacker is initialized to have default
	//               values and be at position start.
	//
	Attacker(const Position& start);

	//
	//  Copy Constructor
	//
	//  Purpose: To create an Attacker base on existing Attacker
	//  Parameter(s):
	//    <1> original: Attacker that will be copied
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: The Attacker will be initialized based on 'original' Attacker
	//
	Attacker(const Attacker& original);

	//
	//  Destructor
	//
	//  Purpose: Return all the used memory
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: N/A
	//
	virtual ~Attacker();

	//
	//  Assignment Operator
	//
	//  Purpose: To reinitialize Attacker base on existing Attacker
	//  Parameter(s):
	//    <1> original: Attacker that will be copied
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: 'original' Attacker will be copied to the current Attacker
	Attacker& operator= (const Attacker& original);

	//
	//  getDisplayChar
	//
	//  Purpose: To display the indicated character for the monster
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: The character to be used to display this Monster
	//  Side Effect: N/A
	//
	virtual char getDisplayChar() const;

	//
	//  getClone
	//
	//  Purpose: To create a dynamically allocated copy of the current Monster, using the override in the correct subclass
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: A pointer to a monster
	//  Side Effect: N/A
	//
	virtual Monster* getClone() const;

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
		const Position& player_position);


};
