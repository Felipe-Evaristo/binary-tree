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

void *insertNode(struct Node* mainNode, int newValue)
{
	Node *newNode = createNode(newValue);

	if (newValue == mainNode->data) {
		printf("Nao e permitido incluir valores duplicados \n");
		return 0;
	}

	if (newValue > mainNode->data) {
		if (mainNode->right != NULL) {
			insertNode(mainNode->right, newValue);
		} else {
			mainNode->right = newNode;
		}
	} else {
		if (mainNode->left != NULL) {
			insertNode(mainNode->left, newValue);
		} else {
			mainNode->left = newNode;
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

				mainNode = insertNode(mainNode, data);
				break;
			default:
				printf("Digite uma opcao valida\n");
		}
	} while(1);
}
