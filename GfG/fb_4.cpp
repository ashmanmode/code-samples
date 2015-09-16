#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	Graph(int n);
	void printAL();    //prints adjancency list
	void addEgde(int v, int w);
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

int main()
{
	int test_cases;
	cin >> test_cases ;
	for(int i =0 ; i < test_cases ; i++ )
	{
		int n,x; cin >> n >> x;
		Graph g(n);
		for(int j = 1 ; j < n ; j++ )
		{
			cin >> x ;
			g.addEgde(x-1,j);
		}
		g.printAL();
	}	
}