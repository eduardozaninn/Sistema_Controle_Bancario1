#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>


int main(){
    int opc;
    TipoLista listaM;
    NovoTipoLista lista;
    Inicializa(&listaM, &lista);
    lerDoArquivoContas(&lista);
    CarregarMovimentacoes(&listaM);
    
    do{
        system("cls");
        tela_principal();
        gotoxy(2, 1);
        printf("UNICV ------------------------------------------------------");

        gotoxy(30, 2);
        printf("SISTEMA DE CONTROLE BANCARIO");

        gotoxy(63,1);
        printf("AUTORES..:GEOVANA E EDUARDO");

        gotoxy(31,11);
        printf("1. Cadastrar Contas..");

        gotoxy(31,13);
        printf("2. Movimentacao Financeira..");

        gotoxy(31,17);
        printf("3. Salvar e Sair..");

        gotoxy(2,29);
        printf("MSG | Opcao... ");
        gotoxy(17,29);
        scanf("%d", &opc);

        switch(opc){
            case 1:
                TelaInfo(&lista, &listaM);
                break;
            case 2:
                Telamovimentacao(&listaM, &lista);
                break;
            case 3:
                salvarContas(&lista);
                SalvarAquivoMovimentacoes(&listaM);
                break;
            default:
                gotoxy(2, 29);
                printf("                                                       ");
                gotoxy(2, 29);
                printf("MSG | Opcao invalida!");
                gotoxy(25, 29);
                getch(); 
        }
    } while(opc != 3);
}