#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define mod 1000000007
#define F first
#define S second
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%llu",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%llu",a)
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;


int main()
{
	int n ;
	cin >> n ; 
	vector<int> arr(n);
	fr(i,0,n) cin >> arr[i];

	//preprocessing
	vector<int> m1(n);
	vector<int> m2(n);
	int max =  arr[0]; m1[0] = max ;
	fr(i,1,n)
	{
		if(arr[i] > max)
			max = arr[i];
		m1[i] = max ;
	}
	max =  arr[n-1]; m2[n-1] = max ;
	for(int i = n-2 ; i > -1 ; i-- )
	{
		if(arr[i] > max)
			max = arr[i];
		m2[i] = max ;
	}
	fr(i,0,n)
		arr[i] = min(m1[i],m2[i]);

	printvect(arr,n); cout << endl;

	// int x,y,x1,y1; 
	// cin >> x >> y ;
	// fr(i,1,100000)
	// {
	// 	x1 = (x+7)%(n-1);
	// 	y1 = (y+11)%(n);
	// 	cout << x << " " << y << endl ;
	// 	x = x1;
	// 	y = y1;
	// }
	return 0 ;
}