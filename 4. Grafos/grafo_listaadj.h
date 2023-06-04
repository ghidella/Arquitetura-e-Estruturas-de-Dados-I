#include <stdbool.h>

typedef int Peso; // no caso o peso é a altura

typedef struct aresta
{
    int dest;            // Vértice destino, onde a aresta aponta
    Peso peso;           // Peso da aresta caso o grafo exija, caso contrário não é essencial
    struct aresta *prox; // Ponteiro para o próximo vértice adjacente
} Aresta;

// Estrutura não obrigatória por ter outra opção para usar
typedef struct node
{
    Aresta *cabeca; // Nó que indica a lista ligada dos vértices adjacentes ao vértice em questão
    int arestas;    // Número de arestas que saem do vértice
} Node;

typedef struct lista
{
    int vertice; // É o número de vértices, não obrigatório mas ajuda a não ter que contar caso precise
    int aresta;  // É o número de arestas, não obrigatório mas ajuda a não ter que contar caso precise
    Node *nodeLista;
    // Link **nodeList; Esse código poderia ser usado caso não quisesse declarar uma terceira estrutura Node na implementação
} Grafo;

Grafo *criaGrafo(int nodes);

Aresta *criaAresta(int node, int peso);

bool adicionaAresta(Grafo *g, int nodeI, int nodeE, Peso peso);

bool deletaAresta(Grafo *g, int nodeI, int nodeE);

void obtemDestinoePeso(Grafo *g, int nodeI, int LinkIndex, int *dest, Peso *peso);

int obtemVertices(Grafo *g, int nodeI);

void imprimeGrafo(Grafo *g);

void deletaGrafo(Grafo *g);
