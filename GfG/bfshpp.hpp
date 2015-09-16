#include <iostream>
#include "bfshpp.hpp"
#include <vector>
using namespace std;

class Graph
{
public:
	Graph(int n);
	void printAL();    //prints adjancency list
	void addEgde(int v, int w);
	pair<int,int> BFS1(int s,int at);
	int BFS2(int s);
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
		//graph[w].push_back(v);
} 

pair<int,int> Graph::BFS1(int s,int at)
{
	pair<int,int> ret;
	bool visited[graph.size()];
	int dist[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

	//queue for visiting
	int atcount = 0;
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
				dist[graph[q[0]][i]] = dist[q[0]] +1 ;
				if(g[graph[q[0]][i]/n][graph[q[0]][i] - (graph[q[0]][i]/n)*n ] == '@')
					atcount++;
				if(atcount == at)
				{
					ret.first = graph[q[0]][i] ; ret.second = dist[graph[q[0]][i]] ;
					return ret;
				}
				visited[graph[q[0]][i]] = true ;
				q.push_back(graph[q[0]][i]);
			}
		}
		q.erase(q.begin());
	}
}

int Graph::BFS2(int s)
{
	bool visited[graph.size()];
	int dist[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

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
				if(g[graph[q[0]][i]/n][graph[q[0]][i] - (graph[q[0]][i]/n)*n ] == 'g')
					return dist[graph[q[0]][i]];
				visited[graph[q[0]][i]] = true ;
				q.push_back(graph[q[0]][i]);
			}
		}
		q.erase(q.begin());
	}
}