#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"

void ExibirLista(NovoTipoLista *L, int linhaInicial) {
    system("cls");
    TelinhaE();
    NovoTipoApontador atual = L -> NovoPrimeiro;

    linhaInicial = 5;
    int linha = linhaInicial;

    float totalSaldo = 0.0;
    float totalLimite = 0.0;


    gotoxy(2, linha);
    printf("%-2s |%-15s |%-10s |%-5s |%-19s |%-10s |%-10s |%-1s ",
           "Cd", "Banco", "Agen", "Conta", "Tipo Conta", "Saldo", "Limite", "St");
           linha++;

    
    while (atual != NULL) {

        gotoxy(2, linha);
        printf("%d", atual->novoconteudo.codigoConta);
        
        gotoxy(5, linha);
        printf("|%s", atual->novoconteudo.banco);

        gotoxy(22, linha);
        printf("|%s", atual->novoconteudo.agencia);

        gotoxy(34, linha);
        printf("|%d", atual->novoconteudo.numeroConta);

        gotoxy(41, linha);
        printf("|%s", atual->novoconteudo.tp_conta);

        gotoxy(62, linha);
        printf("|%.2f", atual->novoconteudo.saldo);

        gotoxy(74, linha);
        printf("|%.2f", atual->novoconteudo.limite);

        gotoxy(86, linha);
        printf("|%d", atual->novoconteudo.status);

        totalSaldo += atual->novoconteudo.saldo;
        totalLimite += atual->novoconteudo.limite;

        atual = atual->NovoProximo;
        linha++;
    }

    linha++;

    gotoxy(38,linha);
    printf("[Total de Saldo: %.2f, Total de Limite: %.2f]", totalSaldo, totalLimite);
    fflush(stdin);
    getch();
}

    




        