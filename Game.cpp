//
//  Game.cpp
//
//  Updated by Stephanie Irish Paladin, 2019-04-08, 3am


#include <cassert>
#include <string>
#include <iostream>

#include "Position.h"
#include "Level.h"
#include "Player.h"
#include "Monster.h"
#include "Attacker.h"
#include "Drone.h"
#include "Sentry.h"
#include "Game.h"

using namespace std;



Game::Game()
	: level(),
	player(level.getPlayerStart()),
	monsters(NULL)  // will be set below
{
	monsters = new Monster*[0];

	assert(invariant());
}

Game::Game(const std::string& file_name)
	: level(file_name),
	player(level.getPlayerStart()),
	monsters(NULL)  // will be set by initMonsters
{
	initMonsters();

	assert(invariant());
}

Game::Game(const Game& original)
	: level(original.level),
	player(original.player),
	monsters(NULL)  // will be set by copyMonsters
{
	assert(original.invariant());

	copyMonsters(original);

	assert(invariant());
	assert(original.invariant());
}

Game :: ~Game()
{
	assert(invariant());

	deleteMonsters();
}

Game& Game :: operator= (const Game& original)
{
	assert(invariant());
	assert(original.invariant());

	if (&original != this)
	{
		deleteMonsters();

		level = original.level;
		player = original.player;
		copyMonsters(original);
	}

	assert(invariant());
	assert(original.invariant());
	return *this;
}



bool Game::isOver() const
{
	assert(invariant());

	if (player.isDead())
		return true;
	if (level.isGoalPosition(player.getPosition()))
		return true;
	return false;
}

void Game::print() const
{
	assert(invariant());

	// print top outline
	cout << "+";
	for (int c = 0; c < COLUMNS; c++)
		cout << "-";
	cout << "+" << endl;

	for (int r = 0; r < ROWS; r++)
	{
		// print left outline
		cout << '|';

		// print level contents
		for (int c = 0; c < COLUMNS; c++)
		{
			Position here = toPosition(r, c);
			bool is_printed = false;

			if (!player.isDead() &&
				areEqual(player.getPosition(), here))
			{
				cout << '@';
				is_printed = true;
			}
			for (unsigned int i = 0; i < level.getMonsterCount(); i++)
			{
				if (!is_printed &&
					!monsters[i]->isDead() &&
					areEqual(monsters[i]->getPosition(), here))
				{
					cout << monsters[i]->getDisplayChar();
					is_printed = true;
				}
			}
			if (!is_printed)
				level.printAtPosition(here);
		}

		// print right outline
		cout << '|' << endl;
	}

	// print bottom outline
	cout << "+";
	for (int c = 0; c < COLUMNS; c++)
		cout << "-";
	cout << "+" << endl;

	cout
		<< "Health: " << player.getHealth()
		<< "    Move cost: " << player.getTotalMoveCost()
		<< "    Score: " << player.getScore() << endl;
}



void Game::tryMoveNorth()
{
	assert(invariant());

	Position new_player_position = player.getPosition();
	new_player_position.row -= 1;

	tryMove(new_player_position);

	assert(invariant());
}

void Game::tryMoveSouth()
{
	assert(invariant());

	Position new_player_position = player.getPosition();
	new_player_position.row += 1;

	tryMove(new_player_position);

	assert(invariant());
}

void Game::tryMoveEast()
{
	assert(invariant());

	Position new_player_position = player.getPosition();
	new_player_position.column += 1;

	tryMove(new_player_position);

	assert(invariant());
}

void Game::tryMoveWest()
{
	assert(invariant());

	Position new_player_position = player.getPosition();
	new_player_position.column -= 1;

	tryMove(new_player_position);

	assert(invariant());
}

void Game::updateMonsters()
{
	assert(invariant());

	for (unsigned int i = 0; i < level.getMonsterCount(); i++)
		if (!monsters[i]->isDead())
		{
			Position player_position = player.getPosition();
			Position new_monster_position = monsters[i]->calculateMove(*this, player_position);
			assert(isValid(new_monster_position));

			if (areEqual(new_monster_position, player_position))
			{
				// monster is attacking the player
				player.receiveDamage(monsters[i]->getDamage());
			}
			else
			{
				// monster is moving
				monsters[i]->setPosition(new_monster_position);
			}
		}

	assert(invariant());
}

bool Game::isBlockedForMonster(const Position& position) const
{
	assert(invariant());
	assert(isValid(position));

	if (level.isWall(position))
		return true;
	for (unsigned int i = 0; i < level.getMonsterCount(); i++)
	{
		if (!monsters[i]->isDead() &&
			areEqual(position, monsters[i]->getPosition()))
		{
			return true;
		}
	}
	return false;
}



void Game::initMonsters()
{
	assert(monsters == NULL);

	monsters = new Monster*[level.getMonsterCount()];

	unsigned int next_monster = 0;
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLUMNS; c++)
		{
			Position pos = toPosition(r, c);
			if (level.getValue(pos) == SENTRY_START)
			{
				monsters[next_monster] = new Sentry(pos);
				next_monster++;
			}	
			else if (level.getValue(pos) == DRONE_START)
			{
				monsters[next_monster] = new Drone(pos);
				next_monster++;
			}
			else if (level.getValue(pos) == ATTACKER_START)
			{
				monsters[next_monster] = new Attacker(pos);
				next_monster++;
			}
		}
	assert(next_monster == level.getMonsterCount());

	assert(monsters != NULL);
}

void Game::tryMove(const Position& position)
{
	assert(invariant());

	for (unsigned int i = 0; i < level.getMonsterCount(); i++)
	{
		if (!monsters[i]->isDead() &&
			areEqual(position, monsters[i]->getPosition()))
		{
			// player is attacking the monster
			monsters[i]->receiveDamage(player.getDamage());
			if (monsters[i]->isDead())
				player.increaseScore(monsters[i]->getPoints());

			assert(invariant());
			return;
		}
	}

	if (isValid(position) && !level.isWall(position))
	{
		// player made a valid move
		unsigned int cost = level.getCost(position);
		player.increaseTotalMoveCost(cost);
		player.setPosition(position);
	}
	else
	{
		// player made an invalid move
		// do nothing
	}

	assert(invariant());
}

void Game::copyMonsters(const Game& original)
{
	assert(monsters == NULL);

	monsters = new Monster*[level.getMonsterCount()];
	for (unsigned int i = 0; i < level.getMonsterCount(); i++)
		monsters[i] = original.monsters[i]->getClone();

	assert(monsters != NULL);
}

void Game::deleteMonsters()
{
	assert(monsters != NULL);

	for (unsigned int i = 0; i < level.getMonsterCount(); i++)
		delete monsters[i];
	delete[] monsters;
	monsters = NULL;

	assert(monsters == NULL);
}

bool Game::invariant() const
{
	if (monsters == NULL)
		return false;
	return true;
}
