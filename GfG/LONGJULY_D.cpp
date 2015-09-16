#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define vectin(a,n)
typedef unsigned long long int ull;
typedef signed long long int sll;

int main()
{
	int test ;
	cin >> test ;
	while(test--)
	{
		unsigned long long int a ;
		cin >> a ;

		//if divisible by 10 : do nothing
		unsigned long long int current = a ;
		while( (current/10)*10 == current)
		{
			current /= 10 ;
		}

		//if 5 den multiply by 4 
		unsigned long long int count = 0 ; 
		while( (current/5)*5 == current )
		{
			current /= 5 ;
			if(count%2 == 0) a *= 4 ;
			count++ ;
		}

		cout << a << endl ;
	}
}