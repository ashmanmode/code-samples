#include <bits/stdc++.h>
#define siz 2000
#define mod 1000000007
using namespace std;

unsigned long long int sfree[siz+1][siz+1];
unsigned long long int sful[siz+1][siz+1];

int cal_sfree(int a,int b)
{
	if( b == 0 )
	{
		sfree[a][0] = 1;
		return sfree[a][0];
	}
	if(a-b > 1)
	{
		if(sfree[a-1][b] == -1)
			sfree[a-1][b] = cal_sfree(a-1,b)%mod;
		if(sfree[a][b-1] == -1)
			sfree[a][b-1] = cal_sfree(a,b-1)%mod;
		return (sfree[a-1][b] + sfree[a][b-1])%mod;
	}
	else if(a-b == 1)
	{
		if(sfree[a][b-1] == -1)
			sfree[a][b-1] = cal_sfree(a,b-1)%mod;	
		return sfree[a][b-1];
	}
	return 0;
}

int cal_sful(int a,int b)
{
	if( a == 0 )
	{
		sful[0][b] = 1;
		return sful[0][b];
	}
	if(a-b >= 0)
	{
		if(sful[a-1][b] == -1)
			sful[a-1][b] = cal_sful(a-1,b)%mod;
		return sful[a-1][b];
	}
	else if( b-a >= 1)
	{
		if(sful[a-1][b] == -1)
			sful[a-1][b] = cal_sful(a-1,b)%mod;
		if(sful[a][b-1] == -1)
			sful[a][b-1] = cal_sful(a,b-1)%mod;
		return (sful[a-1][b] + sful[a][b-1])%mod;
	}
	return 0;
}

int main()
{
	//freopen("fb_input.txt","r",stdin);
	//freopen("fb_output.txt","w",stdout);
	int test_cases;
	cin >> test_cases ;
	int a,b;
	for(int i = 0 ; i < siz+1 ; i++ )
		for(int j = 0 ; j < siz+1 ; j++ )
		{
			sfree[i][j] = -1 ; 
			sful[i][j] = -1;
		}
	for(int i = 0  ; i < test_cases ; i++ )
	{
		scanf("%d-%d",&a,&b);
		cout << "Case #" << i+1 << ": " << cal_sfree(a,b) << " " << cal_sful(a,b) << endl ;
	}
}