#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
	struct Node *right;
	int data;
	struct Node *left;
} Node;

typedef struct ListNode
{
	int data;
	struct ListNode *next;
} ListNode;

Node *createNode(int data)
{
	Node *node = (Node *)malloc(sizeof(Node));

	node->left = NULL;
	node->data = data;
	node->right = NULL;

	return node;
}

void insertIntoRight(	Node *root,struct ListNode *listHead, int subSize);
void insertIntoLeft(	Node *root,struct ListNode *listHead, int subSize);

void *insertNode(struct Node *node, int newValue)
{
	Node *newNode = createNode(newValue);

	if (newValue == node->data)
	{
		printf("Nao e permitido incluir valores duplicados \n");
		return 0;
	}

	if (newValue > node->data)
	{
		if (node->right != NULL)
		{
			insertNode(node->right, newValue);
		}
		else
		{
			node->right = newNode;
		}
	}
	else
	{
		if (node->left != NULL)
		{
			insertNode(node->left, newValue);
		}
		else
		{
			node->left = newNode;
		}
	}
}

void preOrder(struct Node *node)
{
	printf("%d", node->data);

	if (node->left)
	{
		printf("-");
		preOrder(node->left);
	}

	if (node->right)
	{
		printf("-");
		preOrder(node->right);
	}
}

void postOrder(struct Node *node)
{
	if (node->left)
	{
		postOrder(node->left);
	}

	if (node->right)
	{
		postOrder(node->right);
	}
	printf("-");
	printf("%d", node->data);
}

void inOrder(struct Node *node)
{
	if (node->left)
	{
		inOrder(node->left);
	}

	printf("%d", node->data);
	printf("-");

	if (node->right)
	{
		inOrder(node->right);
	}
}

struct Node *findNode(struct Node *node, int value)
{
	if (node == NULL)
	{
		return NULL;
	}

	if (node->data == value)
	{
		return node;
	}

	if (value > node->data)
	{
		return findNode(node->right, value);
	}

	return findNode(node->left, value);
}

struct Node *minValueNode(struct Node *node)
{
	struct Node *current = node;

	while (current && current->left != NULL)
		current = current->left;

	return current;
}

struct Node *deleteNode(struct Node *root, int key)
{
	if (root == NULL)
		return root;

	if (key < root->data)
		root->left = deleteNode(root->left, key);

	else if (key > root->data)
		root->right = deleteNode(root->right, key);

