#ifndef _POINT_H
#define _POINT_H
#include "Gotoxy.h"
#include <iostream>
#include <string>
#include <string.h>
# define M_PI           3.14159265358979323846  
using namespace std;
class Point {

private:
	int x, y;
	int dirX, dirY;

public:

	enum directions { LEFT = 'g', RIGHT = 'j', UP = 'y', DOWN = 'h', STOPJ = 's', STAND };
	enum limits { LIMRIGHT = 10, LIMLEFT = 0, LIMDOWN = 15, LIMUP = 3 };
	Point(int x1, int y1);
	Point() {};
	~Point() {};

	void move(directions newDirection);
	void draw(char c);
	void setX(int newX) { x = newX; };
	void setY(int newY) { y = newY; };
	int getX() { return x; };
	int getY() { return y; };
	void rotate90Point(float cx, float cy, int dir);
};
#endif 

