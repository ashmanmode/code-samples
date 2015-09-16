#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#define C 1000000007l
using namespace std;
 
int main(){
	int n,e;
	scanf("%d",&n);
	int brackets[n+1];
	int dp[n+1][n+1];
	for(int i=0;i<n;i++)
		scanf("%d",&brackets[i+1]);
	for(int i = 0; i < n+1; ++i)
		for (int j = 0; j < n+1; ++j)
			dp[i][j]=0l;
 
	for(int w=1;w<n;w++){
		for(int s=1;(e=s+w)<n+1;s++){
			dp[s][e]=dp[s][e-1];
			if(brackets[e]>0)
				for(int j=s;j<e;j++)
					if(brackets[j]==(-brackets[e])){
						dp[s][e]+=dp[j+1][e-1]+1l+(dp[j+1][e-1]+1l)*dp[s][j-1];
						dp[s][e]%=C;
					}
		}
	}
	cout<<(dp[1][n]+1l)%C<<endl;
} 