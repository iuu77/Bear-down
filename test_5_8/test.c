#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#if 0
//���첻��ѧϰ��ˢˢ��
int main()
{
	//����ָ��
	//

	int* p = NULL;         //����ָ��  -  ������εĵ�ַ
	char* pa = NULL;       //�ַ�ָ��  -  ����ַ���ָ��
	int arr[10] = { 0 };
	int(*parr)[10] = &arr; //����ָ��  -  ��������ָ��
	//arr     - ��Ԫ�صĵ�ַ 
	//&arr[0] - ��Ԫ�صĵ�ַ
	//&arr    - ����ĵ�ַ
	//
	int (* (*parr3[10]) )[5];

	return 0;
}




//��������ָ���ָ���������ϰ

//�����ӡ���鷽��
void print1(int arr[], int length)
{
	int i = 0;
	for ( i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//����ָ���ӡ����
void print2(int* arr, int length)//��������arr��ʵ����Ԫ�صĵ�ַ
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


//��ά���������ָ��

//�����ӡ��ά���鷽��
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

//ʹ������ָ���ӡ
void print2(int(*p)[5], int x, int y)// p �ǵ�һ�еĵ�ַ
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
	print(arr, 3, 5);//arr ������ ������Ԫ�صĵ�ַ
	print2(arr, 3, 5);//�����������ǵ�һ�еĵ�ַ

	int i = 0;
	int arr2[5] = { 1,2,3,4,5 };
	int* p = arr2;
	for ( i = 0; i <5; i++)
	{
		//����������ʽ�ȼۣ�
		printf("%d ", arr2[i]);
		printf("%d ", *(p+i));
		printf("%d ", p[i]);
		printf("%d ", *(arr2+i));
	}
	printf("\n");
	return 0;
}