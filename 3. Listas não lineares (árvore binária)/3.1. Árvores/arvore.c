#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux{
    TIPOCHAVE chave;
    /* Dados armazenados vao aqui*/
    struct aux *esq, *dir;
    } NO;

typedef NO* PONT;

PONT inicializa(){
    return(NULL);
}

/* insercao recursiva SEM repeticao */
PONT adiciona(PONT raiz, PONT no){
    if (raiz == NULL) return(no);
    if(no->chave < raiz->chave)
        raiz->esq = adiciona(raiz->esq, no);
    else
        raiz->dir = adiciona(raiz->dir, no);
    return(raiz);
}

PONT criaNovoNo(TIPOCHAVE ch){
    PONT novoNo = (PONT)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    return(novoNo);
}

PONT contem(TIPOCHAVE ch, PONT raiz){
    if(raiz == NULL) return(NULL);
    if(raiz->chave == ch) return(raiz);
    if(raiz->chave > ch)
        return(contem(ch, raiz->esq));
    return(contem(ch, raiz->dir));
}

int numeroNos(PONT raiz){
    if(!raiz) return 0;
    return(numeroNos(raiz->esq))
        + 1
        + numeroNos(raiz->dir);
}

void exibirArvore(PONT raiz){
    if(raiz != NULL){
        printf("%i", raiz->chave);
        printf("(");
        exibirArvore(raiz->esq);
        exibirArvore(raiz->dir);
        printf(")");
    }
}

/*
    Busca binária não recursiva. Devolve o ponteiro do nó buscado. Abastece pai com o ponteiro para o nó pai deste
*/
PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai){
    PONT atual = raiz;
    *pai = NULL;
    while(atual){
        if(atual->chave == ch) return(atual);
        *pai = atual;
        if(ch < atual->chave) atual = atual->esq;
        else atual = atual->dir;
    }
    return(NULL);
}

PONT removeNo(PONT raiz, TIPOCHAVE ch){
    PONT pai, no, p, q;
    no = buscaNo(raiz, ch, &pai);
    if(no == NULL) return(raiz);
    if (!no->esq || !no->dir){
        if(!no->esq) q = no->dir;
        else q = no->esq;
    }
    else {
        p = no;
        q = no->esq;
        while(q->dir){
            p = q;
            q = q->dir;
        }
        if(p != no){
            p->dir = q->esq;
            q->esq = no->esq;
        }
        q->dir = no->dir;
    }
    if (!pai){
        free(no);
        return(q);
    }
    if(ch < pai->chave) pai->esq = q;
    else pai->dir = q;
    free(no);
    return(raiz);

}


int contarNiveis(NO *raiz){
    if(!raiz) return 0;
    int alturaEsquerda = contarNiveis(raiz->esq);
    int alturaDireita = contarNiveis(raiz->dir);
    if(alturaEsquerda > alturaDireita){
        return alturaEsquerda + 1;
    } else {
        return alturaDireita + 1;
    }
}

int contarMaiores(NO *raiz, NO *p) {
  if (!raiz) {
    return 0;
  }

  if (raiz->chave > p->chave) {
    return 1 + contarMaiores(raiz->esq, p) + contarMaiores(raiz->dir, p);
  }
  return contarMaiores(raiz->esq, p) + contarMaiores(raiz->dir, p);
}

int main(){
    PONT r = inicializa();
    PONT no = criaNovoNo(44);
    r = adiciona(r, no);
    PONT no2 = criaNovoNo(22);
    r = adiciona(r, no2);
    PONT no3 = criaNovoNo(11);
    r = adiciona(r, no3);
    PONT no4 = criaNovoNo(33);
    r = adiciona(r, no4);
    PONT no5 = criaNovoNo(66);
    r = adiciona(r, no5);
    PONT no6 = criaNovoNo(55);
    r = adiciona(r, no6);
    PONT no7 = criaNovoNo(77);
    r = adiciona(r, no7);
    PONT no8 = criaNovoNo(54);
    r = adiciona(r, no8);
    printf("%d\n", numeroNos(r));
    exibirArvore(r);

    printf("\n MAIORES %d ", contarMaiores(r, no3));
}
