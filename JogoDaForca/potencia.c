#include <stdio.h>
#include <math.h>
// Escreva uma função potencia() que receba dois inteiros, a e b, calcule a potência a^b, ou seja, a elevado a b e imprima o resultado.

void potencia(int a, int b){
    printf("O numero %d elevado a %d = %d", a, b, (int)pow(a,b));
}
int main(){

    potencia(2,8);

}