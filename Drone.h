//
//  Drone.h
//
//  Encapsulates a module to represent a type of (enemy) monster in a
//    grid-based game.
//

#pragma once

#include "Position.h"
#include "Monster.h"

class Game;



class Drone :public Monster
{
private:
	char direction;
public:
	//
	//  Default Constructor
	//
	//  Purpose: To create a dead Drone
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: A new Drone is initialized to have 0 health
	//               at position (0, 0).
	//
	Drone();

	//
	//  Constructor
	//
	//  Purpose: To create a Drone at a specific position.
	//  Parameter(s):
	//    <1> start: The starting position for the Drone
	//  Precondition:
	//    <1> isValid(start)
	//  Returns: N/A
	//  Side Effect: A new Drone is initialized to have default
	//               values and be at position start.
	//
	Drone(const Position& start);

	//
	//  Copy Constructor
	//
	//  Purpose: To create an Drone base on existing Drone
	//  Parameter(s):
	//    <1> original: Drone that will be copied
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: The Drone will be initialized based on 'original' Drone
	//
	Drone(const Drone& original);

	//
	//  Destructor
	//
	//  Purpose: Return all the used memory
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: N/A
	//
	virtual ~Drone();

	//
	//  Assignment Operator
	//
	//  Purpose: To reinitialize Drone base on existing Drone
	//  Parameter(s):
	//    <1> original: Drone that will be copied
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: 'original' Drone will be copied to the current Drone
	Drone& operator= (const Drone& original);

	//
	//  getDisplayChar
	//
	//  Purpose: To display the indicated character for the Drone
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: The character to be used to display this Drone
	//  Side Effect: N/A
	//
	virtual char getDisplayChar() const;

	//
	//  getClone
	//
	//  Purpose: To create a dynamically allocated copy of the current Drone, using the override in the correct subclass
	//  Parameter(s): N/A
	//  Precondition: N/A
	//  Returns: A pointer to a Drone
	//  Side Effect: N/A
	//
	virtual Monster* getClone() const;

	//
	//  calculateMove
	//
	//  Purpose: To calculate this Drone's next move.
	//  Parameter(s):
	//    <1> Game: The Game that this Drone is moving around in
	//    <2> player_position: The player's current position
	//  Precondition: N/A
	//  Returns: The new position for this Drone.  If this is the
	//           same as player_position, this Drone is attacking
	//           the player instead of moving.
	//  Side Effect: N/A
	//
	virtual Position calculateMove(const Game& game,
		const Position& player_position);


};
