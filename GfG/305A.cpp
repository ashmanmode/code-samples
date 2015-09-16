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
typedef signed long long int sll;

int main()
{
	int k; 
	string a ;
	cin >> a >> k ;
	int len = a.length()/k ; 
	bool poss = true;

	if(len*k == a.length())
	{
		fr(i,0,k)
		{
			fr(j,0,len/2)
			{
				if(a[j+len*i] != a[len*i+len-1-j])
				{
					poss = false;
					break;
				}
			}
			if(!poss)
				break;
		}
	}
	if(!poss || len*k != a.length())
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}