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

int main()
{
	int n,k;
	char c ; 
	cin >> n ; 
	vector<bool> str(n);

	fr(i,0,n)
	{
		cin >> c ;
		if(c == '*')
			str[i] = true;
		else
			str[i] = false;
	}

	fr(i,0,n)
	{
		if(str[i])
		{
			k = 1 ;
			while(i+4*k < n)
			{
				if(str[i+k] && str[i+2*k] && str[i+3*k] && str[i+4*k])
				{
					cout << "yes" << endl ;
					return 0 ;
				}
				k++ ;
			}
		}
	}
	cout << "no" << endl ;
	return 0 ;
}