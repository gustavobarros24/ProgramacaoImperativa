#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//1
void imprimemaiorelem(){
    int flag;
    int result = 0;
    while(flag != 0){
        scanf("%d", &flag);
        if(flag > result){
            result = flag;
        }
    }
    printf("%d", result);
}

//2
void medianumeros(){
    float flag;
    float soma = 0;
    float count = 0;
    while(flag != 0){
        scanf("%f", &flag);
        if(flag != 0){
            soma = soma + flag;
            count++;
        }
    }
    float result = soma/count;
    printf("%f", result);
}

//3
void imprimesegundomaiorelem(){
    int flag;
    int result = 0;
    int maior = 0;
    while(flag != 0){
        scanf("%d", &flag);
        if(flag > maior){
            result = maior;
            maior = flag;
        }
        if(flag > result && flag < maior){
            result = flag;
        }
    }
    printf("%d", result);
}

//4
int bitsUm (unsigned int n){
    int count = 0;
    int result = 0;
    while(n>0){
        if(n%2 == 1){
            result++;
        }
        n = n/2;
    }
    return result;
}

int bitsUm2(unsigned int n) {
    int count = 0;
    
    while (n > 0) {
        if ((n & 1) == 1) {
            count++;
        }
        n = n >> 1;
    }
    
    return count;
}

//5
int trailingZ (unsigned int n){
    int count = 0;
    while((n & 1) == 0){
        count++;
        n = n >> 1;
    }
    return count;
}

//6
int qDig (unsigned int n){
    int count = 0;
    while(n >= 1){
        count++;
        n=n/10;
    }
    return count;
}

//7
char *mystrcat(char s1[], char s2[]){
    char* aux1;
    char* aux2;

    for(aux1 = s1; *aux1 != '\0'; aux1++);
    for(aux2 = s2; *aux2 != '\0'; aux2++){
        *aux1 = *aux2;
        aux1++;
    }
    *aux1 = '\0';
    return s1;
}

//8
char *mystrcpy (char *dest, char source[]){
    char *aux1;
    char *aux2;

    for(aux1 = dest, aux2 = source; *aux2 != '\0'; aux1++, aux2++){
        *aux1 = *aux2;
    }
    *aux1 = '\0';
    return dest;
}

//9
int mystrcmp (char s1[], char s2[]){
    int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0'){
        i++;
    }
    if(s1[i] == s2[i]){
        return 0;
    }
    if(s1[i] == '\0' || s2[i] > s1[i]){
        return -1;
    }
    else{
        return 1;
    }
}

//10
char *mystrstr (char haystack[], char needle[]) {

    if (haystack == NULL || needle == NULL){
        return NULL;
    }

    for (; *haystack; haystack++) {
        char *h;
        char *n;
        for (h = haystack, n = needle; (*h != '\0') && (*n != '\0') && (*h == *n); ++h, ++n);
        if (*n == '\0'){
            return haystack;
        }
    }
    return NULL; 
}

//11
void strrev (char s[]){
    int length = strlen(s);
    for(int i = 0, j = length-1; i < j; j--, i++){
        int aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }
}

//12
void strnoV (char s[]){
    int length = strlen(s);
    char aux[length+1];
    int i = 0;
    int j = 0;
    while(s[i] != '\0'){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            i++;
        }
        else{
            aux[j] = s[i];
            i++;
            j++;
        }
    }
    aux[j] = '\0';
    strcpy(s,aux);
}

//13
void truncW (char t[], int n) {
    int i;
    int j = 0;
    int size = strlen(t);
    int counter = 0;
    char aux[size+1];

    for (i = 0; t[i] != '\0'; i++) {
        if (t[i] == ' ') {
            aux[j] = t[i];
            counter = 0;
            j++;
        } else 
            if (counter < n) {
                aux[j] = t[i];
                counter++;
                j++;
            }
    }
    aux[j] = '\0';
    strcpy(t, aux);
}

//14
char charMaisfreq (char s[]){
    if(s[0] == '\0'){
        return 0;
    }
    int countaux = 0;
    char freq;
    for(int i = 0; s[i] != '\0'; i++){
        int count = 0;
        for(int j = 0; s[j] != '\0'; j++){
            if(s[i] == s[j]){
                count++;
            }
        }
        if(count > countaux){
            countaux = count;
            freq = s[i];
        }
    }
    return freq;
}

//15
int iguaisConsecutivos (char s[]){
    int count = 1;
    int consec = 1;
    int length = strlen(s);
    if(s[0] == '\0'){
        return 0;
    }
    if(length == 1){
        return consec;
    }
    for(int i = 1; s[i] != '\0'; i++){
        if(s[i] == s[i-1]){
            count++;
            if(count>consec){
                consec = count;
            }
        }
        else{
            count = 1;
        }
    }
    return consec;
}

//16
int difConsecutivos (char s[]){
    int count = 1;
    int difconsec = 1;
    int length = strlen(s);
    if(s[0] == '\0'){
        return 0;
    }
    if(length == 1){
        return difconsec;
    }
    for(int i = 1; s[i] != '\0'; i++){
        if(s[i] != s[i-1]){
            count++;
            if(count>difconsec){
                difconsec = count;
            }
        }
        else{
            count = 1;
        }
    }
    return difconsec;
}

