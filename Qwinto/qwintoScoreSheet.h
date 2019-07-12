//Course: CSI 2372 A
//Project (work alone - implement Qwinto only)
//Student Name: Tianyu Shi
//Student Number: 7875409

#include <iostream>

#include "scoreSheet.h"
#include "qwintoRow.h"
using namespace std;


class QwintoScoreSheet: public ScoreSheet
{
	//variables:
	protected:
	QwintoRow<Colour::RED> rowRED;
	QwintoRow<Colour::YELLOW> rowYELLOW;
	QwintoRow<Colour::BLUE> rowBLUE;
	
	
	//constructors:
	public:
	QwintoScoreSheet();	
	QwintoScoreSheet(string playerName);
	
	
	//methods (in requirement):
	
	//return true if a dice can be scored
	bool validate(RollOfDice& _roll, Colour selectedColour, int pos=-1);
	
	//calculate total points
 	int calcTotal();
 	 	
 	//return true if the Dice can be scored and score it
 	bool score(RollOfDice& _roll, Colour selectedColour, int pos=-1);
 	
 	//overload << operator to print QwintoScoreSheet
    friend ostream& operator<<(ostream& _os, QwintoScoreSheet& _qwintoScoreSheet);
 	
 	
 	//methods (not in requirement):
 	
 	//return true if the ScoreSheet indicates that the player wins
 	bool win();
 	
 	//helper to print ScoreSheet
 	ostream& print(ostream& _os);
};
