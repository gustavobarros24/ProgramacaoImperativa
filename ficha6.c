#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define Max 24

//1
typedef struct staticStack {
    int sp;
    int values [Max];
} STACK, *SStack;

//a
void SinitStack (SStack s){
    s -> sp = 0;
}

//b
int SisEmpty (SStack s){
    return s -> sp == 0;
}

//c
int Spush (SStack s, int x){
    if(s->sp == Max){
        return 1;
    }
    s->values[s->sp] = x;
    s->sp++;
    return 0;
}

//d
int Spop (SStack s, int *x){
    if(s->sp == 0){
        return 1;
    }

    s->sp--;
    *x = s->values[s->sp];
    return 0;
}

//e
int Stop (SStack s, int *x){
    if(s->sp == 0){
        return 1;
    }
    int aux = s->sp-1;
    *x = s->values[aux];
    return 0;
}

//2
typedef struct staticQueue {
    int front;
    int length;
    int values [Max];
} QUEUE, *SQueue;

//a
void SinitQueue (SQueue q){
    q->length = 0;
}

//b
int SisEmptyQ (SQueue q){
    return q->length == 0;
}

//c
int Senqueue (SQueue q, int x){
    if(q->length == Max){
        return 1;
    }
    q->values[q->front+q->length] = x;
    q->front++;
    return 0;
}
//d
int Sdequeue (SQueue q, int *x){
    if(q->length == 0){
        return 1;
    }
    *x = q->values[q->front];
    q->length--;
    q->front++;
    return 0;
}

//e
int Sfront (SQueue q, int *x){
    if(q->length == 0){
        return 1;
    }
    *x = q->values[q->front];
    return 0;
}

//3 Stack
typedef struct dinStack {
    int size; // guarda o tamanho do array values
    int sp;
    int *values;
} *DStack;

int dupStack(DStack s) {
    int *t = realloc(s->values, 2 * s->size * sizeof(int));

    if (t == NULL){
        return 1;
    }
    s->values = t;
    s->size = s->size*2;
    return 0;
}

//a
void DinitStack(DStack s) {
    s->sp = 0;
    s->size = 0;
    s->values = malloc(s->size * sizeof(int));
}

//b
int DisEmpty(DStack s){
    return s->size == 0;
}

//c
int Dpush(DStack s, int x){
    if(s->sp == s->size){
        if(dupStack(s) != 0){
            return 1;
        }
    }
    s->values[s->sp] = x;
    s->sp++;

    return 0;
}

//d
int Dpop(DStack s, int *x){
    if(DisEmpty(s) == 1){
        return 1;
    }
    s->sp--;
    *x = s->values[s->sp];
    return 0;
}

//e
int Dtop (DStack s, int *x){
    if(DisEmpty(s) == 1){
        return 1;
    }

    *x = s->values[s->sp - 1];
    return 0;
}

//3 Queue
typedef struct dinQueue {
    int size; // guarda o tamanho do array values
    int front;
    int length;
    int *values;
} *DQueue;

int dupQueue(DQueue q){
    int *aux = realloc(q->values, 2*q->size*sizeof(int));
    if(aux == NULL){
        return 1;
    }
    q->size = q->size*2;
    int k = q->size - 1;
    for(int i = q->length - 1; i < q->front; i--, k--){
        aux[k] = q->values[i];
    }
    q->values = aux;
    q->front = k+1;

    return 0;
}

//a
void DinitQueue(DQueue q){
    q->length = 0;
    q->front = 0;
    q->size = 1;
    q->values = malloc(q->size * sizeof(int));
}

//b
int DisEmptyQ(DQueue q){
    return q->length == 0;
}

//c
int Denqueue(DQueue q, int x){
    if(q->length == q->size){
        dupQueue(q);
    }
    q->values[q->front+q->length] = x;
    q->length++;
    return 0;
}

//d
int Ddequeue(DQueue q, int *x){
    if(q->length == 0 || q->size == 0){
        return 1;
    }
    *x = q->values[q->front];
    q->length--;
    q->front++;
    return 0;
}

//e
int Dfront (SQueue q, int *x){
    if(DisEmptyQ(q) == 1){
        return 1;
    }
    *x = q->values[q->front];
    return 0;
}


int main(int argc, char *argv[]){

    return 0;
}