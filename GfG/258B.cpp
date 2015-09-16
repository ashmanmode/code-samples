#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define mod 1000000007
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;
typedef signed long long int sll;

int main()
{
	int n,a;
	cin >> n ;
	vector< pair<int,int> >  arr;
	fr(i,0,n)
	{
		cin >> a ; 
		arr.pb(mp(a,i+1));
	} 
	sort(arr.begin(),arr.end());
	
	int s,r; s =1 ; r =1 ;
	bool set = false;
	fr(i,0,n)
	{
		if(arr[i].S +i+1 != 2*i + 2 && !set)
		{
			set = true;
			s = i+1 ;
			r = arr[i].S ; 	
		}
		else if(set && i < r )
		{
			if(arr[i].S + i + 1 != s+r)
			{
				cout << "no" << endl ;
				return 0;
			}
		}
		else
		{
			if(arr[i].S + i + 1 != 2*i+2)
			{
				cout << "no" << endl ;
				return 0;
			}
		}
	}	
	cout << "yes" << endl <<  s << " "<< r << endl;
	return 0;
}