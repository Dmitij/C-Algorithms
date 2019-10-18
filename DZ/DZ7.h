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


int CharToIndex(char ch, char* arr, int size )  //находим индекс вершины
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
		if (matrix[size * top + i] > 0)//	включить в стек все вершины, смежные со стартовой
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

void HW71()//1. Написать функцию обхода графа в глубину.
{
	system("cls");

	srand(time(0));
	int const size = 5;
	int rnd = 2;
	int matrix[size][size];   //матрицы смежности
	char tops[size];         //вершины
	

	cout << "   "; 
	for (int i = 0; i < size; i++)
	{
		cout << (char)(65 + i) << " ";
		tops[i] = (char)(65 + i);
	}
	cout << "\n ";

	//int matrix[size][size] = { {1, 1, 0}, {1, 0, 0}, {0, 0, 0} };

	

	for (int i = 0; i < size; i++) // печатаем матрицу
	{
		cout << (char)(65 + i) << " ";
		for (int j = 0; j < size; j++)
		{			
			matrix[i][j] = rand() % rnd;
			cout << matrix[i][j] << " ";
		}
		cout << "\n ";
	}
		
	

	//Обход в глубину
	//	Поиск в глубину использует две структуры – стек для запоминания еще не обработанных вершин и список для запоминания уже обработанных.
	stack7.StSize = 0;
	
	
	
													//Поиск выполняется следующим образом :
													//задать стартовую вершину(аналог корневой вершины при обходе дерева)	
													//	обработать стартовую вершину и включить ее во вспомогательный список обработанных вершин	
	AddToStack('B',tops, size, &matrix[0][0]);		//	включить в стек все вершины, смежные со стартовой	
	
	while (stack7.StSize > 0)							//	организовать цикл по условию опустошения стека и внутри цикла выполнить :
	{
														//извлечь из стека очередную вершину		
		char stacktop = pop7(&stack7);					 //верхний елемент стека
														//	проверить по вспомогательному списку обработанность этой вершины		
		if (CheckList(stacktop) == false)						//	если вершина еще не обработана, то обработать ее и поместить в список обработанных вершин
			AddToStack(stacktop, tops, size, &matrix[0][0]);
																//	если вершина уже обработана, то извлечь из стека следующую вершину	
																//	просмотреть весь список смежных с нею вершин и поместить в стек все еще не обработанные вершины
	}


	//printStack(&stack7, printStackValue, "stack > ");
	printStack(&list7, printStackValue, " Список обхода в глубину - ");
	//for (int i = 0; i < list7.StSize+1; i++)
	//{
	//	pop7(&list7);
	//}	
	//free(&list7);





	_getch();
}


void HW72()//2. Написать рекурсивную функцию обхода графа в ширину.
{
	system("cls");
	
	//Работает немного по другому : сначала обрабатываются все вершины, смежные с текущей, а лишь потом – их потомки.
	//Вместо стека для запоминания еще не обработанных вершин используется очередь.
	//задать стартовую вершину(аналог корневой вершины при обходе дерева)
	//	обработать стартовую вершину и включить ее во вспомогательный список обработанных вершин
	//	включить в очередь все вершины, смежные со стартовой
	//	организовать цикл по условию опустошения очереди и внутри цикла выполнить :
	//извлечь из очереди очередную вершину
	//	проверить по вспомогательному списку обработанность этой вершины
	//	если вершина уже обработана, то извлечь из очереди следующую вершину
	//	если вершина еще не обработана, то обработать ее и поместить в список обработанных вершин
	//	просмотреть весь список смежных с нею вершин и поместить в очередь все еще не обработанные вершины

	_getch();
}