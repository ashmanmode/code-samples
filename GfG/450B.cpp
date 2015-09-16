#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
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

ull retmod(sll a)
{
	if(a == 0 || a == mod || a == -mod)
		return 0;
	else if(a > 0)
		return a%mod;
	else 	
		return mod - (-a)%mod ;
}

int main()
{
	sll x,y,k;
	cin >> x >> y >> k ;

	if( (k/3) % 2  == 0 )
	{
		if(k%3 == 0)
			cout << retmod(x-y) << endl ;
		else if(k%3 == 1)
			cout << retmod(x) << endl ;
		else
			cout << retmod(y) << endl ;
	} 
	else
	{
		if(k%3 == 0)
			cout << retmod(y-x) << endl ;
		else if(k%3 == 1)
			cout << retmod(-x) << endl ;
		else
			cout << retmod(-y) << endl ;
	}
	return 0;
}