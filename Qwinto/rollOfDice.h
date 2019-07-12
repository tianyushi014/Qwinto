//Course: CSI 2372 A
//Project (work alone - implement Qwinto only)
//Student Name: Tianyu Shi
//Student Number: 7875409

#pragma once

#include <iostream>
#include <vector>

#include "dice.h"
using namespace std;


//helper structor used in order to do range for loop on RollOfDice
template<typename T>
struct Iterator
{
	//variables:
    vector<T>& typeVec;
    int pointerPos;
	
	
	//constructors:
    Iterator(vector<T>& vec) : typeVec{vec}, pointerPos{0} {}
    Iterator(vector<T>& vec, int size) : typeVec{vec}, pointerPos{size} {}
    
    
    //overload operators:
    bool operator!=(const Iterator<T>& other) const {
        return !(*this == other);
    }

    bool operator==(const Iterator<T>& other) const {
        return pointerPos == other.pointerPos;
    }

    Iterator& operator++() {
        pointerPos++;            
        return *this;
    }

    T& operator*() const {
        return typeVec.at(pointerPos);   
    }
};



struct RollOfDice
{
	//variables:
	protected:
	vector<Dice> diceVec;    
    int rollSize = 0;
	
	
	//methods (in requirement):
	public:
	
	//call roll function on all Dices in the container
	void roll();
	
	//return a RollOfDice contains two selected Dice
	RollOfDice pair(Dice& _diceA, Dice& _B);	
	
	//overload conversion operator to add all the faces in the roll
	operator int();
	
	//overload << operator to print RollOfDice
    friend ostream& operator<<(ostream& _os, RollOfDice& _diceRoll);
	
	
	//methods (not in requirement):
	
	//set the size of the roll
    void setRollSize();
    
    //get the size of the roll
    int getRollSize() const;
      
    //return true if a dice can be added to the roll
    bool isValidated(Dice& _dice) const;
	
	//add a dice to the current RollOfDice
    void addDice(Dice dice);
    
    //overload [] operator to get a dice by position
    Dice& operator[](int index);
	
	
	//range-based for loop methods:
    Iterator<Dice> begin();
    Iterator<Dice> end();
};
