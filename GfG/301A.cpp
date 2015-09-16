#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define mod 1000000007
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;
typedef signed long long int sll;

int main()
{
	int n;
	cin >> n ; 
	string a,b;
	cin >> a >> b ;
	int total = 0 ;
	fr(i,0,n)
	{
		int k = abs(int(a[i]-b[i])) ;
		if(k < 6)
			total += k ; 
		else
			total += (10-k);
	}
	cout << total << endl ; 
	return 0;
}