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
typedef signed long long int sll;

int main()
{
	int test ;
	cin >> test ;
	while(test--)
	{
		int n,k,m,l,r,v;
		cin >> n >> k >> m ;
		
		vector<int> a(n);
		signed long long int sum = 0 ;
		fr(i,0,n)
		{
			cin >> a[i] ;
			sum += a[i] ;
		}

		vector<int> tmp ;
		vector< vector<int> > loc(n,tmp) ;
		fr(i,0,m)
		{
			cin >> l >> r >> v ;
			loc[l-1].pb(v);
			if(r != n )
				loc[r].pb(-v);
		}

		vector<int> min_a ;
		multiset<int> q ;
		multiset<int>::iterator it;
		fr(i,0,n)
		{
			fr(j,0,loc[i].size())
			{
				if(loc[i][j] > 0)
					q.insert(loc[i][j]);
				else
				{
					it = q.find(-loc[i][j]);
					q.erase(it);
				}
			}
			it = q.begin();
			min_a.push_back(*it);
		}

		// cout << "min printing" << endl ;
		// fr(i,0,n)
		// 	cout << min_a[i] << " " ;
		// cout << endl ;

		//knapsack stage
		vector< pair<int,int> > bag ;
		fr(i,0,n)
		{
			if(a[i] < 0 && min_a[i] != 0)
			{
				bag.pb(mp(-1*a[i],min_a[i]));
				//cout << -1*a[i] << " " <<  min_a[i] << endl ;
			}
			
		}

		//DP Knapsack 1 
		vector< vector<sll> > dp;
		vector<sll> lst(k+1);
		fr(i,0,bag.size()+1)
			dp.pb(lst);

		fr(i,0,k+1)
			dp[0][i] = 0 ;
		fr(i,1,bag.size()+1)
		{
			fr(j,0,k+1)
			{
				if(j-bag[i-1].S >= 0)
					dp[i][j] = max(dp[i-1][j],dp[i-1][j-bag[i-1].S] + bag[i-1].F);
				else
					dp[i][j] = dp[i-1][j];
			}
		}
		// fr(i,0,bag.size()+1)
		// {
		// 	fr(j,0,k+1)
		// 	cout << dp[i][j] << " ";
		// 	cout << endl ;		
		// }
		cout << sum + dp[bag.size()][k] << endl ;
	}
}