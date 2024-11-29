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

int datas(char data[10]){
    char dia[3];
    char mes[3];
    char ano[5];
    int Dias;
    int Meses;
    int Anos;

    strncpy(dia, data, 2);
    dia[2] = '\0';

    strncpy(mes, data + 3, 2);
    mes[2] = '\0';

    strncpy(ano, data + 6, 4);
    ano[4] = '\0';

    Dias = atoi(dia);
    Meses = atoi(mes);
    Anos = atoi(ano);


    if(Dias < 1 || Dias > 31){
        return 1;
    }

    if(Meses < 1 || Meses > 12){
        return 1;
    }

    if(Anos < 2024){
        return 1;
    }

    return 0;
}