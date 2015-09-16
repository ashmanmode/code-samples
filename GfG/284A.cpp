#include <iostream>
using namespace std;

int main()
{
	int n,x;
	cin >> n >> x ;
	int count = 0 ;
	int l,r;
	int current  = 1 ;
	for(int i = 0 ; i < n ;i++)
	{
		cin >> l >> r ;
		current = ((l - current)/x)*x + current ; 
		count = count + r - current + 1;
		current = r + 1 ;
	}
	cout << count << endl ;
}