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

ull gcd(ull a,ull b)
{
	if(a==0)
		return b ;
	else if(b==0)
		return a;
	else
	{
		if(a > b)
			return gcd(b,a%b);
		else
			return gcd(a,b%a);
	}
}

int main()
{
	ull test,a,b;
	cin >> test ;
	fr(i,0,test)
	{
		cin >> a >> b ; 
		ull k = gcd(a,b);
		while(b != 1 && k !=1)
		{
			b = b/k ;
			k = gcd(k,b);
		}
		if(b==1)
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}
	return 0;
}