#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	cin >> test ;
	while(test--)
	{
		int n,m;
		cin >> n >> m ;
		int k = ((2*n-1) - sqrt( (2*n-1)*(2*n-1) - 8*m ))/2 ; 
		if( k*k - (2*n-1)*k + 2*m > 0 )
			cout << k+2 << endl ;
		else
			cout << k+1 << endl ;
	}
	return 0;
}

6
13
17
6
4
8
4
11
6
12
2
6
18
7
2
8
7
14
20
12
6
4


dfvdvd
2
3
3
2
2
4
2
6
2
4
2
2
4
3
2
2
2
6
3
12
2
2
2
2
2
3
3
2
2
4
2
6
3
4
4
2
2
4
2
4
6
2
15
2
2
7
2
2
2
3
4
2
14
2
2
2
3
3
7
2
5
5
7
2
9
3
2
6
2
9