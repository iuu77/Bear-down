#define  _CRT_SECURE_NO_WARNINGS 1

//��ϰ��
#include<stdio.h>
#include<string.h>


//���� strlen �� sizeof�������������
int main()
{
	int arr[] = { "abcdef" };
	printf("%d\n", sizeof(arr + 0)); //arr����Ԫ�صĵ�ַ��arr+0�ǵ�ַ����ַ�Ĵ�С�� 4/8
	char(*p)[7] = &arr;//&arr����������ĵ�ַ
	printf("%d\n", strlen(&arr + 1));//����ĵ�ַ+1 ���ӽ�β����ʼ���� �õ��������ֵ
	//int strlen(const char*);  //��Ҫ����const char*
	//char* p = "abcdef";//�����ַ�����p�����ŵ��� a �ĵ�ַ��
	printf("%d\n", strlen(&p));//���ֵ���ⲻ�����飬����Ǵ�p���׵�ַ������
	int arrr[3][4] = { 0 };
	printf("%d\n", sizeof(arrr[0] + 1));//arrr[0]�ǵ�һ�е���������arrr[0]�����ŵ�һ����Ԫ�صĵ�ַ
	                                    //arrr[0]+1 == &(arrr[0][1]);
	printf("%d\n", sizeof(arrr + 1));//�ڶ��еĵ�ַ��
	*(arrr + 1) == arrr[1];
	(&arrr[0] + 1);//�����ŵڶ��еĵ�ַ��*��&arrr[0] + 1)  ����������ĵڶ���
	return 0;
}