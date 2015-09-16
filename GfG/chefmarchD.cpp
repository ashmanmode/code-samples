//Devu and his Class 
#include <bits/stdc++.h>
using namespace std;
 
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;
 
int main()
{
	int t ,type;
	string s ; 
	cin >> t ;
	int b,g; 
	ull ans ;
	fr(i,0,t)
	{
		cin >> type >> s ;
		if(type == 2) type = 1 ;
		b = 0 ; g = 0 ;
		fr(j,0,s.length())
		{
			if(s[j] == 'B')
				b++;
			else
				g++;
		}
 
		ans = 0 ; 
		vector<int> wb,wg;
		if(b - g == 1) 
		{
			for(int j = 0 ; j < s.length() ; j = j + 2 )
				if(s[j] != 'B')
					wb.pb(j);
 
			for(int j = 1 ; j < s.length() ; j = j + 2 )
				if(s[j] != 'G')
					wg.pb(j);
 
			for(int j = 0 ; j < wb.size() ; j++ )
				ans += pow(abs(wb[j] - wg[j]),type);
			cout << ans << endl ;
		}
		else if(g-b == 1)
		{
			for(int j = 0 ; j < s.length() ; j = j + 2 )
				if(s[j] != 'G')
					wg.pb(j);
 
			for(int j = 1 ; j < s.length() ; j = j + 2 )
				if(s[j] != 'B')
					wb.pb(j);
 
			for(int j = 0 ; j < wb.size() ; j++ )
				ans += pow(abs(wb[j] - wg[j]),type);
			cout << ans << endl ;
		}
		else if(b == g)
		{
			for(int j = 0 ; j < s.length() ; j = j + 2 )
				if(s[j] != 'B')
					wg.pb(j);
 
			for(int j = 1 ; j < s.length() ; j = j + 2 )
				if(s[j] != 'G')
					wb.pb(j);
 
			for(int j = 0 ; j < wb.size() ; j++ )
				ans += pow(abs(wb[j] - wg[j]),type);
			wb.clear() ; wg.clear();
 
			ull min = ans ; ans = 0 ;
			for(int j = 0 ; j < s.length() ; j = j + 2 )
				if(s[j] != 'G')
					wg.pb(j);
 
			for(int j = 1 ; j < s.length() ; j = j + 2 )
				if(s[j] != 'B')
					wb.pb(j);
 
			for(int j = 0 ; j < wb.size() ; j++ )
				ans += pow(abs(wb[j] - wg[j]),type);
 
			if(ans < min)
				min = ans ;
			cout << min << endl ;
		}
		else
			cout << -1 << endl ;
		wb.clear() ; wg.clear();
	}
}