#include <iostream>
#include <string>
#include "room.h"
#include "elevator.h"
#include "position.h"

typedef room* ptoroom;
extern ptoroom ***rm;
extern position cur;
elevator::elevator(const elevator& ele)
{
	exitnum = ele.exitnum;
	west = ele.west;
	east = ele.east;
	north = ele.north;
	south = ele.south;
	up = ele.up;
	down = ele.down;
}
void elevator::show()
{
	string level;
	cout << "`````````````````````````````````ELEVATOR`````````````````````````````````" << endl;
	cout << "You have found an elevator!" << endl;
	cout << "You can go to any level you like through the elevator" << endl;
	while(1){
		cout << "Please enter which level you would like to go from 1 to 3, if you don't, enter 0: " << endl;
		getline(cin, level);
		if(level == "1"){
			cur.lev = 0; break;
		}
		else if(level == "2"){
			cur.lev = 1; break;
		}
		else if(level == "3"){
			cur.lev = 2; break;
		}
		else if(level == "0"){
			break;
		}
		else
			cout << "Wrong command! Pless enter your command again!" << endl;
	}
	cout << "`````````````````````````````````ELEVATOR`````````````````````````````````" << endl << endl;
}