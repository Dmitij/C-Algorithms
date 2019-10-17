#pragma once
void HW61() // 1. ����������� ���������� ���-�������. �� ���� ������� �������� ������, �� ������ ����� ����� ��������.
{
	system("cls");
	string str;
	int hash = 0;
	cout << "������� ������ -  ";
	cin >> str;

	for (int i = 0; i < str.length(); i++)
		hash = hash + (unsigned char)str[i];

	cout << "����� ����� �������� ������ = " << hash;


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
// ���������� ��������� ������ � ���� ��������� ������
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

// �������� ������ ����
NodeTree* getFreeNode(TT value, NodeTree* parent)
{
	NodeTree* tmp = (NodeTree*)malloc(sizeof(NodeTree));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

// ������� ����
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
		if (value > tmp->data)  //���� �������� ������, ��� �������� �������� ����
		{
			if (tmp->right)   //���� ��� ���� ������ ���� �� ������, �� �� ������ ������ ������� ������ ����� � �������� ���� �������
			{
				tmp = tmp->right;
				continue;
			}
			else  //���� ������ ����� ���, �� ��������� ���� ������
			{
				tmp->right = getFreeNode(value, tmp);
				return;
			}
		}
		else if (value < tmp->data)   //����� ������������ ����� �����
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
			printf("������!!!!!!!!!!!! �������� �� ������ ����������!");
			exit(2);                     // ������ ��������� �����������
		}
	}
}

void preOrderTravers(NodeTree* root) //����� � ������ ������� ��� � ������� � ����� � ������ 
{
	if (root)
	{
		printf("%d ", root->data);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}
void inOrderTravers(NodeTree* root) //������������ ����� ��� � ������ � ������ � ������
{
	if (root)
	{
		inOrderTravers(root->left);
		printf("%d ", root->data);
		inOrderTravers(root->right);
	}
}
void postOrderTravers(NodeTree* root) //����� � �������� ������� ��� � �������������������
{
	if (root)
	{
		postOrderTravers(root->left);
		postOrderTravers(root->right);
		printf("%d ", root->data);
	}
}


NodeTree* getMinNodeTree(NodeTree* root) //����������� ������� ������
{
	while (root->left)
		root = root->left;
	return root;
}


NodeTree* getMaxNodeTree(NodeTree* root) //������������ �������
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


void HW62() // "2. ����������� �������� ������ ������ �) �������� ����� ������ ���������� ���������; �) ����������� ����� � �������� ������ ������;\n";
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

	ShowArr(arr, size, true, "������ ������: ");
	//Bubble2(arr, size, true, "\n");			

	printf("\n������: ");
	printTree(Tree);
	printf("\n\nPreOrderTravers: ");
	preOrderTravers(Tree);
	printf("\n\nInOrderTravers: ");
	inOrderTravers(Tree);
	printf("\n\nPostOrderTravers: ");
	postOrderTravers(Tree);

	printf("\n����������� ������� �������: %d ", getMinNodeTree(Tree)->data);
	printf("\n������������ ������� �������: %d ", getMaxNodeTree(Tree)->data);
	printf("\n��������� ������� �������: %d ", getNodeTreeByValue(Tree, arr[size - 1])->data);

	_getch();
}