#include <iostream>
#include<conio.h>
#include<ctime>
#include "func.hpp"

using std::cout; using std::endl; 

//Creates and initalizes the snake object
Snake snake({ width / 2, height / 2 }, 1);

int main() {
	//Initializes random seed
	srand(time(nullptr));

	//Creates and initializes the food object
	Food food;

	bool gameOver = false;

	//calls for the board to be drawn 
	while (!gameOver) {
		board(snake, food);

		//Starts changing the direction as soon as a spefic key is hit
		if (_kbhit()) {
			switch (_getch()) {
			case 'w': snake.changeDirection('u'); break;
			case 'a': snake.changeDirection('l'); break;
			case 's': snake.changeDirection('d'); break;
			case 'd': snake.changeDirection('r'); break;

			//defined arrow keys with ASCII values (defined in func.hpp)
			//Can use WASD or arrow keys because of this
			case arrowUp: snake.changeDirection('u'); break;
			case arrowLeft: snake.changeDirection('l'); break;
			case arrowDown: snake.changeDirection('d'); break;
			case arrowRight: snake.changeDirection('r'); break;
			}
			


		}
		snake.moveSnake(); //moves snake once direction is selected

		if (snake.didCollide()) {
			gameOver = true;
			cout << "Game Over! Your score was: " << snake.getLength() - 1 << endl;
			continue;
		}

		//Checks to see if food has been eaten
		if (snake.didEatFood(food.getPosition())) {
			food.generateFood();
			snake.grow();
		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
	}
}

