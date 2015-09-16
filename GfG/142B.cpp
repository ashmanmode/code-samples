#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define mod 1000000007
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;
typedef signed long long int sll;


bool isprime(ull a)
{
	//works till 10^18 
	if(a == 2 || a == 3)
		return true;
	if(a%2 ==0 || a%3 == 0 )
		return false;

	ull i =  5 ;
	while(i*i <= a)
	{
		if(a%i == 0 || a%(i+2) == 0)
			return false ;
		i = i+6;
	}
	return true;
}


bool checksqr(ull a)
{
	ull rootsqr = ((ull)sqrt(a))*((ull)sqrt(a)); 
	  
	if(rootsqr == a)
	{
		if(isprime((ull)sqrt(a)))
			return true ;
	}
	else
		return false;
}

int main()
{
	unsigned long long int a;
	int n;
	cin >>  n ; 
	fr(i,0,n)
	{
		cin >> a ;
		if(checksqr(a) && a != 1)
			cout << "YES" << endl ;
		else
			cout << "NO" << endl ;
	}
	return 0;
}