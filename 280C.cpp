#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long int ull;

int main()
{
	ull n,r,avg,sum = 0;
	cin >> n >> r >> avg ;
	pair<int,int> grades[n];
	for(int i = 0 ; i < n ; i++ )
	{
		cin >> grades[i].second >> grades[i].first ;
		sum += grades[i].second;
	}
	sort(&grades[0],&grades[n]);
	ull no_eassays = 0 ;
	ull required =  avg*n - sum ; 
	if(required > 0)
	{
		for(int i = 0 ; i < n ; i++ )
		{
			if(grades[i].second != r)
			{
				if(required > (r-grades[i].second))
				{
					no_eassays += (r-grades[i].second)*grades[i].first ;
					required -= (r-grades[i].second);
				}
				else
				{
					no_eassays += required*grades[i].first ;
					break ;
				}
			}
		}
		cout << no_eassays << endl ;
	}
	else
		cout << 0 << endl ;
	return 0;
}