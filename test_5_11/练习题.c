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



//�������⣬һԪһƿ������ƿ��һƿ����
int main()
{
	int money = 20;    //������Ǯ
	int bottle = money;//��ƿ��
	int count = money; //�ȵ���ƿ��
	while (bottle > 1)
	{
		count += bottle / 2;
		bottle = bottle / 2 + bottle % 2;
	}
	printf("%d\n", count);
	return 0;
}


//5�˲μ���ˮ������ÿ����˵����һ�룬ȷ����������
int main()
{
	for (size_t A = 1; A <= 5; A++)
	{
		for (size_t B = 1; B <= 5; B++)
		{
			for (size_t C = 1; C <= 5; C++)
			{
				for (size_t D = 1; D <= 5; D++)
				{
					for (size_t E = 1; E <= 5; E++)
					{
						if ((((B==2)+(A==3)==1) &&
							((B==2)+(E==4)==1) &&
							((C==1)+(D==2)==1) &&
							((C==5)+(D==3)==1) &&
							((E==4)+(A==1)==1))&&
							(A * B * C * D * E == 120))
						{
							printf("A=%d B=%d C=%d D=%d E=%d\n", A, B, C, D, E);
						}
					}
				}
			}
		}
	}
	return 0;
}



//��ת�ַ�������������k���ַ�
//ABCD --> BCDA
//ABCD --> CDAB

//������ⷨ
void Rot_Left(char* arr0, int n)
{
	assert(arr0 != NULL);
	int len = strlen(arr0);
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		//��תһ���ַ�
		char tmp = *arr0;
		for(j=0; j< len-1; j++)
		{
			*(arr0 + j) = *(arr0 + 1 + j);
		}
		*(arr0-1+len) = tmp;
	}
}

//������ⷢ��������ת����
void reverse(char* arr, int n)
{
	int left = 0;
	int right = n-1;
	while (left < right)
	{
		char tmp = *(arr + left);
		*(arr + left) = *(arr + right);
		*(arr + right) = tmp;
		left++;
		right--;
	}
}
void Rot_Left2(char* arr, int n)
{
	assert(arr);//�����Ƿ�Ϊ��ָ��
	int len = strlen(arr);
	assert(n <= len);
	reverse(arr, n);//�������
	reverse(arr + n, len-n);//�����ұ�
	reverse(arr, len);//��������
}
int main()
{
	char arr[] = "abc0";
	printf("%s\n", arr);
	int n = 4;
	//Rot_Left(arr, n);
	Rot_Left2(arr, n);
	printf("%s\n", arr);
	return 0;
}


//��ͨ�Ĳ��Һ���  �ҵ����� 1 ���Ҳ������� 0 
int Findnum_1(int arr[3][3], int k, int row, int col)
{
	int x = 0;
	int y = col - 1;
	while (x < row && y >= 0)
	{
		if (arr[x][y] > k)
			y--;
		else if (arr[x][y] < k)
			x++;
		else
			return 1;//��ȵ�ʱ�� ���� 1
	}
	return 0;//�Ҳ���
}

//���׵Ĳ��Һ���  �ҵ����� �±�  �Ҳ������� 0 
int Findnum_2(int arr[3][3], int k, int* row, int* col)
{
	int x = 0;
	int y = *col - 1;
	while (x < *row && y >= 0)
	{
		if (arr[x][y] > k)
			y--;
		else if (arr[x][y] < k)
			x++;
		else
		{
			*row = x;
			*col = y;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[3][3]={ {1,2,3},
					{4,5,6},
					{7,8,9} };//����һ����������
	int k = 5;
	int ret = 0;
	int x = 3;
	int y = 3;

	ret = Findnum_1(arr,k,3,3);//���Һ������ҵ����� 1���Ҳ������� 0.
	if (ret == 1)
		printf("FIND\n");
	else
		printf("NOT FOUND\n");

	ret = Findnum_2(arr, k, &x, &y);//�ҵ��˷��� �±꣬�Ҳ������� 0.
	if (ret == 1)
		printf("(%d %d)\n", x, y);
	else
		printf("NOT FOUND\n");
	return 0;
}

//�����Լ�ʵ�� strlen
//����ʵ�ַ��� 1������  2�����ݹ�  3ָ�����
int my_strlen(const char* arr)
{
	assert(arr != NULL);
	int count = 0;
	while(*arr!='\0')
	{
		arr++;
		count++;
	}
	return count;
}

int main()
{
	char arr[] = "abcdef";
	int count = my_strlen(arr);
	printf("%d\n", count);
	return 0;
}
#endif


//�Լ�ʵ�� strcpy 
char* my_strcpy(char* arr1, const char* arr2)
{
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	char* ret = arr1;
	//����arr2��arr1���� ����'\0'
	while (*arr1++ = *arr2++)
	{
		;
	}
	//����Ŀ�ĺ������׵�ַ
	return ret;
}
int main()
{
	char arr1[] = "abcde";
	char arr2[] = "134";

	char* ret = my_strcpy(arr1, arr2);//�� arr2 ���Ƶ� arr1 ����ȥ
	printf("%s\n", ret);
	return 0;
}