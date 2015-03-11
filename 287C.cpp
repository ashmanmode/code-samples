#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

ull search(ull n,ull h,bool prev)
{
	if(n == 0)
		return 1;
	if(prev == 1)
	{
		if(h > pow(2,n-1))
		{
			h -= pow(2,n-1);
			return pow(2,n) + search(n-1,h,true);
		}
		else
			return 1 + search(n-1,h,false);
	}
	else
	{
		if(h <= pow(2,n-1))
			return pow(2,n) + search(n-1,h,false);
		else
		{
			h -= pow(2,n-1);
			return 1 + search(n-1,h,true);
		}
	}
}

int main()
{
	ull h,n;
	cin >> n >> h ;
	cout << search(n,h,1)-1 << endl;
}