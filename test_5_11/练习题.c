#define  _CRT_SECURE_NO_WARNINGS 1

//��ϰ��
#include<stdio.h>
#include<string.h>


//���� strlen �� sizeof�������������
int main()
{
	int arr[] = { "abcdef" };
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
	printf("%d, %x\n", *(ptr1-1), *ptr2);//4, 2000000 (��ʵ��0x02000000)
	int a1[3][2] = { (0,1),(2,3),(4,5) };//ע�⣺����������Ƕ��ű��ʽ����������

	int a2[5][5];
	int(*p2)[4];
	p2 = a2;
	printf("%p, %d\n", &p2[4][2] - &a2[4][2] //��ά�������ڴ��д洢����ʵ����һά����ķ�ʽ���еġ�
		, &p2[4][2] - &a2[4][2]);			 //��ַ��ֱ�Ӵ�ӡ���룬�����Ǵ��油�룬��ӡԭ�롣
	return 0;
}

