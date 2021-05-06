#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

#if 0
void define(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = i;
	}
}
void invert(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left<right)
	{
		int tmp = 0;
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}

}
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(0);
	define(arr, sz);
	print(arr, sz);
	invert(arr, sz);
	print(arr, sz);
	return 0;
}



void exch(char arr[], int sz) 
{
	static int left = 0;
	static int right = 5;

	char tmp = arr[left];
	arr[left] = arr[right];	
	arr[right] = tmp;
	left++;
	right--;
	if (left < right)
		exch(arr, sz);
}
void print(char arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%c ", arr[i]);
	}
	printf("\n");
}
int main()
{
	char arr[] = { 'a','b','c','d','e','f'};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	print(arr, sz);
	exch(arr, sz);
	print(arr, sz);
	return 0;
}


int strlen_11(char arr[])
{
	int count = 0;
	while (*arr != '\0')
	{
		count++;
		arr++;
	}
	return count;
}
int main() 
{
	char arr[] = { "abcdef" };
	int sz = strlen_11(arr);
	printf("%d\n", sz);
	return 0;
}

//Ìõ¼þ 1    left < right
#endif

//7234
//723  4
//7


int DigitSum(int n)
{
	static int sum = 0;
	int i = n % 10;
	sum += i;
	if(n!=0)
		DigitSum(n / 10);
	return sum;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int sum = DigitSum(n);
	printf("%d\n", sum);
	return 0;
}