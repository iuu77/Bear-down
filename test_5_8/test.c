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
	int* p = arr;
	int(*parr)[10] = &arr;
	int i=0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", (*parr)[i]);
	}
	printf("\n");
	for ( i = 0; i < 10; i++)
	{
		printf("%d ", *(*parr + i));
	}
	printf("\n");
	print1(arr, 10);
	print2(arr, 10);
	return 0;
}

#endif


//二维数组的数组指针

//常规打印二维数组方法
void print(int arr[3][5], int x, int y) 
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//使用数组指针打印
void print2(int(*p)[5], int x, int y)// p 是第一行的地址
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", *(*(p+i)+j));
		}
		printf("\n");
	}
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ",(*(p+i))[j]);
		}
		printf("\n");
	}
}

int main()
{
	int arr[3][5] = { {1,2,3,4,5,},{2,3,4,5,6},{3,4,5,6,7} };
	print(arr, 3, 5);//arr 数组名 就是首元素的地址
	print2(arr, 3, 5);//数组名可以是第一列的地址

	int i = 0;
	int arr2[5] = { 1,2,3,4,5 };
	int* p = arr2;
	for ( i = 0; i <5; i++)
	{
		//以下四种形式等价：
		printf("%d ", arr2[i]);
		printf("%d ", *(p+i));
		printf("%d ", p[i]);
		printf("%d ", *(arr2+i));
	}
	printf("\n");
	return 0;
}