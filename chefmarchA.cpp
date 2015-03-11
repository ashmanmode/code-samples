#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	int t ;
	cin >> t; 
	int x,y,k,n,p,c;
	bool lucky;
	fr(i,0,t)
	{
		lucky = false;
		cin >> x >> y >> k >> n ;
		fr(j,0,n)
		{
			cin >> p >> c ; 
			if(p >= (x-y) && c <= k)
				lucky = true;
		}
		if(lucky)
			cout << "LuckyChef" << endl ;
		else
			cout << "UnluckyChef" << endl ;
	}
	return 0;
}