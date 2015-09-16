#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,l;
	cin >> n >> l ;
	int lamps[n];
	for(int i = 0 ; i < n ; i++) 
		cin >> lamps[i];
	sort(&lamps[0],&lamps[n]);
	unsigned long long int diff = 2*lamps[0];
	if(lamps[0] < (l-lamps[n-1]))
		diff = 2*(l-lamps[n-1]) ;
	for(int i = 0 ; i < n-1 ; i++)
	{
		if( lamps[i+1] - lamps[i] > diff )
			diff = lamps[i+1] - lamps[i] ;
	}
	if(diff%2 == 0)
		cout << std::fixed << (diff/2) << endl ;
	else
		cout << std::fixed << (diff/2) + 0.5 << endl ;
	return 0;
}