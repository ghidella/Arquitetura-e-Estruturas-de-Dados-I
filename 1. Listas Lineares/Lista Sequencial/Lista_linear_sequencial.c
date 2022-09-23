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

//bubble sort
void ordena(LISTA* l)
{
    int i, j;
    for (i = 0; i < l->nroElem; i++)

        for(j = 0; j < l->nroElem - i - 1; j++)
            if((l->A[j].chave > l->A[j + 1].chave))
            {
                int x;
                x = l->A[j].chave;
                l->A[j].chave = l->A[j+1].chave;
                l->A[j + 1].chave = x;
            }
}

void preencheLista(LISTA* l)
{
    printf("Elementos da lista\n");
    int i = 0;
    while(i < l->nroElem)
    {
        int elemento;
        printf("\nElemento %i: ", i+1);

        scanf("%d", &elemento);
        if(buscaElemento(l, elemento) != -1)
        {
            printf("Elemento ja existente\n");
            continue;
        }

        l->A[i].chave = elemento;
        i++;
    }
    ordena(l);
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
    if(buscaElemento(*l, elemento) != -1)
    {
        printf("Elemento ja existente\n");
        return;
    }
    l->A[l->nroElem].chave = elemento;
    l->nroElem ++;
    ordena(l);
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
            printf("O elemento existe e ocupa a posi��o: %d", buscaElemento(l, elemento));
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
