#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	int n,m,k;
	cin >> n >> m >> k ;
	bool arr[n][m];
	fr(i,n)
		fr(j,m)
			arr[i][j] = false;
	int x,y,i;
	for(i = 0 ; i < k ; i++)
	{
		cin >> x >> y ;
		arr[x-1][y-1] = true;

		if(x > 1 && y > 1)
		{
			if (arr[x-2][y-2] == true && arr[x-1][y-2] == true && arr[x-2][y-1] == true )
			{ 	
				cout << i+1 << endl;
				break;
			}
		}
		if(x > 1 && y < m)
		{
			if (arr[x-2][y] == true && arr[x-1][y] == true && arr[x-2][y-1] == true )
			{
				cout << i+1 <<  endl; 
				break;
			}
		}
		if(y > 1 && x < n)
		{
			if (arr[x][y-2] == true && arr[x-1][y-2] == true && arr[x][y-1] == true )
			{
				cout << i+1 << endl;
				break;
			}
		}
		if(x < n && y < m)
		{
			if (arr[x][y] == true && arr[x-1][y] == true && arr[x][y-1] == true )
			{
				cout << i+1 <<  endl;
				break;
			}
		}
	}
	if( i == k )
		cout << 0 << endl;
	return 0;
}