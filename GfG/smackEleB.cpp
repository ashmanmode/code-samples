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

int main()
{
	int t;
	cin >> t ;
	while(t--)
	{
		string s;
		cin >> s ;
		int mypt = 0 ;
		int othrpt = 0 ;
		bool case10 = false ;
		fr(i,0,s.length())
		{
			//cout << i << " " << mypt << " " << othrpt << endl ;
			if(s[i] == '1')
				mypt++;
			else
				othrpt++;

			if(case10)
			{
				if(mypt - othrpt == 2 )
				{
					cout << "WIN" << endl;
					break;
				}
				else if(othrpt - mypt == 2)
				{
					cout << "LOSE" << endl ;
					break;
				}
			}
			if(i==19 && mypt==othrpt && !case10)
				case10 = true ;
			if(mypt == 11 && othrpt < 11 && !case10)
			{
				cout << "WIN" << endl;
				break;
			}
			else if(othrpt == 11 && mypt < 11 && !case10)
			{
				cout << "LOSE" << endl ;
				break;
			}
		}
	}
	return 0 ;
}