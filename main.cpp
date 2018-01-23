#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "room.h"
#include "elevator.h"
#include "helproom.h"
#include "position.h"
#include "equipmentroom.h"
#include "gamblingroom.h"
using namespace std;

position mons, prin, cur = {0, 2, 1};
int map[3][3][3] = {0};
int sheild = 0, PrinFound = 0;
typedef room* ptoroom;
ptoroom ***rm;

int roomcheck()
{
		if(cur == mons){
			if(sheild){
				sheild--;
				cout << "Is it the princess? You say to yourself as you walk into the room, aware of something unusal. " << endl;
				cout << "^^^^^^^^^^^^^^^^^" << endl;
				cout << "< A MONSTER!!!  >" << endl;
				cout << "^^^^^^^^^^^^^^^^^" << endl;
				cout << "The monster rush to you. You are scared to death. Just in the moment you recall that you have a sheild. You raise your sheild immediately. "
				<< "The monster hit on your sheild badly and the run away. However, your sheild is also broken. 'That was close' You said to yourself." << endl;
				while(mons == prin || mons == cur || map[mons.lev][mons.row][mons.col] == 0){
					mons.lev = rand()%3;
					mons.row = rand()%3;
					mons.col = rand()%3;	
				}
			}
			else{
				cout << "Is it the princess? You say to yourself as you walk into the room, aware of something unusal. " << endl;
				cout << "	xxxxxxxxxxxxxxxxx" << endl;
				cout << "	x A MONSTER!!!  x" << endl;
				cout << "	xxxxxxxxxxxxxxxxx" << endl;
				cout << "It was too late. You lost your princess, and your life" << endl;
				cout << "|---------------|" << endl;
				cout << "|   GAME OVER!  |" << endl;
				cout << "|---------------|" << endl;
				cout << "-------------------------------------------------------------------------" << endl;
				return 0;	
			}
		}
		if(cur == prin && !PrinFound){
			cout << "******************************************************" << endl;
			cout << "* Congratualations! The princess have been found!    *" << endl;
			cout << "* Please take her leave the castle through the lobby!*" << endl;
			cout << "* Watch for the monster!                             *" << endl;
			cout << "******************************************************" << endl;
			PrinFound = 1;
		}
		if(cur.lev == 0 && cur.row == 2 && cur.col ==1 && PrinFound){
			cout << "************************************************************" << endl;
			cout << "* Congratualations again!                                  *" << endl;
			cout << "* You have come back to the lobby and can leave the castle!*" << endl;
			cout << "* May you happy with the princess!                         *" << endl;
			cout << "************************************************************" << endl;
			return 0;
		}
		return -1;
}

