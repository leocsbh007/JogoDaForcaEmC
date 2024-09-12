#include <stdio.h>
#include <stdlib.h>


char** mapa;
int linhas, colunas;

int main (){   

    // Cria um ponteiro de FILE para ler o arquivo
    FILE* f;

    // abre o arquivo como somente leitura "r"e guarda em f
    f = fopen("mapa.txt", "r");

    // Verifica se o arquivo foi aberto corretamente
    if (f == 0)
    {
        printf("Erro ao abrir o arquivo \n");
        exit(1);
    }

    // Lê a primeira linha do arquivo que traz a dimensão da matriz
    fscanf(f,"%d %d",&linhas, &colunas);
    //printf("%d %d\n", linhas, colunas);

    // Reserva espaço de memoria para as linhas da matriz, ponteiro das linhas
    mapa = malloc(sizeof(char *) * linhas);

    // Reserva espaço de memoria para as colunas da matriz, ponteiro das colunas
    for (signed i = 0; i < colunas; i++)
    {
        mapa[i] = malloc(sizeof(char) * (colunas+1));
    }

    // lê linha a linha do arquivo e joga na matriz 
    for (signed int i = 0; i < linhas; i++)
    {
        fscanf(f, "%s", mapa[i]);
    }

    // imprime o desenho do mapa que foi lido do arquivo
    for (signed int i = 0; i < linhas; i++)
    {
        printf("%s\n", mapa[i]);
        
    }

    fclose(f);
    
    // Libera a memoria das linhas
    for (signed i = 0; i < linhas; i++)
    {
        free(mapa[i]);
    }
    // libera a memoria das colunas
    free(mapa);
    
    
}