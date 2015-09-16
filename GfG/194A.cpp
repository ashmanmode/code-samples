//DISJOINT - UNION DATA STRUCTURE FOR GRAPHS
//used to check for connectivity, takes lesser time than BFS as only connectivity is needed
//and not the path or path length
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
typedef unsigned long long int ull;

//global DS container
map< point, pair<point,int> > m ;

bool comppoint(point x,point y)
{
	if(x.F != y.F)
		return false;
	if(x.S != y.S)
		return false;
	return true;
}

point findroot(point x)
{
	if( !comppoint(x,m[x].F) )
		return findroot(m[x].F);
	return x;
}

void mergeset(point x,point y)
{
	point px = findroot(x); 	
	point py = findroot(y);
	if(!comppoint(px,py))
	{
		if( m[px].S > m[py].S )
		{
			m[py].F = px ;
			m[px].S += m[py].S;  
		}
		else
		{
			m[px].F = py ;
			m[py].S += m[px].S;
		}
	}
}

int main()
{
	int n;
	point a ;
	cin >> n ; 
	
	pair<point,bool> x_arr[1001]; 
	pair<point,bool> y_arr[1001]; 

	fr(i,1,1001)
	{
		x_arr[i].S = false;
		y_arr[i].S = false;
	}

	//points input stream
	pair<point,int> tmp ;
	while(n--)
	{
		cin >> a.F >> a.S ;
		tmp.F = a ; tmp.S = 1 ;
		m[a] = tmp ;
		if(x_arr[a.F].S)
			mergeset(a,x_arr[a.F].F);
		if(y_arr[a.S].S)
			mergeset(a,y_arr[a.S].F);
		x_arr[a.F].F = a ; x_arr[a.F].S = true;
		y_arr[a.S].F = a ; y_arr[a.S].S = true;
	}
	
	int count = 0 ;
	for(std::map< point, pair<point,int> >::const_iterator it = m.begin() ; it != m.end() ; ++it )
	{
		//cout << it->first.F << " " << it->first.S << " ---> " << it->second.F.F << " " << it->second.F.S << endl ;
		if( comppoint(it->first,it->second.F) )
			count++;
	}
	cout << count - 1 << endl ;
	return 0;
}