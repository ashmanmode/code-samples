//Normal Segment tree
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
#define vectin(a,n)
typedef unsigned long long int ull;
typedef signed long long int sll;

struct query
{
	sll x;
	sll y;
	sll v;
};

int main()
{
	sll n,m,k,x,y; 
	cin >> n >> m >> k ;

	vector<sll> a(n);
	vector<sll> up(n);
	fr(i,0,n)
	{
		cin >> a[i] ;
		up[i] = 0 ;
	}

	vector<query> s ; 
	query temp ;
	fr(i,0,m)
	{
		cin >> temp.x >> temp.y >> temp.v ;
		s.pb(temp);
	}

	vector<int> myq(m);
	fr(i,0,k)
	{
		cin >> x >> y ;
		myq[x-1] += 1 ;
		if( y  <  m)
			myq[y] -= 1 ;
	}

	fr(i,1,m)
		myq[i] += myq[i-1] ;

	fr(i,0,m)
	{
		up[s[i].x - 1] += myq[i]*s[i].v ;
		if( s[i].y  <  n )
			up[s[i].y] -= myq[i]*s[i].v ;
	}
	
	a[0] = a[0] + up[0] ;
	fr(i,1,n)
	{
		up[i] += up[i-1] ;
		a[i] += up[i] ;
	}

	fr(i,0,n)
			cout << a[i] << " ";
	cout << endl ;
	return 0 ;
}