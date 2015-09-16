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

int main() {
	int n,p;
	char x;
	cin >> n ; 

	map<int,bool> m;
	vector<char> op;
	vector<int> id;
	fr(i,0,n)
	{
		cin >> x >> p ;
		op.pb(x);
		id.pb(p);
	}

	int prev = 0 ;
	fr(i,0,n)
	{
		if(op[i]=='+')
			m[id[i]] = true;
		else
		{
			if(m.find(id[i]) == m.end())
			{
				prev++ ; 
			}
		
		}
	}
	//cout << prev << endl ;
	
	m.clear();
	int max = prev ;
	int current = prev ;
	fr(i,0,n)
	{
		if(op[i]=='+')
		{
			current++ ;
			m[id[i]] = true;
		}
		else
		{
			if(m.find(id[i]) != m.end() && m[id[i]] == true)
			{
				current--;
				m[id[i]] = false;
			}
			else if(m.find(id[i]) == m.end())
			{
				current-- ; 
			}
		
		}
		//cout << current << " " ;
		if(max < current)
			max = current ;
	}

	//cout << endl ;
	cout << max << endl ;
	return 0;
}