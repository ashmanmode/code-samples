#include <iostream>
#include <fstream>
using namespace std;

struct point 
{
	long double x;
	long double y;
};

int main()
{
	ifstream in("inpChef.txt");
	point v,r1,r2;
	in >> v.x >> v.y ;
	in >> r1.x >> r1.y ;
	in >> r2.x >> r2.y ;
	cout << fixed << v.x << " " << v.y << endl ;
	return 0;
}