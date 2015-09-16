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
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;

class Graph
{
public:
	Graph(int n);
	void printAL();    //prints adjancency list
	void addEgde(int v, int w); //for directed edge put directed = 1 
	int DFS1(int s);
private:
	vector< vector<int> > graph;
};

Graph::Graph(int n)
{
	vector<int> list;
	for(int i = 0 ; i < n ; i++ )
		graph.push_back(list);
}

void Graph::printAL()
{
	cout << "printing the Adjacency list " << endl ;
	for(int i = 0 ; i < graph.size() ;i++ )
	{
		cout << "v" << i << " - " ;
		for(int j = 0 ; j < graph[i].size() ; j++ )
			cout << graph[i][j] << " " ;
		cout << endl ;
	}
}

void Graph::addEgde(int v,int w)
{
	graph[v].push_back(w);
	graph[w].push_back(v);
} 

int Graph::DFS1(int s)
{
	bool visited[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

	//stack for visiting
	int i;
	int min = 123456 ;
	vector<int> q;
	q.push_back(s);
	visited[s] = true ;
	while(q.size() != 0)
	{
		for(i = 0 ; i < graph[q[q.size()-1]].size(); i++ )
		{
			if(q.size() == 3)
			{
				//cout << graph[q[q.size()-1]][i] + 1 << " " ;
				//cout << "herg" << endl ;
				if(graph[q[q.size()-1]][i] == s)
					{
						int some  = graph[s].size() + graph[q[q.size()-1]].size() + graph[q[q.size()-2]].size() - 6 ;
						if(some < min)
							min = some ;
					}
				else
					continue;
			}
			if(visited[graph[q[q.size()-1]][i]] == false)
			{
				//cout << graph[q[q.size()-1]][i] + 1 << " " ;
				if(q.size() < 3)
				{
					visited[graph[q[q.size()-1]][i]] = true ;
					q.push_back(graph[q[q.size()-1]][i]);
					break;
				}
				
			}
		}
		if( i == graph[q[q.size()-1]].size())
		{
			//cout << "nikala" << endl ;
			q.erase(q.begin() + q.size()-1 );
		}
	}
	return min;
}


int main()
{

	int n,m;
	int u,v;
	cin >> n >> m;
	Graph g(n);
	fr(i,0,m)
	{
		cin >> u >> v ;
		g.addEgde(u-1,v-1);
	}

	int min = 12345678;
	int k;
	fr(i,0,n)
	{
		//cout << "New Run" << endl; 
		k = g.DFS1(i) ;
		if( k != -1 && k < min )
			min = k ;
	}

	if(k!=12345678)
		cout << min << endl ;
	else
		cout << -1 << endl;



}