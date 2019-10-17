#pragma once
void Swap(int* arr, int i, int j)//  ������ ������� ��� �������� �������
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void ShowArr(int* arr, int size, bool show, string name)// ������� �������� �������
{
	if (show)
	{
		cout << name;
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
	}
	cout << "\n ";
}
//static void PigeonHole(int* arr, int size, bool show, string name)//PigeonHole ����������
//{
//	counter = 0;
//	
//	ShowArr(arr, size, show, name);
//}
static void Insertor(int* arr, int size, bool show, string name)//���������� ����������
{
	counter = 0;

	int buff = 0;
	int j;

	/************* ������ ���������� *******************/
	for (int i = 1; i < size; i++)
	{
		buff = arr[i];

		for (j = i - 1; j >= 0 && arr[j] > buff; j--)
		{
			arr[j + 1] = arr[j];
			counter++;
		}
		arr[j + 1] = buff; // � �������� ����������� �� ��� ����� ����� 
	}
	ShowArr(arr, size, show, name);
}
static void Selector(int* arr, int size, bool show, string name)//���������� ����������
{
	counter = 0;
	int jmin;
	for (int i = 0; i < size; i++)
	{
		jmin = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[jmin])
			{
				jmin = j;
			}
			counter++;
		}
		Swap(arr, i, jmin);
	}
	ShowArr(arr, size, show, name);
}

static void Shaker(int* arr, int size, bool show, string name)//��������� ����������
{
	counter = 0;

	int left = 0, right = size - 1;

	while (left < right)
	{
		for (int i = left; i < right; i++)
		{
			if (arr[i] > arr[i + 1])
				Swap(arr, i, i + 1);
			counter++;
		}
		right--;

		for (int i = right; i > left; i--)
		{
			if (arr[i - 1] > arr[i])
				Swap(arr, i - 1, i);
			counter++;
		}
		left++;
	}
	ShowArr(arr, size, show, name);

}
void Bubble2(int* arr, int size, bool show, string name)//���������� ����������� ����������
{
	counter = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				Swap(arr, j, j + 1);
			counter++;
		}

	}
	ShowArr(arr, size, show, name);
}
void Bubble(int* arr, int size, bool show, string name)//���������� ����������� ����������
{
	counter = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				Swap(arr, j, j + 1);
			counter++;
		}
	}
	ShowArr(arr, size, show, name);
}

void Calculator(int* arr, int size, bool show, string name, void(*func)(int[], int, bool, string))
{
	clock_t start, end;
	start = clock();
	func(arr, size, show, name);
	end = clock();
	cout << name << " ���������� �������� ���������: " << counter << "; ����� ���������� " << ((double)end - start) / ((double)CLOCKS_PER_SEC) << "���";
}

typedef void(*FuncPointer)(int[], int, bool, string); // FuncPointer - ��������� �� �������

FuncPointer ArrFuncPointer[] = { Bubble, Bubble2, Shaker, Selector, Insertor };// ������ ���������� �� �������



void HW31() //1. ����������� �������������� ����������� ����������.�������� ���������� �������� ��������� ���������������� � �� ���������������� ���������.
//�������� ������� ����������, ������� ���������� ���������� ��������.\n";
{
	system("cls");
	srand(time(0));

	int const size = 25;
	int rnd = 100;


	int arr[size];
	int arr2[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % rnd;
		arr2[i] = arr[i];
	}

	bool show = true;

	ShowArr(arr, size, show, "����������������� ������: \n");
	string name[] = { "\n�����������:\n" , "\n�����������++:\n","\n���������:\n","\n�������������:\n","\n��������������:\n" };
	int namecount = sizeof(name) / sizeof(name[0]);


	for (int i = 0; i < namecount; i++)
	{
		Calculator(arr, size, show, name[i], ArrFuncPointer[i]);
		for (int i = 0; i < size; i++)
		{
			arr[i] = arr2[i];
		}
	}


	_getch();
}