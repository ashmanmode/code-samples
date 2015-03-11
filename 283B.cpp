#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	int n ; cin >> n ; 
	int arr[n];
	string num ;
	cin >> num ;
	char x;
	istringstream ss(num);
	int i = 0 ;
	while(ss >> x)
	{
		arr[i] = (int)x - 48 ;
		i++ ; 
	}
	int max = 0;
	for(int i = 0 ; i < n ; i++ )
		if(arr[i] > max )
			max = arr[i] ;
	while()
	for(int i = 0 ; i < n ; i++ )
		arr[i] -= (10-max);
}