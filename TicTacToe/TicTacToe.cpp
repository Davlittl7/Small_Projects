#include<iostream>


using std::cout; using std::cin; using std::endl;

const int size = 3;

void checkForTie(bool& x, char arr[][size]);
void gameFinished(bool& gameCheck, char playerChar, char arr[][size]);
void drawBoard(char arr[][size]);

int main() {
	//  0  1  2
	//0 [] [] []
	//1 [] [] []
	//2 [] [] []

	//Initializes our game board
	char num = '1';
	char board[size][size], playerOne, playerTwo;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			board[i][j] = num;
			++num;
		}
	}

	//Determines what character each player will use
	cout << "Welcome to this fun game of tic-tac-toe! Let's determine which player will be which!" << endl;
	cout << "X or O player one?? [X/O] "; cin >> playerOne;
	if (playerOne != 'X' && playerOne != 'O') {
		if (playerOne == 'o') playerOne = 'O';
		else playerOne = 'X';
	}

	if (playerOne == 'X') playerTwo = 'O';
	else playerTwo = 'X';

	cout << "So player two will be: " << playerTwo << endl;

	bool gameOverCheck;
	int x = 0;
	do {
		
		int xOrOPlacement = 0;
		drawBoard(board);

		//Asks player one where they want to place their char/token
		//and Modifies board for where player places their token
		bool placement = false; 
		while (placement != true) {
			cout << "Okay player one, it's your turn! Select your placement (number represents place): ";
			cin >> xOrOPlacement;
			switch (xOrOPlacement) {
			case 1:
				if (board[0][0] != 'X' && board[0][0] != 'O') {
					board[0][0] = playerOne;
					placement = true;

				}
				else cout << "Someone already placed a token here!" << endl;
				break;
			case 2:
				if (board[0][1] != 'X' && board[0][1] != 'O') {
					board[0][1] = playerOne;
					placement = true;

				}
				else cout << "Someone already placed a token here!" << endl;
				break;
			case 3:
				if (board[0][2] != 'X' && board[0][2] != 'O') {
					board[0][2] = playerOne;
					placement = true;

				}
				else cout << "Someone already placed a token here!" << endl;
				break;

			case 4:
				if (board[1][0] != 'X' && board[1][0] != 'O') {
					board[1][0] = playerOne;
					placement = true;

				}
				else cout << "Someone already placed a token here!" << endl;
				break;

			case 5:
				if (board[1][1] != 'X' && board[1][1] != 'O') {
					board[1][1] = playerOne;
					placement = true;

				}
				else cout << "Someone already placed a token here!" << endl;
				break;

			case 6:
				if (board[1][2] != 'X' && board[1][2] != 'O') {
					board[1][2] = playerOne;
					placement = true;

				}
				else cout << "Someone already placed a token here!" << endl;
				break;

			case 7:
				if (board[2][0] != 'X' && board[2][0] != 'O') {
					board[2][0] = playerOne;
					placement = true;

				}
				else cout << "Someone already placed a token here!" << endl;
				break;

			case 8:
				if (board[2][1] != 'X' && board[2][1] != 'O') {
					board[2][1] = playerOne;
					placement = true;

				}
				else cout << "Someone already placed a token here!" << endl;
				break;

			case 9:
				if (board[2][2] != 'X' && board[2][2] != 'O') {
					board[2][2] = playerOne;
					placement = true;
				}
				else cout << "Someone already placed a token here!" << endl;
				break;

			default:
				cout << "Incorrect input!" << endl;
				break;
			}
		}

		//Checks if the game is over and if playerOne won, else it will move to playerTwo
		gameFinished(gameOverCheck, playerOne, board);
		if (gameOverCheck == true) {
			drawBoard(board);
			cout << "Player One Wins!!" << endl;
		}
		else {
			if (gameOverCheck != true) checkForTie(gameOverCheck, board);
			placement = false;
			drawBoard(board);

			//Asks player two where they want to place their token
			//and modifies board for where player places their token
			while (placement != true) {
				cout << "Now it's your turn player two! Select your placement (number represents place) ";
				cin >> xOrOPlacement;
				switch (xOrOPlacement) {
				case 1:
					if (board[0][0] != 'X' && board[0][0] != 'O') {
						board[0][0] = playerTwo;
						placement = true;

					}
					else cout << "Someone already placed a token here!" << endl;
					break;

				case 2:
					if (board[0][1] != 'X' && board[0][1] != 'O') {
						board[0][1] = playerTwo;
						placement = true;

					}
					else cout << "Someone already placed a token here!" << endl;
					break;

				case 3:
					if (board[0][2] != 'X' && board[0][2] != 'O') {
						board[0][2] = playerTwo;
						placement = true;

					}
					else cout << "Someone already placed a token here!" << endl;
					break;

				case 4:
					if (board[1][0] != 'X' && board[1][0] != 'O') {
						board[1][0] = playerTwo;
						placement = true;

					}
					else cout << "Someone already placed a token here!" << endl;
					break;

				case 5:
					if (board[1][1] != 'X' && board[1][1] != 'O') {
						board[1][1] = playerTwo;
						placement = true;

					}
					else cout << "Someone already placed a token here!" << endl;
					break;

				case 6:
					if (board[1][2] != 'X' && board[1][2] != 'O') {
						board[1][2] = playerTwo;
						placement = true;

					}
					else cout << "Someone already placed a token here!" << endl;
					break;

				case 7:
					if (board[2][0] != 'X' && board[2][0] != 'O') {
						board[2][0] = playerTwo;
						placement = true;

					}
					else cout << "Someone already placed a token here!" << endl;
					break;

				case 8:
					if (board[2][1] != 'X' && board[2][1] != 'O') {
						board[2][1] = playerTwo;
						placement = true;

					}
					else cout << "Someone already placed a token here!" << endl;
					break;
				case 9:
					if (board[2][2] != 'X' && board[2][2] != 'O') {
						board[2][2] = playerTwo;
						placement = true;
					}
					else cout << "Someone already placed a token here!" << endl;
					break;
				default:
					cout << "Incorrect input!" << endl;
					break;
				}
			}
			gameFinished(gameOverCheck, playerTwo, board);
			if (gameOverCheck == true) {
				drawBoard(board);
				cout << "Player Two Wins!!" << endl;
			}
			if (gameOverCheck != true) checkForTie(gameOverCheck, board);
		}
	} while (gameOverCheck != true);
	
}

