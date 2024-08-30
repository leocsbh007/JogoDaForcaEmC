/****************************************Copyright (c)****************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:               forca.c
** Descriptions:            Description
**
**--------------------------------------------------------------------------------------------------------
** Created by:              Leonardo Souza
** Created date:            Ago 30, 2024
** Version:                 v1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
**
*********************************************************************************************************/

/*********************************************************************************************************
 * 											INCLUDES
 *********************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h"


/*********************************************************************************************************
 * 											VARIABLES
 *********************************************************************************************************/
char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;





/*********************************************************************************************************
* Function Name  : abertura
* Description    : Function to initialize can 0
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
 *********************************************************************************************************/
void abertura(){
    printf("**********************\n");
    printf("*   JOGO DE FORCA    *\n");
    printf("**********************\n\n");
}

/*********************************************************************************************************
* Function Name  : chuta
* Description    : Function to initialize can 0
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
 *********************************************************************************************************/
void chuta() {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

/*********************************************************************************************************
* Function Name  : jachutou
* Description    : Function to initialize can 0
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
 *********************************************************************************************************/
int jachutou(char letra){
    int achou = 0;            
    for (int j = 0; j < chutesdados; j++) {
        if (letra == chutes[j]){                    
            achou = 1;
            break;
        }      
    }
    return achou;
}

/*********************************************************************************************************
* Function Name  : desenhaforca
* Description    : Function to initialize can 0
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
 *********************************************************************************************************/
void desenhaforca() {

    printf("Voce ja deu %d chutes\n", chutesdados);

    for(unsigned int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

/*********************************************************************************************************
* Function Name  : escolhepalavra
* Description    : Function has numbers, file words on the first line.
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
 *********************************************************************************************************/
void escolhepalavra() {
    //sprintf(palavrasecreta, "MELANCIA");
    // Cria uma variavel do tipo aquivos, ela é um ponteiro
    FILE* f;

    // abre o arquivo somente para leitura (parametro "r" - read), e guarda a posição em f
    f = fopen("palavras.txt", "r");
    // Verifica de o valor não é valido, se não houve algum problema com a abertura/leitura do arquivo
    if (f == 0){
        printf("Banco de dados nao disponivel\n\n");
        printf("O programa sera finalzado\n\n");
        exit(1);
    }

    unsigned int qtdpalavras = 0;
    // Acessa a primeira linha do arquivo referenciado pelo ponteiro f e joga o valor pra qtdpalavras
    fscanf(f, "%d", &qtdpalavras);
    //printf("%d", qtdpalavras);

    //cria uma semente aleatoria
    srand(time(0));
    // cria um numero aleatorio onde o seu valor maximo será o tamanho da lista que esta contida na 
    // primeira linha do arquivo
    unsigned int numerorandomico = rand() % qtdpalavras;

    //Varre o arquivo até o valir randomico para buscar a palavra que será usada no jogo
    for (unsigned int i = 0; i < numerorandomico; i++)
    {
        fscanf(f, "%s", &palavrasecreta);
    }

    fclose(f);
}

/*********************************************************************************************************
* Function Name  : enforcou
* Description    : Function to initialize can 0
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
 *********************************************************************************************************/
int enforcou(){
    unsigned int erros = 0, j = 0;
    for(signed int i = 0; i < chutesdados; i++){
        unsigned int existe = 0;

        if (jachutou(palavrasecreta[j])){
            existe = 1;
            j++;
        }
        if(!existe) erros++;
    }
    return erros >= 5;
}

/*********************************************************************************************************
* Function Name  : acertou
* Description    : Function to initialize can 0
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
 *********************************************************************************************************/
int acertou(){
    for (unsigned int i = 0; i < strlen(palavrasecreta); i++)
    {
        if (!jachutou(palavrasecreta[i])){
            return 0;
        }
    }
    return 1;
    

}

/*********************************************************************************************************
* Function Name  : adicionapalavra
* Description    : Function has numbers, file words on the first line.
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
 *********************************************************************************************************/
void adicionapalavra(){
    
    char quer;

    printf("Voce quer adicionar mais uma palavra a bonco (S/N) ");
    scanf(" %c", &quer);

    if (quer == 'S'){
                char novapalvra [20];
        printf("Digite a nova palvra: ");
        scanf("%s", &novapalvra);

        FILE * f;
        // abre o arquivo somente para leitura (parametro "r+" - read e write), e guarda a posição em f
        f = fopen("palavras.txt", "r+");
        // Verifica de o valor não é valido, se não houve algum problema com a abertura/leitura do arquivo
        if (f == 0){
            printf("Banco de dados nao disponivel\n\n");
            printf("O programa sera finalzado\n\n");
            exit(1);
        }

        unsigned int qtd = 0;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalvra);

        fclose(f);

    }

}


/*********************************************************************************************************
* Function Name  : main
* Description    : Function to initialize can 0
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
 *********************************************************************************************************/
int main() {

    //int acertou = 0;
    //int enforcou = 0;

    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();

    } while (!acertou() && !enforcou());

    adicionapalavra();

}
