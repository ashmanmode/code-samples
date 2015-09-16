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
	int n ; 
	cin >> n ;
	char s,prev;
	prev = 'a' ;

	vector<int> count ;
	int current = 0 ;
	int other = 0 ;
	fr(i,0,n)
	{
		cin >> s ;
		if(prev == 'v' || prev == 'w')
		{
			if(s == 'v')
				current++;
			else if(s == 'w' )
				current += 2 ;
			else
			{
				other++ ;
				count.pb(current);
				current = 0 ;
			}
		}
		else
		{
			if(s == 'v')
				current = 1;
			else if(s == 'w' )
				current = 2 ;
			else
				other++ ;
		}
		prev = s ;
	}
	count.pb(current);
	
	int min = other ;
	int max = other ;
	fr(i,0,count.size())
	{
		min += count[i]/2 + count[i]%2 ;
		max += count[i];
	}
	cout << min << " " << max << endl ;
}