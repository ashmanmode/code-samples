#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	int t;
	cin >> t ;
	string s;
	bool funny;
	fr(i,t)
	{
		cin >> s ;
		funny = true;
		fr(i,s.length()/2)
		{
			if( abs((int)s[i] - (int)s[i+1]) != abs((int)s[s.length() - 1 - i] - (int)s[s.length() - i - 2]) )
				funny = false;
		}
		if(funny)
			cout << "Funny" << endl;
		else
			cout << "Not Funny" << endl;
	}
	return 0;
}