/*
    AUTORA: GEOVANA PAULA DA SIVA
*/

#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void tela_consulta(){

    gotoxy(2, 1);
    printf("UNICV -----------------------------------------------------------------");

    gotoxy(30, 2);
    printf("SISTEMA DE CONTROLE BANCARIO");

    gotoxy(74,1);
    printf("AUTORA..:GEOVANA");

    gotoxy(2,7);
    printf("Data");

    gotoxy(14,7);
    printf("Descricao");

    gotoxy(55,7);
    printf("Tp_Movin");

    gotoxy(67,7);
    printf("Vlr_Movin");

    gotoxy(79,7);
    printf("Saldo");

    gotoxy(2,8);
    printf("----------");

    gotoxy(14,8);
    printf("--------------------------------------------");

    gotoxy(55,8);
    printf("----------");

    gotoxy(67,8);
    printf("----------");

    gotoxy(79,8);
    printf("----------");
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

    gotoxy(1, 5);
    printf("%c", 186);

    gotoxy(90, 5);
    printf("%c", 186);

    gotoxy(1, 6);
    printf("%c", 204);

    gotoxy(90, 6);
    printf("%c", 185);

    for(i = 2; i < 13; i++){
        gotoxy(i, 6);
        printf("%c", 205);
    }

    for(i = 79; i < 90; i++){
        gotoxy(i, 6);
        printf("%c", 205);
    }

    for(i = 67; i < 78; i++){
        gotoxy(i, 6);
        printf("%c", 205);
    }

    for(i = 55; i < 66; i++){
        gotoxy(i, 6);
        printf("%c", 205);
    }

    for(i = 12; i < 54; i++){
        gotoxy(i, 6);
        printf("%c", 205);
    }


    gotoxy(13, 6);
    printf("%c", 203);

    gotoxy(78, 6);
    printf("%c", 203);

    gotoxy(66, 6);
    printf("%c", 203);

    gotoxy(54, 6);
    printf("%c", 203);
    
    //---------------

    for(i = 2; i < 13; i++){
        gotoxy(i, 28);
        printf("%c", 205);
    }

    for(i = 79; i < 90; i++){
        gotoxy(i, 28);
        printf("%c", 205);
    }

    for(i = 67; i < 78; i++){
        gotoxy(i, 28);
        printf("%c", 205);
    }

    for(i = 55; i < 66; i++){
        gotoxy(i, 28);
        printf("%c", 205);
    }

    for(i = 12; i < 54; i++){
        gotoxy(i, 28);
        printf("%c", 205);
    }


    gotoxy(13, 28);
    printf("%c", 202);

    gotoxy(78, 28);
    printf("%c", 202);

    gotoxy(66, 28);
    printf("%c", 202);

    gotoxy(54, 28);
    printf("%c", 202);

    for(i = 7; i < 28; i++){
        gotoxy(13, i);
        printf("%c", 186);

        gotoxy(78, i);
        printf("%c", 186);

        gotoxy(66, i);
        printf("%c", 186);

        gotoxy(54, i);
        printf("%c", 186);

    }

    //-----------------
    
    for(i = 7; i < 28; i++){
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
    }
}