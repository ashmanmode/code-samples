#include <stdio.h>

int ackermann(int x, int y);

int main()
{
	int a , b;
	printf("Enter a and b\n");
	scanf("%d %d",&a,&b);
	int val = ackermann(a,b);
	printf("%d\n",val);
}

int ackermann(int x,int y)
{
	int i =0,j=0;
	int a[100][100];
	
	for(i=0;i<=y;i++)
		a[0][i] = i+1;
	for(j=1;j<=x;j++)
		a[j][0]= a[j-1][1];
	for(i=0;i<=x;i++){
		for(j=0;j<=y;j++){
			if(i-1 ==0)
				a[i-1][j] = j+1;
			else if(j-1==0)
				a[i][j-1] = a[i-1][1];
			else
				a[i][j] = a[i-1][a[i][j-1]];
		}
	}
	return a[x][y];
}