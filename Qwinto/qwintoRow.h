#include <iostream>
#include <array>

#include "rollOfDice.h"
using namespace std;


//template declaration:
template<Colour colour> struct QwintoRow;
template<Colour colour> ostream& operator<<(ostream&, const QwintoRow<colour>&);


//template implementation:
template<Colour colour>
struct QwintoRow
{
	//variables:
	protected:
	int filledCount = 0;
	int rowArr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	public:
	const Colour rowColour = colour;
	
	
	//methods (in requirement):
	
	//overload [] operator to add an integer score at a certain index
	int& operator[](const int index) {
		return rowArr[index];
	};
	
	//perform error checking for adding a RollofDice to the row at a certain index
	bool validate(RollOfDice& _roll, int index) const{
		
		//check if rowArr[index] is not XX and has not be filled
  		if (rowColour==Colour::RED && (index==3 || rowArr[index]!=0)) {
  			cout << "FALIED: Position is not available." << endl << endl;
  			return false;
		} else if (rowColour==Colour::YELLOW && (index==5 || rowArr[index]!=0)) {
			cout << "FALIED: Position is not available." << endl << endl;
			return false;
		} else if (rowColour==Colour::BLUE && (index==4 || rowArr[index]!=0)) {
			cout << "FALIED: Position is not available." << endl << endl;
			return false;
		};
		
		//check if scores are in increasing order
  		int rollScore = _roll;
  		for (int i=0; i<index; i++) {
  			if (rowArr[i]!=0 && rowArr[i]>=rollScore) {
  				cout << "FALIED: Scores are not in increasing order." << endl << endl;
  				return false;
			};	
		};
		for (int i=index+1; i<10; i++) {
  			if (rowArr[i]!=0 && rowArr[i]<=rollScore) {
  				cout << "FALIED: Scores are not in increasing order." << endl << endl;
  				return false;
			};	
		};
		
		return true;
	}; 
	
	//overload << operator to print QwintoRoll
	friend std::ostream& operator<< <colour>(ostream&, const QwintoRow<colour>&);
	
	
	//methods (not in requirement):
	
	//set and return the number of filled position
	int setFilledCount() {
		int count=0;
		for (int i=0; i<10; i++) {
    		if ((rowColour==Colour::RED && i!=3) || (rowColour==Colour::YELLOW && i!=5) ||
				(rowColour==Colour::BLUE && i!=4)) {
  				if (rowArr[i]!=0) {
					count++;
				};
			};
  		};
  		filledCount = count;
  		return filledCount;
	};
	
	//return true if the row is full filled
	bool isFull() {
		if (setFilledCount()!=9) {
			return false;
		};
  		return true;
	};
	
	//return the score of the row
	int calcScore() {
		int score=0;
		if (isFull()) {
			score = rowArr[9];
		} else {
			score = filledCount;
		};
		return score;
	};
};


template<Colour colour>
ostream& operator<<(ostream& _os, const QwintoRow<colour>& _qwintoRoll)
{
	//before starting to print scores
	if (_qwintoRoll.rowColour==Colour::RED) {
  		_os << "      " << "|";
	} else if (_qwintoRoll.rowColour==Colour::YELLOW) {
		_os << "   " << "|";
	} else if (_qwintoRoll.rowColour==Colour::BLUE) {
		_os << "|";
	};
	
	//loop through each score
	for (int i=0; i<10; i++) {	
		
		//special positions: positions with % bounds or occupied by XX
		//normal positions: positions with | bounds		
		if (_qwintoRoll.rowColour==Colour::RED && (i==3 || i==0 || i==1 || i==4 || i==5)) {
			
			//colour RED: 3 is XX; 0, 1, 4, 5 is followed by %
			if (i==3) {
				_os << "XX" << "|";
			} else {
				if (_qwintoRoll.rowArr[i]==0) {
					_os << "  " << "%";
				} else if (_qwintoRoll.rowArr[i]<10) {
					_os << " " << _qwintoRoll.rowArr[i] << "%";
				} else {
					_os << _qwintoRoll.rowArr[i] << "%";
				};
			};
					
		} else if (_qwintoRoll.rowColour==Colour::YELLOW && (i==5 || i==6 || i==7)) {
			
			//colour YELLOW: 5 is XX; 6, 7 is followed by %
			if (i==5) {
				_os << "XX" << "|";
			} else {
				if (_qwintoRoll.rowArr[i]==0) {
					_os << "  " << "%";
				} else if (_qwintoRoll.rowArr[i]<10) {
					_os << " " << _qwintoRoll.rowArr[i] << "%";
				} else {
					_os << _qwintoRoll.rowArr[i] << "%";
				};
			};
			
		} else if (_qwintoRoll.rowColour==Colour::BLUE && (i==4 || i==1 || i==2 || i==8 || i==9)) {
			
			//colour BLUE: 4 is XX; 1, 2, 8, 9 is followed by %
			if (i==4) {
				_os << "XX" << "|";
			} else {
				if (_qwintoRoll.rowArr[i]==0) {
					_os << "  " << "%";
				} else if (_qwintoRoll.rowArr[i]<10) {
					_os << " " << _qwintoRoll.rowArr[i] << "%";
				} else {
					_os << _qwintoRoll.rowArr[i] << "%";
				};
			};
			
		} else {
			if (_qwintoRoll.rowArr[i]==0) {
				_os << "  " << "|";
			} else if (_qwintoRoll.rowArr[i]<10) {
				_os << " " << _qwintoRoll.rowArr[i] << "|";
			} else {
				_os << _qwintoRoll.rowArr[i] << "|";
			};
		};
				 
  	};
	
	_os << endl;			
	return _os;
};

//#include "qwintoRow.cpp"
