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

struct some
{
	int l;
	int r;
	int v;
};

bool mycomp(some a,some b)
{
	return a.v < b.v ;
}

int main()
{
	int test ;
	cin >> test ;
	while(test--)
	{
		int n,k,m ;
		cin >> n >> k >> m ;
		
		vector<int> a(n);
		signed long long int sum = 0 ;
		fr(i,0,n)
		{
			cin >> a[i] ;
			sum += a[i] ;
		}

		some tmp;
		vector<some> judges ;
		fr(i,0,m)
		{
			cin >> tmp.l >> tmp.r >> tmp.v ;
			judges.pb(tmp);
		}

		//preprocessing for min_a
		sort(judges.begin(),judges.end(),mycomp);
		vector<int> min_a(n,-1);
		int change_count = 0 ;
		int front = judges[0].l;
		int end = judges[0].r ;
		fr(i,front-1,end)
		{
			min_a[i] = judges[0].v ; 
			change_count++;
		}
			cout << front << " " << end << endl ;
		
		fr(i,1,m)
		{
			//cout << judges[i].l << " " << judges[i].r << " " << judges[i].v << endl ;
			if( judges[i].l < front )
			{
				fr(j,judges[i].l-1,min(front-1,judges[i].r))
				{
					min_a[j] = judges[i].v ;
					change_count++;
				}
				front = judges[i].l ;
			}
			if( judges[i].r > end )
			{
				fr(j,max(end,judges[i].l-1),judges[i].r)
				{
					min_a[j] = judges[i].v ;
					change_count++;
				}
				end = judges[i].r ;
			}
			cout << front << " " << end << endl ;
		}

		//knapsack stage
		vector< pair<int,int> > bag ;
		fr(i,0,n)
		{
			cout <<   min_a[i] << " " ;
			if(a[i] < 0 && min_a[i] != -1)
			{
				bag.pb(mp(-1*a[i],min_a[i]));
				//cout << -1*a[i] << " " <<  min_a[i] << endl ;
			}
			
		}
		cout <<endl <<"changes "<< change_count << endl ;

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