int main()
{
	int i, j;
	ptoroom ***rm = new ptoroom**[3];
	for(i = 0; i < 3; i++){
		rm[i] = new ptoroom*[3];
		for(j = 0; j <3; j++)
			rm[i][j] = new ptoroom[3];
	}

	rm[0][0][1] = new room(2, 0, 1, 0, 1, 0, 0, "You just heard a sound. Is it a moan? Is it from upstairs? You can't tell");
	rm[0][0][2] = new elevator(2, 1, 0, 0, 1, 0, 0);
	rm[0][1][1] = new room(3, 0, 1, 1, 1, 0, 0, "You have walked in to an empty single room. So huge the castle is. Is it even possible to find the princess?");
	rm[0][1][2] = new helproom(2, 1, 0, 1, 0, 0, 0);
	rm[0][2][0] = new room(1, 0, 1, 0, 0, 0, 0, "It's a dining room. The chicken in the table is still hot");
	rm[0][2][1] = new room(3, 1, 0, 1, 0, 1, 0, "Welcome to the lobby!");
	map[0][0][1] = 1;
	map[0][0][2] = 1;
	map[0][1][1] = 1;
	map[0][1][2] = 1;
	map[0][2][0] = 1;
	map[0][2][1] = 1;

	rm[1][0][1] = new helproom(1, 0, 1, 0, 0, 0, 0);
	rm[1][0][2] = new elevator(2, 1, 0, 0, 1, 0, 0);
	rm[1][1][2] = new room(2, 0, 0, 1, 1, 0, 0, "A sunbeam penetrate the windows in the balcony. A bit reassuring.");
	rm[1][2][0] = new gamblingroom(1, 0, 1, 0, 0, 0, 0);
	rm[1][2][1] = new room(4, 1, 1, 0, 0, 1, 1, "The door you just came from opened. Is it wind? ");
	rm[1][2][2] = new equipmentroom(2, 1, 0, 1, 0, 0, 0);
	map[1][0][1] = 1;
	map[1][0][2] = 1;
	map[1][1][2] = 1;
	map[1][2][0] = 1;
	map[1][2][1] = 1;
	map[1][2][2] = 1;

	rm[2][0][0] = new equipmentroom(1, 0, 1, 0, 0, 0, 0);
	rm[2][0][1] = new room(4, 1, 1, 0, 1, 0, 1, "A secret ladder showed up in the corner. Is is a thread? or a trap?");
	rm[2][0][2] = new elevator(2, 1, 0, 0, 1, 0, 0);
	rm[2][1][1] = new room(3, 0, 1, 1, 1, 0, 0, "A big swiming pool jumped into your eyes. What a castle! But you need to find the princess and leave as soon as possible. ");
	rm[2][1][2] = new gamblingroom(2, 1, 0, 1, 0, 0, 0);
	rm[2][2][1] = new helproom(2, 0, 0, 1, 0, 0, 1);
	map[2][0][0] = 1;
	map[2][0][1] = 1;
	map[2][0][2] = 1;
	map[2][1][1] = 1;
	map[2][1][2] = 1;
	map[2][2][1] = 1;

	srand((unsigned)time( NULL ));
	mons.lev = rand()%3;
	mons.row = rand()%3;
	mons.col = rand()%3;
	while(mons == cur || map[mons.lev][mons.row][mons.col] == 0){
		mons.lev = rand()%3;
		mons.row = rand()%3;
		mons.col = rand()%3;
	}
	prin.lev = rand()%3;
	prin.row = rand()%3;
	prin.col = rand()%3;
	while(prin == cur || prin == mons || map[prin.lev][prin.row][prin.col] == 0){
		prin.lev = rand()%3;
		prin.row = rand()%3;
		prin.col = rand()%3;
	}

	cout << "	//======================================================//" << endl;
	cout << "	//                                                      //" << endl;
	cout << "	//                ADVENTURE in the CASTLE!              //" << endl;
	cout << "	//                                                      //" << endl;
	cout << "	//                                        By:LiZhaoyang //" << endl;
	cout << "	//                          Email:lizhaoyang@zju.edu.cn //" << endl;
	cout << "	//                                   Copyright reserved //" << endl;
	cout << "	//======================================================//" << endl;
	cout << endl << endl;
	cout << "	|~~~~~~~~~~~~~~~~~~~~~INTRODUCTION~~~~~~~~~~~~~~~~~~~~~~|" << endl;
	cout << "	|                                                       |" << endl;
	cout << "	|    Your beloved princess is prisoned in a castle by a |" << endl;
	cout << "	| ferocious monster. You must explore the castle by     |" << endl;
	cout << "	| yourself and find the room where the princess is      |" << endl;
	cout << "	| prinsoned and take her leave the castle to reunit     |" << endl;
	cout << "	| with your princess again. There are many different    |" << endl;
	cout << "	| rooms in the castle, and the monster is in one of     |" << endl;
	cout << "	| them, which you must avoid.                           |" << endl;
	cout << "	|                                                       |" << endl;
	cout << "	|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
	cout << endl;
	cout << "	|------------------------TIPS---------------------------|" << endl;
	cout << "	|                                                       |" << endl;
	cout << "	|   *Follow the instructions and informations given     |" << endl;
	cout << "	|   *Explore different rooms by commands like 'go east' |" << endl;
	cout << "	|   *There are 3 levels in the castle                   |" << endl;
	cout << "	|   *Type 'exit' to exit the game.                      |" << endl;
	cout << "	|                                                       |" << endl;
	cout << "	|-------------------------------------------------------|" << endl;
	cout << endl;
	cout << "ADVENTURE BEGINS!" << endl;
	rm[cur.lev][cur.row][cur.col]->show();
	while(1){
		if(rm[cur.lev][cur.row][cur.col]->go() == 0)
			return 0;
		if(roomcheck() == 0)
			return 0;
		rm[cur.lev][cur.row][cur.col]->show();
		if(roomcheck() == 0)
			return 0;
	}
}