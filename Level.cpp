

/*
Position.h
Stephanie Irish Paladin
last revise: March 10 11pm
*/


#include "Level.h"
#include "Position.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

static const char terrain_char[] = { ' ', '^', ':', '#', ' ', '*',' ', ' ',' ' };

Level::Level() {
	for (int i = 1; i < ROWS; i++) {
		for (int j = 1; j < COLUMNS; j++) {
			level[ROWS][COLUMNS] = EMPTY;
		}
	}
	level[0][0] = PLAYER_START;
}
//opening the file and soring the respictive value in the array
Level::Level(const string str) {
	ifstream indata(str.c_str());
	char ch;
	indata >> ch;
	monster_count = 0;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			switch (ch)
			{
			case '.':
				level[i][j] = 0;
				break;
			case '^':
				level[i][j] = 1;
				break;
			case ':':
				level[i][j] = 2;
				break;
			case '#':
				level[i][j] = 3;
				break;
			case 'P':
				level[i][j] = 4;
				break;
			case '*':
				level[i][j] = 5;
				break;
			case 'S':
				level[i][j] = 6;
				monster_count++;
				break;
			case 'A':
				level[i][j] = 7;
				break;
			case 'D':
				level[i][j] = 8;
				break;
			}
			indata >> ch;
		}
	}
	indata.close();
}

//returning the monster's row and columns in the 2 int variable
Position Level::getMonsterStart() const {
	Position p;
	p.row = -1;
	p.column = -1;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (level[i][j] == MONSTER_START) {
				p.row = i;
				p.column = j;
				return p;
			}
		}
	}
	return p;
}

//storing the player's row and columns in the 2 int variable
Position Level::getPlayerStart() const {
	Position p;
	p.row = -1;
	p.column = -1;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (level[i][j] == PLAYER_START) {
				p.row = i;
				p.column = j;
				return p;
			}
		}
	}
	return p;
}

//returns the travel cost of a certain array element
unsigned int Level::getCost(const Position & p)const {
	unsigned int cost[] = { 1,2,4,1000,1,1,1,1,1 };
	return cost[level[p.row][p.column]];
}

//prints the level
/*
void Level::print(const Position& m_position, const Position& p_position)const {
	/*char lvl_ch[ROWS][COLUMNS];
	char ch[] = { ' ', '^', ':', '#', ' ', '*',' ', ' ',' ' };
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			lvl_ch[i][j] = ch[level[i][j]];
		}
	}
	//initializing monter and target's position

	lvl_ch[p_position.row][p_position.column] = '@';
	lvl_ch[m_position.row][m_position.column] = 'M';*/
/*
	//printing
	cout << "\n+------------------------------------------------------------+" << endl;
	for (int i = 0; i < ROWS; i++) {
		cout << "|";
		for (int j = 0; j < COLUMNS; j++) {
			if (areEqual(p_position,toPosition(i,j))) {
				cout << '@';
			}
			else if (areEqual(m_position, toPosition(i, j))) {
				cout << 'M';
			}
			else {
				//cout << terrain_char[level[i][j]];
				printAtPosition(toPosition(i, j));
			}

			
		}
		cout << "|" << endl;
	}
	cout << "+------------------------------------------------------------+" << endl;
}
*/


//returns true if the position is a wall
bool Level::isWall(const Position& p) const {
	return level[p.row][p.column] == 3;
}


unsigned int Level::getMonsterCount() const{
	return monster_count;
}
unsigned int Level::getValue(const Position& p) const {
	return level[p.row][p.column];
}
void Level:: printAtPosition(const Position& p) const {
	cout << terrain_char[level[p.row][p.column]];
}

bool Level::isGoalPosition(const Position& p) const {
	return level[p.row][p.column] == PLAYER_GOAL;
}