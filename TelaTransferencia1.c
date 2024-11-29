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

NovoTipoApontador TelaContaemTransferencia1(NovoTipoLista *L, int codigo){
    NovoTipoApontador P;
    P = L->NovoPrimeiro;
    

    while(P != NULL){

        if(codigo == P->novoconteudo.codigoConta){
            gotoxy(28, 8);
            printf("%d", P->novoconteudo.codigoConta);

            gotoxy(28, 9);
            printf("%s", P->novoconteudo.banco);

            gotoxy(28, 10);
            printf("%s", P->novoconteudo.agencia);

            gotoxy(28, 11);
            printf("%d", P->novoconteudo.numeroConta);

            gotoxy(28,12);
            printf("%s", P->novoconteudo.tp_conta);

            gotoxy(28, 13);
            printf("%.2f", P->novoconteudo.saldo);

            gotoxy(28, 14);
            printf("%.2f", P->novoconteudo.limite);

            gotoxy(28, 15);
            printf("%.2f", P->novoconteudo.saldo + P->novoconteudo.limite);
        }

        P = P->NovoProximo;
    }

    return NULL;
}