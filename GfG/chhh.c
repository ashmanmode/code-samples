#include <stdio.h>
#include <string.h>

int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	char *names[test_cases];
	int i ,j;
	for ( i = 0 ; i < test_cases ;i ++) 
		scanf("%s",names[i]);
	for ( j = 0 ; j < test_cases ;j ++) 
		printf("%s\n",names[i] );
	return 0 ;
}