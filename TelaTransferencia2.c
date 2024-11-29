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

NovoTipoApontador TelaContaemTransferencia2(NovoTipoLista *L, int codigo){
    NovoTipoApontador P;
    P = L->NovoPrimeiro;
    

    while(P != NULL){

        if(codigo == P->novoconteudo.codigoConta){
            gotoxy(72, 8);
            printf("%d", P->novoconteudo.codigoConta);

            gotoxy(72, 9);
            printf("%s", P->novoconteudo.banco);

            gotoxy(72, 10);
            printf("%s", P->novoconteudo.agencia);

            gotoxy(72, 11);
            printf("%d", P->novoconteudo.numeroConta);

            gotoxy(72,12);
            printf("%s", P->novoconteudo.tp_conta);

            gotoxy(72, 13);
            printf("%.2f", P->novoconteudo.saldo);

            gotoxy(72, 14);
            printf("%.2f", P->novoconteudo.limite);

            gotoxy(72, 15);
            printf("%.2f", P->novoconteudo.saldo + P->novoconteudo.limite);
        }

        P = P->NovoProximo;
    }

    return NULL;
}