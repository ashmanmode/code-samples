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
#define vectin(a) fr(i,0,a.size()) { cin >> a[i] ; }
typedef unsigned long long int ull;
typedef signed long long int sll;

int main()
{
	int n,q,f1,f2,a,b,l,r;
	cin >> n >> q >> f1 >> f2 >> a >> b ;
	vector<int> arr(n);
	vector<int> change(n);
	vector<int> fun(n);
	fun[0] = f1 ;
	fun[1] = f2 ;
	vectin(arr);
	memset(&change[0],0,sizeof(change));

	fr(i,2,n)
		fun[i] = a*fun[i-2] + b*fun[i-1];

	fr(i,0,n)
		cout << fun[i] << " " ;
	cout << endl ;

	fr(i,0,q)
	{
		cin >> l >> r ;
		change[l-1] = fun[i-l];
		change[r-1] = -fun[i-l];
	}

	fr(i,1,q)
		change[i] += change[i-1];

	fr(i,0,n)
		arr[i] += change[i] ;

	fr(i,0,n)
		cout << arr[i]  << " ";
	cout << endl ;
}