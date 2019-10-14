// DZ.cpp: определяет точку входа для приложения.
//
#include <sstream>
#include <iostream>
#include <conio.h>
#include <ctime>
#include "DZ.h"
#include <chrono>

//Рязанцев Дмитрий



using namespace std;

int counter;


void HW11()//1. Ввести вес и рост человека.Рассчитать и вывести индекс массы тела по формуле I = m / (h * h); где m - масса тела в килограммах, h - рост в метрах.
{
	float m, h, I;

	system("cls");       // очищаем окно консоли
	printf("Введите вес: "); // выводим сообщение
	scanf_s("%f", &m);
	printf("Введите рост: ");
	scanf_s("%f", &h);
	I = m / (h * h);
	printf("Индекс массы тела I=%f", I);
	cin.get();

}
void HW12() //3. Написать программу обмена значениями двух целочисленных переменных : b. * без использования третьей переменной.
{
	int a, b, c;
	system("cls");
	printf("Введите: a, b: \n");
	scanf_s("%d %d", &a, &b);

	c = a;
	a = b;
	b = c;
	system("cls");
	printf("a=%d ", a);
	printf("b=%d ", b);

	a = a + b;
	b = a - b;
	a = a - b;

	printf("a=%d ", a);
	printf("b=%d ", b);
	cin.get();
}
void HW13()//4. Написать программу нахождения корней заданного квадратного уравнения.
{
	system("cls");
	float a, b, c;
	printf("Введите: a, b, c: \n");
	scanf_s("%f %f %f", &a, &b, &c);
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				printf("x = любое число");
			}
			else
			{
				printf("Нет корней");
			}
		}
		else
		{
			printf("x = %f", -c / b);
		}
	}
	else
	{
		float d;
		d = b * b - 4 * a * c;
		if (d < 0)
		{
			printf("Нет корней");
		}
		else
		{
			if (d == 0)
			{
				printf("x= %f", -b / (2 * a));
			}
			else
			{
				printf("x1= %f, x2= %f", (-b + sqrt(d)) / (2 * a), (-b - sqrt(d)) / (2 * a));
			}
		}
	}
	cin.get();

}
void HW14()//6. Ввести возраст человека(от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
{
	int a, b;
	system("cls");
	printf("Введите ваш возраст числом\n");
	scanf_s("%d", &a);
	b = a;
	if (((a > 10) && (a < 21)) || ((a > 110) && (a < 121)))
	{
		printf("Вам %d лет", a);
	}
	else
	{
		b = b % 10;
		if (b == 1)
		{
			printf("Вам %d год", a);
		}
		if ((b == 0) || ((b > 4) && (b < 10)))
		{
			printf("Вам %d лет", a);
		}
		if ((b > 1) && (b < 5))
		{
			printf("Вам %d года", a);
		}
	}
	cin.get();
}
void HW15()//7. Имеются числовые координаты двух полей шахматной доски(x1, y1, x2, y2).Требуется определить, относятся ли к поля к одному цвету или нет.
{
	int x1, y1, x2, y2, flag1, flag2;
	system("cls");
	printf("Введите координаты x1,y1 \n");
	scanf_s("%d %d", &x1, &y1);
	printf("Введите координаты x2,y2 \n");
	scanf_s("%d %d", &x2, &y2);


	if ((x1 % 2 == 1 && y1 % 2 == 1) || (x1 % 2 == 0 && y1 % 2 == 0))
	{
		flag1 = 1;
	}
	else
	{
		flag1 = 0;
	}

	if ((x2 % 2 == 1 && y2 % 2 == 1) || (x2 % 2 == 0 && y2 % 2 == 0))
	{
		flag2 = 1;
	}
	else
	{
		flag2 = 0;
	}

	if (flag1 == flag2)
	{
		printf("Поля одного цвета");
	}
	else
	{
		printf("Поля разного цвета");
	}
	cin.get();
}
void HW16()//9. Даны целые положительные числа N и K.Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.
{
	int n, k, ostatok, chastnoe;
	system("cls");
	printf("Введите целые положительные числа N > K \n");
	scanf_s("%d %d", &n, &k);

	chastnoe = 0;
	do
	{
		chastnoe = chastnoe + 1;
		n = n - k;
	} while (n >= k);


	ostatok = n;

	printf("Частное = %d ", chastnoe);
	printf("Остаток = %d ", ostatok);
	cin.get();
}
void HW17()//10. Дано целое число N(> 0).С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры.Если имеются, то вывести True, если нет — вывести False.
{
	int N = 1;
	system("cls");
	printf("Введите целое положительное число N \n");
	scanf_s("%d", &N);
	string str = "False";

	while (N > 0)
	{
		int z = N % 10;
		if (z % 2 == 1)
		{
			str = "True";
			break;
		}
		N = N / 10;
	}
	cout << str;
	cin.get();
}
void HW18()//14. * Автоморфные числа.Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата.Например, 25 \ :sup: 2 = 625. Напишите программу, которая выводит на экран все автоморфные числа, в пределах 1_000_000
{
	long int N, d;
	system("cls");
	N = 1000000;
	d = 10;
	for (int i = 1; i <= 1000000; i++)
	{
		while (d <= i)
			d = d * 10;
		if ((i * i) % d == i)
			printf("%d * %d = %d\n", i, i, i * i);
	}
	cin.get();
}
void HW19()//15. Дублирую задание по улучшению алгоритма с урока))";
{
	system("cls");
	int count = -1;
	double grade = 0, sum = 0;
	cout << "Вводите оценки, если надоест введите -1\n";
	while (grade != -1)
	{
		sum += grade;
		count++;
		cin >> grade;
	}
	std::cout << "Срядняя оценка: " << sum / count;
	cin.get();
}




