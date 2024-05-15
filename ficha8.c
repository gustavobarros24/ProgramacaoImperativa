#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;


LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x; r->prox = xs;
    }
    return r;
}


typedef LInt Stack;


typedef struct {
    LInt inicio,fim;
} Queue;


typedef LInt QueueC;


typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} *DList;


typedef struct {
    DList back, front;
} Deque;


//1
void initStack (Stack *s){
    *s = NULL;
}

int SisEmpty (Stack s){
    return s == NULL;
}

int push(Stack *s, int x){
    LInt new = newLInt(x, (*s));
    if(new == NULL){
        return 1;
    }
    else{
        (*s) = new;
    }
    return 0;
}

int pop (Stack *s, int *x){
    if(SisEmpty(*s)){
        return 1;
    }
    Stack aux = (*s);
    *x = (*s) -> valor;
    *s = (*s) -> prox;
    free(aux);
    return 0;
}

int top (Stack s, int *x){
    (*x) = s->valor;
    return 0;
}


//2
void initQueue (Queue *q){
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty (Queue q){
    return q.inicio == NULL;
}

int enqueue (Queue *q, int x){
    LInt new = malloc(sizeof(struct slist));
    new->valor = x;
    new->prox = NULL;
    if((*q).inicio != NULL){
        (*q).fim->prox = new;
        q->fim = new;
    }
    else{
        q->inicio = new;
        q->fim = new;
    }
}

int dequeue (Queue *q, int *x){
    if(q == NULL){
        return 1;
    }
    LInt aux =  q->inicio;
    *x = q->inicio->valor;
    q->inicio = q->inicio->prox;
    free(aux);
}

int front (Queue q, int *x){
    if(q.inicio == NULL){
        return 1;
    }
    *x = q.inicio->valor;
    return 0;
}


//3
typedef LInt QueueC;


void initQueueC (QueueC *q){
    *q == NULL;
}

int QCisEmpty (QueueC q) {
    return q == NULL;
}

int enqueueC (QueueC *q, int x){
    if(*q == NULL){
        QueueC new = malloc(sizeof(struct slist));
        new->valor = x;
        new->prox = new;
        (*q) = new;
    }
    else{
        QueueC aux = (*q);
        while(aux != (*q)->prox){
            q = &((*q)->prox);
        }
        QueueC new = malloc(sizeof(struct slist));
        new->valor = x;
        new->prox = aux;
        (*q)->prox = new;
    }
    return 0;
}

int dequeueC(QueueC *q, int *x){
    if(*q == NULL){
        return 1;
    }
    if((*q) == (*q)->prox){
        (*q) = NULL;
    }
    else{
        QueueC aux = (*q);
        while(aux != (*q)->prox){
            q = &((*q)->prox);
        }
        (*q)->prox = aux->prox;
        (*q) = aux;
    }
}


int main(int argc, char *argv[]){

    return 0;
}