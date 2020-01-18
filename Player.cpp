//
//  Player.cpp
//

//  Updated by Stephanie Irish Paladin, 2019-04-08, 3am

#include <cassert>

#include "Position.h"
#include "Level.h"
#include "Player.h"

static const int STARTING_HEALTH = 40;
static const int DAMAGE = 2;


Player::Player()
	:health(0),
	damage(0),
	position(toPosition(0,0)),
	score(0),
	total_cost(0) {

}


Player::Player(const Player& original) 
	:health(original.getHealth()),
	damage(original.getDamage()),
	position(original.getPosition()),
	score(original.getScore()),
	total_cost(original.getTotalMoveCost())
{

}

Player::~Player() {
}

Player& Player::operator= (const Player& original) {
	health = original.getHealth();
	damage = original.getDamage();
	position = original.getPosition();
	score = original.getScore();
	total_cost = original.getTotalMoveCost();
	return *this;

}

Player::Player(const Position& start)
	: health(STARTING_HEALTH),
	damage(DAMAGE),
	position(start),
	score(0),
	total_cost(0)
{
	assert(isValid(start));
}



bool Player::isDead() const
{
	if (health <= 0)
		return true;
	return false;
}

int Player::getHealth() const
{
	return health;
}

int Player::getDamage() const
{
	return damage;
}

unsigned int Player::getScore() const
{
	return score;
}

unsigned int Player::getTotalMoveCost() const
{
	return total_cost;
}

const Position& Player::getPosition() const
{
	return position;
}



void Player::setPosition(const Position& p)
{
	assert(isValid(p));

	position = p;
}

void Player::receiveDamage(int amount)
{
	health = health - amount;
}

void Player::increaseScore(unsigned int amount)
{
	score = score + amount;
}

void Player::increaseTotalMoveCost(unsigned int amount)
{
	total_cost = total_cost + amount;
}
