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
//#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;
typedef signed long long int sll;

int main()
{
	int n,x;
	cin >> n;
	vector<int> arr(n,0);
	fr(i,0,n)
	{
		cin >> x ;
		if(x != -1)
			arr[i] = arr[x-1] + 1 ;
	}
	int max = 0 ;
	fr(i,0,n)
		if(arr[i] > max)
			max = arr[i];
	cout << max+1 << endl ;
}