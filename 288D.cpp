#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

vector<char> ans;

class Graph
{
public:
	Graph(int n);
	void printAL();    //prints adjancency list
	void addEgde(int v, int w); 
	int findstart(int ind[]);
	void euler(int start);
private:
	vector< vector<int> > graph;
};

char backhash(int a)
{
	if(a <= 9)
		return '0' + a ;
	else if(a <= 35)
		return 'A' + (a-10);
	else
		return 'a' + (a-36);
}

int hashf(char a)
{
	int i;
	if(a <= '9')
		i = (int)(a - '0');
	else if(a <= 'Z')
		i = (int)(a-'A') + 10 ;
	else
		i = (int)(a-'a') + 36 ;
	return i;
}

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

int Graph::findstart(int ind[])
{
	int oddcount = 0;
	int start = -1;
	int evenstart = -1 ;
	fr(i,graph.size())
	{
		if(ind[i] != -1 || graph[i].size() > 0)
		{
			if(ind[i] != -1)
				ind[i] = graph[i].size() - ind[i]-1;
			else
				ind[i] = graph[i].size();
			if(ind[i]%2 == 0)
				evenstart = i ;
			else if(ind[i] == 1)
			{
				oddcount++;
				start = i ;
			}
			else if(ind[i] == -1)
				continue;
			else
				return -1;
		}
	}
	if(oddcount == 1)
		return start;
	if(oddcount == 0 )
		return evenstart;
	return -1;
}

void Graph::euler(int start)
{
	int temp;
	ans.pb(backhash((int)start/62)); 
	ans.pb(backhash(start%62)); 
	while(graph[start].size() > 0)
	{
		ans.pb(backhash(graph[start][0]%62));
		temp = start; 
		start = graph[start][0]; 
		graph[temp].erase(graph[temp].begin());
	}
}

int main()
{
	int n;
	string s;
	cin >> n ;
	Graph g(3844);
	int indegree[3844];
	fr(i,3844) indegree[i] = -1;
	fr(i,n)
	{
		cin >> s ;
		g.addEgde(62*hashf(s[0])+hashf(s[1]),62*hashf(s[1])+hashf(s[2]));
		indegree[62*hashf(s[1])+hashf(s[2])] ++ ;
	}
	int start = g.findstart(indegree);
	if(start == -1)
		cout << "NO" << endl;
	else
	{
		g.euler(start);
		cout << "YES" << endl;
		fr(i,ans.size())
			cout << ans[i] ;
		cout << endl;
	}
	return 0;
}
