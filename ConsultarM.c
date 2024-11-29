#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void consultarM(TipoLista *L, int cod){

    TipoApontador P;
    P = L ->primeiro;
    int linha = 9;
    int linhaFolha = 19;
    int ContLinha = 0;

    while(P != NULL){
        

        if(cod == P->conteudo.codico_conta){

            gotoxy(2,linha);
            printf("%s", P->conteudo.dt_movimentacao);

            gotoxy(14,linha);
            printf("%s", P->conteudo.decricao);

            if(P->conteudo.tp_movimentacao == 1){
                gotoxy(55,linha);
                printf("Credito");
            }

            else if(P->conteudo.tp_movimentacao == 2){
                gotoxy(55,linha);
                printf("Debito");
            }

            gotoxy(67,linha);
            printf("R$ %.2f", P->conteudo.valor_movimentado);

            gotoxy(79,linha);
            printf("R$ %.2f", P->conteudo.vlr_saldoAtualizado);

            linha++;
            ContLinha++;
        }

        if(ContLinha >= linhaFolha){
            gotoxy(2,29);
            printf("MSG | Pressine qualquer tecla para ir para seguir...");
            gotoxy(55,29);
            getch();
            system("cls");
            tela_consulta();
            linha = 9;
            ContLinha = 0;
        }

        P = P->proximo;
    }

}