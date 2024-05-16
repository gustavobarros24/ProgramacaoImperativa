#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct {
    float teste, minis;
} Aluno;


//1
int isFib(int x){
    if(x == 0 || x == 1 || x == 2){
        return 1; 
    }
    int ant = 1;
    int atual = 2;
    while(x>atual){
        int aux = atual;
        atual = atual + ant;
        ant = aux;
        if(atual == x){
            return 1;
        }
    }
    return 0;
}


//2
int moda(Aluno turma[], int N){
    int notas[N];
    for(int i = 0; i<N; i++){
        int aux = (turma[i].minis*0.20) + (turma[i].teste*0.80);
        if(aux < 10){
            aux = 0;
        }
        notas[i] = aux;
    }
    int moda = notas[0];
    int aparecimentos = 0;
    for(int i = 0; i<N;i++){
        int count = 0;
        for(int j = 0; j<N; j++){
            if(notas[i] == notas[j]){
                count++;
            }
        }
        if(count > aparecimentos){
            moda = notas[i];
            aparecimentos = count;
        }
    }
    return moda;
}


int main(int argc, char *argv[]){

    return 0;
}