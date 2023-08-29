#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

//Boolean var to determine state of game
bool gameOver;

//Size of the board
const int width = 20;
const int height = 20;

//Coordinates for snake and its tail, fruit, and our total score
int x, y, fruitX, fruitY, score, tailX[100], tailY[100], nTail;


//enum to hold the direction of the snake
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;


void Setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = width / 2;

	fruitX = rand() % width;
	fruitY = rand() % height;

	score = 0;
}

void Draw() {
	system("cls");

	//Draws the top of the board
	for (int i = 0; i < width + 2; i++) {
		cout << "#";
	}
	cout << endl;

	//Draws the sides of the board
	for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) {
			if (j == 0) cout << "#";

			//Draws snake's head
			if (i == y && j == x) cout << "O";

			//Draws fruit
			else if (i == fruitY && j == fruitX) cout << "@";

			else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						cout << "o";
						print = true;
					}
				}

				if(!print) cout << " ";
			}

			if (j == width - 1) cout << "#";
		}
		cout << endl; //What he forgot in class
	}

	//Draws the bottom of the board
	for (int i = 0; i < width + 2; ++i) {
		cout << "#";
	}
	
	cout << endl;
	
	//Keeps drawing the score
	cout << "Score: " << score << endl;
}

void Input() {
	//Determines which key is pressed
	if (_kbhit()) {
		switch (_getch()) {
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				gameOver = true;
				break;
		}
	}
}

void Logic() {
	//Logic for drawing tail
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; ++i) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	//moves characters point
	switch (dir) {
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
	}

	//Moves character to other side if they hit wall
	if (x >= width) x = 0;
	else if (x < 0) x = width - 1;

	if (y >= height) y = 0;
	else if (x < 0) x = height - 1;

	//Die if you eat yourself
	for (int i = 0; i < nTail; ++i) {
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true; 
	}

	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		++nTail;
	}
}

int main() {

	Setup();

	while (!gameOver) {
		Draw();
		Input();
		Logic();
		Sleep(100);
	}

	return 0;
}
