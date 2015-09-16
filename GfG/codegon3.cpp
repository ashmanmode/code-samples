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
	
	vector<int> a(n);
	int max = 0 ; 
	fr(i,0,n)
	{
		cin >> a[i] ;
		if(a[i] > max)
			max = a[i] ;
	}

	vector<int> info(n);
	int count = 0 ;
	fr(i,0,n)
	{
		if(a[i] == max)
			count++;
		info[i] = count ;
	}

	int l,r ;
	fr(i,0,m)
	{
		cin >> l >> r ;
		if(l == 1)
			cout << info[r-1] << endl ;
		else
			cout << info[r-1] - info[l-2] << endl ;
	}
	return 0;
}