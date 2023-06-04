#ifndef GRAFO_MATRIZADJ_H
#define GRAFO_MATRIZADJ_H

#define MAX_VERTICES 100

typedef struct {
    int num_vertices;
    int matriz_adj[MAX_VERTICES][MAX_VERTICES];
} GrafoMatrizAdj;

GrafoMatrizAdj* criarGrafo(int num_vertices);
void destruirGrafo(GrafoMatrizAdj* grafo);
void adicionarAresta(GrafoMatrizAdj* grafo, int origem, int destino);
void removerAresta(GrafoMatrizAdj* grafo, int origem, int destino);
int verificarAdjacencia(GrafoMatrizAdj* grafo, int origem, int destino);
void imprimirGrafo(GrafoMatrizAdj* grafo);

#endif
