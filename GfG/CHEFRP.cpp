#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%llu",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%llu",a)
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
typedef unsigned long long int ull;

int main()
{
	ull test,n,a,min,sum;
	bool possible;
	cin >> test ;
	fr(i,0,test)
	{
		possible = true;
		cin >> n >> a;
		min  = a ;
		if(a==1)
			possible = false ;
		sum = a ; 
		fr(j,1,n)
		{
			cin >> a;
			if(a==1)
				possible = false ;
			sum += a ;
			if(a < min)
				min = a ;
		}
		if(possible)
			cout << sum - min + 2 << endl ; 
		else
			cout << -1 << endl ;
	}
	return 0;
}