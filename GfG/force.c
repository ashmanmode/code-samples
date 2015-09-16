#include <stdio.h>

int main()
{
	int n, m , i ;
	int ans = 0 ;
	scanf("%d%d",&n,&m);

	for ( i = 1 ; i <= n ; i ++ )
	{
		++ans;
		if(i%m==0)
			n += 1 ;
	}
	printf("%d\n",ans );
	return 0; 
}