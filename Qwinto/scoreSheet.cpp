//Course: CSI 2372 A
//Project (work alone - implement Qwinto only)
//Student Name: Tianyu Shi
//Student Number: 7875409

#include "scoreSheet.h"
using namespace std;


//constructors:
ScoreSheet::ScoreSheet() {};

ScoreSheet::ScoreSheet(string playerName) {
	name = playerName;
};


//methods (in requirement):

//return true if the Dice can be scored and score it (overrided in derived class)
bool ScoreSheet::score(RollOfDice& _roll, Colour selectedColour, int pos) {
	return validate(_roll, selectedColour, pos);
};

//set and return the points for the final score
int ScoreSheet::setTotal() {
	return calcTotal();
}; 

//overload ! operator to return true if the ScoreSheet indicates the game has ended
bool ScoreSheet::operator!(){
 	return isEnded();
};

//overload << operator to print ScoreSheet
ostream& operator<<(ostream& _os, ScoreSheet& _scoreSheet) {
	return _scoreSheet.print(_os);
};


//methods (not in requirement):

//return true if the ScoreSheet indicates that the game has ended
bool ScoreSheet::isEnded(){
	//the game ends in two cases: 4 failed throws, and win
	if (failedCount==4 || win()) {
		return true;
	};
	return false;
};

//get ScoreSheet player name
void ScoreSheet::setName(string playerName) {
	name = playerName;
};
	 
//add failedCount by 1
void ScoreSheet::addFailedCount() {
	failedCount++;
};

//get ScoreSheet player name
string ScoreSheet::getName() {
	return name;
};

//get failedCount
int ScoreSheet::getFailedCount() {
	return failedCount;
};
