#include <stdio.h>
#include <stdlib.h>
#include "grafo_listaadj.h" // Inclua o código do grafo com lista de adjacência aqui

int main() {
    FILE *arquivo;
    arquivo = fopen("entrada.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int num_vertices, num_arestas, num_consultas;
    fscanf(arquivo, "%d %d %d", &num_vertices, &num_arestas, &num_consultas);

    GrafoListaAdj *grafo = criarGrafo(num_vertices);

    int i;
    int origem, destino;
    float peso;
    
    // Lendo as definições do grafo
    for (i = 0; i < num_arestas; i++) {
        fscanf(arquivo, "%d %d %f", &origem, &destino, &peso);
        adicionarAresta(grafo, origem, destino, peso);
    }

    // Realizando as consultas
    printf("Consultas:\n");
    for (i = 0; i < num_consultas; i++) {
        fscanf(arquivo, "%d %d", &origem, &destino);
        printf("Consulta %d: Origem = %d, Destino = %d\n", i+1, origem, destino);
        
        if (verificarAdjacencia(grafo, origem, destino)) {
            printf("Os vértices %d e %d são adjacentes.\n", origem, destino);
        } else {
            printf("Os vértices %d e %d não são adjacentes.\n", origem, destino);
        }
    }

    fclose(arquivo);
    destruirGrafo(grafo);

    return 0;
}
