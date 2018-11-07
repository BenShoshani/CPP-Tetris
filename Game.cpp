#include "Game.h"
#include <Windows.h>
#include <conio.h>
#include <math.h>
using namespace std;

void Game::run()
{
	char selection;
	bool left, right, down, runGame = true;
	bool newShape = true;
	bool runnig = true;
	char tempPressed = 0;
	Shape::eShapes randShape;
	Point start = { START_X,START_Y };
	Shape** shape = new Shape*;
	Board::updateScore(0);

	while (true)
	{
		selection = _getch();
		if (selection == (char)Game::START)
		{
			runGame = true;
			break;
		}
		else if (selection == (char)Game::ESC)
		{
			runGame = false;
			break;
		}
	}

	while (runGame)
	{
		if (newShape)
		{
			Board::updateDroppedShape();
			randShape = chooseShape();
			switch (randShape)
			{
			case Shape::SQUARE:
			{
				(*shape) = new Square(start, '*');
				break;
			}
			case Shape::BOMB:
			{
				(*shape) = new Bomb(start, '@');
				break;
			}
			case Shape::JOKER:
			{
				(*shape) = new Joker(start, '*');
				break;
			}
			case Shape::LINE:
			{
				(*shape) = new Line(start, '*');
				break;
			}
			case Shape::L:
			{
				(*shape) = new L(start, '*');
				break;
			}
			case Shape::PLUS:
			{
				(*shape) = new Plus(start, '*');
				break;
			}
			case Shape::Z:
			{
				(*shape) = new Z(start, '*');
				break;
			}
			}
			(*shape)->draw((*shape)->getRows(), (*shape)->getCols(), (*shape)->getHoles());
			newShape = false;
		}
			char keyPressed = tempPressed;
		if (keyPressed == 0)
			if (_kbhit())
				keyPressed = _getch();
		if (keyPressed == (char)ESC)
			break;
		if (keyPressed == (char)PAUSE_AND_RESUME)
		{
			runnig = (!runnig);
			tempPressed = eatBuffer();
		}
		if (runnig)
		{
			left = right = down = true;
			(*shape)->chaeckMoves(&left, &right, &down, board);
			switch ((Point::directions)keyPressed)
			{
			case Point::LEFT:
			{

				if ((*shape)->checkLimX(Point::LEFT, (*shape)->getRows(), (*shape)->getCols()))
				{
					if (left)
					{
						(*shape)->move(Point::LEFT, &board);
					}
					else
					{
						if (randShape == Shape::JOKER)
							(*shape)->move(Point::LEFT, &board);

						else if (randShape == Shape::BOMB)
						{
							(*shape)->explode(board);
							(*shape)->deleteShape((*shape)->getRows());
							delete (*shape);
							newShape = (!newShape);
						}

						else
						{
							if ((*shape)->checkLimY((*shape)->getRows(), (*shape)->getCols()))
							{
								if (down)
									(*shape)->move(Point::STAND, &board);
								else
								{
									board.copyShapeToBoard(*shape, (*shape)->getHoles());
									board.updateBoard(*shape, (int)randShape);
									(*shape)->deleteShape((*shape)->getRows());
									newShape = (!newShape);
								}
							}
							else
							{
								board.copyShapeToBoard(*shape, (*shape)->getHoles());
								board.updateBoard(*shape, (int)randShape);
								(*shape)->deleteShape((*shape)->getRows());
								newShape = (!newShape);
							}
						}
					}
				}
				else
				{
					if ((*shape)->checkLimY((*shape)->getRows(), (*shape)->getCols()))
					{
						if (down)
							(*shape)->move(Point::STAND, &board);
						else
						{
							board.copyShapeToBoard(*shape, (*shape)->getHoles());
							board.updateBoard(*shape, (int)randShape);
							(*shape)->deleteShape((*shape)->getRows());
							newShape = (!newShape);
						}
					}
					else
					{
						board.copyShapeToBoard(*shape, (*shape)->getHoles());
						board.updateBoard(*shape, (int)randShape);
						(*shape)->deleteShape((*shape)->getRows());
						newShape = (!newShape);
					}
				}
				tempPressed = eatBuffer();
				break;
			}

			case Point::RIGHT:
			{

				if ((*shape)->checkLimX(Point::RIGHT, (*shape)->getRows(), (*shape)->getCols()))
				{
					if (right)
					{
						(*shape)->move(Point::RIGHT, &board);
					}
					else
					{
						if (randShape == Shape::JOKER)
							(*shape)->move(Point::RIGHT, &board);

						else if (randShape == Shape::BOMB)
						{
							(*shape)->explode(board);
							(*shape)->deleteShape((*shape)->getRows());
							delete (*shape);
							newShape = (!newShape);
						}
						else
						{
							if ((*shape)->checkLimY((*shape)->getRows(), (*shape)->getCols()))
							{
								if (down)
									(*shape)->move(Point::STAND, &board);
								else
								{
									board.copyShapeToBoard(*shape, (*shape)->getHoles());
									board.updateBoard(*shape, (int)randShape);
									(*shape)->deleteShape((*shape)->getRows());
									newShape = (!newShape);
								}
							}
							else
							{
								board.copyShapeToBoard(*shape, (*shape)->getHoles());
								board.updateBoard(*shape, (int)randShape);
								(*shape)->deleteShape((*shape)->getRows());
								newShape = (!newShape);
							}
						}
					}
				}
				else
				{
					if ((*shape)->checkLimY((*shape)->getRows(), (*shape)->getCols()))
					{
						if (down)
							(*shape)->move(Point::STAND, &board);
						else
						{
							board.copyShapeToBoard(*shape, (*shape)->getHoles());
							board.updateBoard(*shape, (int)randShape);
							(*shape)->deleteShape((*shape)->getRows());
							newShape = (!newShape);
						}
					}
					else
					{
						board.copyShapeToBoard(*shape, (*shape)->getHoles());
						board.updateBoard(*shape, (int)randShape);
						(*shape)->deleteShape((*shape)->getRows());
						newShape = (!newShape);
					}
				}
				tempPressed = eatBuffer();
				break;
			}
			case Point::UP:
			{
				(*shape)->move(Point::UP, &board);
				(*shape)->draw((*shape)->getRows(), (*shape)->getCols(), (*shape)->getHoles());
				tempPressed = eatBuffer();
				break;
			}
			case Point::DOWN:
			{
				if ((*shape)->checkLimY((*shape)->getRows(), (*shape)->getCols()))
				{
					if (down)
					{
						if ((*shape)->chaeckMovesToDown(&board))
						{
							(*shape)->move(Point::DOWN, &board);
							board.updateScore(2);
						}
						else
							(*shape)->move(Point::STAND, &board);
					}
					else
					{
						if (randShape == Shape::BOMB)
						{
							(*shape)->explode(board);
							(*shape)->deleteShape((*shape)->getRows());
							delete (*shape);
							newShape = (!newShape);
						}

						else if (randShape == Shape::JOKER)
						{
							if ((*shape)->chaeckMovesToDown(&board))
							{
								(*shape)->move(Point::DOWN, &board);
								board.updateScore(2);
							}
							else
								(*shape)->move(Point::STAND, &board);
						}
						else
						{
							board.copyShapeToBoard(*shape, (*shape)->getHoles());
							board.updateBoard(*shape, (int)randShape);

							if (lost(*shape))
							{
								gotoxy(0, 17);
								cout << "Game Over\n\n";
								runGame = false;
							}

							else
								(*shape)->draw((*shape)->getRows(), (*shape)->getCols(), (*shape)->getHoles());

							(*shape)->deleteShape((*shape)->getRows());
							newShape = (!newShape);
						}
					}
				}
				else
				{
					if (randShape == Shape::BOMB)
					{
						(*shape)->explode(board);
						(*shape)->deleteShape((*shape)->getRows());
						delete (*shape);
						newShape = (!newShape);
					}
					else
					{
						board.copyShapeToBoard(*shape, (*shape)->getHoles());
						board.updateBoard(*shape, (int)randShape);
						(*shape)->draw((*shape)->getRows(), (*shape)->getCols(), (*shape)->getHoles());
						(*shape)->deleteShape((*shape)->getRows());
						newShape = (!newShape);
					}
				}
				tempPressed = eatBuffer();
				break;
			}

			case Point::STOPJ:
			{
				if (randShape == Shape::JOKER)
				{
					board.copyShapeToBoard(*shape, (*shape)->getHoles());
					board.updateBoard(*shape, (int)randShape);

					if (lost(*shape))
					{
						gotoxy(0, 17);
						cout << "Game Over\n\n";
						runGame = false;
					}
					else
						(*shape)->draw((*shape)->getRows(), (*shape)->getCols(), (*shape)->getHoles());

					(*shape)->deleteShape((*shape)->getRows());
					newShape = (!newShape);
				}
				else
				{
					if ((*shape)->checkLimY((*shape)->getRows(), (*shape)->getCols()))
					{
						if (down)
							(*shape)->move(Point::STAND, &board);
						else
						{
							if (randShape == Shape::BOMB)
							{
								(*shape)->explode(board);
								(*shape)->deleteShape((*shape)->getRows());
								delete (*shape);
								newShape = (!newShape);
							}
							else
							{
								board.copyShapeToBoard(*shape, (*shape)->getHoles());
								board.updateBoard(*shape, (int)randShape);

								if (lost(*shape))
								{
									gotoxy(0, 17);
									cout << "Game Over\n\n";
									runGame = false;
								}

								else
									(*shape)->draw((*shape)->getRows(), (*shape)->getCols(), (*shape)->getHoles());


								(*shape)->deleteShape((*shape)->getRows());
								newShape = (!newShape);
							}
						}
					}
					else
					{
						if (randShape == Shape::BOMB)
						{
							(*shape)->explode(board);
							(*shape)->deleteShape((*shape)->getRows());
							delete (*shape);
							newShape = (!newShape);
						}
						else
						{
							board.copyShapeToBoard(*shape, (*shape)->getHoles());
							board.updateBoard(*shape, (int)randShape);

							if (lost(*shape))
							{
								gotoxy(0, 17);
								cout << "Game Over\n\n";
								runGame = false;
							}

							else
								(*shape)->draw((*shape)->getRows(), (*shape)->getCols(), (*shape)->getHoles());


							(*shape)->deleteShape((*shape)->getRows());
							newShape = (!newShape);
						}
					}
					
				}
				tempPressed = eatBuffer();
				break;
			}
			default:
			{
				if ((*shape)->checkLimY((*shape)->getRows(), (*shape)->getCols()))
				{
					if (down)
						(*shape)->move(Point::STAND, &board);
					else
					{
						if (randShape == Shape::BOMB)
						{
							(*shape)->explode(board);
							(*shape)->deleteShape((*shape)->getRows());
							delete (*shape);
							newShape = (!newShape);
						}

						else if (randShape == Shape::JOKER)
							(*shape)->move(Point::STAND, &board);
						else
						{
							board.copyShapeToBoard(*shape, (*shape)->getHoles());
							board.updateBoard(*shape, (int)randShape);

							if (lost(*shape))
							{
								gotoxy(0, 17);
								cout << "Game Over\n\n";
								runGame = false;
							}

							(*shape)->deleteShape((*shape)->getRows());
							newShape = (!newShape);
						}
					}
				}
				else
				{
					if (randShape == Shape::BOMB)
					{
						(*shape)->explode(board);
						(*shape)->deleteShape((*shape)->getRows());
						delete (*shape);
						newShape = (!newShape);
					}
					else
					{
						board.copyShapeToBoard(*shape, (*shape)->getHoles());
						board.updateBoard(*shape, (int)randShape);
						(*shape)->deleteShape((*shape)->getRows());
						delete (*shape);
						newShape = (!newShape);
					}
				}
				tempPressed = eatBuffer();
				break;
			}
			}
			if (keyPressed == SPEED_UP && sleepSpeed > 100)
				sleepSpeed -= 200;
			else if (keyPressed == SPEED_DOWN && sleepSpeed < 1300)
				sleepSpeed += 200;
			Sleep(sleepSpeed);
		}
	}
}

Shape::eShapes Game::chooseShape()
{
	return (Shape::eShapes)(rand() % 7);
}
bool Game::lost(Shape * shape)
{
	int x;
	for (int i = 0; i < shape->getRows(); i++)
	{
		for (int j = 0; j < shape->getCols(); j++)
		{
			x = shape->getBody()[i][j].getX();
			if (board.getGameBoard()[Point::LIMUP + 1][x] != Board::CLEAR)
				return true;
		}
	}
	return false;
}
char Game::eatBuffer()
{
	char input;
	while (_kbhit())
	{
		input = _getch();
		if (input == (char)SPEED_DOWN || input == (char)SPEED_UP || input == (char)PAUSE_AND_RESUME || input == (char)ESC)
			return input;
	}
	return 0;
}