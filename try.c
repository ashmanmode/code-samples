#include <iostream>

using namespace std;

int height(int c)
{
	if ( c == 0 )
		return 1 ;
	else if ( c % 2 == 0 )
		return height(c-1) + 1 ;
	else
		return height(c-1) * 2 ;
}

int main()
{
	int test_cases;
	cin >> test_cases;
	int cycles[test_cases];
	for ( int i= 0 ; i < test_cases ; i++ )
	{
		cin >> cycles[i];
	}
	for ( int i= 0 ; i < test_cases ; i++ )
	{
		cout << height(cycles[i]) << endl ;
	} 
	return 0 ;
}