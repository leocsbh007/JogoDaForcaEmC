#include <stdio.h>

void calcula(int* c){
    (*c)++;
    printf("Calcula %d %d \n", *c, c);   
    
}


int main()
{
    int c = 10;

    printf("Main %d %d \n", c, &c);
    calcula(&c);
    printf("Main %d %d \n", c, &c);
}
