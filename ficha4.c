#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//1 Funções sobre Strings

//  1
int contaVogais (char *s){
    int result = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            result++;
        }
    }
    return result;
}

//2
int retiraVogaisRep (char *s){
    char aux[100];
    int dup = 0;
    int removed = 0;
    int i = 0;
    for(i = 0; s[i] != '\0' && dup < 100; i++){
        while(s[i] == s[i+1] && (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')){
            i++;
            removed++;
        }
        aux[dup] = s[i];
        dup++;
    }
    strcpy(s,aux);
    return removed;
}

//3
int duplicaVogais (char *s){
    int length = strlen(*s);
    char aux[length];
    int dup = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            aux[i] = s[i];
            i++;
            aux[i] = s[i];
            i++;
            dup++;
        }
        else{
            aux[i] = s[i];
        }
    }
    strcpy(s,aux);
    return dup;
}

//2 Arrays Ordenados

//1
int ordenado (int v[], int N){
    for(int i = 1; i<N; i++){
        if(v[i] < v[i-1]){
            return 0;
        }
    }
    return 1;
}

//2
void merge (int a[], int na, int b[], int nb, int r[]){
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < na && j < nb){
        if(a[i] < b[j]){
            r[k] = a[i];
            k++;
            i++;
        }
        else{
            r[k] = b[j];
            k++;
            j++;
        }
    }
    if(i == na){
        while(j<nb){
            r[k] = b[j];
            k++;
            j++;
        }
    }
    else{
        while(i<na){
            r[k] = a[i];
            k++;
            i++;
        }
    }
}

//3 Há muito a otimizar aqui, por exemplo guardar o indice onde começa o elemento maior que x para o segundo ciclo não ser tão longo e muitas outras coisas ahahahah
int partition (int v[], int N, int x){
    int k = 0;
    int count = 0;
    int aux[N];
    for(int i = 0; i<N; i++){
        if(v[i] <= x){
            aux[k] = v[i];
            k++;
            count++;
        }
    }
    if(count == 0){
        return 0;
    }
    for(int i = 0; i < N; i++){
        if(v[i] > x){
            aux[k] = v[i];
        }
    }
    for(int i = 0; i < N; i++){
        v[i] = aux[i];
    }
    return count;
}

int main(int argc, char* argv[]){
    return 0;
}