#ifndef HEADER_FLAG_ROOM
#define HEADER_FLAG_ROOM
using namespace std;

class room
{
public:
	room(int ex, int w, int e, int n, int s, int u, int d, string st)
		: exitnum(ex), west(w), east(e), north(n), south(s), up(u), down(d), prompt(st){}
	room(int ex, int w, int e, int n, int s, int u, int d)
		: exitnum(ex), west(w), east(e), north(n), south(s), up(u), down(d){}
	room(){}
	room(const room& rm);
	virtual ~room(){}
	int go();
	virtual void show();
	void dir();
protected:
	int exitnum, west, east, north, south, up, down;
private:
	string prompt;
};

#endif