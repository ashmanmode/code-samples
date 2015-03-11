#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	int n,m;
	cin >> n >> m ;
	int arr[n];
	fr(i,n) arr[i] =  i+1 ;
	int fmx,min,sum;
	vector< vector<int> > farr;
	vector<int> tmp;
	fmx = 0 ; 
	do
	{
		sum = 0 ;  
		for(int i = 0 ; i < n ; i++ )
		{
			min = arr[i];
			for(int j = i ; j < n ; j++ )
			{
				if(arr[j] < min)
					min = arr[j];
				sum += min ;
			}
		} 
		if(sum > fmx)
		{
			farr.clear();
			fr(i,n) tmp.pb(arr[i]);
			farr.pb(tmp);
			tmp.clear();
			fmx = sum ;
		}
		else if(sum == fmx)
		{
			fr(i,n) tmp.pb(arr[i]);
			farr.pb(tmp);
			tmp.clear();
		}
	}while(next_permutation(arr,arr+n));
	

	fr(i,n) cout << farr[m-1][i] << " " ;
	cout << endl ;
	return 0;
}