#include "dice.h"
#include "randomDice.h"
using namespace std;


//methods (in requirement):

//change face value randomly between 1 and 6 and return it
int Dice::roll() {
	RandomDice rDice;	
	faceValue = rDice.distribution(rDice.mersenne_generator);
	return faceValue;
}

//overload << operator to print Dice
ostream& operator<<(ostream& _os, const Dice& _dice) {
	string diceColour;
    switch(_dice.colour) {
		case Colour::RED:
			diceColour = "RED";
			break;
		case Colour::YELLOW:
			diceColour = "YELLOW";
			break;
		case Colour::BLUE:
			diceColour = "BLUE";
			break;
		case Colour::GREEN:
			diceColour = "GREEN";
			break;
		case Colour::WHITE:
			diceColour = "WHITE";
			break;
	};
	_os << "Dice colour: " << diceColour << "; face value: " << _dice.faceValue << endl;
	return _os;
};
