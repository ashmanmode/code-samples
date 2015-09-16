#include <bits/stdc++.h>
using namespace std;
#define fr(i,n) for(int i = 0 ; i < n ; i++ )
typedef unsigned long long int ull;

int main()
{
	int n,m,k,q,tmp;
	cin >> n >> m >> k ;
	int arr[n];
	fr(i,n) cin >> arr[i] ;
	int pos[n];
	fr(i,n) pos[arr[i]-1] = i; 

	ull moves = 0 ; 
	fr(i,m) 
	{
		cin >> q ;

		if(pos[q-1] == 0)
			moves += 1 ;
		else
		{
			moves += pos[q-1]/k + 1 ;
			tmp = arr[pos[q-1] - 1];
			arr[pos[q-1] - 1] = arr[pos[q-1]];
			arr[pos[q-1]] = tmp;
			pos[q-1]--;
			pos[tmp-1]++;
		}
	}
	cout << moves << endl;
	return 0;
}
