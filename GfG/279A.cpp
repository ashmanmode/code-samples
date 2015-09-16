#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,tmp ; 
	cin >> n ;
	vector<int> type1,type2,type3;
	for(int  i = 0 ; i < n ; i++ )
	{
		cin >> tmp;
		if(tmp == 1)
			type1.push_back(i+1);
		else if(tmp == 2)
			type2.push_back(i+1);
		else
			type3.push_back(i+1); 
	}
	int min = type1.size();
	if(type2.size() < min)
		min = type2.size();
	if(type3.size() < min)
		min = type3.size();
	cout << min << endl ;
	while(type1.size() != 0 && type2.size() != 0 && type3.size() != 0)
	{
		cout << type1[type1.size()-1] << " "<< type2[type2.size()-1] << " "<< type3[type3.size()-1] << endl;
		type1.pop_back();
		type2.pop_back();
		type3.pop_back();
	}
	return 0;
}