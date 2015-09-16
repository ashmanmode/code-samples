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

bool mycomp(int i,int j)
{
	return i > j ;
}

int main()
{
	int n,x;
	vector<int> s ;
	vector<int> val ;
	cin >> n ;
	while(cin >> x)
		s.pb(x) ;

	sort(s.begin(),s.end(),mycomp);

	fr(i,0,s.size())
		val.pb(n/s[i]) ;

	fr(i,val.size(),4)
		val.pb(0) ;

	//iterating
	ull count = 0 ;
	int sum = 0 ;
	fr(i,0,val[0]+1)
	{
		sum += i*s[0] ;
		fr(j,0,val[1]+1)
		{
			sum += j*s[1] ;
			fr(k,0,val[2]+1)
			{
				sum += k*s[2] ;
				fr(l,0,val[3]+1)
				{
					sum += l*s[3] ;
					if(sum == n)
						count++ ;
					sum -= l*s[3] ;
				}
				sum -= k*s[2] ;
			}
			sum -= j*s[1] ;
		}
		sum -= i*s[0] ;
	}
	cout << count << endl ;
	return 0;
}