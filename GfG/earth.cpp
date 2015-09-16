#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%llu",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%llu",a)
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
	int n,t;
	cin >> t ;
	while(t--)
	{
		cin >> n ; 
		vector<int> a;
		fr(i,0,n)
			cin >> a[i] ;
		int x = 0 ;
		int y = n-1 ;
		int sum1,sum2 ;
		sum1 = 0 ; sum2 = 0 ;
		bool a,b ;
		a = true; 
		b = true; 
		while(x==y || y-x == 1)
		{
			sum1 += a[x] ;
			sum2 += 2*a[y] ;
			if(sum1 < sum2)
			{
				x++ ; a = true ;
			}
			else if(sum2 < sum1)
			{
				y++ ;
				b = true ;
			}
			else
			{
				x++ ;  a = true ;
				y++ ; b = true;
			}
		}
	}
	return 0;
}
