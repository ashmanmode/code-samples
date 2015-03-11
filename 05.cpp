#include <iostream>

using namespace std;

class Point 
{
private:
	int x0,x1;
public:
	Point(int x,int y)
	{
		x0 = x ; x1 = y;
	}
	//Copy Constructor
	Point(const Point &Pt)
	{
		x0 = Pt.x0 ; 
		x1 = Pt.x1 ; 
	}
	int getx()
	{
		return x0;
	}
	int gety()
	{
		return x1;
	}
};

int main()
{
	Point a1(10,45);
	Point a2(a1) ; 

	cout << "Point 1  " << a1.getx() << "  " << a1.gety() << endl;
	cout << "Point 2  " << a2.getx() << "  " << a2.gety() << endl;
	return 0;
}