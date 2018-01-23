#include <iostream>
#include <string>
#include "room.h"
#include "helproom.h"
#include "position.h"

extern position mons, prin, cur;

helproom::helproom(const helproom& help)
{
	exitnum = help.exitnum;
	west = help.west;
	east = help.east;
	north = help.north;
	south = help.south;
	up = help.up;
	down = help.down;
}
void helproom::show()
{
	cout << "`````````````````````````````````help```````````````````````````````````" << endl;
	cout << "Lucky as you are, you are gonna get some information about the princess and the monster" << endl;
	if(prin.lev == cur.lev)
		cout << "The princess ARE in this level. Find her!" << endl;
	else
		cout << "The princess ARE NOT in this level. Find somewhere else!" << endl;
	if(mons.lev == cur.lev)
		cout << "The monster ARE in this level, Watch out!" << endl;
	else
		cout << "The monster ARE NOT in this level, Relax!" << endl;
	cout << "`````````````````````````````````help```````````````````````````````````" << endl << endl;
}