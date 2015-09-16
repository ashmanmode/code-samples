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
	string s ;
	cin >> s ;
	bool ab,ba,ab1,ba1;
	ab = false;
	ba = false;
	bool trip = false;
	
	int i = 1 ;
	while(i < s.length())
	{
		if(!trip && i < s.length()-1 && s[i-1] == 'A' && s[i] == 'B' && s[i+1] == 'A')
		{
			trip = true ;
			i+=3;continue;
		}
		if(!trip && i < s.length()-1 && s[i-1] == 'B' && s[i] == 'A' && s[i+1] == 'B')
		{
			trip = true ;
			i+=3; continue;
		}
		if(s[i-1] == 'A' && s[i] == 'B')
		{
			ab = true;
			i++ ;
		}
		if(s[i-1] == 'B' && s[i] == 'A')
		{
			ba = true ;
			i++ ;
		}
		i++ ;
	}
	//cout << ab << " " << ba << " " << trip << endl ;
	if(ab && ba || ab && trip || ba &&  trip)
		cout << "YES" << endl ;
	else
		cout << "NO" << endl; 
	return 0 ;
}