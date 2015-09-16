#include <bits/stdc++.h>
using namespace std;

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
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
typedef unsigned long long int ull;

vector<ull> populate(ull n)
{
	vector<ull> power(n);
	power[0] = 1 ;
	fr(i,1,n)
		power[i] = (2*power[i-1])%mod;
		
	return power;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ull test,n,till;
	cin >> test ;
	while(test--)
	{
		cin >> n ; 
		vector<ull> arr(n);
		fr(i,0,n)
			cin >> arr[i];
		sort(arr.begin(),arr.end());

		//differences here
		fr(i,0,n-1)
			arr[i] = arr[i+1] - arr[i];

		//sum of difference here
		till = n/2;
		if(n%2 == 0)
			till = n/2-1;
		fr(i,0,till)
			arr[i] = ( arr[i] + arr[n-2-i] )%mod;
		
		//final calc here
		vector<ull> power = populate(n);
		ull answer = 0 ;
		ull quant = 0;
		fr(i,0,n/2)
		{
			quant = ( quant + power[n-1-i] - power[i] )%mod ;
			answer = ( answer + (arr[i]*quant)%mod )%mod ;
		}
		cout << answer << endl ;
		arr.clear();
		power.clear();	
	}
	return 0;
}
