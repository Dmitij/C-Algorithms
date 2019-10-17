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

void HW51() // 	 "1. �������� ���������, ������� ����������, �������� �� ��������� ��������� ������������������ ����������. ������� ���������� ��������� ���������: (), ([])(), {}(), ([{}]), ������������ � )(, ())({), (, ])}), ([(]) ��� ������ [,(,{.	��������: (2 + (2 * 2)) ���[2 / {5 * (4 + 7)}].\n";		
{
	system("cls");

	char buf[BUFSIZ];
	printf("������� ������: ");
	fgets(buf, BUFSIZ, stdin);
	printf("%s\n", (*brackets_check(buf)) ? "������������������ ������������" : "������������������ ����������");


	cin.get();
}


#define T char
// ������ ��������� ���� ������
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
//	// ��������� ���������
//	Node* next = NULL;
//	// �������� �������� ������
//	T value;
//	value = Stack.head->value;
//	next = Stack.head;
//	Stack.head = Stack.head->next;
//	// ������, �� ������� ��������� �������, �������, ���������� ������
//	free(next);
//	// ���������� ��������, ������� ���� � �������
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

//void CopyStack()                   //������� ����������� ������
//{
//	Node* current = Stack.head;
//	while (current != NULL)
//	{
//		printf("%c ", current->value);
//		current = current->next;
//	}
//}
//struct element                      //��������� � ���������� � �������� �����
//{
//	int x;                             //��������. �������� �� x ����� ������������ � ������
//	element* Next;                     //�������� ���� (����� ���������� ��������)
//};
//
//class List                      //����� ������
//{
//	element* Head;                 //��������� �� ��������� �������� ������� ��� ������ ������ ������
//public:
//	List() { Head = NULL; }           //����������� � ������������� ��������� ������ ���������
//	~List();                       //����������. ����� �� ������� �� �����
//	void Add(int x);               //������� ��� ���������� �������� � ������
//	void Show(string str);                   //������� ��� ����������� ������ �� ������	
//};
//
//List::~List()                   //���������� ������� �� �����
//{
//	while (Head != NULL)          //���� �� ������ �� �����
//	{
//		element* temp = Head->Next;   //��������� ���������� ��� �������� ������ ���������� ��������
//		delete Head;                //����������� ����� ������������ ������
//		Head = temp;                  //������ ����� �� ���������
//	}
//}
//
//void List::Add(int x) //������� ���������� ��������� � ������
//{
//	element* temp = new element;           //��� ������ ������ ���������� ������
//	temp->x = x;                            //���������� x � ������� ���������  element (� x ��������� element)
//	temp->Next = Head;                      //���������, ��� ����. ������� ��� ������ �� ������ Head
//	Head = temp;                            //���������, ��� ��������� �������� ������� ��� ������ ��� ���������
//}
//
//
//
//void List::Show(string str)                       //������� ����������� ������ �� ������
//{
//	element* temp = Head;                 //���������� ���������, ������� ���������� �� ����� ������ ������ ������
//
//	cout << "\n" << str;
//	while (temp != NULL)                   //�� ��� ��� ���� �� �������� ������ ��������
//	{
//		cout << temp->x << " ";               //������� ������� x �� ������
//		temp = temp->Next;                    //���������, ��� ����� ��� ����� ��������� �������
//	}
//}



void HW52() // "2. * ������� �������, ���������� ����������� ������(�� ���� ������� � ������ ����� ������������ ������, ��� �������� ������� ������).\n";
{
	system("cls");  //http://ci-plus-plus-snachala.ru/?p=57

	int N;                        //����� ��������� � ������
	char x;                        //�������� �������� � ������
	//List lst;                     //����������, ��� ������� ������
	//List lst2;
	//List lst3;

	//cout << "N = ";
	//cin >> N;                    //������� ������� ��������� ������� � ������

	//for (int i = 0; i < N; i++)
	//{
	//	cout << i + 1 << ". x = ";
	//	cin >> x;             //���� x � ����������
	//	lst.Add(x);           //���������� �������� � ������
	//}

	//lst.Show("��������� ������: "); 				//����� ������ �� �����	

	//lst2 = lst;
	//lst2.Show("������������� ������: ");

	//ListCopy(lst);
	struct Stack Stack;
	struct Stack Stack2;

	cout << "����� ��������� ������ N = ";
	cin >> N;
	Stack.maxSize = N;
	Stack.head = NULL;



	for (int i = 0; i < N; i++)
	{
		cout << i + 1 << ". x = ";
		cin >> x;             //���� x � ����������
		push(x, Stack);           //���������� �������� � ������
	}

	PrintStack(Stack);



	cin.ignore().get();
}