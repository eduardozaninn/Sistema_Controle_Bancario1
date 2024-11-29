/*
  AUTOR: EDUARDO BERNARDES ZANIN
*/

#include "funcoes.h"
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

void remover_conta_final(NovoTipoLista *G, TipoLista *L) {
    


    if (G->NovoPrimeiro == NULL){
        gotoxy(2,29);
        printf("A lista esta vazia! Não ha Contas Cadastradas para remover.");
        getch();
        return;
    }

    NovoTipoApontador R = G->NovoPrimeiro;
    NovoTipoApontador P = R->NovoProximo;

    if(G->NovoPrimeiro->NovoProximo == NULL){
        if(G->NovoPrimeiro->novoconteudo.saldo != 0 || verificar_movimentacoes_pendentes(L, G->NovoPrimeiro->novoconteudo.codigoConta) == 1){
            gotoxy(2,29);
            printf("MSG | Essa conta nao pode ser Excluida pois nao esta zerada ou possui Movimentacoes");
            getch();
            return;
        }
        else{
            free(G->NovoPrimeiro);
            G->NovoPrimeiro = NULL;
            G->NovoUltimo = NULL;

            gotoxy(2,29);
            printf("Conta removida com sucesso!");
            getch();
            return;
        }
    }

    else if(G->NovoPrimeiro->NovoProximo != NULL){

        while(P->NovoProximo != NULL){
            P = P->NovoProximo;
            R = R->NovoProximo;
        }

        if(P->novoconteudo.saldo != 0 || verificar_movimentacoes_pendentes(L, P->novoconteudo.codigoConta) == 1){
            TelinhaE();
            gotoxy(2,29);
            printf("MSG | Essa conta nao pode ser Excluida pois nao esta zerada ou possui Movimentacoes");
            getch();
            return;
        }
        else{
            free(P);
            R->NovoProximo = NULL;
            G->NovoUltimo = R;

            gotoxy(2,29);
            printf("Conta removida com sucesso!");
            getch();
            return;
        }
    }

}   