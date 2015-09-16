#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;
const int mod  = 1000000007;

vector <ull> dp;

class Graph
{
public:
	Graph(int n);
	void printAL();    //prints adjancency list
	void addEgde(int v, int w); 
	void DFS1(int s);
	void DFS2(int s);
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
}

void Graph::DFS1(int s)
{
	bool visited[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

	//stack for visiting
	int i,node;
	vector<int> q;
	q.pb(s);
	visited[s] = true ;
	while(q.size() != 0)
	{
		node = q[q.size()-1];
		for(i = 0 ; i < graph[node].size(); i++ )
		{
			if(visited[ graph[node][i] ] == false)
			{
				visited[graph[node][i]] = true ;
				q.pb(graph[node][i]);
				break;
			}
		}
		if( i == graph[node].size() )
		{	
			if(q.size() > 1)
				dp[ q[q.size()-2] ] =  ( dp[ q[q.size()-2] ] + 2*dp[node])%mod;  //updating value for the parent
			q.erase(q.begin() + q.size()-1 );
		}
	}
}

void Graph::DFS2(int s)
{
	bool visited[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

	//stack for visiting
	int i,node;
	vector<int> q;
	q.pb(s);
	visited[s] = true ;
	while(q.size() != 0)
	{
		node = q[q.size()-1];
		for(i = 0 ; i < graph[node].size(); i++ )
		{
			if(visited[ graph[node][i] ] == false)
			{
				dp[graph[node][i]] = (dp[graph[node][i]] + 2*( dp[node]-2*dp[graph[node][i]] ) )%mod;
				visited[graph[node][i]] = true ;
				q.pb(graph[node][i]);
				break;
			}
		}
		if( i == graph[node].size() )
			q.erase(q.begin() + q.size()-1 );
	}
}

int main()
{
	int n,x,y; 
	cin >> n ; 
	Graph g(n);
	for(int i = 0  ; i  < n-1 ; i++ )
	{
		cin >> x >> y ;
		g.addEgde(x-1,y-1); 
	}

	fr(i,n) dp.pb(1) ; 
	g.DFS1(0); 
	g.DFS2(0);
	ull ans = 0 ;
	fr(i,n) if(dp[i]  > ans ) ans = dp[i];
	cout << ans << endl; 
}