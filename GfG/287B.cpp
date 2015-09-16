#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	double r,x,y,x1,y1;
	cin >> r >> x >> y >> x1 >> y1 ;
	double dist = sqrt(pow(x-x1,2) + pow(y-y1,2));
	double ans = dist/(2*r);
		cout << ceil(ans) << endl;
}