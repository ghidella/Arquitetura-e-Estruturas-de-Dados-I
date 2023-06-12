#include <stdio.h>
#include <stdlib.h>
#include "grafo_listaadj.h"

Grafo *criarGrafo(int num_vertices)
{
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    grafo->num_vertices = num_vertices;

    grafo->lista_adj = (No **)malloc(num_vertices * sizeof(No *));
    int i;
    for (i = 0; i < num_vertices; i++)
    {
        grafo->lista_adj[i] = NULL;
    }

    return grafo;
}

void destruirGrafo(Grafo *grafo)
{
    int i;
    for (i = 0; i < grafo->num_vertices; i++)
    {
        No *atual = grafo->lista_adj[i];
        while (atual != NULL)
        {
            No *proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
    }
    free(grafo->lista_adj);
    free(grafo);
}

void adicionarAresta(Grafo *grafo, int origem, int destino, float peso)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->destino = destino;
    novoNo->peso = peso;
    novoNo->prox = grafo->lista_adj[origem];
    grafo->lista_adj[origem] = novoNo;

    novoNo = (No *)malloc(sizeof(No));
    novoNo->destino = origem;
    novoNo->peso = peso;
    novoNo->prox = grafo->lista_adj[destino];
    grafo->lista_adj[destino] = novoNo;
}

void removerAresta(Grafo *grafo, int origem, int destino)
{
    No *atual = grafo->lista_adj[origem];
    No *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->destino == destino)
        {
            if (anterior == NULL)
            {
                grafo->lista_adj[origem] = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }
            free(atual);
            break;
        }

        anterior = atual;
        atual = atual->prox;
    }

    atual = grafo->lista_adj[destino];
    anterior = NULL;

    while (atual != NULL)
    {
        if (atual->destino == origem)
        {
            if (anterior == NULL)
            {
                grafo->lista_adj[destino] = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }
            free(atual);
            break;
        }

        anterior = atual;
        atual = atual->prox;
    }
}

int verificarAdjacencia(Grafo *grafo, int origem, int destino)
{
    No *atual = grafo->lista_adj[origem];

    while (atual != NULL)
    {
        if (atual->destino == destino)
        {
            return 1;
        }
        atual = atual->prox;
    }

    return 0;
}

void imprimirGrafo(Grafo *grafo)
{
    int i;
    for (i = 0; i < grafo->num_vertices; i++)
    {
        No *atual = grafo->lista_adj[i];
        printf("Vértice %d: ", i);
        while (atual != NULL)
        {
            printf("%d (%.2f) ", atual->destino, atual->peso);
            atual = atual->prox;
        }
        printf("\n");
    }
}

float obterPesoAresta(Grafo *grafo, int origem, int destino)
{
    Grafo *g = (Grafo *)grafo;
    No *atual = g->lista_adj[origem];
    while (atual != NULL)
    {
        if (atual->destino == destino)
        {
            return atual->peso;
        }
        atual = atual->prox;
    }
    return 0;
}

No *obterNoPelaOrigem(Grafo *grafo, int origem)
{
    if (!grafo->lista_adj[origem])
    {
        return NULL;
    }
    return grafo->lista_adj[origem];
}

No *obterProxNo(Grafo *grafo, No *atual)
{
    if (!grafo)
        return NULL;
    return atual->prox;
}
