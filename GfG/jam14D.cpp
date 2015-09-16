#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define mod 1000000007
#define F first
#define S second
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%llu",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%llu",a)
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << fixed << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	int test,n;
	cin >> test;
	fr(t,0,test)
	{
		cin >> n ; 
		vector<double> naomi(n);
		vector<double> ken(n);
		fr(i,0,n) cin >> naomi[i];
		fr(i,0,n) cin >> ken[i];
		sort(naomi.begin(),naomi.end());
		sort(ken.begin(),ken.end());
		//printvect(naomi,n); cout << endl ;
		//printvect(ken,n); cout << endl ;

		//War solution
		int i = 0 ; 
		int j = 0 ; 
		int z = 0 ; 
		while(i < n && j < n)
		{
			if(naomi[i] < ken[j])
			{
				j++; i++ ; z++;
			}
			else
				j++;
		}

		//Deceiving war
		i = 0 ; 
		j = 0 ; 
		int x = 0 ; 
		while(i < n && j < ken.size())
		{
			if(naomi[i] < ken[j])
			{
				ken.pop_back();
				i++ ;
			}
			else
			{
				j++; x++; i++ ;
			}
		}

		cout << "Case #" << t+1 << ": " << x  << " " << n-z << endl ;
	}
	return 0;
}