#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 50


typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;

} REGISTRO;

typedef struct
{
    REGISTRO A[MAX];
    int nroElem;
} LISTA;

void inicializaLista(LISTA* l, int n)
{
    l->nroElem = n;
}

void preencheLista(LISTA* l)
{
    printf("Elementos da lista\n");
    for(int i = 0; i < l->nroElem; i++)
    {
        int elemento;
        printf("\nElemento %i: ", i+1);

        scanf("%d", &elemento);
        l->A[i].chave = elemento;
        fflush(stdin);
    }
}

void opcoes()
{
    printf("\n\n\n");
    printf("(0) Tamanho da lista\n");
    printf("(1) Exibir os elementos\n");
    printf("(2) Buscar elemento\n");
    printf("(3) Inserir elemento\n");
    printf("(4) Excluir elemento\n");
    printf("(5) Reinicializar estrutura\n");
    printf("(6) Encerrar\n");
}

int tamanhoLista(LISTA l)
{
    return l.nroElem;
}

void exibeLista(LISTA l)
{
    for(int i = 0; i < l.nroElem; i++)
    {
        printf("%i ", l.A[i].chave);
    }
    printf("\n");
}

int buscaElemento(LISTA l, TIPOCHAVE elemento)
{
    for(int i = 0; i < l.nroElem; i++)
    {
        if(l.A[i].chave == elemento)
        {
            return i;
        }
    }
    return -1;
}

void inserirElemento(LISTA* l, int elemento)
{
    l->A[l->nroElem].chave = elemento;
    l->nroElem ++;

}

int main()
{
    LISTA l;
    int tamanho;
    printf("Tamanho da lista: \n");
    scanf("%d", &tamanho);
    inicializaLista(&l, tamanho);
    preencheLista(&l);
    system("cls");
    bool exit = false;
    while(!exit)
    {
        opcoes();
        int escolha;
        scanf("%d", &escolha);
        if(escolha == 0)
        {
            system("cls");
            printf("Tamanho da Lista: %d\n\n", tamanhoLista(l));
        }
        else if(escolha == 1)
        {
            system("cls");
            exibeLista(l);
            printf("\n\n");
        }
        else if(escolha ==2)
        {
            system("cls");
            printf("Qual elemento deseja buscar:");
            TIPOCHAVE elemento;
            scanf("%d", &elemento);
            printf("\n\n");
            if(buscaElemento(l, elemento) == -1)
            {
                printf("Nao existe");
                continue;
            }
            printf("O elemento existe e ocupa a posição: %d", buscaElemento(l, elemento));
        }
        else if(escolha == 3)
        {
            system("cls");
            printf("Adicionar: \n");
            int elemento;
            scanf("%d", &elemento);
            inserirElemento(&l, elemento);
        }
        else if(escolha == 6)
        {
            exit = true;
        }


    }
    return 0;
}
