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

int calc(int c,int hr,int wr,int hb,int wb)
{
	//1
	int ans1 = (c/wr)*hr + ((c - c/wr)/wb )*hb;
	int ans2 = (c/wr)*hr + ((c - c/wr)/wb )*hb;


}

int main()
{
	int c,hr,hb,wr,wb;
	cin >> c >> hr >> hb >> wr >> wb ;

	if( (double)hr/(double)wr > (double)hb/(double)wb )
	{

	}
	return 0 ;
}