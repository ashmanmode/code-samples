//Matrix
#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;

//global DS container
int rank_siz[maxsiz];   //here rank_siz is the size of set	
int parent[maxsiz];	//parent denotes root as well as parent
int lset;  //maximum size of the set

class Graph
{
public:
	Graph(int n);
	void printAL();    
	void addEdge(int v, int w); 
	bool remEdge(int v, int w);	
	void createDIS();
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

void Graph::addEdge(int v,int w)
{
	graph[v].push_back(w);
	graph[w].push_back(v);
} 

bool Graph::remEdge(int v,int w)
{
	bool edge = false;
	fr(i,0,graph[v].size())
	{
		if(graph[v][i] == w)
		{
			graph[v].erase(graph[v].begin() + i);
			edge = true;
			break;
		}
	}

	fr(i,0,graph[w].size())
	{
		if(graph[w][i] == v)
		{
			graph[w].erase(graph[w].begin() + i);
			break;
		}
	}
	return edge;
} 

void Graph::createDIS()
{
	lset = 1 ; 
	bool visited[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

	//queue for visiting
	vector<int> q;
	fr(k,0,graph.size())
	{
		if(visited[k] == false)
		{
			rank_siz[k] = 1 ; parent[k] = k ;    //k will be the root
			q.push_back(k);
			visited[k] = true ;
			while(q.size() != 0)
			{
				for(int i = 0 ; i < graph[q[0]].size(); i++ )
				{
					if(visited[graph[q[0]][i]] == false)
					{
						rank_siz[k]++;  parent[ graph[q[0]][i] ] = k ;
						visited[graph[q[0]][i]] = true ;
						q.push_back(graph[q[0]][i]);
					}
				}
				q.erase(q.begin());
			}
			if(rank_siz[k] > lset)
				lset = rank_siz[k];
		}
	}
}

int findroot(int x)
{
	if(x != parent[x])
		return findroot(parent[x]);
	return x;
}

void mergeset(int x,int y)
{
	int px = findroot(x);
	int py = findroot(y);
	if(px != py)
	{
		if(rank_siz[px] > rank_siz[py])
		{
			parent[py] = px ;
			rank_siz[px] += rank_siz[py];  
			if(rank_siz[px] > lset) lset = rank_siz[px];
		}
		else
		{
			parent[px] = py ;
			rank_siz[py] += rank_siz[px];
			if(rank_siz[py] > lset) lset = rank_siz[py];
		}
	}
}

int main()
{
	int t ; 
	//cin >> t ;
	scanf("%d",&t);
	
	int n,m,q,q_type,x1,y1,x2,y2;
	ull sum ; 
	fr(i,0,t)
	{
		sum = 0 ;
		//cin >> n >> m >> q ;
		scanf("%d%d%d",&n,&m,&q);
		
		Graph g(n*m);

		//creating graph
		fr(k,0,n) //horizontal lines
		{
			fr(j,0,m-1)
				g.addEdge(k*m + j ,k*m + j + 1);
		}
		fr(k,0,m) //vertical lines
		{
			fr(j,0,n-1)
				g.addEdge( m*j + k ,m*j + k + m);
		}

		//query handling
		vector< vector<int> > q_stack;
		vector<int> tmp ; 
		fr(j,0,q)
		{
			//cin >> q_type ; 
			scanf("%d",&q_type);
			switch(q_type)
			{
				case 1: //cin >> x1 >> y1 ;
						scanf("%d%d",&x1,&y1); x1--; y1--; 
						if( g.remEdge(x1*m + y1,x1*m + y1+1) ) 
						{
							tmp.pb(1); tmp.pb(x1*m + y1);  q_stack.pb(tmp); tmp.clear(); 
						}
						break;
				case 2: //cin >> x1 >> y1 ; 
						scanf("%d%d",&x1,&y1); x1--; y1--; 
						if( g.remEdge(x1*m + y1,x1*m + y1+m) ) 
						{
							tmp.pb(2); tmp.pb(x1*m + y1);  q_stack.pb(tmp); tmp.clear(); 
						} 
						break;
				case 3: //cin >> x1 >> y1 >> x2 >> y2 ; 
						scanf("%d%d%d%d",&x1,&y1,&x2,&y2); x1--; y1--; x2--; y2--; 
						tmp.pb(3); tmp.pb(x1*m + y1); tmp.pb(x2*m + y2); q_stack.pb(tmp); tmp.clear(); 
						break;
				case 4: tmp.pb(4) ; q_stack.pb(tmp); tmp.clear(); 
			}
		}

		//creating the disjoint union DS  and reverse qurery handling
		g.createDIS();
		for(int j = q_stack.size() -1 ; j > -1 ; j-- )
		{
			q_type = q_stack[j][0];
			switch(q_type)
			{
				case 1: mergeset(q_stack[j][1],q_stack[j][1]+1);
						break;
				case 2: mergeset(q_stack[j][1],q_stack[j][1]+m);
						break;
				case 3: sum += ( findroot(q_stack[j][1]) == findroot(q_stack[j][2]) ); 
						break;
				case 4: sum += lset; 
			}
		}
		
		//cout << sum << endl ;
		printf("%llu\n",sum );
		q_stack.clear();
	}
	return 0;
}