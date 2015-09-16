#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n ;
	int arr[n];
	for(int i = 0 ; i < n ; i ++ )
		cin >> arr[i];
	int difficulty = 0 ;
	for(int  i = 1 ; i < n ;i++ )
	{
		if(arr[i]-arr[i-1] > difficulty)
			difficulty = arr[i]-arr[i-1] ;
	}
	int min =  arr[2] - arr[0]; 
	for(int i = 1 ; i < n - 2 ;i++ )
	{
		if(arr[i+2] - arr[i] < min)
			min = arr[i+2] - arr[i];
	}
	if(min < difficulty)
		cout << difficulty << endl;
	else
		cout << min << endl ;
	return 0;
}
