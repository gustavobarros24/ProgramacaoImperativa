#include <stdio.h>
#include <stdlib.h>

//1
float multInt1 (int n, float m){
    int r = 0;
    for(int i = 0; i < n; i++){
        r = r + m;
    }
    return r;
}

//2
float multInt2 (int n, float m){
    float soma = 0;

    while(n>0){
        if((n%2)!= 0){
            soma = soma + m;
            n = n/2;
            m = m*2;
        }
    }
    return soma;
}

//3
int mdc1 (int a, int b){
    int maior = 0;
    if(a>b){
        for(int i = 1; i<b; i++){
            if(b%i == 0 && maior < i){
                maior = i;
            }
        }
    }
    else{
        for(int i = 1; i<a; i++){
            if(a%i == 0 && maior < i){
                maior = i;
            }
        }
    }
    return maior;
}

//4
int mdc2 (int a, int b){
    int mdc=0;

    while(a>0 && b>0) {
        if(a>b) a-=b;
        if(a<b) b-=a;
        if(a==b) {
            mdc=a;
            break;
        }
    }

    return mdc;
}

//5
int mdc3 (int a, int b) {
    while(a != 0 && b != 0) {
        if(a > b) a %= b;
        else if (b > a) b %= a;
        else return a;
    }
    if(a == 0) return b;
    else return a;
}

//6
//a
int fib1 (int n){
    if(n<2) {
        n=1;
    }
    else{
        n=fib1(n-1)+fib1(n-2);
    }
    return n;
}

//b
int fib2(int n){
    int first = 0;
    int second = 1;
    if(n<2) {
        n=1;
    }
    else{
        while(n>1) {
            int aux= first;
            first =second;
            second += aux;

            n--;
        }
    }
    return second;
}


int main(){
    return 0;
}