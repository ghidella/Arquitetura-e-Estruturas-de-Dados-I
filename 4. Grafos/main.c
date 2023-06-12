#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "grafo_listaadj.h"

typedef struct busca
{
    int ant;
    float altura;
    bool aberto;
} NoDeBusca;

int pegarMaiorMenor(NoDeBusca *array, int numVertices)
{
    float max = -1;
    int index = -1;
    for (int i = 0; i < numVertices; i++)
    {
        if (array[i].aberto && array[i].altura > max)
        {   
            max = array[i].altura;
            index = i;
        }
    }
    return index;
}

float min(float a, float b)
{
    return (a < b) ? a : b;
}

float consulta(Grafo *grafo, int origem, int destino)
{
    NoDeBusca *busca = (NoDeBusca *)malloc(grafo->num_vertices * sizeof(NoDeBusca));

    for (int i = 0; i < grafo->num_vertices; i++)
    {
        busca[i].ant = -1;
        busca[i].altura = -1;
        busca[i].aberto = true;
    }

    busca[origem].aberto = false;

    int index = origem;
    busca[index].altura = INFINITY;

    for (int z = 0; z < grafo->num_vertices - 1; z++)
    {
        No *no = obterNoPelaOrigem(grafo, index);

        while (no != NULL)
        {
            // printf("Origem: %d ", index);
            // printf("Destino: %d ", no->destino);
            // printf("Peso: %f\n", no->peso);
            float m = min(no->peso, busca[index].altura);
            // printf("m: %f\n", m);
            // printf("busca[no->destino].aberto: %d\n", busca[no->destino].aberto);
            // printf("busca[no->destino].altura: %.1f\n", busca[no->destino].altura);
            if (busca[no->destino].aberto && m > busca[no->destino].altura)
            {
                busca[no->destino].altura = m;
                busca[no->destino].ant = origem;
            }
            no = obterProxNo(grafo, no);
        }

        busca[index].aberto = false;

        for (int i = 0; i < grafo->num_vertices; i++)
        {
            printf("[%d]:%d:%.1f\n", i, busca[i].aberto, busca[i].altura);
        }

        printf("\n");

        index = pegarMaiorMenor(busca, grafo->num_vertices);

        if (index == -1)
        {
            break;
        }
    }

    float resp = busca[destino].altura;
    // printf("resp: %f\n", resp);
    free(busca);
    return resp;
}

float caminhao(float altura)
{
    float disponiveis[5] = {2.5, 3.0, 3.5, 4.0, 4.5};
    for (int i = 0; i < 5; i++)
    {
        if (altura < disponiveis[i])
        {
            return disponiveis[i - 1];
        }
    }
    return 4.5;
}

int main()
{
    FILE *arquivo;
    arquivo = fopen("entrada.txt", "r");
    FILE *saida;
    saida = fopen("saida.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int num_vertices, num_arestas, num_consultas;
    fscanf(arquivo, "%d %d %d", &num_vertices, &num_arestas, &num_consultas);

    Grafo *grafo = criarGrafo(num_vertices);

    int i;
    int origem, destino;
    float peso;

    // Lendo as definições do grafo
    for (i = 0; i < num_arestas; i++)
    {
        fscanf(arquivo, "%d %d %f", &origem, &destino, &peso);
        adicionarAresta(grafo, origem, destino, peso);
    }

    // consultas
    for (int i = 0; i < num_consultas; i++)
    {
        int c_origem, c_destino;
        fscanf(arquivo, "%d %d", &c_origem, &c_destino);
        float resp = consulta(grafo, c_origem, c_destino);
        resp = caminhao(resp);
        fprintf(saida, "%.1f\n", resp);
    }

    fclose(arquivo);
    fclose(saida);
    destruirGrafo(grafo);

    return 0;
}
