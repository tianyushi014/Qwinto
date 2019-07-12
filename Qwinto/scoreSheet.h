//Course: CSI 2372 A
//Project (work alone - implement Qwinto only)
//Student Name: Tianyu Shi
//Student Number: 7875409

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "rollOfDice.h"
using namespace std;


class ScoreSheet
{
	//variables:
    protected:
    string name;
    int failedCount = 0;
    int totalScore = 0;
 	
 	
 	//constructors:
 	public:
 	ScoreSheet();
 	ScoreSheet(string playerName);
 	
 	
 	//methods (in requirement):
 	
 	protected:
 	//return true if a dice can be scored
	virtual bool validate(RollOfDice& _roll, Colour _selectedColour, int pos=-1)=0;	
 	
 	public:
 	//calculate total points
 	virtual int calcTotal()=0; 	
 	
 	//return true if the Dice can be scored and score it (overrided in derived class)
 	//(overrided in derived class since ways of scoring points are different in Qwinto and Qwixx
 	virtual bool score(RollOfDice& _roll, Colour selectedColour, int pos=-1);
 	
 	//set and return the points for the final score
 	int setTotal();	
 	
 	//overload ! operator to return true if the ScoreSheet indicates the game has ended
 	bool operator!();
  
 	//overload << operator to print ScoreSheet
    friend ostream& operator<<(ostream& _os, ScoreSheet& _scoreSheet);
    
 	
 	//methods (not in requirment):
 	
 	//return true if the ScoreSheet indicates that the player wins
	//(override in derived class since ways of determine winning are different in Qwinto and Qwixx)
 	virtual bool win()=0;
 	 	
	//return true if the ScoreSheet indicates that the game has ended
 	bool isEnded(); 	
 	
 	//get ScoreSheet player name
 	void setName(string playerName);
	 
	//add ScoreSheet player failedCount by 1
 	void addFailedCount();
 	
 	//get ScoreSheet player name
 	string getName();
	
 	//get ScoreSheet playerfailedCount
 	int getFailedCount();
 	
 	//helper to print ScoreSheet
 	virtual ostream& print(ostream& _os)=0;
}; 
