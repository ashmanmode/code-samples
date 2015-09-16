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
	string a,b;
	cin >> a >> b ;
	int n = a.length();
	vector<bool> def(n);
	int count = 0 ;
	fr(i,0,n)
	{
		if(a[i] != b[i])
		{
			def[i] = true;
			count++;
		}
		else
			def[i] = false;
	}
	if(count%2 == 1)
	{
		cout << "impossible" << endl ;
		return 0 ;
	}
	int change = 0 ;
	fr(i,0,n)
	{
		if(def[i] == false)
			cout << a[i] ;
		else
		{
			if(change < count/2)
			{
				cout << b[i] ;
				change++;
			}
			else
				cout << a[i] ;
		}
	}
	cout << endl ;

}