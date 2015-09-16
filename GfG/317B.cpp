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
	int n,slimit,p,q;
	cin >> n >> slimit ;

	int buy[123456];
	int sell[123456];
	//memset(buy,0,sizeof(buy));
	//memset(sell,0,sizeof(sell));
	fr(i,0,123456)
	{
		buy[i] = 0 ;
		sell[i] = 0 ;
	}

	char c;
	vector<int> b ;
	vector<int> s ;
	fr(i,0,n)
	{
		cin >> c >> p >> q ;
		if(c == 'B')
		{
			if(buy[p] == 0)
				b.pb(p);
			buy[p] += q ;
		}
		else
		{
			if(sell[p] == 0)
				s.pb(p);
			sell[p] += q ;
		}
	}
	sort(b.begin(),b.end());
	sort(s.begin(),s.end());

	int limitsell = slimit-1 ;
	int limitbuy = b.size() - slimit ;
	if(slimit > b.size())
		limitbuy = 0;
	if(slimit > s.size())
			limitsell = s.size() - 1;

	for(int i = limitsell ; i >= 0 ; i-- )
	{
		cout << "S " << s[i] << " " << sell[s[i]] << endl ;
	}
	for(int i = b.size()-1 ; i >= limitbuy ; i-- )
	{
		cout << "B " << b[i] << " " << buy[b[i]] << endl ;
	}
	return 0 ;
}
