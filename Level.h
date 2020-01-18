
/*
Position.h
Stephanie Irish Paladin
last revise: March 10 11pm
*/




#include "Position.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>


using namespace std;

//global variable declarations
const int ROWS = 20, COLUMNS = 60;


const unsigned int
EMPTY = 0,
ROCKY = 1,
ROUGH = 2,
WALL = 3,
PLAYER_START = 4,
PLAYER_GOAL = 5,
MONSTER_START = 6,
ATTACKER_START = 7,
DRONE_START = 8;

class Level {
private:
	unsigned int level[ROWS][COLUMNS];
	 int monster_count;

public:
	Level();
	//function definition
	//
	//  Level
	//
	//  Purpose: To open the file and store the map in an array
	//  Parameter(s):
	//    <1> str: The file name of th emap
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: The map is loaded in the array
	//
	Level(const string str);
	//
	//  getMonsterStart
	//
	//  Purpose: To return the starting position of the Monster
	//  Parameter(s):N/A
	//  Precondition: N/A
	//  Returns: The starting position of the monster
	//  Side Effect: N/A
	//
	Position getMonsterStart()const;
	//
	//  getPlayerStart
	//
	//  Purpose: Returns the starting position of the Player
	//  Parameter(s):N/A
	//  Precondition: N/A
	//  Returns: The starting position of the Player
	//  Side Effect: N/A
	//
	Position getPlayerStart()const;
	//
	//  getCost
	//
	//  Purpose: Returns the traversal cost of a certain array element
	//  Parameter(s):
	//    <1> p: The position in the map
	//  Precondition: N/A
	//  Returns: Traversal cost of a certain array position
	//  Side Effect: N/A
	//
	//returns the traversal cost of a certain array element
	unsigned int getCost(const Position & p)const;
	//
	//  print
	//
	//  Purpose: To display the level
	//    <1> str: The file name of th emap
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: N/A
	//
	//void print(const Position & m_position, const Position & p_position)const;
	//
	//  isWall
	//
	//  Purpose: To open the file and store the map in an array
	//  Parameter(s):
	//    <1> p: The file name of the map
	//  Precondition: N/A
	//  Returns: True or false if the position given has wall or not
	//  Side Effect: N/A
	//
	bool isWall(const Position& p)const;

	unsigned int getMonsterCount()const;
	unsigned int getValue(const Position& p) const;
	void printAtPosition(const Position& p) const;
	bool isGoalPosition(const Position& p) const;

};


