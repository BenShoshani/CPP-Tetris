#include "Joker.h"


void Joker::chaeckMoves(bool * left, bool * right, bool * down, Board& board)
{
	*left = *down = *right = true;
}
void Joker::move(Point::directions direction,Board* board)
{	
	string* tempBoard = board->getGameBoard();
	Point** tempBody = this->getBody();

	if (tempBoard[tempBody[0][0].getY()][tempBody[0][0].getX()] == Board::CLEAR)
		tempBody[0][0].draw(' ');
	if(direction!=Point::UP)
		tempBody[0][0].move(direction);
	else
		tempBody[0][0].move(Point::STAND);
	tempBody[0][0].draw(this->getSign());
	
	tempBoard = NULL;
	tempBody = NULL;
	delete[] tempBody;
	delete[] tempBoard;

}
bool Joker::chaeckMovesToDown(Board* board)
{
	Point maxDown;
	bool down = true;
	Point** tempBody = this->getBody();
	string* tempBoard = board->getGameBoard();
	if (tempBoard[tempBody[0][0].getY() + 2][tempBody[0][0].getX()] != Board::CLEAR)
		down = false;

	tempBoard = NULL;
	tempBody = NULL;
	delete[] tempBody;
	delete[] tempBoard;
	return down;
}
void Joker::explode(Board& board)
{
	Point** tempBody = this->getBody();
	string* tempBoard = board.getGameBoard();
	for (int i = tempBody[0][0].getY() - 1; i <= tempBody[0][0].getY() + 1; i++)
	{
		for (int j = tempBody[0][0].getX() - 1; j <= tempBody[0][0].getX() + 1; j++)
		{
			if (j > Point::LIMLEFT && j<Point::LIMRIGHT && i>Point::LIMUP && i < Point::LIMDOWN)
			{
				if (tempBoard[i][j] == '*')
					Board::updateScore(-50);
				tempBoard[i][j] = Board::CLEAR;
				gotoxy(j, i);
				cout << ' ';
				board.dropColumn(j, i);
			}
		}
	}
	tempBoard = NULL;
	tempBody = NULL;
	delete[] tempBody;
	delete[] tempBoard;
}