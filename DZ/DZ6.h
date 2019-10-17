#pragma once
void HW61() // 1. Реализовать простейшую хэш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
{
	system("cls");
	string str;
	int hash = 0;
	cout << "Введите строку -  ";
	cin >> str;

	for (int i = 0; i < str.length(); i++)
		hash = hash + (unsigned char)str[i];

	cout << "Сумма кодов символов строки = " << hash;


	_getch();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef int TT;
typedef struct NodeTree
{
	TT data;
	struct NodeTree* left;
	struct NodeTree* right;
	struct NodeTree* parent;
} NodeTree;
// Распечатка двоичного дерева в виде скобочной записи
void printTree(NodeTree* root)
{
	if (root)
	{
		printf("%d", root->data);
		if (root->left || root->right)
		{
			printf("(");

			if (root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");

			if (root->right)
				printTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}

// Создание нового узла
NodeTree* getFreeNode(TT value, NodeTree* parent)
{
	NodeTree* tmp = (NodeTree*)malloc(sizeof(NodeTree));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

// Вставка узла
void insert(NodeTree** head, int value)
{
	NodeTree* tmp = NULL;
	if (*head == NULL)
	{
		*head = getFreeNode(value, NULL);
		return;
	}

	tmp = *head;
	while (tmp)
	{
		if (value > tmp->data)  //Если значение больше, чем значение текущего узла
		{
			if (tmp->right)   //Если при этом правый узел не пустой, то за корень теперь считаем правую ветвь и начинаем цикл сначала
			{
				tmp = tmp->right;
				continue;
			}
			else  //Если правой ветви нет, то вставляем узел справа
			{
				tmp->right = getFreeNode(value, tmp);
				return;
			}
		}
		else if (value < tmp->data)   //Также обрабатываем левую ветвь
		{
			if (tmp->left)
			{
				tmp = tmp->left;
				continue;
			}
			else
			{
				tmp->left = getFreeNode(value, tmp);
				return;
			}
		}
		else
		{
			printf("Алярма!!!!!!!!!!!! Элементы не должны повторятся!");
			exit(2);                     // Дерево построено неправильно
		}
	}
}

void preOrderTravers(NodeTree* root) //обход в прямом порядке КЛП – «корень – левый – правый» 
{
	if (root)
	{
		printf("%d ", root->data);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}
void inOrderTravers(NodeTree* root) //симметричный обход ЛКП – «левый – корень – правый»
{
	if (root)
	{
		inOrderTravers(root->left);
		printf("%d ", root->data);
		inOrderTravers(root->right);
	}
}
void postOrderTravers(NodeTree* root) //обход в обратном порядке ЛПК – «левый–правый–корень»
{
	if (root)
	{
		postOrderTravers(root->left);
		postOrderTravers(root->right);
		printf("%d ", root->data);
	}
}


NodeTree* getMinNodeTree(NodeTree* root) //минимальный элемент дерева
{
	while (root->left)
		root = root->left;
	return root;
}


NodeTree* getMaxNodeTree(NodeTree* root) //максимальный элемент
{
	while (root->right)
		root = root->right;
	return root;
}

NodeTree* getNodeTreeByValue(NodeTree* root, TT value)
{
	while (root)
	{
		if (root->data > value)
		{
			root = root->left;
			continue;
		}
		else if (root->data < value)
		{
			root = root->right;
			continue;
		}
		else
			return root;

	}
	return NULL;
}

int FindTheSame(int* arr, int value, int size)
{
	int z = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
			z = 1;
	}
	return z;
}


void HW62() // "2. Реализовать двоичное дерево поиска а) Добавить обход дерева различными способами; б) Реализовать поиск в двоичном дереве поиска;\n";
{
	system("cls");

	srand(time(0));
	int const size = 20;
	int rnd = 100;
	int arr[size];
	int x;
	NodeTree* Tree = NULL;
	for (int i = 0; i < size; i++)
	{
		x = rand() % rnd;
		if (FindTheSame(arr, x, i) == 0)
		{
			arr[i] = x;
			insert(&Tree, x);
		}
		else
			i--;
	}

	ShowArr(arr, size, true, "Массив данных: ");
	//Bubble2(arr, size, true, "\n");			

	printf("\nДерево: ");
	printTree(Tree);
	printf("\n\nPreOrderTravers: ");
	preOrderTravers(Tree);
	printf("\n\nInOrderTravers: ");
	inOrderTravers(Tree);
	printf("\n\nPostOrderTravers: ");
	postOrderTravers(Tree);

	printf("\nМинимальный элемент массива: %d ", getMinNodeTree(Tree)->data);
	printf("\nМаксимальный элемент массива: %d ", getMaxNodeTree(Tree)->data);
	printf("\nПоследний элемент массива: %d ", getNodeTreeByValue(Tree, arr[size - 1])->data);

	_getch();
}