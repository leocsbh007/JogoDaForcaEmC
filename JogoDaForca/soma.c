#include <stdio.h>


// Escreva uma função soma(int numeros[10]) que receba um array de inteiros e imprime a soma de todos os elementos dentro desse array.
void soma (int* numeros){

    int resultado = 0;
    for (unsigned i = 0; i < 10; i++)
    {
        resultado += numeros[i];
    }
    printf("A soma de todos os numeros e: %d", resultado);
    

}


int main(){
    int numeros[10] = {1,1,1,1,1,1,1,1,1,1};
    soma(numeros);

}