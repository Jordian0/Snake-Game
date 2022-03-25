/*
 * Snake.cpp
 *
 *  Created on: Jul 1, 2022
 *      Author: Jordian
 */

#include <iostream>
#include <cstdlib>						// for srand()  and rand function
#include <stdlib.h>						// for clearing terminal screen.
#include <time.h>						// for time() funciton, random seed for rand() function.
#include <conio.h>						// for console input and output
#include "Snake.h"						// Snake class header file

using namespace std;


Snake::Snake() {						// CONSTRUCTOR
	Setup();

	cout << "\t\t\tGame Started!!!!!!!!!!!" << endl;
}


Snake::~Snake() {						// DESTRUCTOR
	cout << "\t\t\tGame Over..." << endl;
}


void Snake::Setup() {
	// initializing values
	gameOver = false;
	dir = STOP;

	// Snake position when game starts. Centered in game window.
	snakeX = width / 2;
	snakeY = height / 2;

	// snake tail length when game starts.
	nTail = 0;


	// using current time as seed for rand() function
	srand(time(0));
	// position of fruit when game starts. Randomly in game window.
	// -3 so that fruit didn't grow in wall area of game window.
	fruitX = rand() % (width - 3);
	fruitY = rand() % (height - 3);

		// score when game starts
		score = 0;

}


void Snake::Draw()
{
	system("clear");								// clearing screen

	// Drawing game window (wall, snake, fruit, game area).
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			if(i == 0 || i == height-1)				// wall for top most and bottom most rows
				cout << "#" << flush;
			else {
				if(j == 0 || j == width-1)			// for right most and left most column
					cout << "#" << flush;
				else if(j == snakeX && i == snakeY)		// snake position
					cout << "0" << flush;
				else if(j == fruitX && i == fruitY)		// fruit position
					cout << "@" << flush;
				else
				{
					bool print = false;					// switching variable for printing snake's tail.
					for(int k = 0; k < nTail; k++)		// printing snake tail
					{
						if(j == tailX[k] && i == tailY[k])
						{
							cout << "o" << flush;
							print = true;
						}
					}
					if(!print)
						cout << " ";
				}
			}
		}
		cout << endl;
	}

	cout << endl;
	cout << "SCORE  :::::::  " << score << endl;	// printing scores
}


void Snake::Input()
{
	if(_kbhit())						// returns positive value if any key is pressed
	{
		switch(_getch())				// gets the character key.
		{
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'x':						// exit game
			gameOver = true;
			break;
		}
	}
}


void Snake::Logic()
{
  /* tail following snake's head */
	int prevX = tailX[0], prevY = tailY[0];			// storing very first value of tailX and tailY for swapping
	int prev2X, prev2Y;								// temporary variable for swapping

	tailX[0] = snakeX, tailY[0] = snakeY;			// tail coordinate first element to follow head.

	for(int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}


 /* changing direction of snake */
	switch(dir)
	{
	case UP:
		snakeY--;
		break;
	case DOWN:
		snakeY++;
		break;
	case LEFT:
		snakeX--;
		break;
	case RIGHT:
		snakeX++;
		break;
	default:
		break;
	}


 /* if snake hits the wall game over */
	if(snakeX > width-1 || snakeX < 1 || snakeY > height-1 || snakeY < 1)
		gameOver = true;


 /* checking if snake head hits its tail or not */
	for(int i = 0; i < nTail; i++)
	{
		if(tailX[i] == snakeX && tailY[i] == snakeY)
			gameOver = true;
	}


 /* If fruit is eaten by snake */
	if(snakeX == fruitX && snakeY == fruitY)
	{
		score += 5;							// increasing score by 5

		// changing position of fruit
		srand(time(0));
		fruitX = rand() % (width - 3) + 1;
		fruitY = rand() % (height - 3) + 1;

		nTail++;							// adding 1 to snake's tail
	}
}
