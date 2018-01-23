#include <iostream>
#include <string>
#include "room.h"
#include "position.h"

extern position cur;
room::room(const room& rm)
{
	exitnum = rm.exitnum;
	west = rm.west;
	east = rm.east;
	north = rm.north;
	south = rm.south;
	up = rm.up;
	down = rm.down;
	prompt = rm.prompt;
}
int room::go()
{
	string cmd;
	dir();
		while(1){
			cout << "Enter your command: " << endl; 
			getline(cin, cmd);
			cout << endl;
			if(cmd == "go west" && west){
				cur.col -= 1;
				return 1;
			}
			else if(cmd == "go east" && east){
				cur.col += 1;
				return 1;
			}
			else if(cmd == "go north" && north){
				cur.row -= 1;
				return 1;
			}
			else if(cmd == "go south" && south){
				cur.row += 1;
				return 1;
			}
			else if(cmd == "go up" && up){
				cur.lev += 1;
				return 1;
			}
			else if(cmd == "go down" && down){
				cur.lev -= 1;
				return 1;
			}
			else if(cmd == "exit")
				return 0;
			cout << "Wrong command! Pless enter your command again!" << endl;
		}
}
void room::show()
{
	cout << "`````````````````````````````````````````````````````````````````````````" << endl;
	cout << prompt << endl;
}
void room::dir()
{
	cout << "There are " << exitnum << " exits as: ";
	if(west)
		cout << "west ";
	if(east)
		cout << "east ";
	if(north)
		cout << "north ";
	if(south)
		cout << "south ";
	if(up)
		cout << "up ";
	if(down)
		cout << "down ";
	cout << endl;
}


