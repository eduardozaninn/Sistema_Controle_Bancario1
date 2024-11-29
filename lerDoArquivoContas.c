#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"


void lerDoArquivoContas(NovoTipoLista *L) {

    // Abre o arquivo "ContasCadastradas.dat" no modo leitura binária
    FILE *arquivoContasBanc = fopen("ContasCadastradas.dat", "rb");

    // Se fopen retornar NULL, significa que o arquivo não foi encontrado ou ocorreu um erro ao abri-lo
    if (arquivoContasBanc == NULL) {
    TelinhaE();
    gotoxy(2,29);
    printf("Arquivo de Contas Cadastradas nao encontrado!");
    getch();
    system("cls");
    return;
     
    }

    // uma variável temporária para armazenar os dados lidos do arquivo
    ContaBancaria temp;

    NovoTipoApontador aux = L ->NovoPrimeiro;
    while (aux != NULL) {
        NovoTipoApontador liberar = aux;
        aux = aux -> NovoProximo;
        free(liberar);
    }

    L ->NovoPrimeiro = NULL;
    L ->NovoUltimo = NULL;

      
     // fread retorna o número de elementos lidos com sucesso; aqui verifica se conseguiu ler 1 elemento.
      while (fread(&temp, sizeof(ContaBancaria), 1, arquivoContasBanc)) {

        // Aloca memória para um novo nó da lista
        NovoTipoApontador novo  = (NovoTipoApontador) malloc(sizeof(TipoItem));
        if (novo == NULL) {
            gotoxy(2,29);
            printf("Memoria Insuficiente!");
            getch();
            fclose(arquivoContasBanc);
            return;
        }

        // Copia os dados lidos do arquivo para o novo nó
        novo -> novoconteudo = temp;

        // Define o ponteiro para o próximo nó como NULL
        novo -> NovoProximo = NULL;

        // Verifica se a lista está vazia.
        if (L -> NovoPrimeiro == NULL) {
            
            // Se estiver vazia, este será o primeiro nó da lista.
            L -> NovoPrimeiro = novo;

        } else {

            // O ponteiro `NovoProximo` do último nó existente apontará para o novo nó.
            L -> NovoUltimo -> NovoProximo = novo;
        }

            // Atualiza o ponteiro do último nó para o novo nó recém-criado.
            L -> NovoUltimo = novo;
        }
    

    fclose(arquivoContasBanc);
    TelinhaE();
    gotoxy(2,29);
    printf("Arquivo de Contas Cadastradas carregado com sucesso!");
    getch();
    system("cls");
}




