#include <bits/stdc++.h>
using namespace std;

int main()
{
	int q,query; 
	cin >> q;
	string k ;
	pair <string,string> tmp;
	map <string,string>  handle;
	map <string,string>::iterator it;
	for(int  i = 0 ; i < q ; i++)
	{
		cin >> tmp.second  >> tmp.first ;
		if(handle.size() == 0 )
			handle.insert(tmp);
		else
		{
			it = handle.find(tmp.second);
			if( it != handle.end() )
			{
				k = it->second ;
				handle.erase(it);
				handle[tmp.first] = k ;
			}
			else
				handle.insert(tmp);
		}
	}
	cout << handle.size() << endl;
	for(it = handle.begin() ; it != handle.end() ; it++ )
		cout << it->second << " " << it->first << endl ;
	return 0 ;
}