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

bool compstr(string a,string b)
{
	int n = a.length();
	fr(i,0,n)
		if(a[i] != b[i])
			return false;
	return true;
}

int main()
{
	string s ,k; 
	cin >> s ;
	cout << "start" << endl ;	
	for(int i = 1 ; i < 32770*2 ; i++ )
	{
		cin >> k ; 
		if(compstr(s,k))
		{
			cout << i << endl;
		}
	}
	return 0 ;
}