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
typedef signed long long int sll;

int main()
{
	int n;
	sll temp ;
	cin >> n ;
	arr a(n);
	vectin(a,n);

	sll sum = 0 ;
	fr(i,0,n)
		sum += a[i] ;

	ull ans = 0 ; 
	if(sum%3 == 0)
	{
		temp = 0 ;
		ull count = 0 ;
		fr(i,0,n-1)
		{
			temp += a[i] ; 
			if(temp == 2*(sum/3))
				ans += count;
			if(temp == (sum/3) )
				count++ ;
		}
	}
	cout << ans << endl ;
}