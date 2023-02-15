#include <stdio.h>
#define MAX 50

#define true 1
#define false 0
typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int topo;
} PILHA;

void inicializarPilha(PILHA* p) {
    p->topo = -1;
}

int tamanhoPilha(PILHA* p){
    return p->topo + 1;
}

void exibirPilha(PILHA* p){
    printf("Pilha: \" ");
    int i;
    for(i = p->topo; i >= 0; i--){
        printf("%i ", p->A[i].chave);
    }
    printf("\"\n");
}

bool inserirElementoPilha(PILHA* p, REGISTRO reg){ //push
    if(p->topo >= MAX-1) return false;
    p->topo = p->topo + 1;
    p->A[p->topo] = reg;
    return true;
}


bool excluirElementoPilha(PILHA* p, REGISTRO* reg){ //pop
    if(p->topo == -1) return false;
    *reg = p->A[p->topo];
    p->topo = p->topo + 1;
    return true;
}

void reinicializarPilha(PILHA* p){
    p->topo = -1;
}

int main(){
    
}