#include <iostream>
#include <string>

using namespace std;

int main()
{
	int test_cases;
	cin >> test_cases;
	string names[test_cases];
	for ( int i = 0 ; i < test_cases ;i ++) 
		cin >> names[i] ;
	for ( int i = 0 ; i < test_cases ;i ++) 
		cout << names[i] << endl ;
	return 0 ;
}