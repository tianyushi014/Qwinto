//Course: CSI 2372 A
//Project (work alone - implement Qwinto only)
//Student Name: Tianyu Shi
//Student Number: 7875409

#include <iostream>

#include "qwintoPlayer.h"
using namespace std;


//#define TEST_DICE
#ifdef TEST_DICE
int main() {
	cout << "TEST_DICE" << endl << endl;
	
	//create a test Dice
	Dice testDice{Colour::RED, 1};
	
	//test the overloaded << operator
	cout << "<< operator:" << endl;
	cout << testDice << endl;
	
	//test the [roll] function
	cout << "roll function:" << endl;
	testDice.roll();
	cout << testDice;
	
	return 0;
};
#endif


//#define TEST_ROLLOFDICE
#ifdef TEST_ROLLOFDICE
int main() {
	cout << "TEST_ROLLOFDICE" << endl << endl;
	
	//create a test RollOfDice with 3 dices
	Dice diceRED = {Colour::RED, 1};
	Dice diceYELLOW = {Colour::YELLOW, 1};
	Dice diceBLUE = {Colour::BLUE, 1};	
	RollOfDice testRoll;
	testRoll.addDice(diceRED);
	testRoll.addDice(diceYELLOW);
	testRoll.addDice(diceBLUE);
	
	//test the overloaded << operator
	cout << "<< operator:" << endl;
	cout << testRoll << endl;
	
	//test the [roll] function
	cout << "roll function:" << endl;
	testRoll.roll();
	cout << testRoll << endl;
	
	//test the [pair] function
	cout << "pair function:" << endl;
	cout << testRoll.pair(diceRED, diceBLUE) << endl << endl;;
	
	//test the overloaded conversion operator
	cout << "conversion operator:" << endl;
	cout << static_cast<int>(testRoll) << endl;
	
	//test the range based for loop
	cout << "range based for loop:" << endl;
	for (Dice& _dice : testRoll) {
		cout << _dice;
	};
	
	return 0;
};
#endif


//#define TEST_QWINTOROW
#ifdef TEST_QWINTOROW
int main() {
	cout << "TEST_QWINTOROW" << endl << endl;
	
	//create a test QwintoRoll
	QwintoRow<Colour::RED> testRow;
	
	//test the overloaded << operator
	cout << "<< operator:" << endl;
	cout << testRow << endl;
	
	//test the overloaded [] operator
	cout << "[] operator:" << endl;
	Dice diceRED = {Colour::RED, 1};
	Dice diceBLUE = {Colour::BLUE, 1};	
	RollOfDice roll;
	roll.addDice(diceRED);
	roll.addDice(diceBLUE);
	testRow[1] = roll;
	cout << testRow << endl;	
	
	//test the [validate] function
	cout << "validate function:" << endl;
	if (testRow.validate(roll, 2)) {
		testRow[2] = roll;
	};
	cout << testRow << endl;
	roll.roll();
	if (testRow.validate(roll, 2)) {
		testRow[2] = roll;
	};
	cout << testRow;
	
	return 0;
};
#endif


//#define TEST_QWINTOSCORESHEET
#ifdef TEST_QWINTOSCORESHEET
int main() {
	cout << "TEST_QWINTOSCORESHEET" << endl << endl;
	
	//create a test QwintoScoreSheet
	QwintoScoreSheet testScoreSheet{"PlayerA"};
	
	//test the overloaded << operator
	cout << "<< operator:" << endl;
	cout << testScoreSheet << endl;
	
	//test the [validate] function
	cout << "validate function:" << endl;
	Dice diceRED = {Colour::RED, 1};
	RollOfDice roll;
	roll.addDice(diceRED);
	if (testScoreSheet.validate(roll, Colour::RED, 0)) {
		cout << "The roll of dices can be scored." << endl << endl;
	};
	
	//test the [calcTotal] function
	cout << "calcTotal function:" << endl;
	cout << testScoreSheet.calcTotal() << endl << endl;
	
	//test the [score] function
	cout << "score function:" << endl;
	testScoreSheet.score(roll, Colour::RED, 0);
	cout << testScoreSheet << endl;
	
	//test the [setTotal] function
	cout << "setTotal function:" << endl;
	cout << testScoreSheet.setTotal() << endl << endl;
	
	//test the overloaded ! operator
	cout << "! operator:" << endl;
	if (!(testScoreSheet)) {
		cout << "The game is ended." << endl;
	} else {
		cout << "The game is not ended." << endl;
	};
	
	return 0;
};
#endif


