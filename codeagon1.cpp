#include <bits/stdc++.h>
//#define mod 1000000000
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

ull mod = 1000000000;

ull calc(ull x,ull y)
{
	ull ret = 1 ;
	fr(i,y)
		ret = (ret*x)%mod;
	return ret;
}


ull rfind(ull n)
{
	if(n == 0 || n == 1 || n == 2)
		return 1;
	else if (n == 3) return 3;
	else if (n == 4) return 3;
	else if (n == 5) return 15;
	else if (n == 6) return 15;
	else if (n == 7) return 105;
	else if (n == 8) return 105;
	else if (n == 9) return 105;
	else if (n == 10) return 105;
	else
	{
		double k = n ;
		ull sol = calc(2,ceil(k/4)); 
		sol = (sol*rfind(ceil(k/5)))%mod; 
		sol = (sol*rfind(ceil(k/10)))%mod; 
		return sol;
	}
}

int main()
{
	ull t,n,r,temp;
	cin >> t ;
	ull sol = 0;
	fr(i,t)
	{
		cin >> n ;
		r = rfind(n); 
		temp = calc(r,2*r);
		if(temp > sol) sol = temp;
		temp = calc(r,3*r);
		if(temp > sol) sol = temp;
		temp = calc(r,4*r);
		if(temp > sol) sol = temp;
		temp = calc(r,5*r);
		if(temp > sol) sol = temp;
		temp = calc(2*r,3*r);
		if(temp > sol) sol = temp;
		temp = calc(2*r,5*r);
		if(temp > sol) sol = temp;
		temp = calc(3*r,4*r);
		if(temp > sol) sol = temp;
		temp = calc(3*r,5*r);
		if(temp > sol) sol = temp;
		temp = calc(4*r,5*r);
		if(temp > sol) sol = temp;
		cout << sol << endl ;
	}
	return 0;	
}