//codechef DEcember long challange
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int test_cases;
	cin >> test_cases ;
	int n ;
	int count,tmp;
	for(int i = 0 ; i < test_cases ; i++ )
	{
		cin >> n ; 
		int trees[n] ;
		for(int j = 0 ; j < n ; j++ )
			cin >> trees[j];
		sort(&trees[0],&trees[n]);
		count = 0 ; tmp = 0 ;
		for(int k = 0 ; k < n ; k++ )
		{
			if(tmp != trees[k])
			{
				tmp = trees[k] ; 
				count++ ; 
			}
		}
		cout << count << endl ;
	}
}