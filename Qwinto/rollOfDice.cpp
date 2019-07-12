#include <cstddef>
#include <algorithm>

#include "rollOfDice.h"
using namespace std;


//methods (in requirement):

//call roll function on all Dices in the container
void RollOfDice::roll() {
	for (Dice& _dice:diceVec) {
      	_dice.roll();
  	}
};

//return a RollOfDice contains two selected Dice
RollOfDice RollOfDice::pair(Dice& _diceA, Dice& _diceB) {
	RollOfDice roll;
	roll.addDice(_diceA);
	roll.addDice(_diceB);
	return roll;
}; 

//overload conversion operator to add all the faces in the roll
RollOfDice::operator int() {
	int allFaceValues=0;
	for (Dice const& dice:diceVec) {
      	allFaceValues += dice.faceValue;
  	};
	return allFaceValues;
};

//overload << operator to print RollOfDice
ostream& operator<<(ostream& _os, RollOfDice& _diceRoll) {
	int rollScore=0;
    for (Dice const& dice:_diceRoll) {
      	_os << dice;
      	rollScore += dice.faceValue;
  	};
  	_os << "Total score of this roll: " << rollScore << endl;
	return _os;
};


//methods (not in requirement):

//set the size of the roll
void RollOfDice::setRollSize() {
	rollSize = diceVec.size();
};

//get the size of the roll
int RollOfDice::getRollSize() const {
	return rollSize;
};

//return true if a dice can be added to the roll
bool RollOfDice::isValidated(Dice& _dice) const{
	
	//for the selected dice, find the occurance of its colour in the current RollOfDice
	int colourCount=0;	
	for (Dice const& _d:diceVec) {
		if (_d.colour==_dice.colour) {
			colourCount++;
		}
	};
	
	//one RollOfDice can have only 1 dice for each colours except WHITE, which can have 2 WHITE dices
	if ((_dice.colour!=Colour::WHITE && colourCount==0) || (_dice.colour==Colour::WHITE && colourCount<2)) {
		return true;
	};
	
	return false;
}; 

//add a dice to the current RollOfDice
void RollOfDice::addDice(Dice dice) {
	if (isValidated(dice)) {
		
		//add the dice only if it is validated
		diceVec.push_back(dice);
		
		//update size of RollOfDice
    	setRollSize();
	};  
};

//overload [] operator to get a dice by position
Dice& RollOfDice::operator[](int index) {
	return diceVec.at(index);	
};


//range-based for loop methods:
Iterator<Dice> RollOfDice::begin() {
    return Iterator<Dice>(diceVec);
}

Iterator<Dice> RollOfDice::end() {
    return Iterator<Dice>(diceVec, diceVec.size());
};
