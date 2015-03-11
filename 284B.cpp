#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int b_search(pair <string,string> dict[],int first,int last,string s)
{
	int index;
	if(first > last)
		index = -1 ;
	else
	{
		int mid = (first+last)/2;
		if(dict[mid].first == s)
			index = mid;
		else if(s < dict[mid].first)
			index = b_search(dict,first,mid,s);
		else
			index = b_search(dict,mid+1,last,s);			
	}
	return index;
}

int main()
{
	int n,m;
	cin >> n >> m ;
	pair <string,string> dict[m];
	bool choice[m];
	for(int i = 0  ; i < m ; i++ )
	{
		choice[i] = false ;
		cin >> dict[i].first >> dict[i].second ;
	}
	sort(&dict[0],&dict[m]);
	//cout << endl ;
	for(int i = 0  ; i < m ; i++ )
	{
		//cout << dict[i].first << " " << dict[i].second << endl ;
		if(dict[i].second.length() <  dict[i].first.length())
			choice[i] = true;
	}

	string word ;
	for(int i = 0 ; i < n ; i++ )
	{
		cin >> word ;
		if(choice[b_search(dict,0,m,word)] == false )
			cout << word << " ";
		else
			cout << dict[b_search(dict,0,m,word)].second << " " ;
	}
	cout << endl ;
	return 0 ;
}