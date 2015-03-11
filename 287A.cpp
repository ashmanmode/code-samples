#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	int n ,k,temp;
	cin >> n >> k ;
	vector< pair<int,int> > a;
	fr(i,n) {
		cin >> temp;
		a.push_back(mp(temp,i+1));
	}
	sort(a.begin(),a.end());
	//fr(i,n) cout << a[i].second << a[i].first << endl;
	int sum = 0 ;
	int i ;
	for(i = 0 ; i < n ; i++ )
	{
		sum += a[i].first;
		if(sum > k)
			break;
	}
	cout << i << endl;
	for(int j = 0 ; j < i ; j++ )
		cout << a[j].second << " " ;

}