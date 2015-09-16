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
typedef unsigned long long int ull;

int main()
{
	int n ,x,h; 
	cin >> n ; 
	vector< pair<int,int> > arr; 
	pair<int,int> temp ;
	fr(i,0,n)
	{
		cin >> temp.F >> temp.S ;
		arr.pb(temp);
		//cpy.pb(mp(x,h));
	}

	if(n == 1)
	{
		cout << 1 << endl ;
		return 0 ;
	}
	int count = 2 ; 
	int current = arr[0].F;
	fr(i,1,n-1)
	{
		if( (arr[i].F - current) > arr[i].S )
		{
			count ++ ; 
			current = arr[i].F ;
			continue ;
		}
		//cout << (arr[i].F - current) << " " << (arr[i+1].F - arr[i].F) << endl ; 
		if( (arr[i+1].F - arr[i].F) > arr[i].S )
		{
			count++ ;
			current = arr[i].F + arr[i].S ;
			continue ;
		}
	}
	cout << count << endl ; 
	return 0 ;
}