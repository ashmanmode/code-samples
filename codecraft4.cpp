#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	int t,l_count,total;
	cin >> t ;
	string a;
	fr(i,t)
	{
		cin >> a ; 
		vector<int> vect;
		l_count = 0 ; total = 0 ;
		for(int j = a.size() - 1 ; j > -1 ; j-- )
		{
			if(a[j] == 'L')
				l_count++;
			else
				vect.pb(l_count);
		}
		fr(j,vect.size())
			total += vect[j]*(vect.size()-j);
		if(a[0] == 'L')
			cout << total << endl;
		else
		{
			fr(j,vect.size())
				total -= vect[j];
			cout << total << endl ;
		}
	}
}
