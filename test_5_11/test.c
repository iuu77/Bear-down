#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct people
{
	int age;
	char name[20];
};
////�Ƚ���������
int com_int(const void* x,const void* y)
{
	return *((int*)x) - *((int*)y);
}

//��ӡ��������
void print_int(int arr[], size_t length)
{
	for (size_t i = 0; i<length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//��ӡ�ṹ������
void print_str(struct people pe[4], size_t length) 
{
	for (size_t i = 0; i < length; i++)
	{
		printf("name: %s, age: %d\n", pe[i].name, pe[i].age);
	}
}

//�ȽϽṹ������
int com_str_age(const void* x, const void* y)
{
	return ((struct people*) x)->age - ((struct people*) y)->age;
}

int com_str_name(const void* x, const void* y)
{
	return strcmp(((struct people*)x)->name, ((struct people*)y)->name);
}
void test1()
{
	int arr[] = { 4,2,3,6,1,5,10,9,7,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print_int(arr, sz);
	qsort(arr, sz, sizeof(arr[0]), com_int);//�⺯��
	print_int(arr, sz);
}


//int main()
//{
//	
//	//test1();
//	test2();
//	return 0;
//}


//дһ���Լ���my_qsort����

void My_Swap(char* x, char* y, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *x;
		*x = *y;
		*y = tmp;
		x++;
		y++;
	}
}


void my_qsort(void* p, int length, int width, int(*com)(const void* e1, const void* e2))
{
	//ð���������� length-1
	int i = 0;
	for ( i = 0; i < length-1; i++)
	{
		//ÿһ����Ҫ���еıȽ�
		int j = 0;
		for ( j = 0; j < length-1-i; j++)
		{
			//�ж��Ƿ���Ҫ����
			if (com((char*)p + j * width, (char*)p + (j + 1) * width) > 0)
			{
				My_Swap((char*)p + j * width, (char*)p + (j + 1) * width, width);
			}
		}
	}
}


void test2()
{
	struct people pe[] = { {28,"zhangsan"} ,{30,"lisi"}, {10,"wangwu"}, {90,"zhaoyi"} };
	int sz = sizeof(pe) / sizeof(pe[0]);
	my_qsort(pe, sz, sizeof(pe[0]), com_str_age);//�⺯��
	print_str(pe, sz);
	my_qsort(pe, sz, sizeof(pe[0]), com_str_name);//�⺯��
	print_str(pe, sz);
}

int main()
{
	int arr[] = { 10,3,4,2,8,6,9,7,15,5};
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, sz, sizeof(arr[0]), com_int);
	print_int(arr, sz);
	test2();
	return 0;
}
