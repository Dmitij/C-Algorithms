#pragma once
using namespace std;


typedef char CH;
typedef struct Stack_tag 
{
	CH Data[100];
	size_t StSize;
} Stack_t;


Stack_t stack7;
Stack_t list7;



void push7(Stack_t* stack, const CH value)
{
	stack->Data[stack->StSize] = value;
	stack->StSize++;
}

CH pop7(Stack_t* stack)
{
	stack->StSize--;
	return stack->Data[stack->StSize];
}



void printStackValue(const CH value) 
{
	printf("%c", value);
}

void printStack(const Stack_t* stack, void (*printStackValue)(const CH), string str)
{
	int i;
	int len = stack->StSize - 1;
	cout << str << stack->StSize;
	for (i = 0; i < len; i++) 	
	{
		printStackValue(stack->Data[i]);
		printf(" | ");
	}
	if (stack->StSize != 0)	
		printStackValue(stack->Data[i]);
	
	printf("\n");
}


int CharToIndex(char ch, char* arr, int size )  //������� ������ �������
{	
	for (int index = 0; index < size; index++)
	{
		if (arr[index] == ch)
		{
			return index;
			break;
		}
	}
}




void AddToStack(char ch, char* tops, int size, int matrix[])
{
	push7(&list7, ch);
	int top = CharToIndex(ch, tops, size);

	for (int i = 0; i < size ; i++)
	{
		if (matrix[size * top + i] > 0)//	�������� � ���� ��� �������, ������� �� ���������
		{					
			push7(&stack7, tops[i]);			
		}
	}
	printStack(&stack7, printStackValue, " stack > ");
	printStack(&list7, printStackValue, " list > ");	
}
bool CheckList( char ch)
{
	for (int i = 0; i < list7.StSize; i++)		
		if (list7.Data[i] == ch)
			return true;
		
	return false;
}

void HW71()//1. �������� ������� ������ ����� � �������.
{
	system("cls");

	srand(time(0));
	int const size = 5;
	int rnd = 2;
	int matrix[size][size];   //������� ���������
	char tops[size];         //�������
	

	cout << "   "; 
	for (int i = 0; i < size; i++)
	{
		cout << (char)(65 + i) << " ";
		tops[i] = (char)(65 + i);
	}
	cout << "\n ";

	//int matrix[size][size] = { {1, 1, 0}, {1, 0, 0}, {0, 0, 0} };

	

	for (int i = 0; i < size; i++) // �������� �������
	{
		cout << (char)(65 + i) << " ";
		for (int j = 0; j < size; j++)
		{			
			matrix[i][j] = rand() % rnd;
			cout << matrix[i][j] << " ";
		}
		cout << "\n ";
	}
		
	

	//����� � �������
	//	����� � ������� ���������� ��� ��������� � ���� ��� ����������� ��� �� ������������ ������ � ������ ��� ����������� ��� ������������.
	stack7.StSize = 0;
	
	
	
													//����� ����������� ��������� ������� :
													//������ ��������� �������(������ �������� ������� ��� ������ ������)	
													//	���������� ��������� ������� � �������� �� �� ��������������� ������ ������������ ������	
	AddToStack('B',tops, size, &matrix[0][0]);		//	�������� � ���� ��� �������, ������� �� ���������	
	
	while (stack7.StSize > 0)							//	������������ ���� �� ������� ����������� ����� � ������ ����� ��������� :
	{
														//������� �� ����� ��������� �������		
		char stacktop = pop7(&stack7);					 //������� ������� �����
														//	��������� �� ���������������� ������ �������������� ���� �������		
		if (CheckList(stacktop) == false)						//	���� ������� ��� �� ����������, �� ���������� �� � ��������� � ������ ������������ ������
			AddToStack(stacktop, tops, size, &matrix[0][0]);
																//	���� ������� ��� ����������, �� ������� �� ����� ��������� �������	
																//	����������� ���� ������ ������� � ��� ������ � ��������� � ���� ��� ��� �� ������������ �������
	}


	//printStack(&stack7, printStackValue, "stack > ");
	printStack(&list7, printStackValue, " ������ ������ � ������� - ");
	//for (int i = 0; i < list7.StSize+1; i++)
	//{
	//	pop7(&list7);
	//}	
	//free(&list7);





	_getch();
}


void HW72()//2. �������� ����������� ������� ������ ����� � ������.
{
	system("cls");
	
	//�������� ������� �� ������� : ������� �������������� ��� �������, ������� � �������, � ���� ����� � �� �������.
	//������ ����� ��� ����������� ��� �� ������������ ������ ������������ �������.
	//������ ��������� �������(������ �������� ������� ��� ������ ������)
	//	���������� ��������� ������� � �������� �� �� ��������������� ������ ������������ ������
	//	�������� � ������� ��� �������, ������� �� ���������
	//	������������ ���� �� ������� ����������� ������� � ������ ����� ��������� :
	//������� �� ������� ��������� �������
	//	��������� �� ���������������� ������ �������������� ���� �������
	//	���� ������� ��� ����������, �� ������� �� ������� ��������� �������
	//	���� ������� ��� �� ����������, �� ���������� �� � ��������� � ������ ������������ ������
	//	����������� ���� ������ ������� � ��� ������ � ��������� � ������� ��� ��� �� ������������ �������

	_getch();
}