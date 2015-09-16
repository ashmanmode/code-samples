#include <iostream>
#include <string>
using namespace std;

int main()
{
	int test_cases;
	char tmp;
	bool found ;
	cin >> test_cases ;
	string names[test_cases];
	for(int i = 0 ; i < test_cases ;i++ )
		cin >> names[i];
	for(int i = 0 ; i < test_cases ;i++ )
	{
		found = false ;
		int j = names[i].size() -1 ; 
		while(j > 0 && found == false)
		{
			int k = j-1 ; 
			while(k >= 0 && found == false)
			{
				if(names[i][j] > names[i][k])
				{
					tmp = names[i][j] ;
					names[i][j] = names[i][k] ;
					names[i][k] = tmp ;
					found = true ;
				}
				k-- ;
			}
			j-- ;
		}
		if(found == false)
			cout << "no answer" << endl;
		else
			cout << names[i] << endl;
	}
	return 0 ;
}