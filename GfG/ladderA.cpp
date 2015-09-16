#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{	
	int n,m ;
	cin >> n >> m ; 
	int min = m ;
	if(n < m)
		min = n ;
	if(min%2 == 0)
		cout << "Malvika" << endl;
	else
		cout << "Akshat" << endl;
	return 0;
}
