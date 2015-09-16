#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define mod 1000000007
#define F first
#define S second
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%llu",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%llu",a)
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << fixed << a[i] << " " ;
typedef unsigned long long int ull;

class Graph
{
public:
	Graph(int n);
	void addedge(int u,int v);
	void printAL();
	int fullbin();
private:
	vector< vector<int> > graph; 
	int BFS(int start);
};

Graph::Graph(int n)
{
	vector<int> lst;
	fr(i,0,n)
		graph.pb(lst);
}

void Graph::addedge(int u,int v)
{
	graph[u].pb(v);
	graph[v].pb(u);
}

void Graph::printAL()
{
	fr(i,0,graph.size())
	{
		cout << "v " << i << ": ";
		fr(j,0,graph[i].size())
			cout << graph[i][j] << " ";
		cout << endl;
	}
}

int Graph::BFS(int s)
{
	int ndel = 1 ;
	vector<bool> visited;
	fr(i,0,graph.size())
		visited.pb(false);

	vector<int> stack;
	stack.pb(s); visited[s] = true;
	while(stack.size() != 0)
	{
		fr(i,0,graph[stack[0]].size())
		{
			if(!visited[ graph[stack[0]][i] ])
			{
				visited[graph[stack[0]][i]] = true;
				if(graph[ graph[stack[0]][i] ].size()  < 3)
					ndel++;
				else
				{
					ndel++;
					stack.pb(graph[stack[0]][i]);
				}
			}
		}
		stack.erase(stack.begin());
	}
	return graph.size() - ndel ;
}

int Graph::fullbin()
{
	int sol = graph.size();
	fr(i,0,graph.size())
	{
		if(graph[i].size() == 2)
		{
			if( BFS(i) < sol )
				sol = BFS(i);
		}
	}
	return sol ;
}

int main()
{
	int test,n,u,v;
	cin >> test;
	fr(t,0,test)
	{
		cin >> n ; 
		Graph g(n) ;
		fr(i,0,n-1)
		{
			cin >> u >> v ;
			g.addedge(u-1,v-1);
		}
		g.printAL();
		cout << "Case #" << t+1 << ": " <<  g.fullbin() << endl;
	}
	return 0;
}