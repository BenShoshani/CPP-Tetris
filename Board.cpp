#include "Board.h"


int Board::score = 0;
int Board::droppedShapes = 0;

Board::Board()
{
	gameBoard = new string[Point::limits::LIMDOWN + 1];
	for (int i = 0; i < Point::limits::LIMDOWN + 1; i++)
	{
		gameBoard[i] = new char[Point::limits::LIMRIGHT + 1];
	}
	
	for (int i = 0; i< Point::limits::LIMDOWN + 1; i++)
	{
		for (int j = 0; j < Point::limits::LIMRIGHT + 1; j++)
		{
			gameBoard[i][j] = (char)CLEAR;
		}
	}
	printLimits();
	createMenu();
}

Board::~Board()
{
	delete[] gameBoard;
}
void Board::copyShapeToBoard(Shape* shape, Point * holes)
{
	for (int i = 0; i < shape->getRows(); i++)
	{
		for (int j = 0; j < shape->getCols(); j++)
		{
			if (holes == NULL)
				gameBoard[shape->getBody()[i][j].getY()][shape->getBody()[i][j].getX()] = shape->getSign();
			else
			{
				if (!(holes[0].getX() == i && holes[0].getY() == j) && !(holes[1].getX() == i && holes[1].getY() == j))
				{
					gameBoard[shape->getBody()[i][j].getY()][shape->getBody()[i][j].getX()] = shape->getSign();
				}
			}
		}
	}
}

void Board::printLimits()
{

	int i, j;
	for (i = 1; i < Point::limits::LIMRIGHT; i++)
	{
		gameBoard[Point::limits::LIMUP - 1][i] = ' ';
	}
	for (int i = 0; i < Point::limits::LIMDOWN + 1; i++)
	{
		gameBoard[i][0] = '|';
		gameBoard[i][Point::limits::LIMRIGHT] = '|';
	}
	for (i = 0; i < Point::limits::LIMRIGHT + 1; i++)
		gameBoard[Point::limits::LIMDOWN][i] = '-';

	for (i = 0; i < Point::limits::LIMDOWN + 1; i++)
	{
		for (j = 0; j < Point::limits::LIMRIGHT + 1; j++)
			cout << gameBoard[i][j];
		cout << endl;
	}
}


void Board::createMenu()
{
	gotoxy(15, 2);
	cout << "Menu:";
	gotoxy(15, 3);
	cout << "1.Start";
	gotoxy(15, 4);
	cout << "2.Pause/Resume";
	gotoxy(15, 5);
	cout << "3.Speed up";
	gotoxy(15, 6);
	cout << "4.Speed down";
	gotoxy(15, 7);
	cout << "9.Exit";
	gotoxy(15, 9);
	cout << "Controllers:";
	gotoxy(15, 10);
	cout << " Up - 'y'";
	gotoxy(15, 11);
	cout << " Down - 'h'";
	gotoxy(15, 12);
	cout << " Left - 'g'";
	gotoxy(15, 13);
	cout << " Right - 'j'";
	gotoxy(15, 14);
	cout << " Stop Joker - 's'";
	gotoxy(15, 15);
}

void Board::updateBoard(Shape* shape, int currShape)
{
	int yLine;
	int indexScore = 0;
	for (int i = 0; i < shape->getRows(); i++)
	{
		for (int j = 0; j < shape->getCols(); j++)
		{
			yLine = shape->getBody()[i][j].getY();
			if (isLineFull(yLine))
			{
				gotoxy(1, yLine);
				for (int k = 1; k < Point::LIMRIGHT; k++)
				{
					gameBoard[yLine][k] = CLEAR;
					cout << ' ';
				}
				indexScore++;
				dropLine(yLine);
			}
		}
	}

	if (indexScore == 1 && currShape == 3)//Checking if the current shape is JOKER
		updateScore(50);
	else if (indexScore == 1)
		updateScore(100);
	else if (indexScore == 2)
		updateScore(300);
	else if (indexScore == 3)
		updateScore(500);
	else if (indexScore == 4)
		updateScore(700);
}
void Board::dropLine(int y)
{
	for (int i = y; i > Point::LIMUP + 1; i--)
	{
		gotoxy(1, i);
		for (int j = 1; j < Point::LIMRIGHT; j++)
		{
			gameBoard[i][j] = gameBoard[i - 1][j];
			cout << gameBoard[i][j];
		}
	}
}

void Board::dropColumn(int x, int y)
{
	for (int i = y; i > Point::LIMUP + 1; i--)
	{
		gotoxy(x, i);
		gameBoard[i][x] = gameBoard[i - 1][x];
		cout << gameBoard[i][x];
	}
}

bool Board::isLineFull(int y)
{
	for (int k = 1; k < Point::LIMRIGHT; k++)
	{
		if (gameBoard[y][k] == CLEAR)
			return false;
	}
	return true;
}



