#include <stdio.h>
#if 0
int main()
{
	printf("Hellow\n""Word\n");
	printf("���");
	return 0;
} 
#endif

int main()
{
	printf("sizeof(char)=%d\n", sizeof(char));
	printf("sizeof(short)=%d\n", sizeof(short));
	printf("sizeof(int)=%d\n", sizeof(int));
	printf("sizeof(long)=%d\n", sizeof(long));
	printf("sizeof(long long)=%d\n", sizeof(long long));
	printf("sizeof(float)=%d\n", sizeof(float));
	printf("sizeof(double)=%d\n", sizeof(double));
	return 0;
}