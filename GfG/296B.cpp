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

int x ;

void lcgx(int seed)
{
	x = seed ;
}

int lcgrandgen()
{
	int a; 
	a = (151561*x + 68481231)%1351655;
	return a ;
}

int main()
{
	int n ; si(n) ; 
	string m,n ;
	cin >> m >> n ;
	
	pair<int,int> inf[26];
	fr(i,0,26)
		inf[i].F = -1 ;

	int hamm = 0 ;
	int x,y; x = -1 ; y = -1 ;
	bool done = false;
	fr(i,0,n)
	{
		if(m[i] != n[i])
		{
			hamm++ ;
			inf[(int)(n[i]-'a')].F =  (int)(m[i]-'a');
			inf[(int)(n[i]-'a')].S =  i;
		}
	}

	//two less
	fr(i,0,26)
	{
		if(inf[i].F != -1)
		{
				done = true;
				x = inf[(int)(m[i]-'a')].S;
				y = i;	
		}
	}

}