void dec_to_bin(int n)
{
	if (n >= 2)
		dec_to_bin(n / 2);
	cout << n % 2;
}
void HW21()//1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
{
	system("cls");
	int n;
	cout << "\n Введите целое число ";
	cin >> n;
	cout << "\n Bin = ";
	dec_to_bin(n);
	cin.get();
}




double pow(int a, int b)
{
	int i;
	double c;
	c = 1;
	for (i = 1; i <= b; i++)
	{
		c = c * a;
	}
	return c;
}
double pow1(int a, int b)//a.без рекурсии;
{
	if (b < 0)
	{
		return 1 / pow(a, -b);
	}
	if (b == 0)
	{
		return 1;
	}
	return pow(a, b);
}
double pow2(int a, int b)//b.рекурсивно
{
	if (b < 0)
	{
		return 1 / pow2(a, -b);
	}
	if (b == 0)
	{
		return 1;
	}
	return a * pow2(a, b - 1);
}
double pow3(int a, int b)//c.* рекурсивно, используя свойство чётности степени.
{
	if (b < 0)
	{
		return 1 / pow3(a, -b);
	}
	if (b == 0)
	{
		return 1;
	}
	else if (b == 1)
	{
		return a;
	}
	else if (b % 2 == 0)
	{
		return pow3(a * a, b / 2);
	}
	else
	{
		return a * pow3(a * a, b / 2);
	}
}
void HW22()//2. Реализовать функцию возведения числа a в степень b :;
{
	system("cls");
	double c;
	int a, b;

	cout << "Введите целое число a ";
	cin >> a;
	cout << "Введите целое число b ";
	cin >> b;


	c = pow1(a, b);
	cout << "\n (a) без рекурсии a^b=" << c;

	c = pow2(a, b);
	cout << "\n (b) рекурсивно a^b=" << c;

	c = pow3(a, b);
	cout << "\n (c)* рекурсивно, используя свойство чётности степени a^b=" << c;

	cin.get();

}




