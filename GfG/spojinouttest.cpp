#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;
typedef signed long long int sll;

int main()
{
	int t ,k;
	scanf("%d%d",&t,&k);
	int a,s; s = 0 ;
	fr(i,0,t)
	{
		scanf("%d",&a);
		if(a%k ==0) s++ ;
		
	}
	printf("%d\n",s);
	return 0 ;
}