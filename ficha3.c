#include <stdio.h>
#include <stdlib.h>


//1
//a 1 1 4
//  2 2 6
//  3 3 8
//  4 4 10
//  5 5 12

//b  13

//2
void swapM (int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

//3
void swap (int v[], int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

//4
int soma (int v[], int N){
    int result = 0;
    for(int i = 0; i < N; i++){
        result = result + v[i];
    }
    return result;
}

//5
void inverteArray (int v[], int N){
    for(int i= 0,j = N; i < j; i++, j--){
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }
}

//6
int maximum (int v[], int N, int *m){
    *m = v[0];
    if(N<1){
        return -1;
    }
    if(N == 1){
        return 0;
    }
    for(int i = 0; i<N; i++){
        if(v[i] > *m){
            *m = v[i];
        }
    }
    return 0;
}

//7
void quadrados (int q[], int N){
    for(int i = 0, j = 1; i < N; i++, j++){
        q[i] = j * j;
    }
}

//8 - Não sei se está correto pq achei o exercício confuso e também já n me lembor bem do triângulo de pascal XD.
void pascal(int v[], int N) {
    int linha[N];
    linha[0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = i - 1; j > 0; j--) {
            linha[j] += linha[j - 1];
        }
        linha[i] = 1;
    }

    for (int i = 0; i <= N; i++) {
        v[i] = linha[i];
    }
}

int main(int argc, char* argv[]){
    return 0;
}