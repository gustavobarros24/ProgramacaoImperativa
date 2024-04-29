#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

//1
int length (LInt l){
    int count = 0;
    while (l != NULL){
        count++;
        l = l->prox;
    }
    return count;
}

//2
void freeL (LInt l){
    LInt aux;
    while(l != NULL){
        aux = l;
        l->prox;
        free(aux);
    }
}

//3
void imprimeL (LInt l){
    while(l != NULL){
        printf("Valor: %d", l->valor);
        l = l->prox;
    }
}

//4
LInt reverseL (LInt l){
    LInt prev = NULL;
    LInt current = l;
    LInt prox = NULL;

    while(current != l){
        prox = current -> prox;
        current -> prox = prev;
        prev = current;
        current = prox;
    }
    l = prev;
    return l;
}

//5
void insertOrd (LInt *l, int x){
    LInt aux = NULL;
    LInt new = malloc(sizeof(struct lligada));
    new -> valor = x;
    new -> prox = NULL;

    while ((*l) != NULL && ((*l) -> valor) < x){
        aux = (*l);
        l = &((*l)->prox);
    }

    if(aux == NULL){
        new->prox = (*l);
        (*l) = new;
    }
    else{
        new->prox = (*l);
        aux->prox = new;
    }
}

//6
int removeOneOrd (LInt *l, int x){
    LInt aux = NULL;
    if((*l) -> valor == x){
        aux = *l;
        (*l) = (*l) -> prox;
        free(aux);
        return 0;
    }
    while((*l) != NULL && (*l) -> valor != x){
        aux = (*l);
        l = &((*l)->prox);
    } 
    if(aux!=NULL){
        aux->prox = (*l) -> prox;
        free(*l);
        return 0;
    }
    return 1;
}

//7
void merge (LInt *r, LInt a, LInt b){
    while(a != NULL && b != NULL){
        if(a->valor>=b->valor){
            *r = b;
            b = b->prox;
        }
        else{
            *r = a;
            a = a->prox;
        }
        r = &(*r)->prox;
    }
    if(a != NULL){
        *r = a;
    }
    else{
        *r = b;
    }
}

//8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    while(l -> valor < x && l != NULL){
        *mx = l;
        l = l->prox;
        mx = &((*mx)->prox);
    }
    *mx = NULL;
    *Mx = l;
}


int main(int argc, char *argv[]){

    return 0;
}