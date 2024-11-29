#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

int contadorM(TipoLista *L){
    TipoApontador p;
    p = L->primeiro;
    int contM = 0;

    while(p != NULL){
        contM++;
        p = p->proximo;
    }

    return contM;
}