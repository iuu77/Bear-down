#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>

#if 0
//ջ�����ڴ���估ʹ��
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
//����  ���������ڴ��еĴ��淽ʽ
int main()
{
	//����
	//�Ȱ����ݵ�ԭ�롢���롢����д����
	//���ó� char ������������ֽ���
	//��ӡ֮ǰ�����������������շ���λ������
	//������������� unsigned ������ʱ��ȫ�� 0
	char a = 128;
	printf("�� %%d �������: %d\n", a);  //-128
	printf("�� %%u �������: %u\n", a);  //��������Ӧ���޷�������
	unsigned char b = 128;
	printf("unsigned char b = %d\n", b); //128

	//���������淽����
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
	printf("%d\n", c);           //�Ƚϴ����
	printf("%lf\n", *pc);        //9.000000
	return 0;
}
#endif


#if 0
//�жϼ�����Ĵ�С��

int my_judge(void)
{
	int a = 1;
	return *(char*)&a;
}
int main()
{
	int i = my_judge();//����1ΪС�ˣ� ����0Ϊ���
	if (i==1)
		printf("С��\n");
	else
		printf("���\n");
	return 0;
}

#endif