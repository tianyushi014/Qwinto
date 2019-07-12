//Course: CSI 2372 A
//Project (work alone - implement Qwinto only)
//Student Name: Tianyu Shi
//Student Number: 7875409


#include "qwintoScoreSheet.h"

using namespace std;


//constructors:
QwintoScoreSheet::QwintoScoreSheet() : ScoreSheet::ScoreSheet() {};

QwintoScoreSheet::QwintoScoreSheet(string playerName) : ScoreSheet::ScoreSheet(playerName) {};


//methods (in requirement):

//return true if a dice can be scored
bool QwintoScoreSheet::validate(RollOfDice& _roll, Colour selectedColour, int pos) {
	
	//check if the index is between 0-9
	if (pos<0 || pos>9) {
		cout << "Invalid index: " << pos << endl << endl;
		return false;
	};
  	
	//check if the dice of the corresponding colour is used
	bool isUsed=false;
	
	for (auto const& dice:_roll) {		
		//check if the roll can be scored if the dice is used
      	if (dice.colour == selectedColour) {
		  	int rollScore = _roll;
				
			if (selectedColour == Colour::RED) {
      			isUsed=true;
      			
      			//check if the column has the same score
      			if ((pos<8 && rowYELLOW[pos+1]!=rollScore && rowBLUE[pos+2]!=rollScore) ||
					(pos==8 && rowYELLOW[9]!=rollScore) ||
					(pos==9)) {
					return rowRED.validate(_roll, pos);
				} else {
					cout << "Scores overlap in column." << endl << endl;
				};
				
			} else if (selectedColour == Colour::YELLOW) {
				isUsed=true;
				
				//check if the column has the same score
      			if ((pos==0 && rowBLUE[1]!=rollScore) ||
				  	(pos>0 && pos<9 && rowRED[pos-1]!=rollScore && rowBLUE[pos+1]!=rollScore) ||
					(pos==9 && rowRED[8]!=rollScore)) {			
      				return rowYELLOW.validate(_roll, pos);
				} else {
					cout << "Scores overlap in column." << endl << endl;
				};
				
			} else if (selectedColour == Colour::BLUE) {
				isUsed=true;
				
				//check if the column has the same score
      			if ((pos==0) ||
				  	(pos==1 && rowYELLOW[0]!=rollScore) ||
					(pos>1 && rowRED[pos-2]!=rollScore && rowYELLOW[pos-1]!=rollScore)) {
					return rowBLUE.validate(_roll, pos);
				} else {
					cout << "Scores overlap in column." << endl << endl;
				};
			};
		};
  	};
  	
  	if (!isUsed) {
  		cout << "The dice of the corresponding colour is not used." << endl << endl; 
	};
  	
  	return false;
};

//calculate total points
int QwintoScoreSheet::calcTotal() {
	//check RED row:
	int scoreRED = rowRED.calcScore();
	
	//check YELLOW row:
	int scoreYELLOW = rowYELLOW.calcScore();
	
	//check BLUE row:
	int scoreBLUE = rowBLUE.calcScore();
	
	//check bonus (position is filled and no repeating in a column):
	int scoreBonus = 0; 
	if ( (rowRED[0]>0 			  && rowYELLOW[1]>0 	   && rowBLUE[2]>0) &&
		 (rowRED[0]!=rowYELLOW[1] && rowRED[0]!=rowBLUE[2] && rowYELLOW[1]!=rowBLUE[2]) ) {
		scoreBonus = rowBLUE[2]; 
	} else if ( (rowRED[1]>0 			 && rowYELLOW[2]>0		  && rowBLUE[3]>0) &&
				(rowRED[1]!=rowYELLOW[2] && rowRED[1]!=rowBLUE[3] && rowYELLOW[2]!=rowBLUE[3]) ) {
		scoreBonus = rowRED[1]; 
	} else if ( (rowRED[5]>0 			 && rowYELLOW[6]>0	 	  && rowBLUE[7]>0) &&
		 		(rowRED[5]!=rowYELLOW[6] && rowRED[5]!=rowBLUE[7] && rowYELLOW[6]!=rowBLUE[7]) ) {
		scoreBonus = rowRED[5]; 
	} else if ( (rowRED[6]>0 			 && rowYELLOW[7]>0 	  && rowBLUE[8]>0) &&
				(rowRED[6]!=rowYELLOW[7] && rowRED[6]!=rowBLUE[8] && rowYELLOW[7]!=rowBLUE[8]) ) {
		scoreBonus = rowYELLOW[7];
	} else if ( (rowRED[7]>0 			 && rowYELLOW[8]>0	 	  && rowBLUE[9]>0) &&
				(rowRED[7]!=rowYELLOW[8] && rowRED[7]!=rowBLUE[9] && rowYELLOW[8]!=rowBLUE[9]) ) {
		scoreBonus = rowBLUE[9]; 
	}; 
	
	//check failed throws:
	int scoreMinus = failedCount*5;
	
	totalScore = scoreRED+scoreYELLOW+scoreBLUE+scoreBonus-scoreMinus;
	return totalScore;
};

//return true if the Dice can be scored and enter score
bool QwintoScoreSheet::score(RollOfDice& _roll, Colour selectedColour, int pos) {
	//check if the roll can be scored with given colour and position
	bool res = validate(_roll, selectedColour, pos);
	
	//enter score if the result is positive
	if (res) {
		if (selectedColour == Colour::RED) {
			rowRED[pos] = _roll;
		} else if (selectedColour == Colour::YELLOW) {
			rowYELLOW[pos] = _roll;
		} else if (selectedColour == Colour::BLUE) {
			rowBLUE[pos] = _roll;
		};
	};
	
	//return if the roll can be scored
	return res;
};

//overload << operator to print QwintoScoreSheet
ostream& operator<<(ostream& _os, QwintoScoreSheet& _qwintoScoreSheet) {
    return _qwintoScoreSheet.print(_os);
};


//methods (not in requirement):

//return true if the ScoreSheet indicates that the player wins
bool QwintoScoreSheet::win() {
	//check how many full filled rows the player has
	int countFullRows=0;
	if (rowRED.isFull()) {
		countFullRows++;
	} else if (rowYELLOW.isFull()) {
		countFullRows++;
	} else if (rowBLUE.isFull()) {
		countFullRows++;
	};
	
	//the player wins if there is at 2 full filled rows
	return countFullRows>=2;
};

//helper to print ScoreSheet
ostream& QwintoScoreSheet::print(ostream& _os) {
	
	//print the first line: player name, total score(if not 0)
	_os << "Player name: " << name;
	if (totalScore!=0) {
		_os << "            " << "Points: " << totalScore;
	};
	_os << endl;
	
	//print 3 rows for colour RED, YELLOW, BLUE
	_os << rowRED;
	_os << rowYELLOW;
	_os << rowBLUE;
	
	//print the failed throws (if any)
	_os << "Failed throws: ";
	for(int i=1; i<=failedCount; i++) {
		_os << i << " ";	
	};
	_os << endl;
	
	return _os;
};

