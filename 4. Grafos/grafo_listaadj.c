#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafo_listaadj.h"

Grafo *criaGrafo(int nodes)
{
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->vertice = nodes;
    g->aresta = 0;
    g->nodeLista = (Node *)malloc((nodes + 1) * sizeof(Node));
    for (int i = 0; i <= nodes; i++)
    {
        g->nodeLista[i].cabeca = NULL;
        g->nodeLista[i].arestas = 0;
    }
    return g;
}

Aresta *criaAresta(int node, int peso)
{
    Aresta *nova = (Aresta *)malloc(sizeof(Aresta));
    nova->dest = node;
    nova->peso = peso;
    nova->prox = NULL;
    return nova;
}