static void CalcArr(int a, int b, string str)
{


	//	// объявление двумерного динамического массива на 10 элементов:
	//	float** ptrarray = new float* [2]; // две строки в массиве
	//	for (int count = 0; count < 2; count++)
	//		ptrarray[count] = new float[5]; // и пять столбцов
	////  где ptrarray  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа float


	//for (int dimm = 3; dimm = 16; dimm++)
	//{
	//	int flag = 0;
	//	int** ptrarray = new int* [dimm]; //  строки в массиве
	//	for (int count = 0; count < 2; count++)
	//		ptrarray[count] = new int[17]; // столбцы
	//	ptrarray[0][0] = a;

	//	for (int count_row = 0; count_row < dimm; count_row++)
	//		for (int count_column = 0; count_column < 17; count_column++)
	//		{
	//			if (count_column == 17 - dimm - 1)
	//				flag = 1;

	//			if (flag == 0)
	//			{
	//				ptrarray[count_row][count_column + 1] = ptrarray[count_row][count_column] + 1;
	//			}
	//			else
	//			{
	//				ptrarray[count_row][count_column + 1] = ptrarray[count_row][count_column] * 2;
	//			}

	//		}
	//}

	//// высвобождение памяти отводимой под двумерный динамический массив:
	//for (int count = 0; count < 2; count++)
	//	delete[] ptrarray[count];
	////      где 2 – количество строк в массиве
}
static void CalcRec(int a1, int b, string str)
{
	counter = 0;
	for (int i = 0; i <= 1; i++)
	{
		string s = str;
		int a = a1;

		if (i == 0)
		{
			a++;
			s += "+1";
		}
		else
		{
			a *= 2;
			s += "*2";
		}
		if (a > b)
			break;
		if (a < b)
			CalcRec(a, b, s); //переприсваиваем и увеличиваем a на 1 или в 2 раза
		if (a == b)
		{
			counter++;
			cout << "\n " + s + "=" << b; //выводим только тогда когда a = b =20	

		}
	}

}
void HW23()//3. Исполнитель Калькулятор преобразует целое число, записанное на экране.У исполнителя две команды, каждой команде присвоен номер :
//Прибавь 1 2.Умножь на 2 Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза.
//Cколько существует программ, которые число 3 преобразуют в число 20 ?
//а) с использованием массива; б) с использованием рекурсии.
{
	system("cls");
	int a = 3;
	int b = 20;

	auto s = std::to_string(a);
	//CalcArr(a, b, s);
	CalcRec(a, b, s);
	cout << "\n Всего программ: " << counter;
	cin.get();
}




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
	bool show = true;

	int arr[size];
	int arr2[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % rnd;
		arr2[i] = arr[i];
	}



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


	cin.get();
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


const int N = 7;
const int M = 7;

void Print2(int n, int m, int a[N][M])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}

void HW41() // "1. *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.\n";
{
	system("cls");

	int A[N][M];
	int i, j;


	//for (j = 0; j < M; j++)
	//	A[0][j] = 1; // Первая строка заполнена единицами
	//for (i = 1; i < N; i++)
	//{
	//	A[i][0] = 1;// Первый столбец заполнен единицами
	//	for (j = 1; j < M; j++)
	//	{
	//		A[i][j] = A[i][j - 1] + A[i - 1][j];
	//	}
	//}
	//Print2(N, M, A);

	A[0][0] = 1;  //первая клетка всегда ровна 1

	A[0][3] = 0;//препятствие
	A[3][0] = 0;//препятствие
	A[1][1] = 0;//препятствие
	A[4][5] = 0;//препятствие

	for (j = 1; j < M; j++) //заполняем первую строку			
		if ((A[0][j] == 0) || A[0][j - 1] == 0)
			A[0][j] = 0;
		else
			A[0][j] = 1;

	for (j = 1; j < N; j++) //заполняем первый столбец
		if ((A[j][0] == 0) || A[j - 1][0] == 0)
			A[j][0] = 0;
		else
			A[j][0] = 1;



	for (i = 1; i < N; i++)
		for (j = 1; j < M; j++)
		{
			if (A[i][j] != 0)
				A[i][j] = A[i][j - 1] + A[i - 1][j];
		}

	Print2(N, M, A);


	cin.get();
}


void HorseNextMove(int n, int m)
{
	int harr[8][2] = { {n + 1,m - 2},{n + 2,m - 1},
					   {n + 2,m + 1},{n + 1,m + 2},
					   {n - 1,m + 2},{n - 2,m + 1},
					   {n - 2,m - 1},{n - 1,m - 2} };
}


