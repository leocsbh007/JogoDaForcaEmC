#include <stdio.h>
#include <math.h>
// Escreva uma função potencia() que receba dois inteiros, a e b, calcule a potência a^b, ou seja, a elevado a b e imprima o resultado.

void potencia(int* resultado,int a, int b){
    
    *resultado = (int)pow(a,b);
    printf("O numero %d elevado a %d = %d\n", a, b, *resultado);
}
int main(){
    int resultado;

    potencia(&resultado,2,8);
    printf("O numero 2 elevado a 8 = %d", resultado);

}