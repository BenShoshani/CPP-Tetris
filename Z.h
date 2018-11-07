#ifndef _Z_H
#define _Z_H
#include "Shape.h"

class Z : public Shape
{
public:
	enum STATES { ZLEFT, ZUP};
	enum SIZE { ROWS = 2, COLS = 3 };
private:

	Point* holes;
	STATES state;
public:
	Z(Point start, char sign);
	~Z() {};

	void chaeckMoves(bool * left, bool * right, bool * down, Board& board);
	void move(Point::directions direction, Board* board);
	bool chaeckMovesToDown(Board* board);
	void explode(Board& board) {};
	Point* getHoles() { return holes; }
};

#endif