#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define INF_LDOUBLE LDBL_MAX
#define PRECISION 1e-6
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
#define vectin(a) fr(i,0,a.size()) { cin >> a[i] ; }
typedef unsigned long long int ull;
typedef signed long long int sll;

bool comp(int i,int j)
{
	return i > j ;
}

int main()
{
	int n,a,x;
	cin >> n >> a;

	int count = 0 ;
	vector<int> ar;
	fr(i,0,n-1)
	{
		cin >> x;
		ar.pb(x);
	}
	sort(ar.begin(),ar.end(),comp);

	while(a <= ar[0])
	{
		a++;
		count++;
		ar[0]--;
		sort(ar.begin(),ar.end(),comp);
		// printvect(ar,n-1);
		// cout << endl ;
	}
	cout << count << endl ;

}