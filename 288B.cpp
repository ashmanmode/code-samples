#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	string n;
	cin >> n;
	int siz = n.size();
	int num = (int)(n[siz-1]-'0');
	int temp,i,j;char t;
	for(i = 0 ; i < siz -1 ;i++ )
	{
		temp = (int)(n[i]-'0');
		if(temp%2 == 0 && temp < num)
		{
			t = n[i];
			n[i] = n[siz-1];
			n[siz-1] = t ;
			break;
		}
	}
	if(i == siz-1)
	{
		for( j = siz-2 ; j > -1 ; j-- )
		{
			temp = (int)(n[j]-'0');
			if(temp%2 == 0 )
			{
				t = n[j];
				n[j] = n[siz-1];
				n[siz-1] = t ;
				break;
			}
		}
		if(j == -1)
			cout << -1 << endl;
		else
			cout << n << endl ;
	}
	else
		cout << n << endl;
}