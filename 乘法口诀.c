#include <stdio.h>
int main()
{
	int n = 0;
	int i,j;
	scanf("%d",&n);
	
	i=1;
	while( i<=n ){
		j=1;
		while( j<=i ){
			printf("%d*%d=%d",j,i,i*j);
			if(i*j<10){
			printf("   ");
			}else {
				printf("  ");
			}
			j++;
		}
		i++;
		printf("\n");
	}
	
	return 0;
}
