#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

//1
int nota (Aluno a){
    float nota = 0;
    float somaminit = 0;
    for(int i = 0; i < 6; i++){
        somaminit = somaminit + a.miniT[i];
    }
    somaminit = somaminit/6;
    somaminit = somaminit * 0.15;
    nota = a.teste * 0.85;
    nota = nota + somaminit;
    if(nota >= 9.5){
        return nota;
    }
    else{
        return 0;
    }
}

//2
int procuraNum (int num, Aluno t[], int N){
    int i;
    for(i = 0; i<N; i++){
        if(t[i].numero == num){
            return i;
        }
        else if(t[i].numero > num){
            return -1;
        }
    }
    return -1;
}

//3
void bsort(int a[], int n) {    
  int i, j;    
  for (i = n - 1; i > 0; i--) {    
    for (j = 0; j < i; j++) {    
      if (a[j] > a[j + 1]) {
          int aux = a[j];    
          a[j] = a[j + 1];    
          a[j + 1] = aux;
      }
    }
  }
}

void ordenaPorNum (Aluno t [], int N){
    int i;
    int j;
    for(int i = N-1; i>0; i--){
        for(j = 0; j<i; j++){
            if(t[j].numero > t[j+1].numero){
                int aux = t[j].numero;
                t[j].numero = t[j+1].numero;
                t[j+1].numero = aux;
            }
        }
    }
}

//4
void criaIndPorNum (Aluno t [], int N, int ind[]){
    int i;
    int j;
    for(int k = 0; k<N; k++){
        ind[k] = k;
    }
    for(i = N-1; i>0; i--){
        for(j = 0; j<i; j++){
            if(t[ind[j]].numero > t[ind[j+1]].numero){
                int aux = ind[j];
                ind[j] = ind[j+1];
                ind[j+1] = aux;
            }
        }
    }
}

//5
void imprimeTurma (int ind[], Aluno t[], int N){
    criaIndPorNum(t,N,ind);
    for(int i = 0; i < N; i++){
        float notadoaluno = nota(t[ind[i]]);
        printf("Número: %d || Nome: %s || Nota: %f\n", t[ind[i]].numero, t[ind[i]].nome, notadoaluno);
    }
}

//6 Vou supor que ind[] já vem ordenado
int procuraNumCriaIndPorNum (int num, Aluno t[], int N, int ind[]){
    int i;
    for(i = 0; i<N; i++){
        if(t[ind[i]].numero == num){
            return i;
        }
        else if(t[ind[i]].numero > num){
            return -1;
        }
    }
    return -1;
}

//7
void criaIndPorNome(Aluno t [], int N, int ind[]){
    int i;
    int j;
    for(int k = 0; k<N; k++){
        ind[k] = k;
    }
    for(i = N-1; i>0; i--){
        for(j = 0; j<i; j++){
            if(strcmp(t[ind[j]].nome, t[ind[j+1]].nome) > 0){
                int aux = ind[j];
                ind[j] = ind[j+1];
                ind[j+1] = aux;
            }
        }
    }
}


int main(int argc, char* argv[]){

    return 0;
}