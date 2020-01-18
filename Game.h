
/*
Position.h
Stephanie Irish Paladin
last revise: March 10 11pm
*/

#include <string>
#include "Player.h"
#include "Monster.h"
#include "Level.h"
#include "Position.h"

const int MONSTER_COUNT_MAX = 100;
class Game {
private:
	Level level;
	Monster monster[MONSTER_COUNT_MAX];
	Player player;


public:
	Game(const string& file_name);

	bool isOver() const;

	void print() const;

	void tryMoveNorth();

	void tryMoveSouth();

	void tryMoveEast();

	void tryMoveWest();

	void updateMonsters();

	bool isBlockedForMonster(const Position& position) const;

};

