#include<iostream>
#include<string>
#include <cstdlib>
#include<ctime>

using namespace std;

int main() {
	srand((unsigned int)time(NULL)); //init rand seed
	string foodOptions[5]; //str array for food choices
	char yOrN = 'y'; //char var to determine if they are done
	int randNum; //int to store rand num

	//Intro and prompts user to input food choices
	cout << "Hello! It is time to play everybody's favorite game... \nWhat food are we eating?????" << endl;
	cout << "\nWhile this may be hard, please select 5 options to eat, or we can always eat at home!" << endl;
	cout << "Have a space between each choice and a hyphen for restaurants that normally have spaces: ";

	//for loop that takes all the user inputted foods
	for (int i = 0; i < 5; ++i) {
		cin >> foodOptions[i];
	}

	//While loop that loops until user finally decides on where to eat
	while ((yOrN != 'n') && (yOrN != 'N')) {
		cout << "Now selecting a random number between 1 & 5 beep boop beep......" << endl;
		randNum = rand() % 5; //Rand Num betw 0 & 4

		cout << "\nThe number has been selected and it has been decided that we will eat at " + foodOptions[randNum] << endl; //Displays random food place selected
		cout << "...Do you want to try again? There's no shame in rolling again you know [Y/N]: "; //Prompts user asking if they want another roll

		cin >> yOrN; //Input to determine whether while loop will continue or not
		if (yOrN == 'y' || yOrN == 'Y') cout << "Okay we shall roll again!" << endl; //Message if user chooses to roll again and then loops back
	}
	cout << "Yay we're done now let's go get it!" << endl; //Final message before finishing.
	return 0;
}
