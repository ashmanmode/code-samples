#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1234567
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;
typedef signed long long int sll;

int main()
{
	int n ;
	cin >> n ;
	fr(i,1,n+1)
	{
		if(i%3 == 0 && i%5 == 0)
			cout << "FizzBuzz" << endl ;
		else if(i%3 == 0)
			cout << "Fizz" << endl ;
		else if(i%5 == 0)
			cout << "Buzz" << endl ;
		else
			cout << i << endl ;
	}
}