#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	string n;
	cin >> n;
	istringstream ss(n);
	char x;
	vector<int> num;
	while(ss >> x)
		num.push_back((int)x-48);
	int a,b,i,previ,rem;
	cin >> a >> b ; 
	previ = 0 ;
	while(1)
	{
		rem = 0 ;
		for(i = previ ; i < num.size(); i++)
		{
			rem = (rem*10 + num[i])%a ; 
			if( rem == 0 )
				break ;
		}
		previ = i+1;
		for( i = previ; i < num.size() ;i++)
		{
			if(num[i] == 0)
				previ++ ;
			else
				break ;
		}
		if(previ > num.size() - 1)
		{
			cout << "NO" << endl;
			return 0;
		}
		for( i = previ ; i < num.size() ;i++)
			rem = (rem*10 + num[i])%b ; 
		if( rem == 0)
		{
			cout << "YES" << endl;
			for(int i = 0 ;i < previ ; i++ )
				cout << num[i] ;
			cout << endl ;
			for(int i = previ ;i < num.size() ; i++ )
				cout << num[i] ;
			cout << endl ;
			return 0 ; 
		}
	}
}