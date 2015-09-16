#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define mod 1000000007
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
typedef unsigned long long int ull;

double calc(double c,double f,double x)
{
	double sol = 0 ; 
	double mult = 0 ;
	double final = x ;

	int n = 10000000;
	fr(i,0,n)
	{
		sol = c*mult + x/(2+i*f);
		if( sol < final )
			final = sol ;
		else
			return final;
		mult += 1/(2+i*f) ; 
	}
}

int main()
{
	int t; 
	cin >> t ;
	double c,f,x;

	fr(i,0,t)
	{
		cin >> c >> f >> x ;
		cout << "Case #" << i+1 << ": " ;
		cout << fixed << calc(c,f,x) << endl ;
	}
	return 0;
}