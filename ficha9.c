#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;


ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));
    if (a!=NULL) {
        a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}


//1
int altura (ABin a){
    if(a == NULL){
        return 1;
    }
    int esquerda = altura(a->esq);
    int direita = altura(a->dir);
    if(esquerda>direita){
        esquerda = esquerda+1;
        return esquerda;
    }
    else{
        direita = direita+1;
        return direita;
    }
    return 1;
}

int nFolhas (ABin a){
    if(a == NULL){
        return 0;
    }
    if(a->esq == NULL && a->dir == NULL){
        return 1;
    }
    return(nFolhas(a->esq) + nFolhas(a->dir));
}

ABin maisEsquerda(ABin a){
    if (a == NULL) {
        return NULL;
    }
    while (a->esq != NULL) {
        a = a->esq;
    }
    return a;
}

void imprimeNivel (ABin a, int l){
    if(a!=NULL){
        if(l == 0){
            printf("%d", a->valor);
        }
        else{
            imprimeNivel(a->esq, l-1);
            imprimeNivel(a->dir,l-1);
        }
    }
}

int procuraE (ABin a, int x){
    if(a == NULL){
        return 1;
    }
    if(a->valor == x){
        return 0;
    }
    return (procuraE(a->esq, x) || procuraE(a->dir,x));
}

struct nodo *procura (ABin a, int x){
    if(a == NULL){
        return NULL;
    }
    if(a->valor == x){
        return a;
    }
    else if(a->valor > x){
        return procura(a->esq, x);
    }
    else{
        return procura(a->dir, x);
    }
}

int nivel (ABin a, int x){
    int count = 0;
    if(a == NULL){
        return 1;
    }
    while(a!=NULL){
        if(a->valor){
            return count;
        }
        if(a->valor > x){
            a = a->dir;
        }
        else{
            a = a->esq;
        }
        count++;
    }
    return 1;
}

void imprimeAte (ABin a, int x){
    if(a!=NULL){
        imprimeAte(a->esq,x);
        if(a->valor<x){
            printf("%d", a->valor);
            imprimeAte(a->dir,x);
        }
    }
}


int main(int argc, char *argv[]){

    return 0;
}