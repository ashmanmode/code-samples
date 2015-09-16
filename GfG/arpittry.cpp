#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;

bool compstr(string a,string b)
{
	int n = a.length();
	fr(i,0,n)
		if(a[i] != b[i])
			return false;
	return true;
}


int main()
{
	string a,b;
	cin >> a >> b ;
	if(compstr(a,b))
		cout << "same" << endl ;
	
	return 0;
}