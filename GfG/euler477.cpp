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
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	ull n ; 
	cin >> n ;
	srand(time(NULL));

	//randomised solution
	vector<ull> sols;
	for(int k = 0 ; k < 100000 ; k++ )
	{
		vector<ull> lst(n);

		//populating list
		lst[0] = 0 ;
		fr(i,1,n)
			lst[i] = ( (lst[i-1]*lst[i-1])%mod + 45) % mod;

		ull sum = 0 ;
		fr(i,0,n-2)
		{
			//double val1 = (double)lst[0]/(double)max(lst[1],lst[lst.size()-1]);
			//double val2 = (double)lst[lst.size()-1]/(double)max(lst[0],lst[lst.size()-2]);
			//cout << val1 << " " << val2 << endl ;
		
			int a = rand()%mod ;    

			if(a%2 == 1)
			{
				if(i%2 == 0 )  sum += lst[0]; 
				lst.erase(lst.begin());
			}
			else
			{
				if(i%2 == 0 ) sum += lst[lst.size()-1]; 
				lst.pop_back();
			}
		}

		//last two
		if(lst[0] > lst[1])
		    sum += lst[0];
		else
			sum += lst[1];
		//cout << sum << endl;
		sols.pb(sum);
	}

	cout << "**************************************************" << endl ;
	sort(sols.begin(),sols.end());
	for(int k = sols.size()-1 ; k > -1 ; k-- )
		cout << sols[k] << endl ;
	return 0 ;
}