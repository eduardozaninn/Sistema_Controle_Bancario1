/*
    AUTORA: GEOVANA PAULA DA SIVA
*/

#include "funcoes.h"
#include <stdio.h>

void CarregarMovimentacoes(TipoLista *L){
    FILE *CarregarM = fopen("Movimentacao.dat", "rb");

    if(CarregarM == NULL){
        
        tela_principal();
        gotoxy(2,29);
        printf("Erro ao carregar o arquivo!");
        return;
    }

    MovimentacaoBancaria MoviB;

    while(fread(&MoviB, sizeof(MovimentacaoBancaria), 1, CarregarM)){
        TipoApontador P = (TipoApontador) malloc(sizeof(TipoItem));
        P->conteudo = MoviB;
        P->proximo = NULL;
        P->anterior = L->ultimo;

        if(L->ultimo != NULL){
            L->ultimo->proximo = P;

        } else {
            L->primeiro = P;
        }

        L->ultimo = P;
    }

    fclose(CarregarM);
    system("cls");
    tela_principal();
    gotoxy(2,29);
    printf("Movimentacoes Carregadas com Sucesso!");
    gotoxy(40,29);
    getch();
}