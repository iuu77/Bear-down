#define  _CRT_SECURE_NO_WARNINGS 1

//��ϰ��
#include<stdio.h>
#include<string.h>
#include<assert.h>

#if 0
//���� strlen �� sizeof�������������
int main()
{
	char arr[] = { "abcdef" };
	char* parr = arr;
	*(parr + 2) == parr[2] == *(arr + 2) == arr[2];
	printf("%d\n", sizeof(arr + 0)); //arr����Ԫ�صĵ�ַ��arr+0�ǵ�ַ����ַ�Ĵ�С�� 4/8
	//char(*p)[7] = &arr;//&arr����������ĵ�ַ
	printf("%d\n", strlen(&arr + 1));//����ĵ�ַ+1 ���ӽ�β����ʼ���� �õ��������ֵ
							 //int strlen(const char*); ��Ҫ����const char*

	char* p = "abcdef";//�����ַ�����p0�����ŵ��� a �ĵ�ַ��
	printf("%d\n", strlen(&p));//���ֵ���ⲻ�����飬����Ǵ�p���׵�ַ������

	int arrr[3][4] = { 0 };
	printf("%d\n", sizeof(arrr[0] + 1));//arrr[0]�ǵ�һ�е���������arrr[0]�����ŵ�һ����Ԫ�صĵ�ַ
										//arrr[0]+1 == &(arrr[0][1]);
	printf("%d\n", sizeof(arrr + 1));//�ڶ��еĵ�ַ��
	*(arrr + 1) == arrr[1];
	(&arrr[0] + 1);//�����ŵڶ��еĵ�ַ��*��&arrr[0] + 1)  ����������ĵڶ���

	int a[4] = { 1,2,3,4 };
	int* ptr1 = (int*)(&a + 1);//ptr1 ָ�� a[5]
	int* ptr2 = (int*)((int)a + 1);//�����ڴ�������
	printf("%d, %x\n", *(ptr1 - 1), *ptr2);//4, 2000000 (��ʵ��0x02000000)
	int a1[3][2] = { (0,1),(2,3),(4,5) };//ע�⣺����������Ƕ��ű��ʽ����������

	int a2[5][5];
	int(*p2)[4];
	p2 = a2;
	printf("%p, %d\n", &p2[4][2] - &a2[4][2] //��ά�������ڴ��д洢����ʵ����һά����ķ�ʽ���еġ�
		, &p2[4][2] - &a2[4][2]);			 //��ַ��ֱ�Ӵ�ӡ���룬�����Ǵ��油�룬��ӡԭ�롣

	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3, c + 2, c + 1, c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);//ע�⣺��ͼ����⡣
	printf("%s\n", *cpp[-2] + 3);   //��POINT�׵�ַ����ƫ������
	printf("%s\n", cpp[-1][-1] + 1);

	return 0;
}

//�����ַ���
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
	my_backward(arr);//�����ַ���
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


//��ӡˮ�ɻ���
//�ж�num�Ǽ�λ��
//��ȡÿһλ�����жϺ�

//�ж�λ��
int Digit(int num)
{
	int digit = 1;
	while (num /= 10)
		digit++;
	return digit;
}
//����
int exp(int num, int length)
{
	int n = 1;
	for (size_t i = 0; i < length; i++)
		n *= num;
	return n;
}

//�ж��Ƿ�Ϊˮ�ɻ�����1.yes ; 0.no
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
		int digit = Digit(num);//�ж�����λ��
		if (Is_Narc(num, digit)) //�ж��Ƿ�Ϊˮ�ɻ���
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