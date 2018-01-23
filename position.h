#ifndef HEADER_FLAG_POSITION
#define HEADER_FLAG_POSITION
using namespace std;

struct position{
	int lev;
	int row;
	int col;
	bool operator == (const position& p){
		return lev == p.lev && row == p.row && col == p.col;
	}
};

#endif