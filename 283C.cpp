#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n,m,j;
	cin >> n >> m ;	
	string a[n];
	for(int i = 0 ; i < n; i++ )
		cin >> a[i];
	int count = 0; 
	bool col[m];
	for( int i = 0 ; i < m ; i++ )
		col[i] = false;
	for(int i = 1 ; i < n ; i++ )
	{
		j = 0 ;
		while(j < m)
		{
			if(a[i-1][j] > a[i][j])
			{
				col[j] = true;cout << "row "<< i << " col " << j << endl;
				j++;
			}
			else if(a[i][j] == a[i-1][j])
				j++;
			else
				break;
		}
	}
	for(int i = 0 ; i < m ; i++ )
		if(col[i]==true)
			count++;
	cout << count << endl; 
}