//Draws the entire board
void drawBoard(char arr[][size] ) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

void gameFinished(bool& gameCheck, char playerChar, char arr[][size]) {
	
	//Checks horizontal wins
	if ((arr[0][0] == playerChar && arr[0][1] == playerChar && arr[0][2] == playerChar)) {
		gameCheck = true;
		return;
	}
	if ((arr[1][0] == playerChar && arr[1][1] == playerChar && arr[1][2] == playerChar)) {
		gameCheck = true;
		return;
	}
	if ((arr[2][0] == playerChar && arr[2][1] == playerChar && arr[2][2] == playerChar)) {
		gameCheck = true;
		return;
	}

	//Checks vertical wins 
	if ((arr[0][0] == playerChar && arr[1][0] == playerChar && arr[2][0] == playerChar)) {
		gameCheck = true;
		return;
	}
	if ((arr[0][1] == playerChar && arr[1][1] == playerChar && arr[2][1] == playerChar)) {
		gameCheck = true;
		return;
	}
	if ((arr[0][2] == playerChar && arr[1][2] == playerChar && arr[2][2] == playerChar)) {
		gameCheck = true;
		return;
	}

	//Checks diagonal wins
	if ((arr[0][0] == playerChar && arr[1][1] == playerChar && arr[2][2] == playerChar)) {
		gameCheck = true;
		return;
	}
	if ((arr[0][2] == playerChar && arr[1][1] == playerChar && arr[2][0] == playerChar)) {
		gameCheck = true;
		return;
	}
}

//Checks if the board is filled for a tie scenario
void checkForTie(bool& x, char arr[][size]) {
	bool tieCheck = true;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (arr[i][j] != 'X' && arr[i][j] != 'O') {
				tieCheck = false;
			}
		}
	}
	if (tieCheck == true) {
		cout << "It's a tie!!" << endl;
		x = true;
	}
}
