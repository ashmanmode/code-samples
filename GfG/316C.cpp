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

	vector<char> s(n+1);
	fr(i,0,n)
		cin >> s[i] ;
	s[n] = 'a';

	set < pair<int,int> > some;
	char prev = s[0];
	int cur = 0 ;
	int total = 0 ; 
	for(int i = 1 ; i < n+1 ; i++ )
	{
		if(s[i] != prev)
		{
			if(s[i] == '.')
			{
				cur = i ;
			}
			if(prev == '.')
			{
				some.insert(make_pair(cur,i-1));
				total += ( i-1-cur );
			}
			prev = s[i];
		}
	}

	pair<int,int> temp ;
	for(std::set< pair<int,int> > ::iterator it=some.begin(); it!=some.end(); ++it)
	{
		temp = *it ;
    	std::cout << ' ' << temp.F << " " << temp.S << endl ;
	}

	cout << total << endl ;
	int add;
	char c;
	std::set< pair<int,int> >::iterator itlow,itup;
	pair<int,int> templ ;
	pair<int,int> temph ;
	fr(i,0,m)
	{
		cin >> add >> c ;
		add--;
		if(c=='.')
		{
			//both side dots
			if( (add < n-1 && s[add+1] == '.') && (add > 0 && s[add-1] == '.') )
			{
				itup = some.lower_bound(mp(add,-1));    
				temph = *itup;
				std::cout << ' ' << temph.F << " " << temph.S << endl ;            
  				itlow = --itup;
  				templ = *itlow;
				std::cout << ' ' << templ.F << " " << templ.S << endl ; 
				some.insert(mp(templ.F,temph.S));
				total += 2 ;
				some.erase(itup);    
				some.erase(itlow);    
			}
		} 
	}
	return 0;
}