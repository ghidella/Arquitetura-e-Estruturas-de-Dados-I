#ifndef GRAFO_LISTAADJ_H
#define GRAFO_LISTAADJ_H

#define INFINITY 9999

typedef struct No
{
    int destino;
    float peso;
    struct No *prox;
} No;

typedef struct
{
    int num_vertices;
    No **lista_adj;
} Grafo;

Grafo *criarGrafo(int num_vertices);
void destruirGrafo(Grafo *grafo);
void adicionarAresta(Grafo *grafo, int origem, int destino, float peso);
void removerAresta(Grafo *grafo, int origem, int destino);
int verificarAdjacencia(Grafo *grafo, int origem, int destino);
void imprimirGrafo(Grafo *grafo);
float obterPesoAresta(Grafo *grafo, int origem, int destino);
No *obterNoPelaOrigem(Grafo *grafo, int origem);
No *obterProxNo(Grafo *grafo, No *atual);

#endif
