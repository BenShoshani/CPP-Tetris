#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(int x1 = 1, int y1 = 1)
{
	x = x1;
	y = y1;
	dirX = 0;
	dirY = 1;
}

void Point::move(directions newDirection)
{

	switch (newDirection)
	{
	case LEFT:
	{
		dirX = -1;
		dirY = 0;
		break;
	}
	case RIGHT:
	{
		dirX = 1;
		dirY = 0;
		break;
	}
	case DOWN:
	{
		dirX = 0;
		dirY = 2;
		break;
	}
	case UP:
	{
		dirX = 0;
		dirY = -1;
		break;
	}
	default:
	{
		dirX = 0;
		dirY = 1;
	}
	}
	x = x + dirX;
	y = y + dirY;
}

void Point::draw(char c)
{
	gotoxy(x, y);
	cout << c;
}
void Point::rotate90Point(float cx, float cy,int dir)
{
	float angle = (float)(dir*(M_PI / 2));
	float s = sin(angle);
	float c = cos(angle);

	// translate point back to origin:
	this->setX((int)(this->getX() - cx));
	this->setY((int)(this->getY() - cy));

	// rotate point
	float xnew = this->getX() * c - this->getY() * s;
	float ynew = this->getX() * s + this->getY() * c;

	// translate point back:
	this->setX((int)(xnew + cx+0.5));
	this->setY((int)(ynew + cy+0.5));
}