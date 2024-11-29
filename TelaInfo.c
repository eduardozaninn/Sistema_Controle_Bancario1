#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"


void TelaInfo(NovoTipoLista *L, TipoLista *G) {

    int opc = 0;

    do{
        system("cls");
        TelinhaE();

        gotoxy(29,6);
        printf("CADASTRAMENTO DE CONTA BANCARIA");

        gotoxy(31,9);
        printf("1 - Cadastrar Conta no Final");
        
        gotoxy(31,11);
        printf("2 - Cadastrar Conta no Inicio ");
        
        gotoxy(31,13);
        printf("3 - Cadastrar Conta na Posicao ");
        
        gotoxy(31,15);
        printf("4 - Remover Conta no final ");
        
        gotoxy(31,17);
        printf("5 - Remover Conta no incio ");
        
        gotoxy(31,19);
        printf("6 - Remover Conta na Posicao ");
        
        gotoxy(31,21);
        printf("7 - Alteracao de Conta ");
        
        gotoxy(31,23);
        printf("8 - Listar Conta ");
        
        gotoxy(31,25);
        printf("9 - Voltar para Menu ");
        
       gotoxy(2,29);
        printf("MSG | Opcao... ");
        scanf("%d", &opc);
        
        gotoxy(2,29);
        printf("                                                     ");
        system("cls");



        switch (opc) {
         case 1:
            Cadastramento_Conta_Bancaria(L, opc);
            system("cls");
            break;


        case 2:
            
            Cadastramento_Conta_Bancaria(L, opc);
            system("cls");
            break;

        case 3:
            Cadastramento_Conta_Bancaria(L, opc);
            system("cls");
            break;

        case 4:
            TelinhaE();
            remover_conta_final(L, G);
            break;

        case 5:
            TelinhaE();
            remover_conta_inicio(L, G);
            break;

        case 6:
            TelinhaE();
            remover_posicao(L, G);
            break;

        case 7:
        
            TelinhaE();
            TelaConta(); 
            alterar_contas(L);
            break;

        case 8:
            Listar_Contas(L);
            break;

        case 9:

            break;
        default:
            system("cls");
            TelinhaE();
            gotoxy(30,15);
            printf("Opcao invalida!\n");
            getch();
            system("cls");

            break;   
        }

    } while(opc!=9);

    return ;
}



