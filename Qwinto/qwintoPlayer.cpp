//Course: CSI 2372 A
//Project (work alone - implement Qwinto only)
//Student Name: Tianyu Shi
//Student Number: 7875409

#include <algorithm>

#include "qwintoPlayer.h"
using namespace std;


QwintoPlayer::QwintoPlayer() : Player::Player() {};
QwintoPlayer::QwintoPlayer(string playerName) : Player::Player(playerName) {
	qScoreSheet.setName(name);
	scoreSheet = &qScoreSheet;
};


//methods (in requirement):

//take user inputs before the roll, return a RollOfDice based on player's selection of dices
RollOfDice QwintoPlayer::inputBeforeRoll(RollOfDice& _roll) {
	
	//active player selects the number of dices and their colours before the roll
	//non-active players do not do anything before the roll
	
	RollOfDice newRoll;
	if (isActive) {
		
		//get the number of dices	
		int numSelectedDices=0;
		do {
			cout << "How many dices do you want to roll? ";
			cin >> numSelectedDices;
		} while (numSelectedDices<1 || numSelectedDices>3);
		
		//return the roll with all dices(RED, YELLOW, BLUE) if player choose to roll 3 dices
		if (numSelectedDices==3 && _roll.getRollSize()==3) {
			cout << endl;
			return _roll;
		};
		
		//get colours of each dices
		vector<Colour> selectedColours;
		vector<string> inputs;
		
		//while all colours are not selected
		int colourCount=0;
		while (colourCount<numSelectedDices) {
			//let user input color (no repeat since it is Qwinto)
			string colour;
			bool isRepeated = false;
			do {
				cout << "Select dice by enter RED, YELLOW, BLUE: ";
				cin >> colour;				
				isRepeated = find(inputs.begin(), inputs.end(), colour)!=inputs.end();	
				//cout << "isRepeated =" << isRepeated << endl;			
			} while ((colour!="RED" && colour!="YELLOW" && colour!="BLUE") || isRepeated);
			inputs.push_back(colour);
			
			//store colour			
			if (colour=="RED") {
				selectedColours.push_back(Colour::RED);
			} else if (colour=="YELLOW") {
				selectedColours.push_back(Colour::YELLOW);
			} else if (colour=="BLUE"){
				selectedColours.push_back(Colour::BLUE);
			};
			
			colourCount++;		
		};
		cout << endl;
		
		//add dices to newRoll based on player's selection of colours		
		for (Dice& _dice:_roll) {
			for (Colour& _colour:selectedColours) {
				if (_dice.colour==_colour) {
					newRoll.addDice(_dice);
				};
			};
		};
	} else {
		cout << "The player do not do anything before the roll since the status is non-active" << endl;
	};
	
	return newRoll;
};

//return true if player decides to score the roll and modify the reference of colour and position
bool QwintoPlayer::inputAfterRoll(RollOfDice& _roll, Colour& _colour, int& _index) {
	
	//for active player, ask at most twice since not score results in a failed throw
	//for non-active player, ask once not score does not result in a failed throw
	
	bool toScore=false;
	
	//get user selection of whether scoring this roll or not
	string inputScore;
	do {
		cout << "Enter Y to score this roll or N to not score: ";
		cin >> inputScore;
	} while (inputScore!="Y" && inputScore!="N");
	
	if (inputScore=="Y") {
		toScore=true;
	};
	
	//ask active player again if the player decides to not score
	if (isActive && !toScore) {
		do {
			cout << "Not score will result in a failed throw, enter Y to score this roll or N to not score: ";
			cin >> inputScore;
		} while (inputScore!="Y" && inputScore!="N");
		
		if (inputScore=="Y") {
			toScore=true;
		};						
	};
	
	//if score, get player's selection of which row and position to score
	string inputColour;
	int inputIndex;
	if (toScore) {
		//get
		do {
			cout << "Select row to score by enter row colour RED, YELLOW, BLUE: ";
			cin >> inputColour;
		} while (inputColour!="RED" && inputColour!="YELLOW" && inputColour!="BLUE");
		
		do {
			cout << "Select position to score by enter index 0-9: ";
			cin >> inputIndex;
		} while (inputIndex<0 || inputIndex>9);		
		cout << endl;
		
		//set
		if (inputColour=="RED") {
			_colour = Colour::RED;
		} else if (inputColour=="YELLOW") {
			_colour = Colour::YELLOW;
		} else if (inputColour=="BLUE"){
			_colour = Colour::BLUE;
		};
				
		_index = inputIndex;
	};
	
	return toScore;
};
