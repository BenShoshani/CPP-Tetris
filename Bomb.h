#ifndef _BOMB_H
#define _BOMB_H
#include "Shape.h"

class Bomb : public Shape
{
	Point* holes = NULL;
public:
	enum SIZE { ROWS = 1, COLS = 1 };
	Bomb(Point start, char sign) : Shape(start, (int)ROWS, (int)COLS, sign) {}
	~Bomb() {};

	virtual void chaeckMoves(bool * left, bool * right, bool * down, Board& board);
	void move(Point::directions direction,Board* board);
	bool chaeckMovesToDown(Board* board);
	void explode(Board& board);
	Point* getHoles() { return holes; }
};

#endif
