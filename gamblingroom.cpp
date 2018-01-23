#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "room.h"
#include "gamblingroom.h"
#include "position.h"

extern position mons, prin, cur;
gamblingroom::gamblingroom(const gamblingroom& ga)
{
	exitnum = ga.exitnum;
	west = ga.west;
	east = ga.east;
	north = ga.north;
	south = ga.south;
	up = ga.up;
	down = ga.down;
}
void gamblingroom::show()
{
	string decision, guess, destination;
	int x;
	cout << "````````````````````````````````GAMBLING````````````````````````````````````" << endl;
	cout << "Are you a gambler? Would you like to try?" << endl;
	cout << "I will flip a coin. if you are right about which face will be upward, You win the game and I can take you to the princess or to the lobby." << endl;
	cout << "But if you are wrong, I will send you to the monster. You have my words. Take a shot? Enter yes or no: " << endl;
	while(1){
		getline(cin, decision);
		if(decision == "yes"){
			srand((unsigned)time( NULL ));
			x = rand()%2;
			cout << "Fling......ALL RIGHT! Now guess which face will be upward. Enter positive or negative: " << endl;
			while(1){
				getline(cin, guess);
				if(guess == "positive" && x == 1 || guess == "negative" && x == 0){
					cout << "BINGO! Lucky day for you today! Now I'll keep my words. Would you like to be taken to the princess or to the lobby? Enter princess or lobby: " << endl;
					while(1){
						getline(cin, destination);
						if(destination == "princess"){
							cur = prin; break;
						}
						else if(destination == "lobby"){
							cur.lev = 0;
							cur.row = 2;
							cur.col = 1;
							break;
						}
						else
							cout << "Wrong command! Pless enter your command again!" << endl;
						}
					break;
				}
				else if (guess == "negative" && x == 1 || guess == "positive" && x == 0){
					cout << "Haaaaaa, Never gamble with me! Enjoy yourself with the monster! " << endl;
					cur = mons;
					break;
				}
				else
					cout << "Wrong command! Pless enter your command again!" << endl;
			}
			break;
		}
		else if(decision == "no"){
			break;
		}
		else
			cout << "Wrong command! Pless enter your command again!" << endl;	
	}
	cout << "````````````````````````````````GAMBLING````````````````````````````````````" << endl << endl;
}