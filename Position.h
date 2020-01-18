
/*
Position.h
Stephanie Irish Paladin
last revise: March 10 11pm
*/

#ifndef POSITION_H
#define POSITION_H


struct Position {
	int row;
	int column;
};
Position toPosition(int row, int column);
bool areEqual(const Position& p1, const Position& p2);
bool isValid(const Position& p1);
double calculateDistance(const Position& p1, const Position& p2);
#endif