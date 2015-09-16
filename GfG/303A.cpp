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
	int n;
	cin >> n ;
	vector< vector<int> > arr;
	vector<int> temp(n);
	fr(i,0,n)
		arr.pb(temp);
	fr(i,0,n)
	{
		fr(j,0,n)
			cin >> arr[i][j] ;
	}
	vector<bool> sol(n);
	fr(i,0,n)
		sol[i] = true ;
	fr(i,0,n)
	{
		fr(j,0,n)
		{
			if(arr[i][j] == 1 || arr[i][j] == 3)
			{
				sol[i] = false;
				break;
			}
		}
	}

	int total = 0 ;
	fr(i,0,n)
	{
		if(sol[i] == true)
			total++ ;
	}

	cout <<  total << endl;
	fr(i,0,n)
	{
		if(sol[i] == true)
			cout << i+1 << " " ;
	}
	if(total != 0)
		cout << endl ;
}