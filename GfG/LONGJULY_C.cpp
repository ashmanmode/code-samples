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
		string colors[6];
		fr(i,0,6)
			cin >> colors[i] ; 

		bool poss = false ;

		if(colors[4]==colors[0] && colors[4]==colors[2])
			poss =  true ;
		if(colors[4]==colors[0] && colors[4]==colors[3])
			poss =  true ;
		if(colors[4]==colors[1] && colors[4]==colors[2])
			poss =  true ;
		if(colors[4]==colors[1] && colors[4]==colors[3])
			poss =  true ;
		if(colors[5]==colors[0] && colors[5]==colors[2])
			poss =  true ;
		if(colors[5]==colors[0] && colors[5]==colors[3])
			poss =  true ;
		if(colors[5]==colors[1] && colors[5]==colors[2])
			poss =  true ;
		if(colors[5]==colors[1] && colors[5]==colors[3])
			poss =  true ;

		if(poss)
			cout << "YES" << endl ;
		else
			cout << "NO" << endl ;

	}
}