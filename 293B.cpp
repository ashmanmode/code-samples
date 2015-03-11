#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;


int main()
{
	string s,t ;
	cin >> s >> t ;
	int len = s.length();
	bool not_possible = true;
	fr(i,len-1)
	{
		if(s[i] != t[i])
			not_possible = false;
	}
	s[len-1] += 1 ;
	if(t[len-1] != s[len-1])
		not_possible = false;

	if(not_possible)
		cout << "No such string" << endl ;
	else
		cout << s << endl; 
	return 0;
}