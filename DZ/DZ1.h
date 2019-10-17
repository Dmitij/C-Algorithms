#pragma once
using namespace std;


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