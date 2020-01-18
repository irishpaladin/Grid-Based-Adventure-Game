
/*
Position.cpp
Stephanie Irish Paladin
last revise: Feb 16 6:30pm
*/



#include "Position.h"
#include"Level.h"
#include <cmath>

Position toPosition(int row, int column) {
	Position pos;
	pos.row = row;
	pos.column = column;
	return pos;
}
bool areEqual(const Position& p1, const Position& p2) {
	if (p1.column != p2.column)return false;
	if (p1.row != p2.row)return false;
	return true;
}
bool isValid(const Position& p1 ) {
	if (p1.row < 0 || p1.row >= ROWS)return false;
	if (p1.column < 0 || p1.column >= COLUMNS)return false;
	
	return true;
}
double calculateDistance(const Position& p1, const Position& p2) {
	return sqrt(pow(p2.row - p1.row, 2) + pow(p2.column - p1.column, 2));
}