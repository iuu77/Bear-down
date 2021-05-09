#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


#if 0
//菜单函数
void menu()
{
	printf("****************************************\n");
	printf("******     1.Add        2.Sub     ******\n");
	printf("******     3.Mul        4.Div     ******\n");
	printf("******     5.Xor        0.exit    ******\n");
	printf("****************************************\n");

}

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int Xor(int x, int y)
{
	return x ^ y;
}



int main()
{
	int input = 0;
	int a = 0;
	int b = 0;
	int (*parr[])(int, int) = { 0,Add,Sub,Mul,Div,Xor };
	do
	{
		menu();
		printf("请选择你需要的运算:>");
		scanf("%d", &input);
		if (input >= 1 && input <= 5)
		{
			printf("请输入两个操作数:>");
			scanf("%d %d", &a, &b);
			printf("%d\n", parr[input](a, b));
		}
		else if (input == 0)
		{
			printf("退出程序！\n");
		}
		else
		{
			printf("输入有误！\n");
		}
	} while (input);
	return 0;
}
#endif


//冒泡排序函数
void bubble_sort(int *arr, int sz)
{
	int i = 0;
	int j = 0;
	int Is_right = 1;
	for (j = 0; j < sz-1; j++)
	{
		Is_right = 1;
		for (i = 0; i < sz-1 - j; i++)
		{
			if (arr[i] < arr[i + 1])
			{
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				Is_right = 0;
			}
		}
		if (Is_right)
		{
			break;
		}
	}
}

//倒序函数
void Reverse(int* arr, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

//打印数组函数
void print(int arr[], int length)
{
	for (size_t i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[10] = {4,3,17,6,7,8,9,15,13,11,};
	int sz = sizeof(arr) / sizeof(arr[0]);
	//写一个冒泡排序，从大到小排列。
	bubble_sort(arr, sz);
	print(arr, sz);

	//倒序函数
	Reverse(arr, sz);
	print(arr, sz);
	return 0;
}