//17
int maiorPrefixo (char s1 [], char s2 []){
    int count = 0;
    for(int i = 0;(s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++){
        count++;
    }
    return count;
}

//18
int maiorSufixo (char s1 [], char s2 []){
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    int count = 0;
    for(int i = length1-1,j = length2-1;(s1[i] == s2[j]) && i >= 0 && j >= 0 ; i--, j--){
        count++;
    }
    return count;
}

//19
int sufPref (char s1[], char s2[]){
    int length1 = strlen(s1);
    int count = 0;
    for(int i = length1-1,j = 0;(s1[i] == s2[j]) && i >= 0 && (s2[j] != '\0') ; i--, j++){
        count++;
    }
    return count;
}

//20
int contaPal (char s[]){
    int count = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] != ' '){
            count++;
            while(s[i] != ' ' && s[i] != '\0'){
                i++;
            }
        }
    }
    return count;
}

//21
int contaVogais (char s[]){
    int result = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            result++;
        }
    }
    return result;
}

//22
int contida (char a[], char b[]){
    int flag = 0;
    int lengtha = strlen(a);
    int count = 0;
    for(int i = 0; a[i] != '\0'; i++){
        for(int j = 0; b[j] != '\0' && flag == 0; j++){
            if(a[i] == b[j]){
                flag = 1;
                count++;
            }
        }
        if(count == lengtha){
            return 1;
        }
        flag = 0;
    }
    return 0;
}

//23
int palindorome (char s[]){
    int length = strlen(s);
    char aux[length+1];
    strcpy(aux,s);
    for(int i = 0, j = length-1; s[i] != '\0' && j>= 0 && i<j; i++, j--){
        if(s[i] != aux[j]){
            return 0;
        }
    }
    return 1;
}

//24
int remRep (char x[]){
    int length = strlen(x);
    int j = 0;
    for(int i = 0; x[i] != '\0'; i++){
        if(x[i] != x[i+1]){
            x[j] = x[i];
            j++;
        }
    }
    x[j] = '\0';
    return strlen(x);
}

//25
int limpaEspacos (char t[]){
    int length = strlen(t);
    int j = 0;
    for(int i = 0; t[i] != '\0'; i++){
        if(t[i] != ' '){
            t[j] = t[i];
            j++;
        }
    }
    t[j] = '\0';
    return strlen(t);
}

//26
void insere (int v[], int N, int x){
    int i = 0;
    for(i = 0; i < N && v[i] < x; i++);

    for(int j = N;j > i; j--){
        v[j] = v[j-1];
    }

    v[i] = x;
}

//27
void merge (int r [], int a[], int b[], int na, int nb){
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

//28
int crescente (int a[], int i, int j){
    if(i >= j){
        return 0;
    }
    for(; i<j; i++){
        if(a[i]>a[i+1]){
            return 0;
        }
    }
    return 1;
}

//29
int retiraNeg (int v[], int N){
    int count = 0;
    for(int i = 0; i < N; i++){
        if(v[i] < 0){
            for(int j = i; j < N-1; j++){
                v[j] = v[j+1];
            }
        }
        else{
            count++;
        }
    }
    return count;
}

//30
int menosFreq (int v[], int N){
    int count = 0;
    int countaux = 0;
    int menosfreq;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(v[i] == v[j]){
                countaux++;
            }
        }
        if(count > countaux){
            count = countaux;
            menosfreq = v[i];
        }
        countaux = 0;
    }
    return menosFreq;
}

//31
int maisFreq (int v[], int N){
    int count = 0;
    int countaux = 0;
    int maisfreq;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(v[i] == v[j]){
                countaux++;
            }
        }
        if(count < countaux){
            count = countaux;
            maisfreq = v[i];
        }
        countaux = 0;
    }
    return maisFreq;
}

//32
int maxCresc (int v[], int N){
    int count = 1;
    int countaux = 1;
    for(int i = 0; i<N-1; i++){
        if(v[i]>=v[i+1]){
            countaux++;
        }
        else{
            if(count < countaux){
                count = countaux;
            }
            countaux = 1;
        }
    }
    if(count < countaux){
        count = countaux;
    }
    return count;
}

//33
int elimRep (int v[], int n){
    int i = 0;
    int j = 0;
    int k = 0;      
    for (i = 0; i < n; i ++)  {  
        for (j = i + 1; j < n; j++)  {  
            if ( v[i] == v[j])  {   
                for (k = j; k < n - 1; k++)  {  
                    v[k] = v [k + 1];  
                }  
                n--;  
                j--;      
            }  
        }
    }
    int count;
    for(int count = 0; count < n; count++);
    return count;  
}

//34
int elimRepOrd (int v[], int n){
    int i = 0;
    int j = 0;
    int k = 0;      
    for (i = 0; i < n; i ++)  {  
        for (j = i + 1; j < n; j++)  {  
            if ( v[i] == v[j])  {   
                for (k = j; k < n - 1; k++)  {  
                    v[k] = v [k + 1];  
                }  
                n--;  
                j--;      
            }  
        }
    }
    int count;
    for(int count = 0; count < n; count++);
    return count;
}

//Estou cansado, depois faço o resto ahahahah

int main(int argc, char* argv[]){
    return 0;
}