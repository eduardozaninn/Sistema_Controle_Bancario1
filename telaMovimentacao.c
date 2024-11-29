/*
    AUTORA: GEOVANA PAULA DA SIVA
*/

#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void Telamovimentacao(TipoLista *listaM, NovoTipoLista *lista){
    int opc;
    NovoTipoApontador novotipo;
    novotipo = lista->NovoPrimeiro;

    if(novotipo == NULL){
        system("cls");
        tela_principal();

        gotoxy(2, 1);
        printf("UNICV -----------------------------------------------------------------");

        gotoxy(30, 2);
        printf("SISTEMA DE CONTROLE BANCARIO");

        gotoxy(74,1);
        printf("AUTORA..:GEOVANA");
        gotoxy(2, 29);
        printf("Encontramos 0 contas cadastradas :( ---------------------------- ");

        gotoxy(67, 29);
        printf("Cadastre uma conta! :)");
        gotoxy(90, 29);
        getch();
        return;
    }

    do{
        system("cls");

        tela_principal();
        gotoxy(2, 1);
        printf("UNICV -----------------------------------------------------------------");

        gotoxy(30, 2);
        printf("SISTEMA DE CONTROLE BANCARIO");

        gotoxy(74,1);
        printf("AUTORA..:GEOVANA");
        
        

        gotoxy(26,12);
        printf("1. Realizar Movimentacao de Debito ou Credito");

        gotoxy(26,14);
        printf("2. Realizar Transferencia entre as contas");

        gotoxy(26,16);
        printf("3. Consultar Movimentacoes Bancarias");

        gotoxy(26,19);
        printf("4. Voltar para Menu");

        gotoxy(2,29);
        printf("MSG | Opcao... ");
        gotoxy(17,29);
        scanf("%d", &opc);

        switch(opc){
            case 1:
                Movimentacoes(listaM, lista);
                break;
            case 2:
                Transacoes(listaM, lista);
                break;
            case 3:
                ConsultarMovimentacoes(listaM, lista);
                break;
            case 4:
                
                break;
            default:
                gotoxy(2, 29);
                printf("                                                       ");
                gotoxy(2, 29);
                printf("MSG | Opcao invalida!");
                gotoxy(25, 29);
                getch(); 
        }
    } while(opc != 4);
}
