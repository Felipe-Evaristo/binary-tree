#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node *right;
	int data;
	struct Node *left;
} Node;

Node *createNode(int data)
{
	Node *node = (Node *)malloc(sizeof(Node));

	node->left = NULL;
	node->data = data;
	node->right = NULL;

	return node;
}

void *insertNode(struct Node* node, int newValue)
{
	Node *newNode = createNode(newValue);

	if (newValue == node->data) {
		printf("Nao e permitido incluir valores duplicados \n");
		return 0;
	}

	if (newValue > node->data) {
		if (node->right != NULL) {
			insertNode(node->right, newValue);
		} else {
			node->right = newNode;
		}
	} else {
		if (node->left != NULL) {
			insertNode(node->left, newValue);
		} else {
			node->left = newNode;
		}
	}
}

void pre(struct Node* node)
{
	printf("%d", node->data);

	if (node->left) {
		printf("-");
		pre(node->left);
	}

	if (node->right) {
		printf("-");
		pre(node->right);
	}
}

void post(struct Node* node)
{
	if (node->left) {
		pre(node->left);
	} else {
		if (node->right) {
			pre(node->right);
		} else {
			printf("-");
			printf("%d", node->data);
		}
	}
}

int main()
{
	Node *mainNode = NULL;

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

		switch(option)
		{
			case 1:
				printf("Digite o valor: ");

				int data = 0;
				scanf("%d", &data);

				mainNode = createNode(data);
				break;
			case 2:
				if (mainNode == NULL) {
					printf("Impossivel inserir pois a arvore ainda nao foi criada");
					return 0;
				}

				printf("Digite o valor: ");

				data = 0;
				scanf("%d", &data);

				insertNode(mainNode, data);
				break;
			case 3:
				printf("Pre Ordem: ");
				pre(mainNode);
				printf("\n");
				break;
			case 4:
				printf("Pos Ordem: ");
				post(mainNode);
				printf("\n");
				break;
			default:
				printf("Digite uma opcao valida\n");
		}
	} while(1);
}
