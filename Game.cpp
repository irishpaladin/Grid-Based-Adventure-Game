



/*
Position.h
Stephanie Irish Paladin
last revise: March 10 11pm
*/


#include "Game.h"
#include <string>

Game::Game(const string& file_name){
	//Loading the level
	level=Level(file_name);
	

	//Initializing Monster
	int next=0;
	for (int i = 0; i < ROWS; i++) {
		for (int j=0; j < COLUMNS; j++) {
			if (level.getValue(toPosition(i,j)) == MONSTER_START) {
				monster[next] = Monster(toPosition(i,j));
				next++;
			}
		}
	}
	

	/*monster=Monster(m_position);
	m_position = level.getMonsterStart();
	monster.setPosition(m_position);
	*/

	//Initializing Player
	player = Player(level.getPlayerStart());
	/*player=Player(p_position);
	p_position = level.getPlayerStart();
	player.setPosition(p_position);
	*/
	//playerInit(player, p_player);
}

bool Game::isOver() const {
	if(player.isDead())return true;
	if (level.isGoalPosition(player.getPosition()))return true;
	return false;
}

void Game::print() const {
	//level.print(monster.getPosition(), player.getPosition());
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

	//printing
	cout << "\n+------------------------------------------------------------+" << endl;
	bool print = false;
	Position curr_pos;
	for (int i = 0; i < ROWS; i++) {
		cout << "|";
		for (int j = 0; j < COLUMNS; j++) {
			
			curr_pos = toPosition(i, j);
			print = false;

			if (areEqual(player.getPosition(), curr_pos)&&!player.isDead()) {
				cout << '@';
				print = true;
			}
			for (unsigned int i = 0; i < level.getMonsterCount(); i++) {
				if (!print&&areEqual(monster[i].getPosition(), curr_pos) && !monster[i].isDead()) {
					cout << 'M';
					print = true;
				}
			}
			if(!print){
				//cout << terrain_char[level[i][j]];
				level.printAtPosition(curr_pos);
			}


		}
		cout << "|" << endl;
	}
	cout << "+------------------------------------------------------------+" << endl;


	cout << "Health: " << player.getHealth() << "\t"
		<< " Cost: " << player.getTotalMoveCost() << "\t"
		<< " Score: " << player.getScore() << endl;
}

void Game::tryMoveNorth() {
	//reinitialize the new position of player
	Position p_newpos = player.getPosition();
	p_newpos = toPosition(player.getPosition().row - 1, player.getPosition().column);

	bool has_atk = false;
	for (unsigned int i = 0; i < level.getMonsterCount(); i++) {
		if (areEqual(monster[i].getPosition(), p_newpos) && !monster[i].isDead()) {
			monster[i].receiveDamage(player.getDamage());
			if (monster[i].isDead()) {
				player.increaseScore(monster[i].getPoints());
			}
		}
	}
	
	//checks if move is valid
	if (isValid(p_newpos) == true && !level.isWall(p_newpos)&&!has_atk) {
		player.increaseTotalMoveCost(level.getCost(p_newpos));
		player.setPosition(p_newpos);
	}
	
}

void Game::tryMoveSouth() {
	//reinitialize the new position of player
	Position p_newpos = player.getPosition();
	p_newpos = toPosition(player.getPosition().row + 1, player.getPosition().column);


	bool has_atk = false;
	for (unsigned int i = 0; i < level.getMonsterCount(); i++) {
		if (areEqual(monster[i].getPosition(), p_newpos) && !monster[i].isDead()) {
			monster[i].receiveDamage(player.getDamage());
			if (monster[i].isDead()) {
				player.increaseScore(monster[i].getPoints());
			}
		}
	}

	//checks if move is valid
	if (isValid(p_newpos) == true && !level.isWall(p_newpos) && !has_atk) {
		player.increaseTotalMoveCost(level.getCost(p_newpos));
		player.setPosition(p_newpos);
	}

}

void Game::tryMoveEast() {
	//reinitialize the new position of player
	Position p_newpos = player.getPosition();
	p_newpos = toPosition(player.getPosition().row, player.getPosition().column + 1);
	
	//checks if move is valid
	bool has_atk = false;
	for (unsigned int i = 0; i < level.getMonsterCount(); i++) {
		if (areEqual(monster[i].getPosition(), p_newpos) && !monster[i].isDead()) {
			monster[i].receiveDamage(player.getDamage());
			if (monster[i].isDead()) {
				player.increaseScore(monster[i].getPoints());
			}
		}
	}

	//checks if move is valid
	if (isValid(p_newpos) == true && !level.isWall(p_newpos) && !has_atk) {
		player.increaseTotalMoveCost(level.getCost(p_newpos));
		player.setPosition(p_newpos);
	}
}

void Game::tryMoveWest() {
	//reinitialize the new position of player
	Position p_newpos = player.getPosition();
	p_newpos = toPosition(player.getPosition().row, player.getPosition().column - 1);
	
	//checks if move is valid
	bool has_atk = false;
	for (unsigned int i = 0; i < level.getMonsterCount(); i++) {
		if (areEqual(monster[i].getPosition(), p_newpos) && !monster[i].isDead()) {
			monster[i].receiveDamage(player.getDamage());
			if (monster[i].isDead()) {
				player.increaseScore(monster[i].getPoints());
			}
		}
	}

	//checks if move is valid
	if (isValid(p_newpos) == true && !level.isWall(p_newpos) && !has_atk) {
		player.increaseTotalMoveCost(level.getCost(p_newpos));
		player.setPosition(p_newpos);
	}
}

void Game::updateMonsters() {
	//initialize monsters's new position
	Position p_newpos = player.getPosition();
	for (unsigned int i = 0; i < level.getMonsterCount(); i++) {
		if (!monster[i].isDead()) {
			Position m_newpos = monster[i].calculateMove(*this, p_newpos);
			if (isValid(m_newpos) == true) {
				//if onster attack player
				if (areEqual(m_newpos, p_newpos)) {
					player.receiveDamage(monster[i].getDamage());
				}
				//if not
				else {
					monster[i].setPosition(m_newpos);
				}
			}
			else {
			}
		}
		//if monster is dead
		else {
			monster[i].setPosition(toPosition(-1, -1));
		}
	}
	
	
}

bool Game::isBlockedForMonster(const Position& position) const {
	for (unsigned int i = 0; i < level.getMonsterCount(); i++) {
		if (areEqual(monster[i].getPosition(), position)) {
			return true;
		}
	}
	if (level.isWall(position)) {
		return true;
	}
	return false;

}