#include <stdio.h>
#include <string.h>


char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

void abertura(){
    printf("**********************\n");
    printf("*   JOGO DE FORCA    *\n");
    printf("**********************\n\n");
}

void chuta() {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

void forca(){
    printf("  --------\n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("  ^");
    printf("-------------\n");
}

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

void escolhepalavra() {
    sprintf(palavrasecreta, "MELANCIA");
}

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

int acertou(){
    for (unsigned int i = 0; i < strlen(palavrasecreta); i++)
    {
        if (!jachutou(palavrasecreta[i])){
            return 0;
        }
    }
    return 1;
    

}

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