//#define TEST_QWINTOPLAYER
#ifdef TEST_QWINTOPLAYER
int main() {
	cout<< "TEST_QWINTOPLAYER" << endl << endl;
	
	//create a test QwintoPlayer
	QwintoPlayer testQwintoPlayer{"PlayerA"};
	
	Dice diceRED = {Colour::RED, 1};
	Dice diceYELLOW = {Colour::YELLOW, 1};
	Dice diceBLUE = {Colour::BLUE, 1};
	RollOfDice roll;
	roll.addDice(diceRED);
	roll.addDice(diceYELLOW);
	roll.addDice(diceBLUE);
	
	//test the [inputBeforeRoll] function
	cout << "inputBeforeRoll function:" << endl;
	cout << testQwintoPlayer.inputBeforeRoll(roll) << endl;
	testQwintoPlayer.setActive();
	cout << testQwintoPlayer.inputBeforeRoll(roll) << endl;
	
	//test the [inputAfterRoll] function
	cout << "inputAfterRoll function:" << endl;
	Colour selectedColour;
	int selectedIndex;
	if (testQwintoPlayer.inputAfterRoll(roll, selectedColour, selectedIndex)) {
		cout << "Player select to score the roll." << endl;
	} else {
		cout << "Player select to not score the roll." << endl;
	}
	
	return 0;
};
#endif


