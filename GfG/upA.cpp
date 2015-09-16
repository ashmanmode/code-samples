#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1234567
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
typedef signed long long int sll;

bool myfunction (string i,string j) { return (i.length()<j.length()); }

int main()
{
	int n ; 
	cin >> n ;
	vector<string> a(n);
	fr(i,0,n)
		cin >> a[i]; 
	sort(a.begin(),a.end(),myfunction);
	map<string,int> st ;
	int ans = 0 ; 
	fr(i,0,n)
	{
		if(a[i].length() == 1)
			st[a[i]] = 1 ;
		else
		{
			fr(j,0,a[i].length())
			{
				string sub = a[i].substr(0,j) + a[i].substr(j+1,a[i].length()-j-1);
				//cout << sub << " " ;
				if(st[sub] && st[sub] > st[a[i]] -1)
					st[a[i]] = 1 + st[sub];
			}
			//cout << endl ;
		}

		if(ans < st[a[i]])
			ans = st[a[i]];
	}
	// cout << " map " << endl ;
	// fr(i,0,n)
	// 	cout << st[a[i]] << " " ; 
	cout << ans << endl ;
}