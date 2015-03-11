#include <bits/stdc++.h>
#define siz 5000
#define Err -1
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int find(int n,int m)
{
	int s1 = 0 ;
	int s2 = 0 ;
	if(n >=1 && m >= 2)
		s1 = 1 + find(n-1,m-2);	
	if(n >= 2 && m >=1)
		s2 = 1 + find(n-2,m-1);
	
	if(s1 > s2)
		return s1;
	else
		return s2;
}

int main()
{
	int n,m;
	cin >> n >> m ; 
	
	ull ans = 0 ;
	/*int min = n ;
	if(m < n) 
		min = m ; 
	ans += (min/3)*2 ;
	n -= (ans/2)*3 ;
	m -= (ans/2)*3 ;*/

	ans += find(n,m) ;
	cout << ans << endl ;
	return 0 ;
}