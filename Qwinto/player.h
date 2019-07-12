//Course: CSI 2372 A
//Project (work alone - implement Qwinto only)
//Student Name: Tianyu Shi
//Student Number: 7875409

#pragma once

#include <iostream>
#include <string>

#include "rollOfDice.h"
#include "scoreSheet.h"
using namespace std;


class Player
{
	//variables:
    protected:
    string name;
 	bool isActive;
 	
 	public:
 	ScoreSheet* scoreSheet;
 	
 	
 	//constructors:
 	public:
 	Player();
 	Player(string playerName);
 	
 	
 	//methods (in requirement):
	
	//return a RollOfDice based on player's selection of dices
	virtual RollOfDice inputBeforeRoll(RollOfDice& _roll)=0;
	
	//return true if player decides to score the roll and modify the reference of colour and position
	virtual bool inputAfterRoll(RollOfDice& _roll, Colour& _colour, int& index)=0;
	
	
	//methods (not in requirement):
	
	//set player's name
	void setName(string playerName);
	
	//set player's status to active
	void setActive();
	
	//set player's status to non-active
	void setNotActive();
	
	//get player's name
	string getName();
	
	//get player's status
	string getStatus();	
}; 
