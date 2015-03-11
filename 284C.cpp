#include <iostream>
using namespace std;

typedef signed long long int si;

int main()
{
	si a,b,c,d;
	cin >> a >> b >> c >> d ;
	int n ;
	cin >> n ;
	int count = 0 ; 
	si x,y,z ;
	si tmp1,tmp2;
	for(int i = 0 ; i < n ; i++ )
	{
		cin >> x >> y >> z ;
		tmp1 = x*a + y*b + z ;
		tmp2 = x*c + y*d + z ;
		if( (tmp1 < 0 && tmp2 > 0) || (tmp1 > 0 && tmp2 < 0) )
			count++ ;
	}
	cout << count << endl ;
}