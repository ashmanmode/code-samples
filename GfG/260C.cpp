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
typedef signed long long int sll;

bool done[100050];
ull freq[100050];
ull dp[100050];
ull sol(int c)
{
	if(c < 0)
		return 0 ;
	if(done[c])
		return dp[c];
	done[c] = true;
	return dp[c] = max( freq[c] + sol(c-2),freq[c-1] + sol(c-3) );
}

int main()
{
	int x,n; cin >> n ;
	fr(i,0,100050)
	{
		freq[i] = 0 ;
		done[i] = false;
	}

	fr(i,0,n)
	{
		cin >> x ;
		freq[x] = freq[x] + x ;
	}

	dp[0] = freq[0]; done[0] = true;
	cout << sol(100050) << endl ;
}