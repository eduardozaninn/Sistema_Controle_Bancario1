/*
    AUTORA: GEOVANA PAULA DA SIVA
*/
#include "funcoes.h"
#include <stdio.h>

void SalvarAquivoMovimentacoes(TipoLista *L){

    FILE *Movimentacao = fopen("Movimentacao.dat", "wb");

    if(Movimentacao == NULL){
        tela_principal();
        gotoxy(2,29);
        printf("Erro ao abrir o arquivo!");
        return;
    }

    TipoApontador P = L->primeiro;

    while(P != NULL){
        fwrite(&(P->conteudo), sizeof(MovimentacaoBancaria), 1, Movimentacao);
        P = P->proximo;
    }

    fclose(Movimentacao);
    tela_principal();
    gotoxy(2,29);
    printf("Movimentacoes salvas com sucesso!");
    gotoxy(36,29);
    getch();
}