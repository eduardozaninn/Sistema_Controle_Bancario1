#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"


void salvarContas(NovoTipoLista *L) {

    // cria um arquivo binário "ContasCadastradas.dat" para escrita ("wb").
    // Caso o arquivo já exista, ele será sobrescrito.
    FILE *arquivoContasBanc = fopen("ContasCadastradas.dat", "wb");


    if (arquivoContasBanc == NULL) {
    TelinhaE();
    gotoxy(2,29);
    printf("Erro ao abrir o arquivo de Contas Cadastradas!");
    return;
   }

   // Cria um ponteiro auxiliar que aponta para o primeiro nó da lista encadeada.
   NovoTipoApontador aux = L -> NovoPrimeiro;

   // Percorre  por cada nó da lista encadeada até o final (quando `aux` for NULL).
   while (aux != NULL) {

     // Escreve o conteúdo do nó atual (uma estrutura do tipo `ContaBancaria`) no arquivo.
     fwrite(&aux->novoconteudo, sizeof(ContaBancaria), 1, arquivoContasBanc);

     // Avança para o próximo nó da lista encadeada.
     aux = aux -> NovoProximo;
   }

  fclose(arquivoContasBanc);
  gotoxy(2,29);
  printf("Contas Cadastradas salvos com sucesso!");
  getch();
}


