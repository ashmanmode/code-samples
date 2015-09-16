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
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;

int main()
{
	int n,s,t;
	cin >> n >> s >> t ;
	arr a(n);
	vectin(a,n);
	if(s==t)
	{
		cout << 0 << endl ;
		return 0 ;
	}

	bool flag = true;
	int next = s;
	int count = 0 ;
	while(1)
	{
		next = a[next-1];
		count++;
		if(next == t)
			break;
		if(next == s)
		{
			flag = false;
			break;
		}
	}
	if(flag)
		cout << count << endl ;
	else
		cout << -1 << endl ;
}