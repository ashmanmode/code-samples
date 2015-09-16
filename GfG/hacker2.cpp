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
typedef unsigned long long int ull;

//global DS container
int myrank[1234567];   //here myrank is the size of set	
int parent[1234567];	//parent denotes root as well as parent

int findroot(int x)
{
	if(x != parent[x])
		return findroot(parent[x]);
	return x;
}

void mergeset(int x,int y)
{
	int px = findroot(x);
	int py = findroot(y);
	if(px != py)
	{
		if(myrank[px] > myrank[py])
		{
			parent[py] = px ;
			myrank[px] += myrank[py];  
		}
		else
		{
			parent[px] = py ;
			myrank[py] += myrank[px];
		}
	}
}

int main()
{
	int test;
	cin >> test ;
	fr(t,0,test)
	{
		int nodes,k;
		cin >> nodes  >> k;
		
		//initialise all the nodes to be separate;
		fr(i,0,nodes) 
		{
			myrank[i] = 1 ;
			parent[i] = i;
		}

		//DS check
		int x,y;
		string s; 
		bool pos = true ;
		fr(i,0,k)
		{
			cin >> x >> s >> y;
			if(pos)
			{
				if(s == "=")
					mergeset(x-1,y-1);
				else
					if( findroot(x-1) == findroot(y-1) ) 
						pos = false ;
			}
			else
				continue ;
		}
		if(pos)
			cout << "YES" << endl;
		else
			cout << "NO" << endl ;
	}
	return 0;
}