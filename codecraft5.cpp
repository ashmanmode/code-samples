#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	int t;
	cin >> t ;
	string s;
	int n,order;
	fr(i,t)
	{
		cin >> n >> s >> order ;
		if(s == "even")
			cout << 2*order -1 << endl;
		else
			cout << 2*order << endl ;
	}
}