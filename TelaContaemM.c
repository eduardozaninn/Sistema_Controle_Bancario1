/*
    AUTORA: GEOVANA PAULA DA SIVA
*/

#include "funcoes.h"
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void TelaContaemM(NovoTipoLista *L, int codigo){
    NovoTipoApontador P;
    P = L->NovoPrimeiro;

    while(P != NULL){

        if(codigo == P->novoconteudo.codigoConta){

            gotoxy(29,11);
            printf("%s", P->novoconteudo.banco);

            gotoxy(29,12);
            printf("%s", P->novoconteudo.agencia);

            gotoxy(29,13);
            printf("%d", P->novoconteudo.numeroConta);

            gotoxy(29,14);
            printf("%s", P->novoconteudo.tp_conta);

            gotoxy(29,15);
            printf("%.2f", P->novoconteudo.saldo);

            gotoxy(29,16);
            printf("%.2f", P->novoconteudo.limite);
        }

        P = P->NovoProximo;
    }

    return;
}