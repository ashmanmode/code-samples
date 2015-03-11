#include <bits/stdc++.h>
using namespace std;

#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;


int main()
{
	int arr[26];
	fr(i,0,26) cin >> arr[i] ;

	string s ;
	cin >> s ;
	ull st[s.length()];
	vector< vector<int> > pos(26);

	fr(i,0,s.length())  
	{
		st[i] = arr[(int)(s[i] - 'a')];
		st[i] += st[i-1];
		pos[(int)(s[i] - 'a')].pb(i);
	}
	
	//search fr substring in the st
	ull count = 0 ; 
	fr(i,0,26)
	{
		map<ull,int> mp;
		fr(j,0,pos[i].size())
		{
			int p = pos[i][j];
			count += mp[ st[p-1] ];
			mp[ st[p] ]++;
		}
		mp.clear();
	}
	cout << count << endl; 
	return 0;
}