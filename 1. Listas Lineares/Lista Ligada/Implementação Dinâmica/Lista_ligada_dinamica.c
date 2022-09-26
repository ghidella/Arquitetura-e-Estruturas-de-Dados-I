#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux
{
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct
{
    PONT inicio;
} LISTA;

void inicializarLista(LISTA* l)
{
    l->inicio = NULL;
}

int tamanho(LISTA* l)
{
    PONT end = l->inicio;
    int tam = 0;
    while(end != NULL)
    {
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibirLista(LISTA* l)
{
    PONT end = l->inicio;
    printf("Lista: \" ");
    while(end != NULL)
    {
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

PONT buscaSequencial(LISTA* l, TIPOCHAVE ch)
{
    if(l->inicio == NULL) return NULL; //lista vazia
    PONT pos = l->inicio;
    while(pos != NULL)
    {
        if(pos->reg.chave == ch) return pos;
        pos = pos->prox;
    }
    return NULL;
}


PONT buscaSeqOrd(LISTA* l, TIPOCHAVE ch)  // PARA LISTAS ORDENADAS APENAS
{
    PONT pos = l->inicio;
    while(pos != NULL && pos->reg.chave < ch) pos = pos->prox;
    if (pos != NULL && pos->reg.chave == ch) return pos;
    return NULL;
}


PONT buscaSequencialExc(LISTA* l, TIPOCHAVE ch, PONT* ant)
{
    *ant = NULL;
    PONT atual = l->inicio;
    while ((atual != NULL) && (atual->reg.chave < ch))
    {
        *ant = atual;
        atual = atual->prox;
    }
    if((atual != NULL) && (atual->reg.chave == ch)) return atual;
    return NULL;
}




bool inserirOrd(LISTA* l, REGISTRO reg)
{
    TIPOCHAVE ch = reg.chave;
    PONT ant, i;
    i = buscaSequencialExc(l, ch, &ant);
    if (i != NULL) return false;
    i = (PONT) malloc(sizeof(ELEMENTO));
    i->reg = reg;
    if (ant == NULL)
    {
        i->prox = l->inicio;
        l->inicio = i;
    }
    return true;

}


int main()
{

}
