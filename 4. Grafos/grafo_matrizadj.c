#include "grafo_matrizadj.h"
#include <stdio.h>
#include <stdlib.h>

GrafoMatrizAdj *criarGrafo(int num_vertices)
{
    GrafoMatrizAdj *grafo = (GrafoMatrizAdj *)malloc(sizeof(GrafoMatrizAdj));

    if (grafo == NULL)
    {
        printf("Erro: falha ao alocar memória para o grafo\n");
        return NULL;
    }

    grafo->num_vertices = num_vertices;

    // Inicializa a matriz de adjacência com zeros
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            grafo->matriz_adj[i][j] = 0;
        }
    }

    return grafo;
}

void destruirGrafo(GrafoMatrizAdj *grafo)
{
    free(grafo);
}

void adicionarAresta(GrafoMatrizAdj *grafo, int origem, int destino)
{
    if (origem < 0 || origem >= grafo->num_vertices || destino < 0 || destino >= grafo->num_vertices)
    {
        printf("Erro: vértices inválidos\n");
        return;
    }

    grafo->matriz_adj[origem][destino] = 1;
}

void removerAresta(GrafoMatrizAdj *grafo, int origem, int destino)
{
    if (origem < 0 || origem >= grafo->num_vertices || destino < 0 || destino >= grafo->num_vertices)
    {
        printf("Erro: vértices inválidos\n");
        return;
    }

    grafo->matriz_adj[origem][destino] = 0;
}

int verificarAdjacencia(GrafoMatrizAdj *grafo, int origem, int destino)
{
    if (origem < 0 || origem >= grafo->num_vertices || destino < 0 || destino >= grafo->num_vertices)
    {
        printf("Erro: vértices inválidos\n");
        return 0;
    }

    return grafo->matriz_adj[origem][destino];
}

void imprimirGrafo(GrafoMatrizAdj *grafo)
{
    for (int i = 0; i < grafo->num_vertices; i++)
    {
        for (int j = 0; j < grafo->num_vertices; j++)
        {
            printf("%d ", grafo->matriz_adj[i][j]);
        }
        printf("\n");
    }
}
