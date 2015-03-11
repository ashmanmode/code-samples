#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int size = 10;
ull primes[size] = {2,3,5,7,11,13} ;

int main()
{
	int t,n;
	cin >> t ;
	ull ans;
	fr(i,t)
	{
		cin >> n ;
		fr(j,size)
		{
			if(n == primes[j])
			{
				//gp formula
				ull ans1 = (n-1)/2 ;
				ull ans2 = (2*n-1)/3 ;
				ans = (n*ans1)%mod;
				ans = (ans*ans2)%mod;
				cout << ans << endl ;
				break;
			}
		}
		ans = 1 ;
		for(int j = 0 ; j < size ; j++ )
		{
			k = 1 ;
			if(n%primes[j] != 0)
			{
				while( pow(primes[j],k) < n)
				{
					ans = ( ans + (primes[j]*primes[j])%mod ) % mod ;
					k++ ;
				}
			}
		}
	}
}