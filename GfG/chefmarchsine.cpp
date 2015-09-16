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
typedef unsigned long long int ull;

int main()
{
	int t ; si(t) ;
	int s,c,k;
	while(t--)
	{
		si(s);si(c);si(k);
		ull ans = 0 ;
		if(s == 0 )
		{
			if(k == 1)
				for(int i = 1 ; i <= c ; i++ )
					ans += pow(2,i);
		}
		else
		{
			vector<ull> arr(s+1);
			for(int i = 1 ; i < s+1 ; i++ )
				arr[i] = pow(2,s-i);
			arr[s] += 2 ;

			

			for(int i = 1; i < min(s,c+1) ; i++ )
			{
				arr[s-i+1] += arr[s-i] ;
				arr[s-i] = 0 ;
			}
			for(int i = s ; i <= c ; i++ )
				arr[1] += pow(2,i);
			
			
			fr(i,k,s+1)
				ans += arr[i];
		}
		cout << ans << endl ;
	}
	return 0;
}