/*
    AUTORA: GEOVANA PAULA DA SIVA
*/

#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void ConsultarMovimentacoes(TipoLista *L, NovoTipoLista *G){
    int cod;
    int esc;
    NovoTipoApontador aux;

    
    do{
        system("cls");
        tela_consulta();

        do{
            gotoxy(2,29);
            printf("MSG | Insira 0 para sair..");
            gotoxy(2, 5);
            printf("Codigo_Conta..: ");

            gotoxy(19,5);
            scanf("%d", &cod);
            fflush(stdin);

            if(cod == 0){
                return;
            }

            aux = pesquisa(G, cod);

            if(aux == NULL){
                gotoxy(2,29);
                printf("MSG | Conta nao Encontrada! Tente Novamente..");
                gotoxy(47,29);
                getch();
                gotoxy(2,29);
                printf("                                                ");
                gotoxy(19,5);
                printf("            ");
            }

        } while(aux == NULL);
        ContaConsultarM(G, cod);
        consultarM(L, cod);

        gotoxy(2, 29);
        printf("Deseja realizar mais uma Consulta? 1-sim 2-nao... ");
        gotoxy(56, 29);
        scanf("%d", &esc);
        fflush(stdin);

    } while(esc == 1);    
    
}