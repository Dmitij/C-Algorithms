#pragma once


int counter;

void dec_to_bin(int n)
{
	if (n >= 2)
		dec_to_bin(n / 2);
	cout << n % 2;
}
void HW21()//1. ����������� ������� �������� �� 10 ������� � �������� ��������� ��������.
{
	system("cls");
	int n;
	cout << "\n ������� ����� ����� ";
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
double pow1(int a, int b)//a.��� ��������;
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
double pow2(int a, int b)//b.����������
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
double pow3(int a, int b)//c.* ����������, ��������� �������� �������� �������.
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
void HW22()//2. ����������� ������� ���������� ����� a � ������� b :;
{
	system("cls");
	double c;
	int a, b;

	cout << "������� ����� ����� a ";
	cin >> a;
	cout << "������� ����� ����� b ";
	cin >> b;


	c = pow1(a, b);
	cout << "\n (a) ��� �������� a^b=" << c;

	c = pow2(a, b);
	cout << "\n (b) ���������� a^b=" << c;

	c = pow3(a, b);
	cout << "\n (c)* ����������, ��������� �������� �������� ������� a^b=" << c;

	_getch();

}




static void CalcArr(int a, int b, string str)
{


	//	// ���������� ���������� ������������� ������� �� 10 ���������:
	//	float** ptrarray = new float* [2]; // ��� ������ � �������
	//	for (int count = 0; count < 2; count++)
	//		ptrarray[count] = new float[5]; // � ���� ��������
	////  ��� ptrarray  � ������ ���������� �� ���������� ������� ������ ��� ������ ������������ �����  ���� float


	//for (int dimm = 3; dimm = 16; dimm++)
	//{
	//	int flag = 0;
	//	int** ptrarray = new int* [dimm]; //  ������ � �������
	//	for (int count = 0; count < 2; count++)
	//		ptrarray[count] = new int[17]; // �������
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

	//// ������������� ������ ��������� ��� ��������� ������������ ������:
	//for (int count = 0; count < 2; count++)
	//	delete[] ptrarray[count];
	////      ��� 2 � ���������� ����� � �������
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
			CalcRec(a, b, s); //��������������� � ����������� a �� 1 ��� � 2 ����
		if (a == b)
		{
			counter++;
			cout << "\n " + s + "=" << b; //������� ������ ����� ����� a = b =20	

		}
	}

}
void HW23()//3. ����������� ����������� ����������� ����� �����, ���������� �� ������.� ����������� ��� �������, ������ ������� �������� ����� :
//������� 1 2.������ �� 2 ������ ������� ����������� ����� �� ������ �� 1, ������ ����������� ��� ����� � 2 ����.
//C������ ���������� ��������, ������� ����� 3 ����������� � ����� 20 ?
//�) � �������������� �������; �) � �������������� ��������.
{
	system("cls");
	int a = 3;
	int b = 20;

	auto s = std::to_string(a);
	//CalcArr(a, b, s);
	CalcRec(a, b, s);
	cout << "\n ����� ��������: " << counter;
	_getch();
}