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

int main()
{
	int test ;
	cin >> test ;
	while(test--)
	{
		ull n,k,remain,a,packs;
		cin >> n >> k ;

		packs = 0 ;
		remain = 0 ;
		fr(i,0,n)
		{
			cin >> a ;
			if(a < remain)
			{
				remain -= (a+1);
				continue;
			}
			a -= remain ;
			if( (a/k)*k == a )	
				packs += a/k ;
			else
				packs += a/k + 1;
			if(a%k == 0)
				remain = 0 ;
			else
				remain = k - a%k - 1;
		}
		cout << packs << endl ;
	}
}