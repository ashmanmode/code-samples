#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,x,suma,sumb;
	cin >> n; 
	vector<int> a;
	vector<int> b;
	suma = 0 ; sumb = 0 ;
	bool firstwin = true ;
	for(int i = 0 ; i < n ; i++ )
	{
		cin >> x;
		if(x > 0)
		{
			suma += x ;
			a.push_back(x);
		}
		else
		{
			sumb += (-1*x) ;
			b.push_back(-1*x);
		}
		if( i == n-1 )
		{
			if(x < 0)
				firstwin = false;
		}
	}
	if(suma > sumb)
		cout << "first" << endl; 
	else if(sumb > suma)
		cout << "second" << endl;
	else
	{
		int size = a.size() ;
		if(b.size() < a.size())
			size = b.size();
		for ( int i = 0 ; i < size ; i++ )
		{
			if(a[i] == b[i])
				continue;
			else if(a[i] > b[i])
			{
				cout << "first" << endl ;
				return 0 ;
			}
			else
			{
				cout << "second" << endl ;
				return 0 ;
			}
		}
		if(a.size() > b.size())
		{
			cout << "first" << endl ; return  0 ;
		}
		else if ( a.size() < b.size())
		{
			cout << "second" << endl ; return 0 ;
		}
		if(firstwin == true)
			cout << "first" << endl ;
		else
			cout << "second" << endl ;
	} 
	return 0 ; 
}