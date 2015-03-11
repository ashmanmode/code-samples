#include <iostream>
#include <vector>
#include "time.h"
using namespace std;

vector< pair<int,int> > data;

class Graph
{
public:
	Graph(int n);  
	void addEgde(int v, int w);
	void BFScapital(int s);
	int DFSproduct(int s,int prdct);
private:
	vector< vector<int> > graph;
};

Graph::Graph(int n)
{
	vector<int> list;
	for(int i = 0 ; i < n ; i++ )
		graph.push_back(list);
}

void Graph::addEgde(int v,int w)
{
	graph[v].push_back(w);
	graph[w].push_back(v);
} 

void Graph::BFScapital(int s)
{
	bool visited[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

	//queue for visiting
	vector<int> q;
	q.push_back(s);
	visited[s] = true ;
	data[s].second = 0 ; //storing distance from source
	while(q.size() != 0)
	{
		for(int i = 0 ; i < graph[q[0]].size(); i++ )
		{
			if(visited[graph[q[0]][i]] == false)
			{
				data[graph[q[0]][i]].second = data[q[0]].second + 1 ;
				visited[graph[q[0]][i]] = true ;
				q.push_back(graph[q[0]][i]);
			}
		}
		q.erase(q.begin());
	}
}

int Graph::DFSproduct(int s,int prdct)
{
	bool no_city = true;
	int city_min = graph.size();
	int g_max = 0 ;
	vector<int> s_p; //stack for distances from capital
	s_p.push_back(data[s].second);
	if(data[s].first == prdct)
	{
		if(data[s].second > g_max)
		{
			g_max = data[s].second;
			city_min = s;
		}
		else if(data[s].second == g_max && s < city_min)
			city_min = s;
		no_city = false;
	}

	bool visited[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

	//stack for visiting
	int i ;
	vector<int> q; 
	q.push_back(s); 
	visited[s] = true ;
	bool last;
	while(q.size() != 0)
	{
		for(i = 0 ; i < graph[q[q.size()-1]].size(); i++ )
		{
			last = true;
			if(visited[graph[q[q.size()-1]][i]] == false)
			{
				visited[graph[q[q.size()-1]][i]] = true ;
				if(data[graph[q[q.size()-1]][i]].second > s_p[s_p.size()-1])
					s_p.push_back(s_p[s_p.size()-1]);
				else
					s_p.push_back(data[graph[q[q.size()-1]][i]].second);
				last = false;

				//if that is the possible destination
				if(data[graph[q[q.size()-1]][i]].first == prdct)
				{
					if(s_p[s_p.size()-1] > g_max)
					{
						g_max = s_p[s_p.size()-1];
						city_min = graph[q[q.size()-1]][i];
					}
					else if(s_p[s_p.size()-1] == g_max && graph[q[q.size()-1]][i] < city_min)
						city_min = graph[q[q.size()-1]][i];
					no_city = false;
				}
				q.push_back(graph[q[q.size()-1]][i]);
				break;
			}
		}
		if( i == graph[q[q.size()-1]].size() && last == true)
		{
			q.pop_back();
			s_p.pop_back();
		}
	}

	//choosing city among possible destinations
	if(no_city)
		return -2;
	return city_min ;
}

int main()
{
	clock_t start = clock();
	int n,k,b,u,v;
	cin >> n >> k >> b;
	Graph g(n);
	for(int i = 0 ;i < n-1 ;i++)
	{
		cin >> u >> v;
		g.addEgde(u-1,v-1);
	}
	pair<int,int> city; //first is product value and second will be distance from capital
	for(int i = 0 ; i < n ; i++)
	{
		cin >> city.first;
		data.push_back(city);
	}
	g.BFScapital(b-1);  //BFS from capital B to find shortest to every city

	//taking queries
	int queries;
	cin >> queries ;
	for(int i = 0 ; i < queries ; i++ )
	{
		cin >> u >> v ;
		cout << g.DFSproduct(u-1,v) + 1 << endl;
	}
	cout << "time " << (float)(clock() - start)*1000/CLOCKS_PER_SEC << " ms" << endl;
	return 0;
}