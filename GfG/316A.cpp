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

int main() {
	int n,m;
	cin >> n >> m ;

	vector<int> a(n);
	fr(i,0,n)
		a[i] = 0 ;

	int x,currentwinner,currentscore;
	fr(i,0,m)
	{
		currentwinner = 1 ;
		currentscore = 0 ;
		fr(j,0,n)
		{
			cin >> x ;
			if(x > currentscore)
			{
				currentscore = x ;
				currentwinner = j+1 ;
			}
		}
		//cout << currentwinner << endl; 
		a[currentwinner-1]++ ;
	}

	int winner,score;
	winner = 1;
	score = 0 ;
	fr(i,0,n)
	{
		if(a[i] > score)
		{
			winner = i+1 ;
			score = a[i];
		}
	}

	cout << winner << endl ;
	return 0;
}