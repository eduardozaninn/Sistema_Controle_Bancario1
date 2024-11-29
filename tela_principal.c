/*
    AUTORA: GEOVANA PAULA DA SIVA
*/

#include "funcoes.h"
#include <windows.h>
#include <stdio.h>

void tela_principal(){

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
    
    for(i = 5; i < 28; i++){
        gotoxy(1, i);
        printf("%c", 186);

        gotoxy(90, i);
        printf("%c", 186);

    }

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

        gotoxy(i, 4);
        printf("%c", 205);

        gotoxy(i,28);
        printf("%c", 205);
    }
}