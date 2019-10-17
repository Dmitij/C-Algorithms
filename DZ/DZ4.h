#pragma once
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

void HW41() // "1. *���������� ��������� � �������������. ����������� ������ ������� � ������������ � ���������� ���������� ���������.\n";
{
	system("cls");

	int A[N][M];
	int i, j;


	//for (j = 0; j < M; j++)
	//	A[0][j] = 1; // ������ ������ ��������� ���������
	//for (i = 1; i < N; i++)
	//{
	//	A[i][0] = 1;// ������ ������� �������� ���������
	//	for (j = 1; j < M; j++)
	//	{
	//		A[i][j] = A[i][j - 1] + A[i - 1][j];
	//	}
	//}
	//Print2(N, M, A);

	A[0][0] = 1;  //������ ������ ������ ����� 1

	A[0][3] = 0;//�����������
	A[3][0] = 0;//�����������
	A[1][1] = 0;//�����������
	A[4][5] = 0;//�����������

	for (j = 1; j < M; j++) //��������� ������ ������			
		if ((A[0][j] == 0) || A[0][j - 1] == 0)
			A[0][j] = 0;
		else
			A[0][j] = 1;

	for (j = 1; j < N; j++) //��������� ������ �������
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

void HW42() // 	 "3. ***��������� ������ ���� ��������� ����� �������� NxM, ������ ����� ��� ���� ����� �� ������ ����.\n";		
{
	system("cls");
	const int n = 4;
	const int m = 4;
	int arr[n][m];


	for (int i = 0; i < n; i++)  //��������� ��� ������ ������
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = 0;
		}
	}



	cin.get();
}