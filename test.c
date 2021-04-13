#include <stdio.h>
enum
{
	RAD,
	YELLOW,
	GREAN,
};
#if 0
int main()
{
	//printf("%d\n%d\n%d\n",RAD,YELLOW,GREAN);
	char arr1[] = "ÄãºÃ\n";
	char arr2[] = { 'a','b','c',0};
	printf("%s", arr1);
	printf("%s", arr2);
	return 0;
}
#endif

int main()
{
	//printf("%d\n%d\n%d\n",RAD,YELLOW,GREAN);
	char arr1[] = "ÄãºÃ\n";
	char arr2[] = { 'a','b','c',0 };
	printf("%s", arr1);
	printf("%s", arr2);
	printf("arr2[2]=%d", arr2[2]);
	return 0;
}