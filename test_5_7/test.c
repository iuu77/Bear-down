#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>

#if 0
//栈区的内存分配及使用
int main()
{
	int i = 0;
	int arr[10] = {1,2,3,4,5,6,7,8,9,10,};
	for (i = 0; i <= 12; i++)
	{
		printf("%d\n", i);
		arr[i] = 0;
		Sleep(200);
	}
	return 0;
}
#endif



#if 0
//整数  浮点数在内存中的储存方式
int main()
{
	//整型
	//先把数据的原码、反码、补码写出来
	//再拿出 char 类型所分配的字节数
	//打印之前进行整型提升：按照符号位来提升
	//如果数据类型是 unsigned 提升的时候全补 0
	char a = 128;
	printf("以 %%d 进行输出: %d\n", a);  //-128
	printf("以 %%u 进行输出: %u\n", a);  //补码所对应的无符号整数
	unsigned char b = 128;
	printf("unsigned char b = %d\n", b); //128

	//浮点数储存方法：
	//00000000000000000000000000001011
	//0 00000000 00000000000000000001011
	//0 10000010 01100000000000000000000
	//01000001001100000000000000000000
	//(-1)^0 * (1.011) * 2^3
	//S  0
	//M  1.011
	//E  3+127=130
	int c = 9;
	float* pc = (float*)&c;
	printf("%d\n", c);           //9
	printf("%lf\n", *pc);        //0.000000
	*pc = 9.0;
	printf("%d\n", c);           //比较大的数
	printf("%lf\n", *pc);        //9.000000
	return 0;
}
#endif


#if 0
//判断计算机的大小端

int my_judge(void)
{
	int a = 1;
	return *(char*)&a;
}
int main()
{
	int i = my_judge();//返回1为小端， 返回0为大端
	if (i==1)
		printf("小端\n");
	else
		printf("大端\n");
	return 0;
}

#endif