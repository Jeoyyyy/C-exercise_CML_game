#ifndef HEADER_FLAG_HELPROOM
#define HEADER_FLAG_HELPROOM
using namespace std;

class helproom:public room
{
public:
	helproom(int ex, int w, int e, int n, int s, int u, int d)
		: room(ex, w, e, n, s, u, d) {}
	virtual ~helproom(){}
	helproom(const helproom& help);
	virtual void show();
};

#endif