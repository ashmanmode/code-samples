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
#define printvect(a,n) fr(i,0,n) cout << fixed << a[i] << " " ;
typedef unsigned long long int ull;

int bits(ull num)
{
	int bits = 0;
	while(num > 0)
	{
		bits += num%2 ; 
		num /= 2 ;
	}
	return bits;
}

int main()
{
	int test,n,l,m;
	ull num,y;
	char x; 
	cin >> test;
	fr(t,0,test)
	{
		cin >> n >> l ; 
		vector<ull> outlet;
		vector<ull> charge;
		
		//input
		fr(i,0,n)
		{
			y = l - 1 ;
			num = 0 ;
			fr(i,0,l) 
			{
				cin >> x ;
				num += pow(2,y)*((int)x - 48) ;
				y-- ;
			}
			outlet.pb(num);
		}
		fr(i,0,n)
		{
			y = l - 1 ;
			num = 0 ;
			fr(i,0,l) 
			{
				cin >> x ;
				num += pow(2,y)*((int)x - 48) ;
				y-- ;
			}
			charge.pb(num);
		}

		//input check
		//printvect(outlet,n); cout << endl ;
		//printvect(charge,n); cout << endl ;

		//Xor table
		map<ull,vector<int> > mp;
		ull x_or;
		fr(i,0,n-1)
		{
			fr(j,0,n)
			{
				x_or = outlet[i]^charge[j];
				mp[x_or].pb(j);
			}
		}

		//examining the last row of xor matrix
		vector<ull> sol;
		fr(j,0,n)
		{
			x_or = outlet[n-1]^charge[j];
			if(mp[x_or].size() == n-1)
				sol.pb( bits(x_or) );
		}

		
		if(sol.size() == 0)
			cout << "Case #" << t+1 << ": NOT POSSIBLE" << endl;
		else
		{
			sort(sol.begin(),sol.end());
			cout << "Case #" << t+1 << ": " << sol[0] << endl;
		}
	}
	return 0;
}