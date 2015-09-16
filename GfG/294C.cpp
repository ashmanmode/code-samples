#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	int n,m;
	cin >> n >> m ; 
	ull max = 0 ;
	ull val;
	fr(i,m)
	{
		val = i + min(n-2*i,m-i)
	}
	return 0 ;
}