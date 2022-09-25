#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50
#define INVALIDO -1

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    REGISTRO reg;
    int prox;
} ELEMENTO;

typedef struct
{
    ELEMENTO A[MAX];
    int inicio;
    int dispo;
} LISTA;

void inicializarLista(LISTA* l)
{
    int i;
    for (i = 0; i < MAX-1; i++)
        l->A[i].prox = i + 1;
    l->A[MAX - 1].prox = INVALIDO;
    l->inicio = INVALIDO;
    l->dispo = 0;
}

int tamanho(LISTA* l)
{
    int i = l->inicio;
    int tam = 0;
    while(i != INVALIDO)
        tam++;
    i = l->A[i].prox;
    return tam;
}



void preencheLista(LISTA* l, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {

    }
}

void exibirLista(LISTA* l)
{
    int i = l->inicio;
    while (i!= INVALIDO)
    {
        printf("%d ", l->A[i].reg.chave);
        i = l->A[i].prox;
    }
    printf("\"\n");
}

int obterNo(LISTA* l)
{
    int resultado = l->dispo;
    if (l->dispo != INVALIDO)
        l->dispo = l->A[l->dispo].prox;
    return resultado;
}


int buscaSeq(LISTA* l, int ch) //listas ordenadas
{
    int i = l->inicio;
    while (i != INVALIDO && l->A[i].reg.chave < ch)
    {
        i = l->A[i].prox;
    }
    if (i != INVALIDO && l->A[i].reg.chave == ch) return i;
    return INVALIDO;
}

bool inserirOrd(LISTA* l, REGISTRO reg)
{
    if (l->dispo == INVALIDO) return false;
    int i = l->inicio;
    int ant = INVALIDO;
    TIPOCHAVE ch = reg.chave;
    //l->A[l->dispo] = reg.chave;
    //l->dispo = obterNo(l);

    while (i != INVALIDO && l->A[i].reg.chave < reg.chave)
    {
        ant = i;
        i = l->A[i].prox;
    }
    if (i != INVALIDO && l->A[i].reg.chave == ch) return false; //sem elementos iguais
    i = obterNo(l);
    l->A[i].reg = reg;
    if (ant == INVALIDO)
    {
        l->A[i].prox = l->inicio;
        l->inicio = i;
    }
    else
    {
        l->A[i].prox = l->A[ant].prox;
        l->A[ant].prox = i;
    }
    return true;
}

void devolverNO(LISTA* l, int j)
{
    l->A[j].prox = l->dispo;
    l->dispo = j;
}

bool excluirElemento(LISTA* l, REGISTRO reg)
{
    int i = l->inicio;
    int ant = INVALIDO;
    TIPOCHAVE ch = reg.chave;
    while(i != INVALIDO && l->A[i].reg.chave < ch)
    {
        ant = i;
        i = l->A[i].prox;
    }
    if(i == INVALIDO || l->A[i].reg.chave != ch) return false;
    if(ant == INVALIDO) l->inicio = l->A[i].prox;
    else l->A[ant].prox = l->A[i].prox;
    devolverNO(l, i);
    return true;
}

void reinicializarLista(LISTA* l)
{
    inicializarLista(l);
}




int main()
{
    LISTA l;

}
