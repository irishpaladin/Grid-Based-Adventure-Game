

//
//  Player.h
//
//  Encapsulates a module to represent the player in a
//    grid-based game.
//	last revise: Mar 10 11pm
//

#include "Position.h"

class Player {
private:
	int health;
	int damage;
	Position position;
	unsigned int score;
	unsigned int total_move_cost;
public:
	Player();
	//
	//Player
	//
	//  Purpose: To initialize a Player at a specific position.
	//  Parameter(s):
	//    <1> start: The starting position for player
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: Player player is initialized to have default
	//               values and to be at the position start.
	//
	Player(const Position& start);
	//
	//  playerIsDead
	//
	//  Purpose: To determine if a Player is dead.
	//  Parameter(s):
	//    N/A
	//  Precondition(s): N/A
	//  Returns: Whether Player player is dead
	//  Side Effect: N/A
	//
	bool isDead() const;
	//
	//  getHealth
	//
	//  Purpose: To determine a Player's current health.
	//  Parameter(s):N/A
	//  Precondition(s): N/A
	//  Returns: Player player's current health.
	//  Side Effect: N/A
	//
	int getHealth() const;
	//
	//  getDamage
	//
	//  Purpose: To determine how much damage a Player deals when
	//           attacking.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: How much damage Player player deals when attacking.
	//  Side Effect: N/A
	//
	int getDamage() const;
	//
	//	getScore
	//
	//  Purpose: To determine a Player's current score.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: Player player's current score.
	//  Side Effect: N/A
	//
	unsigned int getScore() const;
	//
	//  getTotalMoveCost
	//
	//  Purpose: To determine a Player's total movement cost.
	//  Parameter(s):N/A
	//  Precondition(s): N/A
	//  Returns: Player player's total movement cost.
	//  Side Effect: N/A
	//
	unsigned int getTotalMoveCost() const;
	//
	//  getPosition
	//
	//  Purpose: To determine a Player's current position.
	//  Parameter(s):N/A
	//  Precondition(s): N/A
	//  Returns: Player player's current position.
	//  Side Effect: N/A
	//
	const Position& getPosition() const;
	//
	//  setPosition
	//
	//  Purpose: To change a Player's current position.
	//  Parameter(s):
	//    <1> p: The new position
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: The current position of Player player is set to
	//               p.
	//
	void setPosition(const Position& p);
	//
	//  receiveDamage
	//
	//  Purpose: To reduce a Player's health.
	//  Parameter(s):
	//    <1> amount: The amount to reduce player's health by
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: The health of Player player is reduced by
	//               amount.
	//
	void receiveDamage(int amount);
	//
	//  increaseScore
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
	void increaseScore(unsigned int amount);
	//
	//  increaseTotalMoveCost
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
	void increaseTotalMoveCost(unsigned int amount);
};

