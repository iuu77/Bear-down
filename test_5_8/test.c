#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#if 0
//今天不想学习，刷刷题
int main()
{
	//数组指针
	//

	int* p = NULL;         //整形指针  -  存放整形的地址
	char* pa = NULL;       //字符指针  -  存放字符的指针
	int arr[10] = { 0 };
	int(*parr)[10] = &arr; //数组指针  -  存放数组的指针
	//arr     - 首元素的地址 
	//&arr[0] - 首元素的地址
	//&arr    - 数组的地址
	//
	int (* (*parr3[10]) )[5];

	return 0;
}
#endif



//这是数组指针和指针数组的练习

//常规打印数组方法
void print1(int arr[], int length)
{
	int i = 0;
	for ( i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//利用指针打印数组
void print2(int* arr, int length)//传进来的arr其实是首元素的地址
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	print1(arr, 10);
	print2(arr, 10);
	return 0;
}

