/*
 * Snake.h
 *
 *  Created on: Jul 1, 2022
 *      Author: Jordian
 */

#ifndef SNAKE_H_
#define SNAKE_H_

class Snake
{
private:				// data members
	const int width = 80;					// width of game window in blocks
	const int height = 40;					// height of game window in blocks
	int snakeX, snakeY;						// position of snake head in game window
	int fruitX, fruitY;						// position of fruit in game window
	int score;								// to keep track of score in game

	enum Direction {						// enum for directions.
		STOP = 0,
		UP,
		RIGHT,
		DOWN,
		LEFT
	};
	Direction dir;							// declaring Direction type variable.

	int tailX[100], tailY[100];				// coordinate for snake's tail.
	int nTail;								// length of snake tail


public:
	bool gameOver;
	Snake();								// Constructor (it is called when object or instance of a class is created)
	~Snake();								// Destructor (it is called when object or instance of a class is killed/deleted)
	void Setup();							// setting up game window
	void Draw();							// Drawing game
	void Input();							// Taking user input for game controls
	void Logic();							// Logic for game
};

#endif /* SNAKE_H_ */
