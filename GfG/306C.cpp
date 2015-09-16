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
	vector< vector<int> > hash ;
	vector<int> temp ;
	fr(i,0,10)
		hash.pb(temp);
	fr(i,0,s.length())
		hash[(int)(s[i] - '0')].pb(i);
	if(hash[0].size())
	{
		cout << "YES" << endl ;
		cout << 0 << endl ;
		return 0 ;
	}
	
	fr(i,1,125)
	{
		//cout << 8*i << " " ;
		vector<int> num;
		int k = 8*i ;
		while(k > 0)
		{
			num.pb(k%10);
			k /= 10 ;
		}
		int cur = -1 ; 
		int count = 0 ;
		fr(j,0,num.size())
		{	
			if(hash[ num[num.size()-1-j] ].size())
			{
				fr(m,0,hash[ num[num.size()-1-j] ].size())
				{
					if(hash[ num[num.size()-1-j] ][m] > cur)
					{
						count++ ;
						cur = hash[ num[num.size()-1-j] ][m] ;
						break;
					}
				}
			}
			else
				break;
		}
		if(count == num.size())
		{
			cout << "YES" << endl ;
			cout << i*8 << endl ;
			return 0 ;
		}
		num.clear();
	}
	cout << "NO" << endl ;
}