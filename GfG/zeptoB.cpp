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

int maxm(int a ,int b)
{
	if(b > a)
		return b;
	else
		return a ;
}

int minm(int a ,int b)
{
	if(b < a)
		return b;
	else
		return a ;
}

int main()
{
	int n,max;
	cin >> n ;
	int v = pow(2,n+1) - 2 ;
	vector<int> path(v);

	fr(i,0,v) cin >> path[i] ;
	if(n==1)
	{
		cout << ( maxm(path[0],path[1]) - minm(path[0],path[1]) ) << endl ;
		return 0;
	}
		
	fr(i,2,v-pow(2,n)) 
		path[i] += path[(i-2)/2] ;

	max = 0 ;
	fr(i,v-pow(2,n),v)
	{
		path[i] += path[(i-2)/2] ;
		if(path[i] > max)
			max = path[i];
	}

	//UPDATING REMAINS
	fr(i,v-pow(2,n),v)
		path[i] = max - path[i] ;

	//backtracing tree
	ull sol = 0 ;
	for(int i = n ; i > 1 ; i-- )
	{
		for(int j = pow(2,i)-2 ; j < pow(2,i+1)-2 ; j = j + 2 )
		{
			path[(j-2)/2] = minm(path[j],path[j+1]);
			sol += ( maxm(path[j],path[j+1]) - minm(path[j],path[j+1]) );
		}
	}

	cout << sol + path[0] + path[1] <<  endl ;
	return 0;
}