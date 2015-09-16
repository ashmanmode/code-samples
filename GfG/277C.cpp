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
	int m,s ;
	cin >> m >> s ;

	if( (s == 0 && m > 1) || s > 9*m )
	{
		cout << -1 << " "<<  -1 << endl ;
		return 0 ;
	}

	//smallest number
	vector<int> sm(m);
	int csum = s ;
	fr(i,0,m-1)
	{
		if( s > (i+1)*9 )
		{
			sm[i] = 9 ;
			csum -= 9 ;
		}
		else
		{
			sm[i] = csum - 1 ;
			csum = 1 ;
		}
	}
	sm[m-1] = csum ;

	for(int i = m-1 ; i > -1 ; i-- )
		cout << sm[i] ;
	cout << " " ;

	//largest number
	vector<int> lm(m);
	csum = s ;
	fr(i,0,m)
	{
		if( s >= (i+1)*9 )
		{
			lm[i] = 9 ;
			csum -= 9 ;
		}
		else
		{
			lm[i] = csum ;
			csum = 0 ;
		}
	}

	for(int i = 0 ; i < m ; i++ )
		cout << lm[i] ;
	cout << endl ;

}