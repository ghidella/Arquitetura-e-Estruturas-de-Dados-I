#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define INVALIDO -1

typedef TIPOCHAVE;

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
    int incio;
    int dispo;
} LISTA;

void inicializarLista(LISTA* l){
    int i;
    for (i = 0; i < MAX-1; i++)
        l->A[i].prox = i + 1;
    l->A[MAX - 1].prox = INVALIDO;
    l->incio = INVALIDO;
    l->dispo = 0;
}

int tamanho(LISTA* l){
    int i = l->incio;
    int tam = 0;
    while(i != INVALIDO)
        tam++;
        i = l->A[i].prox;
    return tam;
}



void preencheLista(LISTA* l, int n){
    int i;
    for (i = 0; i < n; i++){

    }
    }

void exibirLista(LISTA* l){
    int i = l->incio;
    while (i!= INVALIDO){
        printf("%d ", l->A[i].reg.chave);
        i = l->A[i].prox;
    }
    printf("\"\n");
}

int buscaSeq(LISTA* l, int elemento){
    int i = l->incio;
    while (i != INVALIDO){
        if(l->A[i].reg.chave == elemento) return i;
        i++;
    }
    return INVALIDO;
}


int main(){
    LISTA l;

}
