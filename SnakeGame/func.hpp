
#ifndef FUNC_HPP
#define FUNC_HPP
#include<windows.h>
#include<vector>
#include<cstdlib>

//DEFINITIONS FOR VALUES
#define height 25 
#define width 50
#define arrowUp 72
#define arrowDown 80 
#define arrowLeft 75 
#define arrowRight 77

using std::vector;

//FUNC DECLARATIONS
void board(class Snake& newSnake, class Food& newFood);

//CLASSES

//snake character
class Snake {
public:
	//Snake Constructor
	Snake(COORD pos, int velocity) : pos_(pos), velocity_(velocity) {
		length_ = 1;
		direction_ = 'n';
		body_.push_back(pos_);
	};

	void changeDirection(char dir) { direction_ = dir; } //changes snake direction
	void moveSnake(); //allows snake to move
	void grow() { length_++; } //Increases length of snake
	bool didEatFood(COORD foodPosition);
	bool didCollide();

	//accessor functions
	COORD getPosition() { return pos_; }
	int getLength() { return length_; }
	vector<COORD> getBody() { return body_; }

private:
	COORD pos_;
	int length_, velocity_;
	char direction_;
	vector<COORD> body_;
};

//food class
class Food {
public:
	//Constructor
	Food() { generateFood(); }
	

	//Makes our food when needed
	void generateFood();

	//Accessor functions
	COORD getPosition() { return pos_; };
private:
	COORD pos_;
};


#endif
