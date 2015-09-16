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
    ull n;
    cin >> n ;

    if(n==1)
    {
      cout << 2 << endl;
      continue;
    }

    int a = 0 ;
    bool pos = false;
    fr(i,2,32)
    {
      if( n == pow(2,i) - 1 )
      {
        pos = true;
        break;
      }
    }

    if(pos)
      cout << n/2 << endl;
    else
      cout << -1 << endl ;
  }
	return 0 ;
}
