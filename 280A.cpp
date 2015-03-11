#include <iostream>
using namespace std;

int main()
{
	int n,i ;
	cin >> n ;
	n = n*6 ;
	for(i=0;;i++)
	{
		if( n < i*(i+1)*(i+2))
			break;
	}
	cout << i-1 << endl ;
	return 0;
}