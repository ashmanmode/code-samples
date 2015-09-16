#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define mod 1000000007
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
	string a ;
	int k;
	int arr[26] ;
	cin >> a >> k ;
	int max = 0 ; 
	fr(i,0,26)
	{
		cin >> arr[i] ;
		if(arr[i] > max)
			max = arr[i];
	}
	
	ull sum  = 0 ;
	fr(i,0,a.length())
		sum += (i+1)*arr[(int)(a[i]-'a')];
	sum += ((k*( 2*a.length() + 1 + k))/2 )*max ;
	cout << sum << endl ;
	
}