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

bool myfunction (pii i,pii j) { return (i.F>j.F); }

int main()
{
	int test,n,x,j;
	cin >> test ;
	while(test--)
	{
		cin >> n ; 
		vector<pii> a;
		bool notpossible = false; 
		fr(i,0,n)
		{
			cin >> x ;
			a.pb(mp(x,i+1));
		}

		int sum = 0 ;
		fr(i,0,n)
		{
			if(a[i].F >= n)
			{
				notpossible = true;
				break;
			}
			else
				sum += a[i].F ; 
		}
		if(sum != n || notpossible)
			cout << -1 << endl ;
		else
		{
			vector<int> ans(n);
			vector<bool> is(n);
			fr(i,0,n)
				is[i] = false ;
			
			sort(a.begin(),a.end(),myfunction);
			while(a[0].F > 0 )
			{
				j = n-1 ;
				while(1)
				{
					if(!is[a[j].S - 1] )
					{
						is[a[j].S - 1] = true;
						ans[a[j].S - 1] = a[0].S ; 
						break;
					}
					j-- ;
				}
				a[0].F-- ;
				sort(a.begin(),a.end(),myfunction);
			}

			printvect(ans,n);
			cout << endl ;
		}
	}
}