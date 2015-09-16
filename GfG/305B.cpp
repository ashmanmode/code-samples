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
typedef signed long long int sll;

int main()
{
	int a,b,n,m,q;
	cin >> n >> m >> q ;
	vector<int> temp;
	vector< vector<int> > map ;
	fr(i,0,n)
	{
		fr(j,0,m)
		{
			cin >> a; 
			temp.pb(a);
		}
		map.pb(temp);
		temp.clear();
	}

	vector<int> rowrank(n);
	int cont,final;
	int ans = 0 ;
	fr(i,0,n)
	{
		final = 0 ;
		cont = 0 ;
		fr(j,0,m)
		{
			if(map[i][j] == 1)
				cont++ ;
			if(j == m-1)
			{
				if(cont > final)
					final = cont ;
			}
			if(map[i][j] == 0)
			{
				if(cont > final)
					final = cont ;
				cont = 0 ;
			}
		}
		rowrank[i] = final ;
	}

	fr(i,0,q)
	{
		cin >> a >> b ; a-- ;b-- ;
		if(map[a][b] == 1)
			map[a][b] = 0;
		else
			map[a][b] = 1 ;
		final = 0 ;
		cont = 0 ;
		fr(j,0,m)
		{
			if(map[a][j] == 1)
				cont++ ;
			if(j == m-1)
			{
				if(cont > final)
					final = cont ;
			}
			if(map[a][j] == 0)
			{
				if(cont > final)
					final = cont ;
				cont = 0 ;
			}
		}
		rowrank[a] = final ;

		//max in rowrank
		ans = 0 ;
		fr(j,0,n)
		{
			if(rowrank[j] > ans)
				ans = rowrank[j];
		}
		cout << ans << endl ;
	}
}