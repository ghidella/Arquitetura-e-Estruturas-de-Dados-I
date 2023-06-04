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
// Função auxiliar para encontrar o vértice com a maior chave
int encontrarMaiorChave(float *chave, bool *visitado, int num_vertices)
{
    float maior = -FLT_MAX;
    int indice_maior;

    for (int i = 0; i < num_vertices; i++)
    {
        if (!visitado[i] && chave[i] > maior)
        {
            maior = chave[i];
            indice_maior = i;
        }
    }

    return indice_maior;
}

// Função para imprimir a árvore geradora máxima
void imprimirArvoreGeradoraMaxima(int *pai, GrafoMatrizAdj *grafo)
{
    printf("Arestas da Árvore Geradora Máxima:\n");
    for (int i = 1; i < grafo->num_vertices; i++)
    {
        printf("Aresta: %d - %d, Peso: %.2f\n", pai[i], i, grafo->matriz_adj[i][pai[i]]);
    }
}

// Algoritmo de Prim para criar uma árvore geradora máxima
void primMaximo(GrafoMatrizAdj *grafo)
{
    int *pai = (int *)malloc(grafo->num_vertices * sizeof(int));         // Array para armazenar o pai de cada vértice
    float *chave = (float *)malloc(grafo->num_vertices * sizeof(float)); // Array para armazenar as chaves dos vértices
    bool *visitado = (bool *)malloc(grafo->num_vertices * sizeof(bool)); // Array para marcar os vértices visitados

    // Inicializar as chaves e o array de visitados
    for (int i = 0; i < grafo->num_vertices; i++)
    {
        chave[i] = -FLT_MAX;
        visitado[i] = false;
    }

    chave[0] = 0; // Definir a chave do primeiro vértice como 0
    pai[0] = -1;  // O primeiro vértice não tem pai

    // Construir a árvore geradora máxima
    for (int i = 0; i < grafo->num_vertices - 1; i++)
    {
        int u = encontrarMaiorChave(chave, visitado, grafo->num_vertices); // Encontrar o vértice com a maior chave
        visitado[u] = true;

        for (int v = 0; v < grafo->num_vertices; v++)
        {
            if (grafo->matriz_adj[u][v] > 0 && !visitado[v] && grafo->matriz_adj[u][v] > chave[v])
            {
                pai[v] = u;
                chave[v] = grafo->matriz_adj[u][v];
            }
        }
    }

    imprimirArvoreGeradoraMaxima(pai, grafo);

    free(pai);
    free(chave);
    free(visitado);
}

float min(float a, float b)
{
    return (a < b) ? a : b;
}

// Function to find the maximum of two values
float max(float a, float b)
{
    return (a > b) ? a : b;
}

void encontrarMaiorAltura(GrafoMatrizAdj *grafo, int origem, int destino)
{
    bool *visitado = (bool *)malloc(grafo->num_vertices * sizeof(bool));
    float *alturaMinima = (float *)malloc(grafo->num_vertices * sizeof(float));
    int *pai = (int *)malloc(grafo->num_vertices * sizeof(int));

    for (int i = 0; i < grafo->num_vertices; i++)
    {
        visitado[i] = false;
        alturaMinima[i] = FLT_MAX;
        pai[i] = -1;
    }

    alturaMinima[origem] = 0.0;

    int atual = origem;
    while (atual != destino)
    {
        visitado[atual] = true;

        for (int i = 0; i < grafo->num_vertices; i++)
        {
            if (grafo->matriz_adj[atual][i] > 0 && !visitado[i])
            {
                if (alturaMinima[atual] < grafo->matriz_adj[atual][i] && grafo->matriz_adj[atual][i] < alturaMinima[i])
                {
                    alturaMinima[i] = grafo->matriz_adj[atual][i];
                    pai[i] = atual;
                }
            }
        }

        float menorAltura = FLT_MAX;
        for (int i = 0; i < grafo->num_vertices; i++)
        {
            if (!visitado[i] && alturaMinima[i] < menorAltura)
            {
                menorAltura = alturaMinima[i];
                atual = i;
            }
        }

        if (menorAltura == FLT_MAX)
        {
            // Não existe caminho
            break;
        }
    }

    // Imprimir o caminho com a maior altura mínima
    printf("Caminho com a maior altura mínima %d -> %d: ", origem, destino);
    int caminho[grafo->num_vertices];
    int indice = 0;
    int i = destino;
    while (i != -1)
    {
        caminho[indice++] = i;
        i = pai[i];
    }
    for (int j = indice - 1; j >= 0; j--)
    {
        printf("%d ", caminho[j]);
    }
    printf("\n");

    free(visitado);
    free(alturaMinima);
    free(pai);
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