void move(int* arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//if (arr[i][j] == 0)
			//{
			//	//arr[i][j] == 1;

			//}
		}
	}
}

void HW42() // 	 "3. ***Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному разу.\n";		
{
	system("cls");
	const int n = 4;
	const int m = 4;
	int arr[n][m];


	for (int i = 0; i < n; i++)  //заполняем все клетки нулями
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = 0;
		}
	}



	cin.get();
}
char* brackets_check(const char* s)
{
	switch (*s)
	{
	case '\0':
	case ')':
	case '}':
	case ']':
		return (char*)s;
	case '(':
	{
		char* ret = brackets_check(s + 1);
		return (*ret == ')') ? brackets_check(ret + 1) : (char*)s;
	}
	case '{':
	{
		char* ret = brackets_check(s + 1);
		return (*ret == '}') ? brackets_check(ret + 1) : (char*)s;
	}
	case '[':
	{
		char* ret = brackets_check(s + 1);
		return (*ret == ']') ? brackets_check(ret + 1) : (char*)s;
	}
	default:
		return brackets_check(s + 1);
	}
}

void HW51() // 	 "1. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.	Например: (2 + (2 * 2)) или[2 / {5 * (4 + 7)}].\n";		
{
	system("cls");

	char buf[BUFSIZ];
	printf("Введите строку: ");
	fgets(buf, BUFSIZ, stdin);
	printf("%s\n", (*brackets_check(buf)) ? "Последовательность НЕправильная" : "Последовательность правильная");


	cin.get();
}


#define T char
// Опишем структуру узла списка
struct TNode
{
	T value;
	struct TNode* next;
};
typedef struct TNode Node;

struct Stack
{
	Node* head;
	int size;
	int maxSize;
};


void push(T value, Stack St)
{
	if (St.size >= St.maxSize) {
		printf("Error stack size");
		return;
	}
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = St.head;
	St.head = tmp;
	St.size++;
}
//T pop() {
//
//	if (Stack.size == 0)
//	{
//		printf("Stack is empty");
//
//	}
//	// Временный указатель
//	Node* next = NULL;
//	// Значение «наверху» списка
//	T value;
//	value = Stack.head->value;
//	next = Stack.head;
//	Stack.head = Stack.head->next;
//	// Запись, на которую указывала «голова», удаляем, освобождая память
//	free(next);
//	// Возвращаем значение, которое было в «голове»
//	Stack.size--;
//	return value;
//}
void PrintStack(Stack St)
{
	Node* current = St.head;
	while (current != NULL)
	{
		printf("%c ", current->value);
		current = current->next;
	}
}
//void CopyStack()                   //Функция копирования списка
//{
//	Node* current = Stack.head;
//	while (current != NULL)
//	{
//		printf("%c ", current->value);
//		current = current->next;
//	}
//}
//struct element                      //Структура с инфополями и адресным полем
//{
//	int x;                             //Инфополе. значения из x будут передаваться в список
//	element* Next;                     //Адресное поле (адрес следующего элемента)
//};
//
//class List                      //Класс Список
//{
//	element* Head;                 //Указатель на последний активный элемент или просто голова списка
//public:
//	List() { Head = NULL; }           //Конструктор и инициализация указателя пустым значением
//	~List();                       //Деструктор. Далее он вынесен за класс
//	void Add(int x);               //Функция для добавления значений в список
//	void Show(string str);                   //Функция для отображения списка на экране	
//};
//
//List::~List()                   //Деструктор вынесен за класс
//{
//	while (Head != NULL)          //Пока по адресу не пусто
//	{
//		element* temp = Head->Next;   //Временная переменная для хранения адреса следующего элемента
//		delete Head;                //Освобождаем адрес обозначающий начало
//		Head = temp;                  //Меняем адрес на следующий
//	}
//}
//
//void List::Add(int x) //Функция добавления элементов в список
//{
//	element* temp = new element;           //При каждом вызове выделяется память
//	temp->x = x;                            //Записываем x в элемент структуры  element (в x структуры element)
//	temp->Next = Head;                      //Указываем, что след. элемент это объект по адресу Head
//	Head = temp;                            //Указываем, что последний активный элемент это только что введенный
//}
//
//
//
//void List::Show(string str)                       //Функция отображения списка на экране
//{
//	element* temp = Head;                 //Определяем указатель, который изначально он равен адресу начала списка
//
//	cout << "\n" << str;
//	while (temp != NULL)                   //До тех пор пока не встретит пустое значение
//	{
//		cout << temp->x << " ";               //Выведет элемент x из списка
//		temp = temp->Next;                    //Указываем, что далее нам нужен следующий элемент
//	}
//}


