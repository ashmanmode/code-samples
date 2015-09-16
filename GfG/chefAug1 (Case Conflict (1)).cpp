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
  int test ;
  cin >> test ;
  while(test--)
  {
    string x ,y ;
    cin >> x >> y ;
    bool pos = true;
    fr(i,0,x.length())
    {
      if(x[i] != '?' && y[i] != '?' && x[i] != y[i])
        pos = false;
    }
    if(pos)
      cout << "YES" << endl ;
    else
      cout << "NO" << endl ;
  }
	return 0 ;
}
