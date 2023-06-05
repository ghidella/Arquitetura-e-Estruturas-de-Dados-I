#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>

typedef struct
{
    int num_vertices;
    float **matriz_adj;
} GrafoMatrizAdj;

// funcao para criar o grafo
GrafoMatrizAdj *criarGrafo(int num_vertices)
{
    GrafoMatrizAdj *grafo = (GrafoMatrizAdj *)malloc(sizeof(GrafoMatrizAdj));
    grafo->num_vertices = num_vertices;

    grafo->matriz_adj = (float **)malloc(num_vertices * sizeof(float *));
    int i, j;
    for (i = 0; i < num_vertices; i++)
    {
        grafo->matriz_adj[i] = (float *)malloc(num_vertices * sizeof(float));
        for (j = 0; j < num_vertices; j++)
        {
            grafo->matriz_adj[i][j] = 0.0;
        }
    }

    return grafo;
}

// funcao para destruir o grafo
void destruirGrafo(GrafoMatrizAdj *grafo)
{
    int i;
    for (i = 0; i < grafo->num_vertices; i++)
    {
        free(grafo->matriz_adj[i]);
    }
    free(grafo->matriz_adj);
    free(grafo);
}

// funcao para adicionar arestas
void adicionarAresta(GrafoMatrizAdj *grafo, int origem, int destino, float altura)
{
    grafo->matriz_adj[origem][destino] = altura;
    grafo->matriz_adj[destino][origem] = altura;
}

int main()
{
    FILE *file = fopen("entrada.txt", "r");
    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    int num_vertices, num_arestas, num_consultas;
    fscanf(file, "%d %d %d", &num_vertices, &num_arestas, &num_consultas);

    // Create the graph
    GrafoMatrizAdj *grafo = criarGrafo(num_vertices);

    // Read the edges
    for (int i = 0; i < num_arestas; i++)
    {
        int origem, destino;
        float altura;
        fscanf(file, "%d %d %f", &origem, &destino, &altura);
        adicionarAresta(grafo, origem, destino, altura);
    }

    // Process the queries
    for (int i = 0; i < num_consultas; i++)
    {
        int origem, destino;
        fscanf(file, "%d %d", &origem, &destino);

        // Run Prim's algorithm to find the maximum spanning tree
        primMaximo(grafo);

        // Find the maximum height in the path
        float maxMinAltura = encontrarMaiorMinimaAltura(grafo, origem, destino);
        printf("Maior altura mínima no caminho %d -> %d: %.2f\n", origem, destino, maxMinAltura);
    }

    // Clean up
    destruirGrafo(grafo);
    fclose(file);

    return 0;
}
