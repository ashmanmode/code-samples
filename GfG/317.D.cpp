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
	int n,k;
	cin >> n >> k ;
	vector<int> a(n);
	fr(i,0,n)
		cin >> a[i] ;
	sort(a.begin(),a.end());
	vector<int> pairs;
	for(int i = 0 ; i < n-1 ; i += 2 )
	{
		pairs.pb(abs(a[i+1] - a[i]));
	}
	sort(pairs.begin(),pairs.end());// cout << "pa" << pairs.size() << endl ;
	printvect(pairs,pairs.size());cout << endl ;
	int sum = 0;
	if(n-k <= pairs.size())
	{
		fr(i,0,n-k)
			sum += pairs[i] ;
	}
	else if(n%2 == 0)
	{
		fr(i,0,pairs.size())
			sum += pairs[i] ;
		for(int i = pairs.size()-1 ; i >= k-n + 2*pairs.size() ;i--)
			sum += pairs[i];
	}
	else
	{
		fr(i,0,pairs.size())
			sum += pairs[i] ;
		for(int i = pairs.size()-1 ; i >= k-n + 2*pairs.size() + 1 ;i--)
			sum += pairs[i];
	}
	cout << sum << endl ;
	return 0 ;
}
