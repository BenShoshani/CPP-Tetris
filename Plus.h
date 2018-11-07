#ifndef _PLUS_H
#define _PLUS_H
#include "Shape.h"

class Plus : public Shape
{
public:
	enum STATES { BOLTUP, BOLTRIGHT, BOLTDOWN, BOLTLEFT };
	enum SIZE { ROWS = 2, COLS = 3 };
private:

	Point* holes;
	STATES state;
public:
	Plus(Point start, char sign);
	~Plus() {};

	void chaeckMoves(bool * left, bool * right, bool * down, Board& board);
	void move(Point::directions direction, Board* board);
	bool chaeckMovesToDown(Board* board);
	void explode(Board& board) {};
	Point* getHoles() { return holes; }
};

#endif