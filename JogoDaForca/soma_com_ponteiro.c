#include <stdio.h>

//Escreva uma função soma que recebe um ponteiro de inteiro num e mais dois inteiros a e b. A função deve calcular a soma de a+b em num.
void soma(int* num, int a, int b){
    *num = a+b;
}

int main(){
    int num, a, b;

    a = 10;
    b = 5;

    

    soma(&num, a, b);

    printf("A soma de %d + %d = %d \n", a, b, num);

}