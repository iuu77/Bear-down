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
#endif



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
	print1(arr, 10);
	print2(arr, 10);
	return 0;
}

