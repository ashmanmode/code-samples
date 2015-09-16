#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%llu",&a)
#define ss(a) scanf("%llu",&a)
#define sc(a) scanf("%c",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%llu",a)
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;
typedef signed long long int sll;

int main()
{
	int t ; si(t) ;
	while(t--)
	{
		double x0,y0,x1,y1,r,v;
		cin >> r >> x0 >> y0 >> x1 >> y1 >> v ;
		double ans = r ;
		ans -= sqrt((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1));
		ans /= v ;
		cout << fixed << ans << endl ; 
	}
	return 0;
}