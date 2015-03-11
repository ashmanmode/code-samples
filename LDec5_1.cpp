//multithreaded solution
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
#include "time.h"
using namespace std;

vector< pair<int,int> > data;
vector< pair<int,int> > outputs;
mutex mtx ;

class Graph
{
public:
	Graph(int n);  
	void addEgde(int v, int w);
	void BFScapital(int s);
	void DFSproduct(int s,int prdct,int call);
	void DFSproductm(int s,vector<int> prdct,int call);
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

void Graph::DFSproduct(int s,int prdct,int call)
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
	pair<int,int> out;
	out.first = call;
	if(no_city)
	{
		out.second = -1 ;
		//cout << -1 << endl;
	}
	else
	{
		out.second = city_min + 1 ;
		//cout << city_min + 1 << endl ;
	}
	mtx.lock();
	outputs.push_back(out);
	mtx.unlock();
}

void Graph::DFSproductm(int s,vector<int> prod,int call)
{
	bool no_city[prod.size()];
	int city_min[prod.size()];
	int g_max[prod.size()];
	for(int a = 0 ; a < prod.size();a++)
	{
		no_city[a] = true;
		city_min[a] = graph.size();
		g_max[a] = 0 ;
	}
	vector<int> s_p; //stack for distances from capital
	s_p.push_back(data[s].second);
	for(int a = 0 ; a < prod.size();a++)
	{
		if(data[s].first == prod[a])
		{
			if(data[s].second > g_max[a])
			{
				g_max[a] = data[s].second;
				city_min[a] = s;
			}
			else if(data[s].second == g_max[a] && s < city_min[a])
				city_min[a] = s;
			no_city[a] = false;
		}
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
				for(int a = 0 ; a < prod.size();a++)
				{
					if(data[graph[q[q.size()-1]][i]].first == prod[a])
					{
						if(s_p[s_p.size()-1] > g_max[a])
						{
							g_max[a] = s_p[s_p.size()-1];
							city_min[a] = graph[q[q.size()-1]][i];
						}
						else if(s_p[s_p.size()-1] == g_max[a] && graph[q[q.size()-1]][i] < city_min[a])
							city_min[a] = graph[q[q.size()-1]][i];
						no_city[a] = false;
					}
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
	pair<int,int> out;
	for(int a = 0 ; a < prod.size();a++)
	{	
		out.first = call + a;
		if(no_city[a])
		{
			out.second = -1 ;
			//cout << -1 << endl;
		}
		else
		{
			out.second = city_min[a] + 1 ;
			//cout << city_min + 1 << endl ;
		}
		mtx.lock();
		outputs.push_back(out);
		mtx.unlock();
	}
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

	//taking queries and will use single DFS if queries start with same vertex A
	int call_num = 0 ;
	int actual_calls = 0;
	vector<std::thread*> t;
	int queries,common_v;
	cin >> queries ;
	vector<int> prod;
	cin >> common_v >> v ; prod.push_back(v);
	for(int i = 1 ; i < queries ; i++ )
	{
		cin >> u >> v ;
		if(u == common_v)
			prod.push_back(v);
		else
		{
			//call with common_v and prod
			if(prod.size() == 1)
			{
				t.push_back(new thread (&Graph::DFSproduct,g,common_v - 1 ,prod[0],call_num));
				call_num++ ;actual_calls++;
				//g.DFSproduct(common_v - 1 ,prod[0]);
			}
			else
			{
				t.push_back(new thread (&Graph::DFSproductm,g,common_v - 1 ,prod,call_num));
				call_num += prod.size();actual_calls++;
				//g.DFSproductm(common_v - 1 , prod);
			}
			prod.clear();
			common_v = u ;
			prod.push_back(v);
		}
	}
	if(prod.size() == 1)  //for last call
		t.push_back(new thread (&Graph::DFSproduct,g,common_v - 1 ,prod[0],call_num++));
		//g.DFSproduct(common_v - 1 ,prod[0]);
	else
		t.push_back(new thread (&Graph::DFSproductm,g,common_v - 1 ,prod,call_num++));
		//g.DFSproductm(common_v - 1 , prod);

	for(int i = 0 ; i < actual_calls+1 ;i++ )
    {
  		t[i]->join();
  		delete t[i];
    }

	//now we have all inputs .. sort them according to call and print
	sort(outputs.begin(),outputs.end());
	for(int i = 0 ; i < outputs.size() ; i++)
		cout << outputs[i].second << endl;
	cout << "time " << (float)(clock() - start)*1000/CLOCKS_PER_SEC << " ms" << endl;
	return 0;
}