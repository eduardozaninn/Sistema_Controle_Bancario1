#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"


void alterar_contas(NovoTipoLista *L) {

    NovoTipoApontador aux2;
    ContaBancaria cont_banc;
    int resp;
    int campo;

    do {
        do{

            TelinhaE();
            TelaConta();
            gotoxy(2,29);
            printf("MSG | Digite 0 para sair...");
            gotoxy(38,10);
            scanf("%d", &cont_banc.codigoConta); 
            fflush(stdin);
            
            aux2 = pesquisa(L, cont_banc.codigoConta);
            
            
            if(aux2 == NULL && cont_banc.codigoConta != 0){
                gotoxy(2,29);
                printf("                        ");
                gotoxy(2,29);
                printf("Conta nao encontrada");
                getch();
                gotoxy(2,29);
                printf("                    ");
                gotoxy(38,10);
                printf("         ");

            }
                
        } while (aux2 == NULL && cont_banc.codigoConta != 0);

        if (cont_banc.codigoConta != 0) {
            cont_banc = aux2 -> novoconteudo; 

            gotoxy(38,12);
            printf("%s", cont_banc.banco);
            gotoxy(38,14);
            printf("%s", cont_banc.agencia);
            gotoxy(38,16);
            printf("%d", cont_banc.numeroConta);  
            gotoxy(38,18);
            printf("%s", cont_banc.tp_conta);
            gotoxy(38,20);
            printf("%.2f", cont_banc.saldo);
            gotoxy(38,22);
            printf("%.2f", cont_banc.limite);
            gotoxy(38,24);
            printf("%d", cont_banc.status);

            do {
                do{
                    gotoxy(2,29);
                    printf("                            ");

                    gotoxy(2,29);
                    printf("Escolha um campo a ser alterado [0 - Sair]:");
                    gotoxy(46,29);
                    scanf("%d", &campo);
                    fflush(stdin);
                    gotoxy(2,29);
                    printf("                                               ");

                    
                    if (campo < 0 || campo > 7) {
                        gotoxy(2,29);
                        printf("                               ");
                        gotoxy(2,29);
                        printf("Campo Invalido! Escolha um numero entre 1 e 7.");
                        getch();
                        gotoxy(46,29);
                        printf("        ");
                        gotoxy(2,29);
                        printf("                                              ");
                    }
                    
                } while (campo < 0 || campo > 7);
                

                if (campo != 0) {

                    switch(campo) {
                    
                    case 1:
                         gotoxy(38,12);
                         printf("                ");
                         gotoxy(38,12);
                         fgets(cont_banc.banco, 30, stdin);
                         break;

                    case 2:
                         gotoxy(38,14);
                         printf("                  ");
                         gotoxy(38,14);
                         fgets(cont_banc.agencia, 10, stdin);
                         break;

                    case 3:
                         gotoxy(38,16);
                         printf("                                      ");
                         gotoxy(38,16);
                         scanf("%d", &cont_banc.numeroConta);
                         fflush(stdin);
                         break;

                    case 4:
                         gotoxy(38,18);
                         printf("           ");
                         gotoxy(38,18);
                         strcpy(cont_banc.tp_conta,TipoConta());
                         break;

                    case 5:
                         gotoxy(2,29);
                         printf("Este campo nao pode ser alterado!");
                         getch();
                         break;
                    
                    case 6:
                         gotoxy(2,29);
                         printf("Este campo nao pode ser alterado!");
                         getch();
                         break;
                    
                    case 7:
                         gotoxy(2,29);
                         printf("Este campo nao pode ser alterado!");
                         getch();
                         break;
                    } 
                }
            } while (campo != 0);

            gotoxy(2,29);
            printf("                                 ");
            gotoxy(2,29);
            printf("Confirma a a alteracao [1 - SIM / 2 - NAO]? ");
            scanf("%d", &resp);

            if (resp == 1) {
                
                aux2 -> novoconteudo = cont_banc;
            }            
        }

        TelinhaE();
        gotoxy(2,29);
        printf("Desejar alterar outra Conta [1 - SIM / 2 - NAO]? ");
        scanf("%d", &resp);
        fflush(stdin);

    } while (resp == 1);
}
