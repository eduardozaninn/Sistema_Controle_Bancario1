/*
    AUTORA: GEOVANA PAULA DA SIVA
*/

#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void SalvarMovimentacoes(TipoLista *L, MovimentacaoBancaria MoviB){
    TipoApontador P;
    P = (TipoApontador) malloc (sizeof(TipoItem));
    P->conteudo = MoviB;
    P->proximo = NULL;
    P->anterior = NULL;

    if(L->primeiro == NULL){
        L->primeiro = P;
        L->ultimo = P;
    }
    else{
        L->ultimo->proximo = (TipoApontador) malloc (sizeof(TipoItem));
        L->ultimo->proximo->conteudo = MoviB;
        P = L->ultimo->proximo;
        P->anterior = L->ultimo;
        L->ultimo = P;
        P->proximo = NULL;
    }    
}