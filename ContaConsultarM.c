#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void ContaConsultarM(NovoTipoLista *G, int cod){
    NovoTipoApontador P;
    P = G->NovoPrimeiro;

    while(P != NULL){

        if(cod == P->novoconteudo.codigoConta){
            gotoxy(23,5);
            printf("- %s", P->novoconteudo.banco);

            gotoxy(40,5);
            printf("Agencia: %s", P->novoconteudo.agencia);

            gotoxy(60,5);
            printf("Cta: %d", P->novoconteudo.numeroConta);

            gotoxy(70, 5);
            printf("Tp: %s", P->novoconteudo.tp_conta);
            return;
        }
        P = P->NovoProximo;
    }
}