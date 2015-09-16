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
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;
typedef signed long long int sll;

int main()
{
	string a,b;
	cin >> a >> b;

	int x1 = (int)(a[0]-'a');
	int x2 = (int)(b[0]-'a');
	int y1 = (int)(a[1]-'1');
	int y2 = (int)(b[1]-'1');

	int diag = min(abs(x1-x2),abs(y1-y2)) ;
	int total = max(abs(x1-x2),abs(y1-y2)) ;
	cout << max(abs(x1-x2),abs(y1-y2)) << endl ; 

	if(x1 <= x2 && y1 <= y2)
	{
		fr(i,0,diag)
			cout << "RU" << endl ;
		if(abs(x1-x2) > abs(y1-y2))
		fr(i,0,total-diag)
			cout << "R" << endl ;
		else
		fr(i,0,total-diag)
			cout << "U" << endl ;

	}
	else if(x1 <= x2 && y1 >= y2)
	{
		fr(i,0,diag)
			cout << "RD" << endl ;
		if(abs(x1-x2) > abs(y1-y2))
		fr(i,0,total-diag)
			cout << "R" << endl ;
		else
		fr(i,0,total-diag)
			cout << "D" << endl ;
	}
	else if(x1 >= x2 && y1 <= y2)
	{
		fr(i,0,diag)
			cout << "LU" << endl ;
		if(abs(x1-x2) > abs(y1-y2))
		fr(i,0,total-diag)
			cout << "L" << endl ;
		else
		fr(i,0,total-diag)
			cout << "U" << endl ;
	}
	else
	{
		fr(i,0,diag)
			cout << "LD" << endl ;
		if(abs(x1-x2) > abs(y1-y2))
		fr(i,0,total-diag)
			cout << "L" << endl ;
		else
		fr(i,0,total-diag)
			cout << "D" << endl ;
	}

}