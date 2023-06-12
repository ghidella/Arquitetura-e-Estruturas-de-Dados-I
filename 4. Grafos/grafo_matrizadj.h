#ifndef GRAFO_MATRIZADJ_H
#define GRAFO_MATRIZADJ_H

#define INFINITY 9999

typedef struct No
{
    int destino;
    float peso;
    int origem;
} No;

typedef struct
{
    int num_vertices;
    No ***matriz_adj;
} Grafo;

Grafo *criarGrafo(int num_vertices);
void destruirGrafo(Grafo *grafo);
void adicionarAresta(Grafo *grafo, int origem, int destino, float peso);
void removerAresta(Grafo *grafo, int origem, int destino);
void imprimirGrafo(Grafo *grafo);
No *obterNoPelaOrigem(Grafo *grafo, int origem);
No *obterProxNo(Grafo *grafo, No *no);

#endif