#ifndef TEST_DICE
#ifndef TEST_ROLLOFDICE
#ifndef TEST_QWINTOROW
#ifndef TEST_QWINTOSCORESHEET
#ifndef TEST_QWINTOPLAYER
int main() {
	
	//Ask user to choose game version, number of players and names of players:

	//get game version (must be 1 or 2)
	int numVersion;
	do {
		cout << "Please enter 1 for Qwinto or 2 for Qwixx: ";
		cin >> numVersion;
	} while (numVersion!=1 && numVersion!=2);
	
	//get the number of players (must between 1-3)
	int numPlayers;
	do {
		cout << "Please enter the number of players: ";
		cin >> numPlayers;
	} while (numPlayers!=1 && numPlayers!=2 && numPlayers!=3);
	
	//get the names of players
	string playerNames[numPlayers];
	for (int i=0; i<numPlayers; i++) {
		string name;
		cout << "Please enter a name of one player: ";
		cin >> name;
		playerNames[i] = name;
	};
	cout << endl;
	
	
	//Create the corresponding RollOfDice for the game:
	Dice diceRED = {Colour::RED, 1};
	Dice diceYELLOW = {Colour::YELLOW, 1};
	Dice diceBLUE = {Colour::BLUE, 1};
	Dice diceGREEN = {Colour::GREEN, 1};
	Dice diceWHITE1 = {Colour::WHITE, 1};
	Dice diceWHITE2 = {Colour::WHITE, 1};
	
	RollOfDice allDices;
	allDices.addDice(diceRED);
	allDices.addDice(diceYELLOW);
	allDices.addDice(diceBLUE);
	
	
	//Create the corresponding players for the game:
	vector<Player*> allPlayers;	
	
	//initialize all players with given names for Qwinto or Qwixx based on game version
	if (numVersion==1) {		
		//initialize all players with given names 
		for (int i=0; i<numPlayers; i++) {
			Player* player;
			player = new QwintoPlayer(playerNames[i]);
			//player = new QwintoPlayer;
			//player->setName(playerNames[i]);
			allPlayers.push_back(player);
		};	
	};
	
	
	//While end condition is not reached
	bool isEnded=false;
	int playerCount=0;
	
	while (!isEnded) {
		//Next player takes a turn (becomes active)
		allPlayers[playerCount]->setActive();
		
		//Get input from active player before roll
		RollOfDice selectedDices = allPlayers[playerCount]->inputBeforeRoll(allDices);
			
		//Roll dice and show result
		selectedDices.roll();
		cout << selectedDices << endl;
			
		//Print scoresheet of active player
		cout << *(allPlayers[playerCount]->scoreSheet) << endl;
			
		//Get input from active player after roll
		Colour inputColourA;
		int inputIndexA;
		bool toScoreA = allPlayers[playerCount]->inputAfterRoll(selectedDices, inputColourA, inputIndexA);
			
		//Score dice according to input from active player
		if (toScoreA) {
			bool canScoreA = allPlayers[playerCount]->scoreSheet->score(selectedDices, inputColourA, inputIndexA);
			if (!canScoreA) {
				allPlayers[playerCount]->scoreSheet->addFailedCount();
			};
		} else {
			allPlayers[playerCount]->scoreSheet->addFailedCount();
		};	
		cout << *(allPlayers[playerCount]->scoreSheet) << endl;
			
		//check if active player ends the game (by 4 failed throws or 2 full filled rows)
		isEnded = !(*(allPlayers[playerCount]->scoreSheet));
		if (isEnded) {
			break;
		};
		
		//Loop over all non-active players
		for (int i=0; i<numPlayers; i++) {
			if (i!=playerCount) {
					
				//Print scoresheet of non-active player
				cout << *(allPlayers[i]->scoreSheet) << endl;
					
				//Get input from non-active player
				Colour inputColourN;
				int inputIndexN;
				bool toScoreN = allPlayers[i]->inputAfterRoll(selectedDices, inputColourN, inputIndexN);
					
				//Score dice according to input
				if (toScoreN) {
					allPlayers[i]->scoreSheet->score(selectedDices, inputColourN, inputIndexN);
				};
				cout << *(allPlayers[i]->scoreSheet) << endl;
					
				//check if non-active players end the game (by 2 full fill rows or 4 failed throws)
				isEnded = !(*(allPlayers[i]->scoreSheet));
				if (isEnded) {
					break;
				};
			};
		};
			
		allPlayers[playerCount]->setNotActive();
		
		if (playerCount==(numPlayers-1)) {
			playerCount=0;
		} else {
			playerCount++;
		};
	}; 
	
	
	//loop over all players
	bool findWinner=false;
	int winnerIndex=-1;
	int maxPoints=allPlayers[0]->scoreSheet->setTotal();
	
	for (int i=0; i<numPlayers; i++) {
			
		//Calculate points for player
		int score = allPlayers[i]->scoreSheet->setTotal();
			
		//if a player wins (full fill two rolls), the player wins
		if (allPlayers[i]->scoreSheet->win()) {
			winnerIndex=i;
			findWinner=true;
		};
			
		//if no player wins (full fill two rolls), the player with highest score and failed count<4 wins
		if (!findWinner && maxPoints<score && allPlayers[i]->scoreSheet->getFailedCount()<4) {
			maxPoints=score;
			winnerIndex=i;
		};
			
		//Print scoresheet
		cout << *(allPlayers[i]->scoreSheet) << endl;
	};
	
	
	//Print overall winner
	if (winnerIndex<0) {
		cout << "No winner" << endl;
	} else {
		cout << "Winner is player " << allPlayers[winnerIndex]->getName() << endl;
	};
	
  	return 0;
};
#endif
#endif
#endif
#endif
#endif
