#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;

int main()
{
	int n;
	cin >> n ;
	arr a(n);
	vectin(a,n);

	int here = n;
	bool done = false;
	fr(i,1,n)
	{
		if(a[i] >= a[i-1])
			continue;
		else
		{
			if(done)
			{
				cout << -1 << endl ;
				return 0 ;
			}
			done = true;
			here = i ;
		}
	}
	if(a[n-1] <= a[0] || !done)
		cout << n - here << endl ;
	else
		cout << -1 << endl ;

}