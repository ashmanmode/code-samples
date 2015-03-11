#include <bits/stdc++.h>
using namespace std;
#define size 20
#define sizepow 2048

int n;
int AdjMat[size][size];
int TspMat[size][sizepow];

int solve(int from,int set) //from 'from' to 0 via set
{
	int msk,mskapplied,temp;
	if(TspMat[from][set] != -1)
		return TspMat[from][set];
	TspMat[from][set] = INT_MAX;
	for(int i =0;i<n;i++) //try removing one by one element from set
	{
		msk = ((int)pow(2,n) - 2 ) - (1 << i) ;
		mskapplied = set&msk;
		if(mskapplied != set)
		{
			tmp = AdjMat[from][i] + solve(i,mskapplied);
			if(temp < TspMat[from][set])
				TspMat[from][set] = temp ;
		}
	}
	return TspMat[from][set]; 
}

int main()
{
	//Adj. Mat Graph
	cin >> n ; 
	for(int i = 0 ; i < n ; i++ )   //source at 1 and sink at 0 place
		for(int j = 0  ; j < n ; j++ )
			cin >> AdjMat[i][j];

	//Tsp 
	for(int i = 0 ; i < n ; i++ )    //setting values for nullset 
		TspMat[i][0] = AdjMat[i][0];
	for(int i = 0 ; i < n ; i++ )
		for(int j = 1  ; j < (int)pow(2,n) ; j++ )
			TspMat[i][j] = - 1 ;
	cout << solve(1,(int)pow(2,n)-3) << endl ;
}