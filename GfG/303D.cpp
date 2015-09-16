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
typedef unsigned long long int ull;

int main()
{
	int n ; 
	cin >> n ; 
	vector<int> arr(n);
	fr(i,0,n)
		cin >> arr[i] ;
	sort(arr.begin(),arr.end());
	int current = 0 ;
	int satis = 0 ;
	fr(i,0,n)
	{
		if(current <= arr[i])
		{
			satis ++ ;
			current = current + arr[i] ;
		}
	}
	cout << satis << endl ;
}