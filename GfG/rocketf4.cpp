#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	int n ,x,y; 
	cin >> n ;
	vector< pair<int,int> > bids;
	int fbidthre = 0;
	int max = 0;
	for(int i = 0 ; i < n ; i++ )
	{
		cin >> x >> y ;
		bids.pb(mk(x,y));
		if(x > fbidthre)
			fbidthre = x ;
		if(y > max)
			max = y;
	}
	for(int i = max ; i > fbidthre-1 ; i-- )
	{
		
	}
}