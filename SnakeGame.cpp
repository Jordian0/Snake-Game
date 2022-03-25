//============================================================================
// Name        : Snake Game.cpp
// Author      : Mr. Jordian
// Version     :
// Copyright   : Your copyright notice
// Description : Snake Game in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>						// for usleep() function
#include "Snake.h"						// Snake class header file.
using namespace std;

int main() {

	Snake snake;						// constructor called
	while(!snake.gameOver)
	{
		snake.Draw();
		snake.Input();
		snake.Logic();
		usleep(99000);					// snake speed
	}

	return 0;
}
