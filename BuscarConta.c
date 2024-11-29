#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"


void BuscarConta(NovoTipoLista *L) {

    int codigo, continuar;
    NovoTipoApontador resultado;

    do{
        system("cls");
        TelinhaE();
        TelaConta();

        gotoxy(38,10);
        scanf("%d", &codigo);
        fflush(stdin);

        resultado = pesquisa(L, codigo);

       if (resultado != NULL) {

        gotoxy(38,10);
        printf("%d", resultado->novoconteudo.codigoConta);
        gotoxy(38,12);
        printf("%s", resultado->novoconteudo.banco);
        gotoxy(38,14);
        printf("%s", resultado->novoconteudo.agencia);
        gotoxy(38,16);
        printf("%d", resultado->novoconteudo.numeroConta);
        gotoxy(38,18);
        printf("%s", resultado->novoconteudo.tp_conta);
        gotoxy(38,20);
        printf("%.2f", resultado->novoconteudo.saldo);
        gotoxy(38,22);
        printf("%.2f", resultado->novoconteudo.limite);
        gotoxy(38,24);
        printf("%d", resultado->novoconteudo.status);
        
    } else {
        gotoxy(2,29);
        printf(" MSG | Conta com o codigo %d nao encontrada.", codigo);
        getch();
        gotoxy(2,29);
        printf("                                                 ");
        gotoxy(38,10);
        printf("         ");
    }

    gotoxy(2,29);
    printf("Deseja procurar outra conta? (1 - SIM / 2 - NAO): ");
    scanf("%d", &continuar);
    fflush(stdin);

   } while (continuar == 1);
}



        