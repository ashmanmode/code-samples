#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int binery_search(string word,vector<string> dict)
{
	int word_value = 0 ;
	int i = 0 ;
	int j = 0 ;
	while((int)word[j] != 0)
	{
		if(word[j] == dict[i][j])
		{
			word_value += ((int)word[j] - 64 ) ;  
			j++ ; 
		}
		else
			i++ ;
	}
	return (i + 1)*word_value;
}

int main()
{
	int n ,q;
	cin >> n ; 
	vector<string> dict(n);
	for(int i =0 ; i < n ; i++ )
		cin >> dict[i];
	sort(dict.begin(),dict.end());
	for(int i =0 ; i < n ; i++ )
		cout << dict[i] << endl ;
	cin >> q ;
	string word ; 
	for(int i = 0 ; i < q ; i ++ )
	{
		cin >> word ;
		cout << binery_search(word,dict) << endl ;
	}
	return 0 ;
}