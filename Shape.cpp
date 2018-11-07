#include "Shape.h"

Shape::Shape(Point start, int rows, int cols, char sign)
{
	this->sign = sign;
	body = new Point*[rows];
	for (int i = 0; i < rows; i++)
		body[i] = new Point[cols];
	this->rows = rows;
	this->cols = cols;
	putCoord(start);
}
void Shape::draw(int rows,int cols,Point* holes)
{
	gotoxy(body[0][0].getX(), body[0][0].getY());
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			gotoxy(body[i][j].getX(), body[i][j].getY());
			if (holes == NULL)
				cout << sign;
			else
			{
				if (!(holes[0].getX() == i && holes[0].getY() == j) && !(holes[1].getX() == i && holes[1].getY() == j))
					cout << sign;
			}
		}
	}
}


void Shape::putCoord(Point start)
{
	int xStart = start.getX();
	int yStart = start.getY();

	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			body[i][j].setY(yStart + i);
			body[i][j].setX(xStart + j);
		}
	}
}
bool Shape::checkLimX(Point::directions keyPressed,int rows,int cols)
{
	if (keyPressed == Point::DOWN)
		return false;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if ((body[i][j].getX() + 1) == Point::LIMRIGHT && keyPressed == Point::RIGHT)
				return false;

			else if ((body[i][j].getX() - 1) == Point::LIMLEFT && keyPressed == Point::LEFT)
				return false;
		}
	}
	return true;
}

bool Shape::checkLimY(int rows,int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if ((body[i][j].getY() + 1) == Point::LIMDOWN)
				return false;
		}
	}
	return true;
}

void Shape::deleteShape(int rows)
{
	for (int i = 0; i < rows; i++)
		delete[] body[i];
	delete[] body;
	
}
Point ** Shape::getBody()
{
	return body;
}
//void Shape::chaeckMoves(bool * left, bool * right, bool * down, Shape::eShapes randShape, Board& board)
//{
//	switch (randShape)
//	{
//	case Shape::SQUARE:
//	{
//		shape = new Square(start, '*');
//		break;
//	}
//	case Shape::BOMB:
//	{
//		shape = new Bomb(start, '@');
//		break;
//	}
//	case Shape::JOKER:
//	{
//		shape = new Joker(start, '*');
//		break;
//	}
//	case Shape::LINE:
//	{
//		shape = new Line(start, '*');
//		break;
//	}
//	}
//}