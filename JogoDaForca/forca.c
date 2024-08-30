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
* Description    : Function to initialize can 0
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
 *********************************************************************************************************/
void escolhepalavra() {
    sprintf(palavrasecreta, "MELANCIA");
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

}
