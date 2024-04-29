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


//1
void initStack (Stack *s){
    
}


int main(int argc, char *argv[]){

    return 0;
}