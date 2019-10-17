#pragma once


int counter;

void dec_to_bin(int n)
{
	if (n >= 2)
		dec_to_bin(n / 2);
	cout << n % 2;
}
void HW21()//1. –еализовать функцию перевода из 10 системы в двоичную использу€ рекурсию.
{
	system("cls");
	int n;
	cout << "\n ¬ведите целое число ";
	cin >> n;
	cout << "\n Bin = ";
	dec_to_bin(n);
	_getch();
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
double pow3(int a, int b)//c.* рекурсивно, использу€ свойство чЄтности степени.
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
void HW22()//2. –еализовать функцию возведени€ числа a в степень b :;
{
	system("cls");
	double c;
	int a, b;

	cout << "¬ведите целое число a ";
	cin >> a;
	cout << "¬ведите целое число b ";
	cin >> b;


	c = pow1(a, b);
	cout << "\n (a) без рекурсии a^b=" << c;

	c = pow2(a, b);
	cout << "\n (b) рекурсивно a^b=" << c;

	c = pow3(a, b);
	cout << "\n (c)* рекурсивно, использу€ свойство чЄтности степени a^b=" << c;

	_getch();

}




static void CalcArr(int a, int b, string str)
{


	//	// объ€вление двумерного динамического массива на 10 элементов:
	//	float** ptrarray = new float* [2]; // две строки в массиве
	//	for (int count = 0; count < 2; count++)
	//		ptrarray[count] = new float[5]; // и п€ть столбцов
	////  где ptrarray  Ц массив указателей на выделенный участок пам€ти под массив вещественных чисел  типа float


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

	//// высвобождение пам€ти отводимой под двумерный динамический массив:
	//for (int count = 0; count < 2; count++)
	//	delete[] ptrarray[count];
	////      где 2 Ц количество строк в массиве
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
void HW23()//3. »сполнитель  алькул€тор преобразует целое число, записанное на экране.” исполнител€ две команды, каждой команде присвоен номер :
//ѕрибавь 1 2.”множь на 2 ѕерва€ команда увеличивает число на экране на 1, втора€ увеличивает это число в 2 раза.
//Cколько существует программ, которые число 3 преобразуют в число 20 ?
//а) с использованием массива; б) с использованием рекурсии.
{
	system("cls");
	int a = 3;
	int b = 20;

	auto s = std::to_string(a);
	//CalcArr(a, b, s);
	CalcRec(a, b, s);
	cout << "\n ¬сего программ: " << counter;
	_getch();
}