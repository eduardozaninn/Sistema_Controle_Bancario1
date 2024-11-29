/*
    AUTORA: GEOVANA PAULA DA SIVA
*/

#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void SalvarT2(TipoLista *L, MovimentacaoBancaria M){
    TipoApontador R;
    R = (TipoApontador) malloc (sizeof(TipoItem));
    R->conteudo = M;
    R->proximo = NULL;
    R->anterior = NULL;

    L->ultimo->proximo = (TipoApontador) malloc (sizeof(TipoItem));
    L->ultimo->proximo->conteudo = M;
    R = L->ultimo->proximo;
    R->anterior = L->ultimo;
    L->ultimo = R;
    R->proximo = NULL;
}