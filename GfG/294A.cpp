#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int weight(char a)
{
	if (a == 'q' || a == 'Q')
		return 9 ;
	if (a == 'r' || a == 'R')
		return 5 ;
	if (a == 'b' || a == 'B')
		return 3 ;
	if (a == 'n' || a == 'N')
		return 3 ;
	if (a == 'p' || a == 'P')
		return 1 ;
	return 0;
}

int main()
{
	string s[8];
	fr(i,8)
		cin >> s[i] ;

	int cntA = 0 ;
	int cntB = 0 ;
	fr(i,8)
	{
		fr(j,8)
		{
			if(s[i][j] != '.' )
			{
				if(s[i][j] < '[')  //capital
					cntA += weight(s[i][j]);
				else 
					cntB += weight(s[i][j]);
			}
		}
	}
	if(cntA > cntB)
		cout << "White" << endl;
	else if(cntA == cntB)
		cout << "Draw" << endl;
	else
		cout << "Black" << endl;
	return 0;
}