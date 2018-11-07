#ifndef _L_H
#define _L_H
#include "Shape.h"

class L : public Shape
{
public:
	enum STATES { BOLTUP, BOLTRIGHT, BOLTDOWN, BOLTLEFT };
	enum SIZE { ROWS = 2, COLS = 3 };
private:

	Point* holes;
	STATES state;
public:
	L(Point start, char sign);
	~L() {};

	void chaeckMoves(bool * left, bool * right, bool * down, Board& board);
	void move(Point::directions direction, Board* board);
	bool chaeckMovesToDown(Board* board);
	void explode(Board& board) {};
	Point* getHoles() { return holes; }
};

#endif