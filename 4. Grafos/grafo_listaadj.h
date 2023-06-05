#ifndef GRAFO_LISTAADJ_H
#define GRAFO_LISTAADJ_H

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

GrafoListaAdj *criarGrafo(int num_vertices);
void destruirGrafo(GrafoListaAdj *grafo);
void adicionarAresta(GrafoListaAdj *grafo, int origem, int destino);
void removerAresta(GrafoListaAdj *grafo, int origem, int destino);
int verificarAdjacencia(GrafoListaAdj *grafo, int origem, int destino);
void imprimirGrafo(GrafoListaAdj *grafo);

#endif
