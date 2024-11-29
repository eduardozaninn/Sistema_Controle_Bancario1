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

char *InverterData(char *dt){
    char dia[3];
    char mes[3];
    char ano[5];

    strncpy(dia, dt, 2);
    dia[2] = '\0';

    strncpy(mes, dt + 3, 2);
    mes[2] = '\0';

    strncpy(ano, dt + 6, 4);
    ano[4] = '\0';

    sprintf(dt, "%4s/%2s/%2s", ano, mes, dia);

    return dt;
}