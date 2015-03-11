#include <iostream>
using namespace std;

int main()
{
	int n ;
	int count  = 0 ;
	cin >> n ;
	int  array[n];
	for ( int i =0 ; i < n ;i++)
		cin >> array[i];
	for(int i = 0 ; i < n ; i ++ )
	{
		for ( int  j = i + 1 ; j < n ; j++)
		{
			if ( array[j] < array[i] )
				count++ ;
		}
	}
	cout << "inversions " << count << endl ;
	return 0 ;
}