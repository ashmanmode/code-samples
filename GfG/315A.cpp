#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define vectin(a,n)
typedef unsigned long long int ull;

int main()
{
	int a;
	double b,c;
	cin >> a >> b >> c ;

	double downloaded = b ;
	double cons = (c-1)/c ; 

	int count = 1 ; 
	double  current = 0 ;
	bool flag = false;
	while(current <= a)
	{
		cout << fixed <<  current << " " << downloaded << endl ;
		if(!flag)
		{
			current = floor(downloaded);
			downloaded += downloaded*cons ;
			flag = true;
		}
		else
		{
			if( current+1 <= downloaded ) 
			{
				current++;
				downloaded += cons ;
			}
			else
			{
				cout << "sdvs" << endl;
				flag = false;
				count++;
			}
		}
	}

	cout << count << endl ;
}