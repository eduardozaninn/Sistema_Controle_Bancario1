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

char* UltimaDataMovimentacaoc(TipoLista *L,char *data, int cod){
    TipoApontador P;
    P = L->ultimo;

    while(P != NULL){

        MovimentacaoBancaria MoviB = P->conteudo;

        if(cod == MoviB.codico_conta){
            strncpy(data, MoviB.dt_movimentacao, 10);
            data[10] = '\0';
            return data;
        }
        P = P->anterior;
    }

    return NULL;
}