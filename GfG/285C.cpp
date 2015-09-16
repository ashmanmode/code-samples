#include <iostream>
#include <vector>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	vector< pair<int,int> > edges;
	vector<int> q;
	int n;
	cin >> n ;
	int to[n],x_or[n];
	fr(i,n) cin >> to[i] >> x_or[i];
	fr(i,n) if(to[i] == 1) q.push_back(i);

	while(q.size() != 0)
	{
		int i = q[0];
		if(to[i] == 1)
		{
			q.erase(q.begin());
			edges.pb(mp(i,x_or[i]));
			to[x_or[i]]--;
			x_or[x_or[i]] ^= i;
			if(to[x_or[i]] == 1)
				q.pb(x_or[i]);
		}
		else
			q.erase(q.begin());
	}

	cout << edges.size() << endl;
	fr(i,edges.size()) cout << edges[i].first << " " << edges[i].second << endl;
	return 0;
}