#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m,n;
	cin >> m >> n ; 
	vector< vector <pair<int,int> > > mat ;
	vector< pair<int,int> > row;
	pair<int,int> tmp ;
	for(int i =0 ; i < m ; i++ )
	{
		for(int j = 0  ; j < n ; j++ )
		{
			cin >> tmp.first;
			tmp.second = j + 1 ;
			row.push_back(tmp);
		}
		sort(row.begin(),row.end());
		mat.push_back(row);
		row.clear();
	}
	int tmp[100][100];
	for(int i = 0  ; i < n ; i ++ )
	{

	}
}