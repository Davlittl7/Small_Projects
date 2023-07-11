#include <iostream>
#include "func.hpp"

using std::cout; using std::endl;



//Snake Member function for moving the snake
void Snake::moveSnake() {

	//characters represent from up, down, left, and right
	switch (direction_) {
	case 'u':
		pos_.Y -= velocity_;
		break;
	case 'd':
		pos_.Y += velocity_;
		break;
	case 'l':
		pos_.X -= velocity_;
		break;
	case 'r':
		pos_.X += velocity_;
	}

	body_.push_back(pos_);
	if (body_.size() > length_) body_.erase(body_.begin());

}


//Snake member function to check if food has been eaten
bool Snake::didEatFood(COORD foodPosition) {
	//Checks to see if snake's position is the same as the food
	if (pos_.X == foodPosition.X && pos_.Y == foodPosition.Y) return true;
	else return false;

}

//Snake member function to check for collision
bool Snake::didCollide() {
	//For loop checks for collision with your own body
	for (int i = 0; i < body_.size() - 1; ++i) {
		if (pos_.X == body_[i].X && pos_.Y == body_[i].Y) return true;
	}

	//if-else checks for collision with the borders of the board
	if (pos_.X < 1 || pos_.X >= width - 1 || pos_.Y < 1 || pos_.Y >= height - 1)
		return true;
	else return false;
}

//Creates the board
void board(Snake& newSnake, Food& newFood) {

	COORD snakePosition = newSnake.getPosition();
	vector<COORD> snakeBody = newSnake.getBody();
	COORD foodPosition = newFood.getPosition();

	cout << "Score: " << newSnake.getLength() - 1 << endl;
	for (int i = 0; i < height; ++i) {
		cout << "\t\t#";
		for (int j = 0; j < width - 2; ++j) {
			if (i == 0 || i == height - 1) cout << "#";
			else if (i == snakePosition.Y && j + 1 == snakePosition.X) cout << "0"; //generates snake
			else if (i == foodPosition.Y && j + 1 == foodPosition.X) cout << "*"; // generates food
			else {
				bool isSnakeBody = false;
				for (int k = 0; k < snakeBody.size() - 1; ++k) {
					if (i == snakeBody[k].Y && j + 1 == snakeBody[k].X) {
						cout << "o"; 
						isSnakeBody = true; 
						break;
					}
				}
				if (!isSnakeBody) cout << " ";
			}
			
		}
		cout << "#" << endl;
	}
}

//Food member function
void Food::generateFood() {
	pos_.X = (rand() % (width - 3)) + 1;
	pos_.Y = (rand() % (height - 3)) + 1;

}
