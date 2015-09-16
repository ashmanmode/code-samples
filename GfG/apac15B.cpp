#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define INF_LDOUBLE LDBL_MAX
#define PRECISION 1e-6
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
#define vectin(a) fr(i,0,a.size()) { cin >> a[i] ; }
typedef unsigned long long int ull;
typedef signed long long int sll;

long double rootn(long double a,long double n)
{
	//uses nth root approximation algo.
	long double ans = 2 ; 
	long double delta = 100 ;
	while(delta > PRECISION)
	{
		delta = ans ;
		ans = (1/n)*((n-1)*ans + a/pow(ans,n-1)) ;
		delta = abs(ans - delta);
		//cout << fixed << ans << endl ;
	}
	return ans ;
}

long double nthroot(vector<long double> sol,long double n)
{
	//finds nth root for all elements in sol ;
	long double ret = 1 ;
	fr(i,0,sol.size())
		ret *= rootn(sol[i],n);
	return ret ;
}


int main()
{
	int test ;
	cin >> test ;

	fr(t,0,test)
	{
		int m,l,r;
		long double n ;
		cin >> n >> m ;
		vector<long double> a(n);
		vectin(a);

		cout << "Case #" << t+1 << ": " << endl;
		fr(i,0,m)
		{
			cin >> l >> r ;
			vector<long double> sol;
			long double temp = 1 ;
			fr(j,l,r+1)
			{
				temp *= a[j] ;
				if( temp > INF_LDOUBLE )
				{
					sol.pb(temp);
					temp = 1 ;
				}
			}
			sol.pb(temp);

			//find r-l+1 th root of sol
			long double ans = a[l];
			if(r-l+1 != 1)
				ans = nthroot(sol,r-l+1) ;
			cout << fixed << ans << endl ;
		}
	}
}
