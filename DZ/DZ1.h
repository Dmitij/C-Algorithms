#pragma once
using namespace std;


void HW11()//1. ������ ��� � ���� ��������.���������� � ������� ������ ����� ���� �� ������� I = m / (h * h); ��� m - ����� ���� � �����������, h - ���� � ������.
{
	float m, h, I;

	system("cls");       // ������� ���� �������
	printf("������� ���: "); // ������� ���������
	scanf_s("%f", &m);
	printf("������� ����: ");
	scanf_s("%f", &h);
	I = m / (h * h);
	printf("������ ����� ���� I=%f", I);
	cin.get();
}
void HW12() //3. �������� ��������� ������ ���������� ���� ������������� ���������� : b. * ��� ������������� ������� ����������.
{
	int a, b, c;
	system("cls");
	printf("�������: a, b: \n");
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
void HW13()//4. �������� ��������� ���������� ������ ��������� ����������� ���������.
{
	system("cls");
	float a, b, c;
	printf("�������: a, b, c: \n");
	scanf_s("%f %f %f", &a, &b, &c);
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				printf("x = ����� �����");
			}
			else
			{
				printf("��� ������");
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
			printf("��� ������");
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
void HW14()//6. ������ ������� ��������(�� 1 �� 150 ���) � ������� ��� ������ � ����������� ������ ����, ����� ��� ����.
{
	int a, b;
	system("cls");
	printf("������� ��� ������� ������\n");
	scanf_s("%d", &a);
	b = a;
	if (((a > 10) && (a < 21)) || ((a > 110) && (a < 121)))
	{
		printf("��� %d ���", a);
	}
	else
	{
		b = b % 10;
		if (b == 1)
		{
			printf("��� %d ���", a);
		}
		if ((b == 0) || ((b > 4) && (b < 10)))
		{
			printf("��� %d ���", a);
		}
		if ((b > 1) && (b < 5))
		{
			printf("��� %d ����", a);
		}
	}
	cin.get();
}
void HW15()//7. ������� �������� ���������� ���� ����� ��������� �����(x1, y1, x2, y2).��������� ����������, ��������� �� � ���� � ������ ����� ��� ���.
{
	int x1, y1, x2, y2, flag1, flag2;
	system("cls");
	printf("������� ���������� x1,y1 \n");
	scanf_s("%d %d", &x1, &y1);
	printf("������� ���������� x2,y2 \n");
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
		printf("���� ������ �����");
	}
	else
	{
		printf("���� ������� �����");
	}
	cin.get();
}
void HW16()//9. ���� ����� ������������� ����� N � K.��������� ������ �������� �������� � ���������, ����� ������� �� ������� ������ N �� K, � ����� ������� �� ����� �������.
{
	int n, k, ostatok, chastnoe;
	system("cls");
	printf("������� ����� ������������� ����� N > K \n");
	scanf_s("%d %d", &n, &k);

	chastnoe = 0;
	do
	{
		chastnoe = chastnoe + 1;
		n = n - k;
	} while (n >= k);


	ostatok = n;

	printf("������� = %d ", chastnoe);
	printf("������� = %d ", ostatok);
	cin.get();
}
void HW17()//10. ���� ����� ����� N(> 0).� ������� �������� ������� ������ � ������ ������� �� ������� ����������, ������� �� � ������ ����� N �������� �����.���� �������, �� ������� True, ���� ��� � ������� False.
{
	int N = 1;
	system("cls");
	printf("������� ����� ������������� ����� N \n");
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
void HW18()//14. * ����������� �����.����������� ����� ���������� �����������, ���� ��� ����� ��������� ������ ������ ��������.��������, 25 \ :sup: 2 = 625. �������� ���������, ������� ������� �� ����� ��� ����������� �����, � �������� 1_000_000
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
void HW19()//15. �������� ������� �� ��������� ��������� � �����))";
{
	system("cls");
	int count = -1;
	double grade = 0, sum = 0;
	cout << "������� ������, ���� ������� ������� -1\n";
	while (grade != -1)
	{
		sum += grade;
		count++;
		cin >> grade;
	}
	std::cout << "������� ������: " << sum / count;
	cin.get();
}