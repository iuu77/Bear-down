#define  _CRT_SECURE_NO_WARNINGS 1

//练习题
#include<stdio.h>
#include<string.h>


//关于 strlen 和 sizeof（）的深入理解
int main()
{
	int arr[] = { "abcdef" };
	printf("%d\n", sizeof(arr + 0)); //arr是首元素的地址，arr+0是地址。地址的大小是 4/8
	char(*p)[7] = &arr;//&arr是整个数组的地址
	printf("%d\n", strlen(&arr + 1));//数组的地址+1 ；从结尾处开始计算 得到的是随机值
	//int strlen(const char*);  //需要的是const char*
	//char* p = "abcdef";//常量字符串，p里面存放的是 a 的地址。
	printf("%d\n", strlen(&p));//随机值，这不是数组，这个是从p的首地址往后数
	int arrr[3][4] = { 0 };
	printf("%d\n", sizeof(arrr[0] + 1));//arrr[0]是第一行的数组名，arrr[0]代表着第一行首元素的地址
	                                    //arrr[0]+1 == &(arrr[0][1]);
	printf("%d\n", sizeof(arrr + 1));//第二行的地址，
	*(arrr + 1) == arrr[1];
	(&arrr[0] + 1);//代表着第二行的地址；*（&arrr[0] + 1)  代表着数组的第二行
	return 0;
}