void HW52() // "2. * Создать функцию, копирующую односвязный список(то есть создает в памяти копию односвязного списка, без удаления первого списка).\n";
{
	system("cls");  //http://ci-plus-plus-snachala.ru/?p=57

	int N;                        //Число элементов в список
	char x;                        //Элементы вводимые в список
	//List lst;                     //Переменная, тип которой список
	//List lst2;
	//List lst3;

	//cout << "N = ";
	//cin >> N;                    //Указали сколько элементов вводить в список

	//for (int i = 0; i < N; i++)
	//{
	//	cout << i + 1 << ". x = ";
	//	cin >> x;             //Ввод x с клавиатуры
	//	lst.Add(x);           //Добавление элемента в список
	//}

	//lst.Show("Начальный список: "); 				//Вывод списка на экран	

	//lst2 = lst;
	//lst2.Show("Скопированный список: ");

	//ListCopy(lst);
	struct Stack Stack;
	struct Stack Stack2;

	cout << "Число элементов списка N = ";
	cin >> N;
	Stack.maxSize = N;
	Stack.head = NULL;



	for (int i = 0; i < N; i++)
	{
		cout << i + 1 << ". x = ";
		cin >> x;             //Ввод x с клавиатуры
		push(x, Stack);           //Добавление элемента в список
	}

	PrintStack(Stack);



	cin.ignore().get();
}

void HW1()
{
	char ch_key;
	bool bMENU = true;
	while (bMENU)
	{
		system("cls");
		cout << "**Домашнее задание 1***\n";
		cout << "1. Ввести вес и рост человека.Рассчитать и вывести индекс массы тела по формуле I = m / (h * h); где m - масса тела в килограммах, h - рост в метрах.\n";
		cout << "2. Написать программу обмена значениями двух целочисленных переменных : b. * без использования третьей переменной.\n";
		cout << "3. Написать программу нахождения корней заданного квадратного уравнения.\n";
		cout << "4. Ввести возраст человека(от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».\n";
		cout << "5. Имеются числовые координаты двух полей шахматной доски(x1, y1, x2, y2).Требуется определить, относятся ли к поля к одному цвету или нет.\n";
		cout << "6. Даны целые положительные числа N и K.Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.\n";
		cout << "7. Дано целое число N(> 0).С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры.Если имеются, то вывести True, если нет — вывести False.\n";
		cout << "8. * Автоморфные числа.Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата.Например, 25 \ :sup: 2 = 625. Напишите программу, которая выводит на экран все автоморфные числа, в пределах 1_000_000\n";
		cout << "9. Дублирую задание по улучшению алгоритма с урока))\n";

		switch ((ch_key = _getch()))
		{
		case '1':
			HW11();
			break;
		case '2':
			HW12();
			break;
		case '3':
			HW13();
			break;
		case '4':
			HW14();
			break;
		case '5':
			HW15();
			break;
		case '6':
			HW16();
			break;
		case '7':
			HW17();
			break;
		case '8':
			HW18();
			break;
		case '9':
			HW19();
			break;

		case 27:
			bMENU = false;
			break;
		default:
			cout << "Unsupported key was pressed\n";
			system("pause");
			break;
		}
	}
}
void HW2()
{
	char ch_key;
	bool bMENU = true;
	while (bMENU)
	{
		system("cls");
		cout << "**Домашнее задание 2***\n";
		cout << "1 - Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.\n";
		cout << "2 - Реализовать функцию возведения числа a в степень b  - (a) без рекурсии; (b) рекурсивно; (c)* рекурсивно, используя свойство чётности степени.\n";
		cout << "3 - Исполнитель Калькулятор преобразует целое число, записанное на экране.У исполнителя две команды, каждой команде присвоен номер : Прибавь 1 2.Умножь на 2 Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза.Сколько существует программ, которые число 3 преобразуют в число 20 ? а) с использованием массива; б) с использованием рекурсии.\n";
		cout << "ESC - Exit\n";

		switch ((ch_key = _getch()))
		{
		case '1':
			HW21();
			break;
		case '2':
			HW22();
			break;
		case '3':
			HW23();
			break;

		case 27:
			bMENU = false;
			break;
		default:
			cout << "Unsupported key was pressed\n";
			system("pause");
			break;
		}
	}
}

