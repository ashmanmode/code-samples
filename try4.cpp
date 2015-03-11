#include <bits/stdc++.h>
#include <array>
#define siz 20
#define sizpow 1048576
#define ERR -20
using namespace std;

int AdjMat [siz][siz];
int TspMat[siz][sizpow];
int siz_tsp;

int convert(array<bool,siz_tsp> set)
{
	int num = 0  ;
	for(int i = 0 ; i < siz_tsp ; i++ )
		num += set[i]*pow(2,i);
	return num;
}

int solve(int from,array<bool,siz_tsp> set) 
{
	int temp;
	if(TspMat[from][convert(set)] != -1)
		return TspMat[from][convert(set)];
	TspMat[from][convert(set)] = INT_MAX;
	array<bool,siz_tsp> msk,mskapplied;
	bool same;
	for(int j = 1 ; j < siz_tsp ; j++ )
		msk[j] = true;
	msk[0] = false;
	for(int i =0; i<siz_tsp; i++) 
	{
		if(i>0) msk[i-1] = true;
		msk[i] = false;
		for(int j = 0 ; j < siz_tsp ; j++ )
			mskapplied[j] = msk[j]&set[j];
		same = true ;
		for(int j = 0 ; j < siz_tsp ; j++ )
			if( mskapplied[j] != set[j])
			{
				same = false;
				break;
			}
		if(!same)
		{
			temp = AdjMat[from][i] + solve(i,mskapplied);
			if(temp < TspMat[from][convert(set)])
				TspMat[from][convert(set)] = temp ;
		}
	}
	return TspMat[from][convert(set)]; 
}

int main()
{
	clock_t start = clock();
	freopen("graph_output.txt","r",stdin);
	cin >> siz_tsp ;
	for(int  i = 0 ; i < siz_tsp ; i++ )
		for(int j = 0 ; j < siz_tsp ; j++ )
			cin >> AdjMat[i][j];

	for(int i = 0 ; i < siz_tsp ; i++ )    //setting values for nullset 
		TspMat[i][0] = AdjMat[i][0];
	for(int i = 0 ; i < siz_tsp ; i++ )
		for(int j = 1  ; j < (int)pow(2,siz_tsp) ; j++ )
			TspMat[i][j] = - 1 ;

	array<bool,siz_tsp> set ;
	for(int i = 0 ; i < siz_tsp ; i++ )
		set[i] = true;
	set[1] = false;

	cout << solve(1,set) << endl ;
	cout << "time " << (float)(clock() - start)*1000/CLOCKS_PER_SEC << " ms" << endl;
	return 0 ;
}