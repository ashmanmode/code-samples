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
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;

int main()
{
	int t ;
	cin >> t ;
	while(t--)
	{
		string s ;
		cin >> s ;
		int sum = 0 ;
		fr(i,0,s.length())
			sum += (int)(s[i]-'0');  
		int k = (sum/9)*9 ;
		if( k!=0 || s.length() == 1)
			cout << min(sum-k,k+9-sum) << endl;
		else
			cout << k+9-sum << endl ;
	}
}