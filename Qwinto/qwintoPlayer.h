//Course: CSI 2372 A
//Project (work alone - implement Qwinto only)
//Student Name: Tianyu Shi
//Student Number: 7875409

#include <iostream>

#include "player.h"
#include "qwintoScoreSheet.h"
using namespace std;


class QwintoPlayer: public Player
{
	//variables:
	protected:
	QwintoScoreSheet qScoreSheet;
	
	
	//constructor:
	public:
	QwintoPlayer();
	QwintoPlayer(string playerName);
	
	
	//methods (in requirement):
	
	//return a RollOfDice based on player's selection of dices
	RollOfDice inputBeforeRoll(RollOfDice& _roll);
	
	//return true if player decides to score the roll and modify the reference of colour and position
	bool inputAfterRoll(RollOfDice& _roll, Colour& _colour, int& index);
};
