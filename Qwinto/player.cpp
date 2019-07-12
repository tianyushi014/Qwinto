//Course: CSI 2372 A
//Project (work alone - implement Qwinto only)
//Student Name: Tianyu Shi
//Student Number: 7875409

#include "player.h"
using namespace std;


//constructors:
Player::Player() {};
Player::Player(string playerName) {
	name = playerName;
	isActive = false;
};


//methods (not in requirement):

//set player's name
void Player::setName(string playerName) {
	name = playerName;
};
	
//set player's status to active
void Player::setActive() {
	isActive=true;
	cout << "Player [" << getName() << "] now become " << getStatus() << endl << endl;
};

//set player's status to non-active
void Player::setNotActive() {
	isActive=false;
	cout << "Player [" << getName() << "] now become " << getStatus() << endl << endl;
};

//get player's name
string Player::getName() {
	return name;
};

//get player's status
string Player::getStatus() {
	if (isActive) {
		return "ACTIVE";
	} else {
		return "NOT ACTIVE";
	};
};
