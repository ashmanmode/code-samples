#include <bits/stdc++.h>
using namespace std;

int main()
{
	ifstream in('graph_input.txt');
	int n,m; //n-rows
	in >> n >> m ;
	char a;
	vector< pair<int,int> > nodes;
	pair<int,int> tmp,s,g;
	for(int i = 0 ;i < n ; i++ )
	{
		for(int j = 0 ; j < m ; j++ )
		{
			in >> a ;
			if(a == '@')
			{
				tmp.first = i ; 
				tmp.second = j ;
				nodes.pushback(tmp);
			}
			else if(a == 'S')
			{
				s.first = i ; 
				s.second = j ;
			}
			else if(a == 'G')
			{
				g.first = i ; 
				g.second = j ;
			}
		}
	}

	//TSP
	int g[nodes.size()+2][nodes.size()+2];
	
}