	else
	{
		if (root->left == NULL && root->right == NULL)
			return NULL;

		else if (root->left == NULL)
		{
			struct Node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct Node *temp = root->left;
			free(root);
			return temp;
		}

		struct Node *temp = minValueNode(root->right);

		root->data = temp->data;

		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

void editNode(struct Node *node, int value)
{
	struct Node *nodeToEdit = findNode(node, value);

	if (nodeToEdit == NULL)
	{
		printf("Nao foi possivel encontrar o valor informado \n");
		return;
	}

	int newValue;
	printf("Informe o novo valor: ");
	scanf("%d", &newValue);

	nodeToEdit->data = newValue;
}

struct ListNode *createListFromTree(struct Node *root)
{
	ListNode *list = NULL;
	ListNode *current = NULL;

	if (root == NULL)
	{
		return NULL;
	}

	list = (ListNode *)malloc(sizeof(ListNode));
	list->data = root->data;
	list->next = NULL;
	current = list;

	if (root->left != NULL)
	{
		current->next = createListFromTree(root->left);
	}

	if (root->right != NULL)
	{
		current->next = createListFromTree(root->right);
	}

	return list;
}

void insertIntoRight(	Node *root,struct ListNode *listHead, int subSize)
{
	if (subSize > 0){
		int middle = (subSize / 2) + 1;

		for (int i = 0; i <= middle; i++){
			if (i == middle &&& listHead != NULL){
				insertNode(root, listHead->data);
				subSize = subSize - middle;
				insertIntoRight(root, listHead->next, subSize);
				subSize =  middle - 1;
				insertIntoLeft(root, listHead->next, subSize);
			}
			if (listHead != NULL){
				listHead = listHead->next;
			}
		}
	}
}

void insertIntoLeft(	Node *root,struct ListNode *listHead, int subSize)
{
	if (subSize > 0){
		int middle = (subSize / 2) + 1;

		for (int i = 0; i <= middle; i++){
			if (i == middle &&& listHead != NULL){
				insertNode(root, listHead->data);
				subSize = subSize - middle;
				insertIntoRight(root, listHead->next, subSize);
				subSize =  middle - 1;
				insertIntoLeft(root, listHead->next, subSize);
			}
			if (listHead != NULL){
				listHead = listHead->next;
			}
		}
	}
}

struct Node *createBalanceTreeFromList(struct ListNode *listHead)
{
	int size = 0;
	int subSize = 0;
	ListNode *aux = listHead;
	while (aux != NULL)
	{
		size++;
		aux = aux->next;
	}

	aux = listHead;
	int middle = (size / 2) + 1;


	for (int i = 1; i < middle; i++)
	{
		if (i == middle){
			Node *root = createNode(aux->data);
			subSize = size - middle;
			insertIntoRight(root, aux, subSize);
			subSize = middle - 1;
			insertIntoLeft(root, listHead, subSize);
			return root;
		}
		aux = aux->next;
	}

	return NULL;
}



int main()
{
	Node *mainNode = NULL;
	ListNode *list = NULL;
	do
	{
		printf("1. Criar arvore vazia \n");
		printf("2. Inserir elemento \n");
		printf("3. Exibir arvore em pre-ordem \n");
		printf("4. Exibir arvore em pos-ordem \n");
		printf("5. Exibir arvore em ordem simetrica \n");
		printf("6. Buscar elemento x na arvore \n");
		printf("7. Excluir elemento x da arvore \n");
		printf("8. Editar elemento x da arvore \n");
		printf("9. Balancear arvore \n");

		int option = 0;

		scanf("%d", &option);
		system("cls || clear");

		switch (option)
		{
		case 1:
			printf("Digite o valor: ");

			int data = 0;
			scanf("%d", &data);

			mainNode = createNode(data);
			break;
		case 2:
			if (mainNode == NULL)
			{
				printf("Impossivel inserir pois a arvore ainda nao foi criada");
				return 0;
			}

			printf("Digite o valor: ");

			data = 0;
			scanf("%d", &data);

			insertNode(mainNode, data);
			break;
		case 3:
			printf("Pre Ordem: \n\n");
			preOrder(mainNode);
			printf("\n");
			break;
		case 4:
			printf("Pos Ordem: \n");
			postOrder(mainNode);
			printf("\n");
			break;
		case 5:
			printf("Ordem Simétrica: \n");
			inOrder(mainNode);
			printf("\n");
			break;
		case 6:
			printf("Digite o valor do nó que deseja encontrar: ");
			data = 0;
			scanf("%d", &data);

			struct Node *node = findNode(mainNode, data);
			if (node == NULL)
			{
				printf("Nao encontrado \n");
			}
			else
			{
				printf("Node Encontrado! \n");
				printf("Filho da esquerda: %d \n", node->left->data);
				printf("Filho da direita: %d \n", node->right->data);
			}
			break;
		case 7:
			printf("Digite o valor do nO que deseja excluir: ");
			data = 0;
			scanf("%d", &data);

			mainNode = deleteNode(mainNode, data);
			break;
		case 8:
			printf("Digite o valor do nO que deseja editar: ");
			data = 0;
			scanf("%d", &data);

			break;
		case 9:
			// list = createListFromTree(mainNode);
			// mainNode = createBalanceTreeFromList(list);
			// printf("Arvore balanceada com sucesso! \n");
			break;
		default:
			printf("Digite uma opcao valida\n");
		}
	} while (1);
}
