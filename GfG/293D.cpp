#include <bits/stdc++.h>
#define Err -10
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int n,t;
double p;
double ans = 0 ;
double dp[2001][2001];

void dojob(int inside,int inq,double val,int call)
{
	if(call == 0 || inq == 0)
		ans += inside*dp[inside][call];
	else
	{
		dojob(1+inside,inq-1,val*p,call-1);
		dojob(inside,inq,val*(1-p),call-1);
	}
}	

double dpsolve()
{
	//preprocess
	fr(i,2000)
		fr(j,2000)
			dp[i][j] = 0;
	dp[0][0] = 1 ;

	fr(j,n+1)
	{
		fr(i,t)
		{
			if(j == n)
				dp[i+1][j] += dp[i][j] ;
			else
			{
				dp[i+1][j] += dp[i][j]*(1-p) ;
				dp[i+1][j+1] += dp[i][j]*p ;
			}
		}
	}

	ans = 0 ;
	fr(i,n+1)
		ans += dp[t][i]*i ;

	return ans;
}

int main()
{
	cin >> n >> p >> t ;
	//dojob(0,n,1,t);
	cout << fixed << dpsolve() << endl ;
	return 0 ;
}