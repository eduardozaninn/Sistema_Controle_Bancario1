#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"

void remover_conta_inicio(NovoTipoLista *G, TipoLista *L) {

    NovoTipoApontador P = G->NovoPrimeiro;
    NovoTipoApontador aux;

    if (G-> NovoUltimo == NULL) {
        gotoxy(2,29);
        printf("A lista esta vazia! Nao ha Conta Cadastrada para remover.");
        getch();
        return;
    }

    if(P->NovoProximo == NULL){
        if(P->novoconteudo.saldo != 0 || verificar_movimentacoes_pendentes(L, P->novoconteudo.codigoConta) == 1){
            gotoxy(2,29);
            printf("MSG | Essa conta nao pode ser Excluida pois nao esta zerada ou possui Movimentacoes");
            getch();
            return;
        }

        free(G->NovoPrimeiro);
        G->NovoPrimeiro = NULL;
        G->NovoUltimo = NULL;

        gotoxy(2,29);
        printf("Conta removida com sucesso!");
        getch();
        return;
    }

    if(P->NovoProximo != NULL){
        aux = G->NovoPrimeiro;
        if(aux->novoconteudo.saldo != 0 || verificar_movimentacoes_pendentes(L, aux->novoconteudo.codigoConta) == 1){
            gotoxy(2,29);
            printf("MSG | Essa conta nao pode ser Excluida pois nao esta zerada ou possui Movimentacoes");
            getch();
            return;
        }

        G->NovoPrimeiro = aux->NovoProximo;
        free(aux);
        gotoxy(2,29);
        printf("Conta removida com sucesso!");
        getch();
        return;
        
    }
    
}