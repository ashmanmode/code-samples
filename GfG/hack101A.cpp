#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	int t; 
	cin >> t ;
	ull l,b;
	fr(i,0,t)
	{
		cin >> l >> b ;
		if( l%3 == 0 || b%3 == 0 )
			cout << "YES" << endl ;
		else
			cout << "NO " << ( (l%3)*(b%3) )/3 << endl;
	}
	return 0;
}