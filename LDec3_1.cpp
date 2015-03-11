#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long int ui;

int main()
{
	int test_cases;
	cin >> test_cases ;
	int n,k,m;
	bool done_for_one;
	vector<ui> array;
	ui sum,required; //for taking input this will be used as tmp variable
	for(int i = 0 ; i < test_cases ; i++ )
	{
		cin >> n >> k ; 
		sum = 0 ;
		for(int j = 0 ; j < n ; j++ )
		{
			cin >> required ;
			array.push_back(required);
			sum += required ;
		}
		sort(array.begin(),array.end());
		if( sum == 0 )
		{
			if(n==k)
				cout << " yes " << endl ;
			else
				cout << " no " << endl;
		}
		else if(sum != (sum/k)*k ||  array[n-1] > sum/k)
		{
			cout << sum << endl ;
			cout << " no " << endl ;
		}
		else
			cout << " yes " << endl ;
		array.clear();
	}
	return 0 ;
}