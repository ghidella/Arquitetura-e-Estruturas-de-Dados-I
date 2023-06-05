#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No
{
    int destino;
    float altura;
    struct No *prox;
} No;

typedef struct
{
    int num_vertices;
    No **lista_adj;
} GrafoListaAdj;

GrafoListaAdj *criarGrafo(int num_vertices)
{
    GrafoListaAdj *grafo = (GrafoListaAdj *)malloc(sizeof(GrafoListaAdj));
    grafo->num_vertices = num_vertices;

    grafo->lista_adj = (No **)malloc(num_vertices * sizeof(No *));
    int i;
    for (i = 0; i < num_vertices; i++)
    {
        grafo->lista_adj[i] = NULL;
    }

    return grafo;
}

void destruirGrafo(GrafoListaAdj *grafo)
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

void adicionarAresta(GrafoListaAdj *grafo, int origem, int destino)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->destino = destino;
    novoNo->prox = grafo->lista_adj[origem];
    grafo->lista_adj[origem] = novoNo;

    novoNo = (No *)malloc(sizeof(No));
    novoNo->destino = origem;
    novoNo->prox = grafo->lista_adj[destino];
    grafo->lista_adj[destino] = novoNo;
}

void removerAresta(GrafoListaAdj *grafo, int origem, int destino)
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

int verificarAdjacencia(GrafoListaAdj *grafo, int origem, int destino)
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

void imprimirGrafo(GrafoListaAdj *grafo)
{
    int i;
    for (i = 0; i < grafo->num_vertices; i++)
    {
        No *atual = grafo->lista_adj[i];
        printf("Vértice %d: ", i);
        while (atual != NULL)
        {
            printf("%d ", atual->destino);
            atual = atual->prox;
        }
        printf("\n");
    }
}
