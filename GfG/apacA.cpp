#include <iostream>
#include <string>
using namespace std ;

bool num[10][7] = {
	{1,1,1,1,1,1,0},//0
	{0,1,1,0,0,0,0},//1
	{1,1,0,1,1,0,1},//2
	{1,1,1,1,0,0,1},//3
	{0,1,1,0,0,1,1},//4
	{1,0,1,1,0,1,1},//5
	{1,0,1,1,1,1,1},//6
	{1,1,1,0,0,0,0},//7
	{1,1,1,1,1,1,1},//8
	{1,1,1,1,0,1,1}//9
	};

bool checkmatch(int i,string a,bool b[])
{
	cout << "matching " << endl ;
	for(int k = 0 ;k < 7 ;k++)
	{
		cout << a[k] << " " << ((int)b[k]*(int)num[i][k]) << endl ;
		if((int)a[k] == ((int)b[k]*(int)num[i][k]))
			continue;
		else
		{
			cout << "ret " ;
			return false;
		}
	}
	return true;
}

int main()
{
	bool display[7];
	int test_cases;
	cin >> test_cases ;
	int n;
	for(int i = 0; i< test_cases ;i++)
	{
		cin >> n ;
		string inp[n];
		for(int j =0 ; j < 7 ;j++)
			display[j] = false ;
		for ( int k = 0  ; k < n ;k++)
		{
			cin >> inp[k] ;
			for(int j = 0 ; j < 7 ;j++)
			{
				if(display[j] == false && (int)inp[k][j] == 49)
					display[j] = true ;
			}
		}
		for ( int k = n-1  ; k > -1 ;k--)
		{
			for(int j = 0 ; j < 10 ; j++ )
			{
				if(checkmatch(j,inp[k],display))
					cout << "match found" << endl ;
			}
		}
		
	}
	return 0 ;
}