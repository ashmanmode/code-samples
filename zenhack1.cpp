#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	ull r,c;
	cin >> r >> c ;
	ull ans = 10*((r-1)/2) ;
	if(r%2 == 0)
		cout << 2*c-1 + ans << endl ;
	else
		cout << 2*c-2 + ans << endl ;
	return 0;
}