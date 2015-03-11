//Works Application Prob 1
#include <bits/stdc++.h>
#define siz 20
#define sizpow 1048576
#define ERR -20
using namespace std;

int AdjMat [siz][siz];
int TspMat[siz][sizpow];
int source,desti,siz_tsp;
vector<int> at;

class Graph
{
public:
	Graph(int n);
	void printAL();    //prints adjancency list
	void addEgde(int v, int w);
	bool makeAdjMat();
private:
	vector< vector<int> > graph;
	bool BFS(int s,int place);
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

bool Graph::makeAdjMat()
{
	if(!BFS(desti,0))
		return false;
	if(!BFS(source,1))
		return false;
	for(int i = 0 ; i < at.size() ;i++ )
		BFS(at[i],i+2);
	return true;
}

bool Graph::BFS(int s,int place)
{
	bool visited[graph.size()];
	int dist[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
	{
		visited[i] = false ;
		dist[i] = ERR ;
	}

	//queue for visiting
	dist[s] = 0 ;
	vector<int> q;
	q.push_back(s);
	visited[s] = true ;
	while(q.size() != 0)
	{
		for(int i = 0 ; i < graph[q[0]].size(); i++ )
		{
			if(visited[graph[q[0]][i]] == false)
			{
				dist[graph[q[0]][i]] = dist[q[0]] + 1 ;
				visited[graph[q[0]][i]] = true ;
				q.push_back(graph[q[0]][i]);
			}
		}
		q.erase(q.begin());
	}
	if ( dist[source] == ERR || dist[desti] == ERR )
		return false ;
	AdjMat[place][0] = dist[desti];
	AdjMat[place][1] = dist[source];
	for(int j = 0;j < at.size() ; j++ )
		AdjMat[place][j+2] = dist[at[j]];
	return true;
}

int solve(int from,int set) //function mincost 'from' to Desti. via set
{
	int msk,mskapplied,temp;
	if(TspMat[from][set] != -1)
		return TspMat[from][set];
	TspMat[from][set] = INT_MAX;
	for(int i =0;i<siz_tsp;i++) //try removing one by one element from set
	{
		msk = ((int)pow(2,siz_tsp) - 2 ) - (1 << i) ;
		mskapplied = set&msk;
		if(mskapplied != set)
		{
			temp = AdjMat[from][i] + solve(i,mskapplied);
			if(temp < TspMat[from][set])
				TspMat[from][set] = temp ;
		}
	}
	return TspMat[from][set]; 
}

int main()
{
	clock_t start = clock();
	freopen("graph_input.txt","r",stdin);
	//freopen("graph_output.txt","w",stdout);
	int n,m;
	cin >> n >> m;
	char g[100][100];
	for(int i = 0 ; i < m ; i++ )
		for(int j = 0 ; j < n ;j++)
		cin >> g[i][j];

	//constructing the graph
	Graph graph(n*m);
	for(int i = 0 ; i < m ; i++ )
	{
		for(int j = 0 ; j < n ; j++ )
		{
			if(g[i][j] != '#')
			{
				if(j > 0 && g[i][j-1] != '#') //left
					graph.addEgde(i*n+j,i*n+j-1);
				if(j < n-1 && g[i][j+1] != '#') //right
					graph.addEgde(i*n+j,i*n+j+1);
				if(i > 0 && g[i-1][j] != '#') //top
					graph.addEgde(i*n+j,i*n+j-n);
				if(i < n-1 && g[i+1][j] != '#') //down
					graph.addEgde(i*n+j,i*n+j+n);
				if(g[i][j] == 'S')
					source = i*n+j;
				else if(g[i][j] == 'G')
					desti = i*n+j;
				else if(g[i][j] == '@')
					at.push_back(i*n+j);
			}
		}
	}

	if(!graph.makeAdjMat())
	{
		cout << -1 << endl;
		return 0 ;
	}
	siz_tsp = 2 + at.size();

	/*//try printing AdjMat
	cout << siz_tsp << endl ;
	for(int i = 0 ; i < siz_tsp ; i++ )
	{
		for(int j = 0 ; j < siz_tsp ; j++ )
			cout << AdjMat[i][j] << " ";
		cout << endl ;
	}*/
	cout << siz_tsp << endl ;

	//Tsp
	for(int i = 0 ; i < siz_tsp ; i++ )    //setting values for nullset 
		TspMat[i][0] = AdjMat[i][0];
	for(int i = 0 ; i < siz_tsp ; i++ )
		for(int j = 1  ; j < (int)pow(2,siz_tsp) ; j++ )
			TspMat[i][j] = - 1 ;
	cout << solve(1,(int)pow(2,siz_tsp)-3) << endl ;
	cout << "time " << (float)(clock() - start)*1000/CLOCKS_PER_SEC << " ms" << endl;
	return 0 ;
}