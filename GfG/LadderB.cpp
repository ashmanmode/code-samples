#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;


int main()
{
	int n ;
	cin >> n ; 
	int start = 0 ; 
	int end = 0 ; 
	int stpt,prev;
	cin >> prev;
	stpt = prev ; 

	fr(i,n-1)
	{
		cin >> x ;
		if(x >= prev)
		{
			start = i ;
			end = i ;
			prev = x ;
		}
		else
		{
			start = i-1 ;
		}
	}
	return 0;	
}
