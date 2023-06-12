#include "grafo_matrizadj.h"
#include <stdio.h>
#include <stdlib.h>

Grafo *criarGrafo(int num_vertices)
{
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    grafo->num_vertices = num_vertices;
    grafo->matriz_adj = (No***)malloc(num_vertices * sizeof(struct No**));

    for (int i = 0; i < num_vertices; i++)
    {
        grafo->matriz_adj[i] = (No**)malloc(sizeof(No*) * num_vertices);
        for (int j = 0; j < num_vertices; j++)
        {
            grafo->matriz_adj[i][j] = NULL;
        }
    }

    return grafo;
}

void destruirGrafo(Grafo *grafo)
{
    free(grafo);
}

void adicionarAresta(Grafo *grafo, int origem, int destino, float peso)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->destino = destino;
    novoNo->peso = peso;
    novoNo->origem = origem;

    No *novoNo2 = (No *)malloc(sizeof(No));
    novoNo2->destino = origem;
    novoNo2->peso = peso;
    novoNo2->origem = destino;

    grafo->matriz_adj[origem][destino] = novoNo;
    grafo->matriz_adj[destino][origem] = novoNo2;
}

void removerAresta(Grafo *grafo, int origem, int destino)
{
    free(grafo->matriz_adj[origem][destino]);
}

void imprimirGrafo(Grafo *grafo)
{
    for (int i = 0; i < grafo->num_vertices; i++)
    {
        for (int j = 0; j < grafo->num_vertices; j++)
        {

            if (grafo->matriz_adj[i][j] != NULL)
                printf("%.1f ", grafo->matriz_adj[i][j]->peso);
        }
        printf("\n");
    }
}

No *obterNoPelaOrigem(Grafo *grafo, int origem)
{
    for (int i = 0; i < grafo->num_vertices; i++)
    {
        if (grafo->matriz_adj[origem][i] != NULL)
            return grafo->matriz_adj[origem][i];
    }
    return NULL;
}

No *obterProxNo(Grafo *grafo, No *no)
{
    for (int i = no->destino + 1; i < grafo->num_vertices; i++)
    {
        if (grafo->matriz_adj[no->origem][i] != NULL)
            return grafo->matriz_adj[no->origem][i];
    }

    return NULL;
}