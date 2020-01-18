



/*
Position.h
Stephanie Irish Paladin
last revise: March 10 11pm
*/




#include "Game.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;
int main()
{
	string file;
	cout << "Enter the name of the file to load, including the file extension." << endl;
	getline(cin, file);
	ifstream inD(file);
	if (!inD) {
		cout << "File not found" << endl;
		return 1;
	}
	else {
		
		Game game(file);
		char direction = '.';
		while (direction != 'q'&&direction != 'Q' && !game.isOver()) {
			game.print();
			cout << "Next? ";
			cin >> direction;
			
			switch (direction)
			{
			case 'e':
			case 'E': game.tryMoveEast();
				break;
			case 'w':
			case 'W': game.tryMoveWest();
				break;
			case 's':
			case 'S': game.tryMoveSouth();
				break;
			case 'n':
			case 'N': game.tryMoveNorth();
				break;
			}
			game.updateMonsters();
			
		}
		game.print();
		

		/*
		//Loading the level
		Level level(file);

		//Initializing Monster
		Position p_monster;
		Monster monster(p_monster);
		p_monster = level.getMonsterStart();
		monster.setPosition(p_monster);

		//Initializing Player
		Position p_player;
		Player player(p_player);
		p_player = level.getPlayerStart();
		player.setPosition(p_player);
		//playerInit(player, p_player);

		*/


		/*
		//Game starts
		char direction = '.';
		bool iswall = false;
		while (direction != 'Q' && direction != 'q' && !player.isDead()) {
			//get the position of monster
			Position curr_mons = monster.getPosition();
			Position curr_plyr = player.getPosition();
			level.print(curr_mons, curr_plyr);
			unsigned int cost = level.getCost(player.getPosition());

			//getcost regardless of direction
			if (direction == 'e' || direction == 'E' ||
				direction == 'w' || direction == 'W' ||
				direction == 's' || direction == 'S' ||
				direction == 'n' || direction == 'N')
			{
				if (!iswall)player.increaseTotalMoveCost(cost);
			}

			//Print Health, total move cost and score
			cout << "Health: " << player.getHealth() << "\t"
				<< " Cost: " << player.getTotalMoveCost() << "\t"
				<< " Score: " << player.getScore() << endl;
			cout << "Next? ";
			cin >> direction;
			cin.ignore(1000, '\n');

			//reinitialize the new position of player
			Position p_newpos = player.getPosition();
			switch (direction)
			{
			case 'e':
			case 'E': p_newpos = toPosition(player.getPosition().row, player.getPosition().column + 1);
				break;
			case 'w':
			case 'W': p_newpos = toPosition(player.getPosition().row, player.getPosition().column - 1);
				break;
			case 's':
			case 'S': p_newpos = toPosition(player.getPosition().row + 1, player.getPosition().column);
				break;
			case 'n':
			case 'N': p_newpos = toPosition(player.getPosition().row - 1, player.getPosition().column);
				break;
			}

			iswall = level.isWall(p_newpos);
			//checks if move is valid
			if (isValid(p_newpos) == true && !level.isWall(p_newpos)) {
				//if player attack monster
				if (areEqual(monster.getPosition(), p_newpos) == true && !monster.isDead()) {
					monster.receiveDamage(player.getDamage());
					if (monster.isDead()) {
						player.increaseScore(monster.getPoints());
					}
				}
				//if not
				else {
					player.setPosition(p_newpos);
				}
			}

			//initialize monsters's new position
			p_newpos = player.getPosition();
			if (!monster.isDead()) {
				Position m_newpos = monster.calculateMove(level, p_newpos);
				if (isValid(m_newpos) == true) {
					//if onster attack player
					if (areEqual(m_newpos, p_newpos)) {
						player.receiveDamage(monster.getDamage());
					}
					//if not
					else {
						monster.setPosition(m_newpos);
					}
				}
				else {
				}
			}
			//if monster is dead
			else {
				Position m_newpos = toPosition(-1, -1);
				monster.setPosition(m_newpos);
			}
		}
		*/

	}

	return 0;
}
