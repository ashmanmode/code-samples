#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	int m,t,r;
	cin >> m >> t >> r;
	int val[m];
	fr(i,m) cin >> val[i];

	if(t < r)
	{
		cout << -1 << endl;
		return 0;
	}

	//if t >=r
	int end = val[0] - r + t ;
	int count = r ;
	int at_end = r;
	for(int i = 1; i < m ; i++ )
	{
		if(val[i] <= end )
			continue;
		else if(val[i] >= end + r)
		{
			count += r;
			end = val[i] - r + t  ;
			at_end = r ;
		}
		else
		{
			int current = at_end - val[i] + end  ;
			count += (r - current);
			end = val[i] - (r - current) + t  ;
			at_end = (r - current) ;
		}
	}
	cout << count << endl;
	return 0;
}