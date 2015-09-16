#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define vectin(a,n)
typedef unsigned long long int ull;
typedef signed long long int sll;

int main()
{	
	int n,k,m;
	cin >> n >> k;

	map<int,vector<int> > mymap;
	fr(i,0,n)
	{
		cin >> m ;
		mymap[m].pb(i) ;
	}

	sll ans = 0 ;
	for (std::map<int,vector<int> >::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	{
		//std::cout << it->first << " => " << it->second.size() << '\n';
		if( mymap.find(it->first*k) != mymap.end()  && mymap.find(it->first*k*k) != mymap.end()  )
		{
			vector<int> state(mymap[it->first*k].size());
			int current = 0 ;
			int myprev = mymap[it->first*k*k].size()-1 ;
			for(int j = mymap[it->first*k].size()-1; j > -1 ; j-- )
			{
				for(int x = myprev; x > -1 ; x-- )
				{
					if(mymap[it->first*k*k][x] > mymap[it->first*k][j])
						current++;
					else
					{
						myprev = x ;
						break;
					}
					if(x == 0)
						myprev = -1 ;
				}
				if(mymap[it->first*k].size()-1 != j)
					state[j] = current + state[j+1];
				else
					state[j] = current ; 
			}
			//printvect(state,mymap[it->first*k].size()) ;
			//cout << endl ;

			myprev = mymap[it->first*k].size()-1 ;
			current = 0 ;
			for(int j = mymap[it->first].size()-1; j > -1 ; j-- )
			{
				for(int x = myprev; x > -1 ; x-- )
				{
					if(mymap[it->first*k][x] > mymap[it->first][j])
						current++;
					else
					{
						myprev = x ;
						break;
					}
					if(x == 0)
						myprev = -1 ;
				}
				//cout << current << " " ;
				ans += state[mymap[it->first*k].size() - current] ;
			}
			//cout << endl ;
			state.clear();
		}
	}
   
	cout << ans << endl ;
	
	return 0;
}