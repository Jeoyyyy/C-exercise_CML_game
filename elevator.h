#ifndef HEADER_FLAG_ELEVATOR
#define HEADER_FLAG_ELEVATOR
using namespace std;

class elevator:public room
{
public:
	elevator(int ex, int w, int e, int n, int s, int u, int d)
		: room(ex, w, e, n, s, u, d) {}
	virtual ~elevator(){}
	elevator(const elevator& ele);
	virtual void show();
};

#endif