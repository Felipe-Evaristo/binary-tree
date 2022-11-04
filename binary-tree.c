#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 

struct no
{
    struct no *direita;
    int valor;
    struct no *esquerda;
};
struct no *no

struct no *novoNo(int data)
{
    struct no *no = (struct no *)malloc(sizeof(struct no));

    no->esquerda = NULL;
    no->valor = valor;
    no->direita = NULL;

    return node;
}

void criarArvoreVazia()
{
	
	

}

int main(void)
{
	setlocale(LC_ALL,'PORTUGUESE');

    int continuar=1;

    do
    {
        printf("\n\t Árvore Binária \n\n");
        printf("1. Criar Árvo Vazia\n");
        printf("2. criar novo nó\n");
        printf("0. Sair\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch(continuar)
        {
            case 1:
                criarArvoreVazia();
                break;

            case 2:
                novoNo();
                break;

            case 0:
                break;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(continuar);
}



