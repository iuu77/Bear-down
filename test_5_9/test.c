#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


#if 0
//�˵�����
void menu()
{
	printf("****************************************\n");
	printf("******     1.Add        2.Sub     ******\n");
	printf("******     3.Mul        4.Div     ******\n");
	printf("******     5.Xor        0.exit    ******\n");
	printf("****************************************\n");

}

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int Xor(int x, int y)
{
	return x ^ y;
}



int main()
{
	int input = 0;
	int a = 0;
	int b = 0;
	int (*parr[])(int, int) = { 0,Add,Sub,Mul,Div,Xor };
	do
	{
		menu();
		printf("��ѡ������Ҫ������:>");
		scanf("%d", &input);
		if (input >= 1 && input <= 5)
		{
			printf("����������������:>");
			scanf("%d %d", &a, &b);
			printf("%d\n", parr[input](a, b));
		}
		else if (input == 0)
		{
			printf("�˳�����\n");
		}
		else
		{
			printf("��������\n");
		}
	} while (input);
	return 0;
}
#endif


//ð��������
void bubble_sort(int *arr, int sz)
{
	int i = 0;
	int j = 0;
	int Is_right = 1;
	for (j = 0; j < sz-1; j++)
	{
		Is_right = 1;
		for (i = 0; i < sz-1 - j; i++)
		{
			if (arr[i] < arr[i + 1])
			{
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				Is_right = 0;
			}
		}
		if (Is_right)
		{
			break;
		}
	}
}

//������
void Reverse(int* arr, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

//��ӡ���麯��
void print(int arr[], int length)
{
	for (size_t i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[10] = {4,3,17,6,7,8,9,15,13,11,};
	int sz = sizeof(arr) / sizeof(arr[0]);
	//дһ��ð�����򣬴Ӵ�С���С�
	bubble_sort(arr, sz);
	print(arr, sz);

	//������
	Reverse(arr, sz);
	print(arr, sz);
	return 0;
}