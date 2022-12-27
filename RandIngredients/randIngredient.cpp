#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<numeric>

using namespace std;

int main() {
	//initializing random seed
	srand(time(nullptr));

	//# of ingredients & participants, and how many ingredients
	//for each person
	int ingredientAmt, participants, partyAmt;
	string participantName;

	//Prompts and getting values
	cout << "Welcome to Chopped! How many ingredients do we have (input num): ";
	cin >> ingredientAmt;

	//Initializes a vector based on ingredient amt
	vector<string> ingredients(ingredientAmt);

	cout << "Okay! So we have " << ingredientAmt << " ingredients!" << endl;

	//Takes in all ingredients
	cout << "Please enter the ingredients (hypen inbetween things w/ spaces)" << endl;
	for (auto& e : ingredients) cin >> e;

	//Collecting more info
	cout << "Okay, my partner tells me that you're finished up w/ putting ALL of that in..." << endl;
	cout << "...Sooooo, how many participants are there? (more than 1): ";
	cin >> participants;
	
	cout << "Okay we have " << participants << "!" << endl;
	cout << "Finally, how many ingredients per participant? ";
	cin >> partyAmt;

	cout << "Alright enough boring stuff!! Let's get to it!" << endl;

	//Vector for the participant's 
	vector<string> ingredForParticipants(partyAmt);
	for (int i = 0; i < participants; ++i) {
		//Takes in player's name 
		cout << "What's your name participant #" << i + 1 << ": ";
		cin >> participantName;
		cout << endl;
		cout << "Okay " << participantName << "! Your ingredients are the following: " << endl;

		//Puts random ingredients into participant's vector from the ingredient vector
		transform(ingredForParticipants.begin(), ingredForParticipants.end(), ingredForParticipants.begin(),
			[ingredientAmt, ingredients](string str) {int randElement = rand() % ingredientAmt; return ingredients[randElement]; });
		for (const auto& e : ingredForParticipants) cout << e << endl;
		cout << endl;
	}

	cout << "Alright we're all done here let's get cooking chefs!" << endl;
}
