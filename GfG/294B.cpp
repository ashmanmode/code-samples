#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	int n,tmp;
	cin >> n ; 

	vector<int> arr0(n);
	vector<int> arr1(n-1);
	vector<int> arr2(n-2);

	fr(i,n) cin >> arr0[i] ;
	fr(i,n-1) cin >> arr1[i] ;
	fr(i,n-2) cin >> arr2[i] ;

	sort(arr0.begin(),arr0.end());
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());

	int i;
	for(i = 0 ; i < n-1 ; i++ )
	{
		if(arr0[i] != arr1[i])
		{
			cout << arr0[i] << endl;
			break;
		}
	}
	if(i == n-1 )
		cout << arr0[n-1] << endl;

	for(i = 0 ; i < n-2 ; i++ )
	{
		if(arr1[i] != arr2[i])
		{
			cout << arr1[i] << endl;
			break;
		}
	}
	if(i == n-2 )
		cout << arr1[n-2] << endl;
	return 0 ;
}