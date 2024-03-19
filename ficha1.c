#include <stdio.h>
#include <stdlib.h>

//1 Estado e Atribuições

//1 R: x = 12; y = 16
//2 x = 0; y vai ser algo aleatório da memória
//3 vai dar print a A 65; B 66 2 50; b 98
//4 x = 100; y = 200

//2 Estruturas de controlo

//a x = 3; y = 5
//b x = 11; y = 66
//c _#_#_#_#_#_#_#_#_#_#
//d 1
//  01
//  11
//  001
//  101
//  011
//  111
//  0001
//  1001
//  0101
//  1101
//  0011
//  1011
//  0111
//  1111

//3 Programas iterativos

//1
int quadrado(int x){
    for(int i = 0; i < x; i++){
        printf("#####\n");
    }
    return 0;
}

//2
int xadrez(int x){
    for(int i = 0; i<x; i++){
        for(int j = 0; j<x; j++){
            if((i+j)%2 == 0){
                printf("#");
            }
            else{
                printf("_");
            }
        }
        printf("\n");
    }
    return 0;
}

//3
int trianguloH(int x){
    for(int i = 1; i <= x; i++) {
        int j = i - 1;
        for(int k = 0; k < x - 1 - j; k++){
            putchar(' ');
        }
        for(int k = 0; k < 1 + 2 * j; k++){
            putchar('#');
        }
        putchar('\n');
    }
}

int trianguloV(int x){
    for(int i = 1; i < 2 * x; i++) {
        for(int j = 1; j <= 2 * x - i; j++) {
            if(j <= i) putchar('#');
        }
        putchar('\n');
    }
}

//4
















int main () {
    quadrado(5);
    xadrez(5);
    trianguloV(5);
    trianguloH(5);
    return 0;
}