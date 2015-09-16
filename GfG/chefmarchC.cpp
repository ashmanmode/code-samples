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
	Graph(int n,int m);   
	bool remEdge(int v, bool type,int m); //0 if side or 1 for down edge	
	void createDIS(int n,int m);
private:
	vector<int> graph;
};

Graph::Graph(int n,int m)
{
	int list; //1111 B
	for(int i = 0 ; i < n ; i++ )
	{
		for(int j = 0 ; j < m ; j++ )
		{
			list = 15;
			if( j == 0 )  list = 14 ;
			if( j == m-1 ) list = 13;
			if( i == 0 )  list = 7;
			if( i == n-1 ) list = 11;
			graph.push_back(list);
		}
	}
}

bool Graph::remEdge(int v,bool type,int m)
{
	if(type == false) //side edge
	{
		if( (graph[v]/2)%2 == 0) return false ;
		graph[v] -= 2 ; graph[v+1] -= 1 ;
	}
	else //down edge
	{
		if((graph[v]/4)%2 == 0) return false ;
		graph[v] -= 4 ; graph[v+m] -= 8 ;
	}
	return true;
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

void Graph::createDIS(int n,int m)
{
	fr(i,0,n*m) 
	{
		rank_siz[i] = 1 ;
		parent[i] = i;
	}
	lset = 1 ;
	fr(i,0,n)
	{
		fr(j,0,m-1)
		{
			if( (graph[i*m+j]/2)%2 )
				mergeset(i*m+j,i*m+j+1);
		}
	}
	fr(i,0,n-1)
	{
		fr(j,0,m)
		{
			if( (graph[i*m+j]/4)%2 )
				mergeset(i*m+j,i*m+j+m);
		}
	}
}

int main()
{
	int t ; 
	scanf("%d",&t);
	
	int n,m,q,q_type,x1,y1,x2,y2;
	ull sum ; 
	fr(i,0,t)
	{
		sum = 0 ;
		scanf("%d%d%d",&n,&m,&q);
		
		Graph g(n,m);

		//query handling
		vector< vector<int> > q_stack;
		vector<int> tmp ; 
		fr(j,0,q)
		{
			scanf("%d",&q_type);
			switch(q_type)
			{
				case 1: scanf("%d%d",&x1,&y1); x1--; y1--; 
						if( g.remEdge(x1*m + y1,0,m) ) 
						{
							tmp.pb(1); tmp.pb(x1*m + y1);  q_stack.pb(tmp); tmp.clear(); 
						}
						break;
				case 2: scanf("%d%d",&x1,&y1); x1--; y1--; 
						if( g.remEdge(x1*m + y1,1,m) ) 
						{
							tmp.pb(2); tmp.pb(x1*m + y1);  q_stack.pb(tmp); tmp.clear(); 
						} 
						break;
				case 3: scanf("%d%d%d%d",&x1,&y1,&x2,&y2); x1--; y1--; x2--; y2--; 
						tmp.pb(3); tmp.pb(x1*m + y1); tmp.pb(x2*m + y2); q_stack.pb(tmp); tmp.clear(); 
						break;
				case 4: tmp.pb(4) ; q_stack.pb(tmp); tmp.clear(); 
			}
		}

		//creating the disjoint union DS  and reverse qurery handling
		g.createDIS(n,m);
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