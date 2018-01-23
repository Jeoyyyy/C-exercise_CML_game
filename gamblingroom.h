#ifndef HEADER_FLAG_GAMBLINGROOM
#define HEADER_FLAG_GAMBLINGROOM
using namespace std;

class gamblingroom:public room
{
public:
	gamblingroom(int ex, int w, int e, int n, int s, int u, int d)
		: room(ex, w, e, n, s, u, d) {}
	virtual ~gamblingroom(){}
	gamblingroom(const gamblingroom& ga);
	virtual void show();
};

#endif