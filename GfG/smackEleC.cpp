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
	pair<int,int> DFS2(int s);
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
	cout << "DFS1 " << endl;
	bool visited[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

	//stack for visiting
	int i ;
	int diamet = 0 ;
	int vert = 0 ;
	vector<int> q;
	q.push_back(s);
	visited[s] = true ;
	while(q.size() != 0)
	{
		for(i = 0 ; i < graph[q[q.size()-1]].size(); i++ )
		{
			if(visited[graph[q[q.size()-1]][i]] == false)
			{
				cout << graph[q[q.size()-1]][i] + 1 << " " ;
				visited[graph[q[q.size()-1]][i]] = true ;
				q.push_back(graph[q[q.size()-1]][i]);
				break;
			}
		}
		if( i == graph[q[q.size()-1]].size())
		{
			if(q.size()  > diamet)
			{
				diamet = q.size() ;
				vert = q[q.size()-1 ]; 
				cout << "Dia " << vert+1 << " " << diamet <<endl ; 
			}
			q.erase(q.begin() + q.size()-1 );
		}
	}
	//cout << endl ;
	return vert;
}

pair<int,int> Graph::DFS2(int s)
{
	cout << "DFS2 " << endl;
	bool visited[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

	//stack for visiting
	int i ;
	int diamet = 0 ;
	int vert = 0 ;
	vector<int> q;
	q.push_back(s);
	visited[s] = true ;
	while(q.size() != 0)
	{
		for(i = 0 ; i < graph[q[q.size()-1]].size(); i++ )
		{
			if(visited[graph[q[q.size()-1]][i]] == false)
			{
				cout << graph[q[q.size()-1]][i] + 1 << " " ;
				visited[graph[q[q.size()-1]][i]] = true ;
				q.push_back(graph[q[q.size()-1]][i]);
				break;
			}
		}
		if( i == graph[q[q.size()-1]].size())
		{
			if(q.size()  > diamet)
			{
				diamet = q.size() ;
				vert = q[q.size()-1 ]; 
				cout << "Dia " << vert+1 << " " << diamet <<endl ; 
			}
			q.erase(q.begin() + q.size()-1 );
		}
	}
	//cout << endl ;
	return mp(vert,diamet);
}

int main()
{
	int t ;
	cin >> t ;
	while(t--)
	{
		int n,u,v;
		cin >> n ;
		Graph g(n);
		fr(i,0,n-1)
		{
			cin >> u >> v ;
			g.addEgde(u-1,v-1);
		}
		int m = g.DFS1(0) ;
		pair<int,int> d = g.DFS2(m) ;
		g.addEgde(u,d.F); cout << "Diameter " << d.S << endl ;
		g.printAL();

		int x = g.DFS1(0) ;
		pair<int,int> p = g.DFS2(x) ;
		if(p.S == d.S)
			cout << "NO" << endl ;
		else
			cout << "YES" << endl ;

	}
}