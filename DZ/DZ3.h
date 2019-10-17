#pragma once
void Swap(int* arr, int i, int j)//  меняем местами два элемента массива
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void ShowArr(int* arr, int size, bool show, string name)// выводим элементы массива
{
	if (show)
	{
		cout << name;
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
	}
	cout << "\n ";
}
//static void PigeonHole(int* arr, int size, bool show, string name)//PigeonHole сортировка
//{
//	counter = 0;
//	
//	ShowArr(arr, size, show, name);
//}
static void Insertor(int* arr, int size, bool show, string name)//вставочная сортировка
{
	counter = 0;

	int buff = 0;
	int j;

	/************* Начало сортировки *******************/
	for (int i = 1; i < size; i++)
	{
		buff = arr[i];

		for (j = i - 1; j >= 0 && arr[j] > buff; j--)
		{
			arr[j + 1] = arr[j];
			counter++;
		}
		arr[j + 1] = buff; // и поставим запомненный на его новое место 
	}
	ShowArr(arr, size, show, name);
}
static void Selector(int* arr, int size, bool show, string name)//выборочная сортировка
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

static void Shaker(int* arr, int size, bool show, string name)//шейкерная сортировка
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
void Bubble2(int* arr, int size, bool show, string name)//улучшенная пузырьковая сортировка
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
void Bubble(int* arr, int size, bool show, string name)//стадартная пузырьковая сортировка
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
	cout << name << " количество операций сравнения: " << counter << "; время выполнения " << ((double)end - start) / ((double)CLOCKS_PER_SEC) << "сек";
}

typedef void(*FuncPointer)(int[], int, bool, string); // FuncPointer - указатель на функцию

FuncPointer ArrFuncPointer[] = { Bubble, Bubble2, Shaker, Selector, Insertor };// массив указателей на функции



void HW31() //1. Попробовать оптимизировать пузырьковую сортировку.Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
//Написать функции сортировки, которые возвращают количество операций.\n";
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

	ShowArr(arr, size, show, "Неотсортированный массив: \n");
	string name[] = { "\nПузырьковый:\n" , "\nПузырьковый++:\n","\nШейкерный:\n","\nВыбирательный:\n","\nВставлятельный:\n" };
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