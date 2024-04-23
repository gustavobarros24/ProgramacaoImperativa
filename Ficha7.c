#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

//1
void libertaLista (Palavras l){
    Palavras aux;
    while(l != NULL){
        aux = l;
        free(l->palavra);
        l=l->prox;
        free(aux);
    }
}

//2
int quantasP(Palavras l){
    int result = 0;
    while(l != NULL){
        result++;
        l = l->prox;
    }
    return result;
}

//3
void listaPal (Palavras l){
    while(l != NULL){
        printf("Palavra: %s\n", l->palavra);
        printf("Ocorrência: %d\n",l->ocorr);
        l=l->prox;
    }
}

//4
char * ultima (Palavras l){
    char *ultima = NULL;
    while(l != NULL){
        ultima = l->palavra;
        l = l->prox;
    }
    return ultima;
}

//5
Palavras acrescentaInicio (Palavras l, char *p){
    Palavras novo = malloc(sizeof(struct celula));
    novo->palavra = p;
    novo->ocorr = 1;
    novo->prox=l;
    return novo;
}

//6
Palavras acrescentaFim (Palavras l, char *p){
    Palavras head = l;
    while(l!=NULL){
        l=l->prox;
    }
    Palavras novo = malloc(sizeof(struct celula));
    novo->palavra = p;
    novo->ocorr = 1;
    novo->prox = NULL;
    l = novo;
    return head;
}

//7
Palavras acrescenta (Palavras l, char *p){
    Palavras aux = l;
    while(aux != NULL){
        if(strcmp(aux->palavra,p) == 0){
            aux->ocorr++;
            return l;
        }
        aux = aux->prox;
    }
    Palavras novo = malloc(sizeof(struct celula));
    novo->palavra = p;
    novo->ocorr = 1;
    novo->prox = l;
    return novo;
}

//8
struct celula * maisFreq (Palavras l){
    struct celula *c;
    int max = 0;

    while(l!=NULL){
        if(l->ocorr > max){
            c=l;
            max = l->ocorr;
        }
        l = l->prox;
    }
    return c;
}


int main(int argc, char *argv[]){

    return 0;
}