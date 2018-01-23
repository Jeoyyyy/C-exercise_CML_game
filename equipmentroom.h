#ifndef HEADER_FLAG_EQUIPMENTROOM
#define HEADER_FLAG_EQUIPMENTROOM
using namespace std;

class equipmentroom:public room
{
public:
	equipmentroom(int ex, int w, int e, int n, int s, int u, int d)
		: room(ex, w, e, n, s, u, d) {}
	virtual ~equipmentroom(){}
	equipmentroom(const equipmentroom& eq);
	virtual void show();
};

#endif