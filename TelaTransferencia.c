/*
    AUTORA: GEOVANA PAULA DA SIVA
*/

#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void tela_transferencia(){

    gotoxy(2, 1);
    printf("UNICV -----------------------------------------------------------------");

    gotoxy(30, 2);
    printf("SISTEMA DE CONTROLE BANCARIO");

    gotoxy(74,1);
    printf("AUTORA..:GEOVANA");

    int i;

    gotoxy(1, 4);
    printf("%c", 204);

    gotoxy(90, 4);
    printf("%c", 185);

    gotoxy(1, 28);
    printf("%c", 204);

    gotoxy(90, 28);
    printf("%c", 185);

    

    for(i = 1; i < 4; i++){
        gotoxy(1, i);
        printf("%c", 186);

        gotoxy(90, i);
        printf("%c", 186);

    }
    
    for(i = 5; i < 17; i++){
        gotoxy(1, i);
        printf("%c", 186);

        gotoxy(90, i);
        printf("%c", 186);

    }

    for(i = 18; i < 28; i++){
        gotoxy(1, i);
        printf("%c", 186);

        gotoxy(90, i);
        printf("%c", 186);

    }

    gotoxy(1, 17);
    printf("%c", 204);

    gotoxy(90, 17);
    printf("%c", 185);

    gotoxy(90,29);
    printf("%c", 186);

    gotoxy(1,29);
    printf("%c", 186);

    gotoxy(1, 0);
    printf("%c", 201);

    gotoxy(90, 0);
    printf("%c", 187);

    gotoxy(1, 30);
    printf("%c", 200);

    gotoxy(90, 30);
    printf("%c", 188);

    for(i = 2; i < 90; i++){
        gotoxy(i, 0);
        printf("%c", 205);

        gotoxy(i, 30);
        printf("%c", 205);

        gotoxy(i,28);
        printf("%c", 205);
    }
    
    for(i = 2; i < 44; i++){
        gotoxy(i, 4);
        printf("%c", 205);
    }

    gotoxy(44, 4);
    printf("%c", 203);

    for(i = 45; i < 90; i++){
        gotoxy(i, 4);
        printf("%c", 205);
    }

    for(i = 5; i < 17; i++){
        gotoxy(44, i);
        printf("%c", 186);
    }

    gotoxy(44, 17);
    printf("%c", 202);

    for(i = 2; i < 44; i++){
        gotoxy(i, 17);
        printf("%c", 205);
    }

    for(i = 45; i < 90; i++){
        gotoxy(i, 17);
        printf("%c", 205);
    }
}