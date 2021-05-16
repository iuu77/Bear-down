#define  _CRT_SECURE_NO_WARNINGS 1

//练习题
#include<stdio.h>
#include<string.h>
#include<assert.h>

#if 0
//关于 strlen 和 sizeof（）的深入理解
int main()
{
	char arr[] = { "abcdef" };
	char* parr = arr;
	*(parr + 2) == parr[2] == *(arr + 2) == arr[2];
	printf("%d\n", sizeof(arr + 0)); //arr是首元素的地址，arr+0是地址。地址的大小是 4/8
	//char(*p)[7] = &arr;//&arr是整个数组的地址
	printf("%d\n", strlen(&arr + 1));//数组的地址+1 ；从结尾处开始计算 得到的是随机值
							 //int strlen(const char*); 需要的是const char*

	char* p = "abcdef";//常量字符串，p0里面存放的是 a 的地址。
	printf("%d\n", strlen(&p));//随机值，这不是数组，这个是从p的首地址往后数

	int arrr[3][4] = { 0 };
	printf("%d\n", sizeof(arrr[0] + 1));//arrr[0]是第一行的数组名，arrr[0]代表着第一行首元素的地址
										//arrr[0]+1 == &(arrr[0][1]);
	printf("%d\n", sizeof(arrr + 1));//第二行的地址，
	*(arrr + 1) == arrr[1];
	(&arrr[0] + 1);//代表着第二行的地址；*（&arrr[0] + 1)  代表着数组的第二行

	int a[4] = { 1,2,3,4 };
	int* ptr1 = (int*)(&a + 1);//ptr1 指向 a[5]
	int* ptr2 = (int*)((int)a + 1);//利用内存来分析
	printf("%d, %x\n", *(ptr1 - 1), *ptr2);//4, 2000000 (其实是0x02000000)
	int a1[3][2] = { (0,1),(2,3),(4,5) };//注意：（）里面的是逗号表达式。！！！！

	int a2[5][5];
	int(*p2)[4];
	p2 = a2;
	printf("%p, %d\n", &p2[4][2] - &a2[4][2] //二维数组在内存中存储，其实是以一维数组的方式排列的。
		, &p2[4][2] - &a2[4][2]);			 //地址是直接打印补码，整型是储存补码，打印原码。

	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3, c + 2, c + 1, c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);//注意：画图来理解。
	printf("%s\n", *cpp[-2] + 3);   //从POINT首地址往后偏移三个
	printf("%s\n", cpp[-1][-1] + 1);

	return 0;
}

//逆序字符串
void my_backward(char *arr)
{
	assert(arr);
	int sz = strlen(arr);
	char* left = arr;
	char* right = arr + sz - 1;
	while (left < right) 
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[256] = { 0 };
	//printf("%s\n", arr);
	//scanf("%s", &arr);
	gets(arr);
	my_backward(arr);//逆序字符串
	printf("%s\n", arr);
	return 0;
}


int Sum(int num, int n)
{
	int sum = 0;
	int nn = num;
	for (size_t i = 0; i < n; i++)
	{
		sum += num;
		num = num * 10 + nn;
	}
	return sum;
}
// 2+22+222+2222
int main()
{
	int num = 0;
	int n = 0;
	scanf("%d%d", &num, &n);
	printf("%d", Sum(num,n));
	return 0;
}


//打印水仙花数
//判断num是几位数
//提取每一位数，判断和

//判断位数
int Digit(int num)
{
	int digit = 1;
	while (num /= 10)
		digit++;
	return digit;
}
//次幂
int exp(int num, int length)
{
	int n = 1;
	for (size_t i = 0; i < length; i++)
		n *= num;
	return n;
}

//判断是否为水仙花数：1.yes ; 0.no
int Is_Narc(int num, int length)
{
	int numm = num;
	int sum = 0;
	while (num>0)
	{
		sum += exp(num % 10, length);
		num = num / 10;
	}
	if (sum == numm)
		return 1;
	else
		return 0;
}

int main()
{
	int num = 0;
	for (num = 0; num < 100000; num++)
	{
		int digit = Digit(num);//判断数的位数
		if (Is_Narc(num, digit)) //判断是否为水仙花数
			printf("%d ", num);
	}
	return 0;
}


int main()
{
	int line = 0;
	scanf("%d", &line);
	int i = 0;
	for (i = 0; i <= line/2; i++)
	{
		int j = 0;
		for (j=0; j<line/2-i; j++)
		{
			printf(" ");
		}
		for ( j = 0; j < 2*i+1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = line / 2-1; i >= 0; i--) 
	{
		int j = 0;
		for (j = 0; j < line / 2 - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
} 
//  *
// ***
//*****  
//*****
// ***
//  *
//
#endif

int main()
{
	int n = 20;
	int sum = n;
	int count = 0;
	while (n / 2)
	{
		n /= 10;
		sum += n;
		if (n % 10)
			count++;
	}
	n = count;
	if(count)
	printf("%d\n", sum);
	return 0;
}