void HW3()
{
	char ch_key;
	bool bMENU = true;
	while (bMENU)
	{
		system("cls");
		cout << "**Домашнее задание 2***\n";
		cout << "1. Попробовать оптимизировать пузырьковую сортировку.Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.Написать функции сортировки, которые возвращают количество операций.\n";
		cout << " Реализовать шейкерную сортировку.\n";
		cout << " optional.Погуглить как осуществляется Pigeon Hole Sort и попробовать реализовать на языке С.";
		cout << "ESC - Exit\n";

		switch ((ch_key = _getch()))
		{
		case '1':
			HW31();
			break;

		case 27:
			bMENU = false;
			break;
		default:
			cout << "Unsupported key was pressed\n";
			system("pause");
			break;
		}
	}
}

void HW4()
{
	char ch_key;
	bool bMENU = true;
	while (bMENU)
	{
		system("cls");
		cout << "**Домашнее задание 2***\n";
		cout << "1. *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.\n";
		cout << "2. ***Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному разу.\n";
		cout << "ESC - Exit\n";

		switch ((ch_key = _getch()))
		{
		case '1':
			HW41();
			break;
		case '2':
			HW42();
			break;
		case 27:
			bMENU = false;
			break;
		default:
			cout << "Unsupported key was pressed\n";
			system("pause");
			break;
		}
	}
}
void HW5()
{
	char ch_key;
	bool bMENU = true;
	while (bMENU)
	{
		system("cls");
		cout << "**Домашнее задание 2***\n";
		cout << "1. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.	Например: (2 + (2 * 2)) или[2 / {5 * (4 + 7)}].\n";
		cout << "2. * Создать функцию, копирующую односвязный список(то есть создает в памяти копию односвязного списка, без удаления первого списка).\n";
		cout << "3. * Реализовать очередь на основе двусвязного списка.\n";
		cout << "ESC - Exit\n";

		switch ((ch_key = _getch()))
		{
		case '1':
			HW51();
			break;
		case '2':
			HW52();
			break;
		case 27:
			bMENU = false;
			break;
		default:
			cout << "Unsupported key was pressed\n";
			system("pause");
			break;
		}
	}
}
//
//
void MainMenu()
{
	char ch_key;
	bool bMENU = true;
	while (bMENU)
	{
		system("cls");
		cout << "***MENU***\n";
		cout << "1 - Домашняя работа 1\n";
		cout << "2 - Домашняя работа 2\n";
		cout << "3 - Домашняя работа 3\n";
		cout << "4 - Домашняя работа 4\n";
		cout << "5 - Домашняя работа 5\n";
		cout << "ESC - Exit\n";

		switch ((ch_key = _getch()))
		{
		case '1':
			HW1();
			break;
		case '2':
			HW2();
			break;
		case '3':
			HW3();
			break;
		case '4':
			HW4();
			break;
		case '5':
			HW5();
			break;
		case 27:
			bMENU = false;
			cout << "Exit from program\n";
			break;
		default:
			cout << "Unsupported key was pressed\n";
			system("pause");
			break;
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	MainMenu();

	system("pause");
	return 0;
}