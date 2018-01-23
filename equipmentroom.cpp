#include <iostream>
#include <string>
#include "room.h"
#include "equipmentroom.h"
extern int sheild;
equipmentroom::equipmentroom(const equipmentroom& eq)
{
	exitnum = eq.exitnum;
	west = eq.west;
	east = eq.east;
	north = eq.north;
	south = eq.south;
	up = eq.up;
	down = eq.down;
}

void equipmentroom::show()
{
	static int sheildStorage = 1;
	cout << "```````````````````````````````EQUIPMENTROOM``````````````````````````````" << endl;
	if(sheildStorage){
		cout << "There is a sheild for you in this room. With this sheild You will be protected from the monster for only one time" << endl;
		cout << "That means, when you encounter the monster, you will not die But you will lost the sheild, and the monster will hide elsewhere" <<endl;
		cout << "Good luck with that!" << endl;
		sheild++;
		sheildStorage = 0;
	}
	else{
		cout << "The sheild has already been taken!" << endl;
	}
	cout << "```````````````````````````````EQUIPMENTROOM``````````````````````````````" << endl << endl;
}