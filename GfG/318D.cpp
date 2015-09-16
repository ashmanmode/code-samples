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

bool comp(int i,int j)
{
	return i > j ;
}

int main()
{
	int n ;
	cin >> n ; 

	vector<int> a(n);
	ull sum = 0 ;
	fr(i,0,n)
	{
		cin >> a[i] ;
		sum += a[i];
	}

	while(sum != 0)
	{	
		sum -= a[0] ;
		a[0] = 0 ;
		fr(i,1,n-1)
		{
			if(a[i-1] >= a[i] && a[i+1] >= a[i])
			{
				a[i]--;
				sum--;
			}
			else
			{
				sum -= a[i] - min(a[i-1],a[i+1])
				a[i] = min(a[i-1],a[i+1]);
			}
		}
	}

}
