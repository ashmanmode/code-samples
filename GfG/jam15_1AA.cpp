#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define mod 1000000007
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
typedef unsigned long long int ull;

ull gcd( ull x, ull y )
{
   if( x < y )
      return gcd( y, x );

   ull f = x % y;
   if( f == 0 )
     return y;
   else
      return gcd( y, f );
}


int main()
{
	int test,b;
	ull n;
	cin >> test ;
	fr(t,0,test)
	{
		cin >> b >> n ; 
		vector<ull> num(b);
		fr(i,0,b) cin >> num[i] ;

		ull divisor = num[0] ;
		ull period = 0 ;
		fr(i,1,b)
			divisor = gcd(divisor,num[i]);
		fr(i,0,b)
			period += num[i]/divisor  ;
		n = n%period;
		
		if(n==0)
			n = period ;
		if(n <= b)
			cout << "Case #" << t+1 << ": " << n  <<  endl;
		else
		{
			ull pick ;
			n = n - b ; 
			fr(i,0,n)
			{
				ull min = num[0]; pick = 1 ;
				fr(i,1,b)
				{
					if(num[i] < min)
					{
						min = num[i];
						pick = i+1; 
					}
				}
				num[pick-1] += num[pick-1] ;
			}
			cout << "Case #" << t+1 << ": " << pick  <<  endl;
		}
	}
	return 0 ;
}