#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;

ull find(ull n,ull m,ull x,ull y)
{
	if(x > 1 && y > 1 && x < n &&  y < m)
		return 2*(n+m) - 4 + find(n-2,m-2,x-1,y-1);
	else 
	{	
		if((x == 1) || y == m)
			return x-1 + y - 1 ;
		else
			return n-x + m-y + m-1 + n-1 ;
	}
}

int main()
{
	ull n,m,x,y;
	cin >> n >> m >> x >> y ;
	cout << find(n,m,x,y) << endl;
	return 0;
}