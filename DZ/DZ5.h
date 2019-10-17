#pragma once
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