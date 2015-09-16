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
//#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;
typedef signed long long int sll;

int main()
{
	int t;
	cin >> t ;
	while(t--)
	{
		int n,x;
		cin >> n ;
		vector<int> groups ;
		vector<int> arr;
		fr(i,0,n)
		{
			cin >> x ;
			arr.pb(x) ;
		}
		sort(arr.begin(),arr.end());

		int start = arr[0] ; 
		int grpcount = 1 ;
		fr(i,1,n)
		{
			if(arr[i] == start+1)
				grpcount++;
			else
			{
				groups.pb(grpcount);
				grpcount = 1 ;
			}
			start = arr[i];
		}
		groups.pb(grpcount);
		int min = 0 ;
		int max = 0 ;
		fr(i,0,groups.size())
		{
			if(groups[i]%3 == 0)
				min += groups[i]/3 ;
			else
				min += groups[i]/3 + 1 ;

			if(groups[i]%2 == 0)
				max += groups[i]/2 ;
			else
				max += groups[i]/2 + 1 ;

		}
		cout << min << " " << max << endl ;	
		groups.clear();
		arr.clear();
	}
}