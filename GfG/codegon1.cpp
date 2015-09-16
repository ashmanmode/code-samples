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
#define vectin(a,n)
typedef unsigned long long int ull;

int main() {
	int n,m;
	cin >> n >> m ;
	if( m > (n*(n+1))/2 )
		cout << -1 << endl ;
	else
	{
		if( m <= n )
			cout << 1 << endl ;
		else
		{
			int count = 0 ;
			int current = n ;
			while(m > 0)
			{
				if(m >= current)
				{
					//cout << current << endl ;
					count++ ;
					m -= current ;
					current-- ;
				}
				else
					break;
			}
			if(m==0)
				cout << count << endl ;
			else
				cout << count +1 << endl ;
		}
	}
	return 0;
}