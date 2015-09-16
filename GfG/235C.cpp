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
	int n,m;
	cin >> n >> m ; 
	if(m > 2*n+2 || m < n-1 )
		cout << -1 << endl ;
	else
	{
		if(n >= m)
		{
			fr(i,0,m)
				cout << "01" ;
			if(n > m)
				cout << "0" ;
			cout << endl ;
		}
		else 
		{
			int k = 0 ;
			if(m/(2*n))
				k = m-(2*n);
			fr(i,0,k)
				cout << "1" ;
			
			int t2 = min(m-n,n) ; 
			int t1 = n - min(m-n,n) ; 
			fr(i,0,t2)
				cout << "011" ;
			fr(i,0,t1)
				cout << "01" ; 
			cout << endl ;
		}
	}
}