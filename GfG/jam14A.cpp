#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
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
	int t,a,b;
	int matA[4][4];
	int matB[4][4];
	cin >> t ;

	fr(k,0,t)
	{
		cin >> a ;
		fr(i,0,4)
			fr(j,0,4)
				cin >> matA[i][j] ;
		cin >> b ;
		fr(i,0,4)
			fr(j,0,4)
				cin >> matB[i][j] ;

		int count = 0 ;
		int val;
		fr(i,0,4)
		{
			fr(j,0,4)
			{
				if(matA[a-1][i] == matB[b-1][j])
				{
					val = matA[a-1][i] ;
					count++;
					break;
				}
			}
		}
 		if(count==1)
			cout << "Case #" << k+1 << ": " << val << endl;
		else if(count == 0)
			cout << "Case #" << k+1 << ": Volunteer cheated!" << endl;
		else
			cout << "Case #" << k+1 << ": Bad Magician!" << endl;
	}
}