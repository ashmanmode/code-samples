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

int main()
{
	int n,l,r,x ;
	int max,min,sum;
	cin >> n >> l >> r >> x ;
	vector<int> a(n);
	vectin(a,n);
	sort(a.begin(),a.end());

	int count = 0 ;
	fr(i,0,pow(2,n))
	{
		bitset<15> foo(i) ;
		min = 12345678 ;
		max = -1 ;
		sum = 0 ;
		fr(j,0,n)
		{
			if(foo[j] == 1)
			{
				sum += a[j];
				if(max < a[j])
					max = a[j];
				if(min > a[j])
					min = a[j];
			}
		}
		if(sum <= r && sum >= l && max-min >= x)
			count++ ;
	}
	cout << count << endl ;
}