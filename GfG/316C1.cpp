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
	int n,m;
	cin >> n >> m ;

	vector<char> s(n+1);
	fr(i,0,n)
		cin >> s[i] ;
	s[n] = 'a';

	char prev = s[0];
	int cur = 0 ;
	int total = 0 ; 
	for(int i = 1 ; i < n+1 ; i++ )
	{
		if(s[i] != prev)
		{
			if(s[i] == '.')
				cur = i ;
			if(prev == '.')
				total += ( i-1-cur );
			prev = s[i];
		}
	}

	int add;
	char c;
	fr(i,0,m)
	{
		cin >> add >> c ;
		add--;
		if(c!=s[add])
		{
			if(c=='.')
			{
				//both side dots
				if( add < n-1 && s[add+1] == '.')
					total += 1 ;
				if( add > 0 && s[add-1] == '.')
					total += 1 ;
			} 
			else
			{
				//both side dots
				if( add < n-1 && s[add+1] == '.')
					total -= 1 ;
				if( add > 0 && s[add-1] == '.')
					total -= 1 ;
			}
		}
		s[add] = c ;
		cout << total << endl ;
	}

	return 0;
}