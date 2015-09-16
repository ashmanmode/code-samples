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

map<int,int> graph_a;
map<int,int> graph_b;

void nodea(int a,int index)
{
	if(a != 1)
	{
		if(a%2 == 0)
		{
			graph_a[a/2] = index + 1 ;
			nodea(a/2,index+1);
		}
		if(a%3 == 0)
		{
			graph_a[a/3] = index + 1 ;
			nodea(a/3,index+1);
		}
		if(a%5 == 0)
		{
			graph_a[a/5] = index + 1 ;
			nodea(a/5,index+1);
		}
	}
}

int nodeb(int a,int index)
{
	if(a != 1)
	{
		if(graph_a[a])
			return graph_a[a] + index ; 
		if(a%2 == 0)
		{
			graph_b[a/2] = index + 1 ;
			nodeb(a/2,index+1);
		}
		if(a%3 == 0)
		{
			graph_b[a/3] = index + 1 ;
			nodeb(a/3,index+1);
		}
		if(a%5 == 0)
		{
			graph_b[a/5] = index + 1 ;
			nodeb(a/5,index+1);
		}
	}
}

int main()
{
	int a,b;
	cin >> a >> b ; 
	if(a==b)
	{
		cout << 0 << endl;
		return 0 ;
	}
	graph_b[b] = 0 ;
	graph_a[a] = 0 ;
	nodea(min(a,b),0);  

	int sol = 1000000000;
	
	for(std::map<int,int>::iterator it=graph_a.begin(); it!=graph_a.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << '\n';
		if(graph_b[it->first] && graph_b[it->first] + it->second < sol)
			sol = graph_b[it->first] + it->second ;
	}
   
	if(sol != 1000000000)
		cout << sol << endl ;
	else
		cout << -1 << endl ;

	return 0;
}