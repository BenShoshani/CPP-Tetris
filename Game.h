#ifndef _GAME_H
#define _GAME_H
#include "Shape.h"
#include "Joker.h"
#include "Bomb.h"
#include "Line.h"
#include "Square.h"
#include "Board.h"
#include "L.h"
#include "Plus.h"
#include "Z.h"
class Game
{
private:
	Board board;

	bool lost(Shape *shape);
	int sleepSpeed = 700;
	char eatBuffer();
	Shape::eShapes chooseShape();
public:
	enum gameMamger { ESC = '9', START = '1', PAUSE_AND_RESUME = '2', SPEED_UP = '3', SPEED_DOWN = '4', START_X=4, START_Y=4 };
	enum numOfShapes {NUM_OF_SHAPES = 7};
	Game() {}
	~Game() {}
	void run();
};

#endif 