/*
    AUTORA: GEOVANA PAULA DA SIVA
*/

#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>

void Transacoes(TipoLista *L, NovoTipoLista *G){
    int x;
    int esc;
    char DataU[11];
    char DataU2[11];
    char dataM[11];
    NovoTipoApontador AUX;
    NovoTipoApontador AUX1;
    MovimentacaoBancaria MoviB;
    MovimentacaoBancaria MoviB2;

    do{
        system("cls");
        tela_transferencia();
        dadosC_telaTransferencia();

        MoviB.sequencial = contadorM(L) + 1;
        MoviB2.sequencial = MoviB.sequencial + 1;

        strcpy(MoviB.decricao, "Transferencia");
        strcpy(MoviB2.decricao, "Transferencia");

        MoviB.tp_movimentacao = 2;
        MoviB2.tp_movimentacao = 1;

        gotoxy(30,19);
        printf("Data da Movimentacao:....  ");
        gotoxy(30,20);
        printf("Valor a ser Transferido: R$");

        do{
            gotoxy(2,29);
            printf("MSG | Insira 0 para sair..");
            gotoxy(28, 8);
            scanf("%d", &MoviB.codico_conta);
            fflush(stdin);

            if(MoviB.codico_conta == 0){
                return;
            }

            AUX = pesquisa(G, MoviB.codico_conta);
            if(AUX == NULL){
                gotoxy(2,29);
                printf("MSG | Conta nao Cadastrada! Tente Novamente..");
                gotoxy(47,29);
                getch();
                gotoxy(2,29);
                printf("                                                ");
                gotoxy(28, 8);
                printf("            ");
            }

        } while(AUX == NULL);

        TelaContaemTransferencia1(G, MoviB.codico_conta);
                
        do{
            gotoxy(72, 8);
            scanf("%d", &MoviB2.codico_conta);
            fflush(stdin);

            AUX1 = pesquisa(G, MoviB2.codico_conta);

            if(AUX1 == NULL || MoviB2.codico_conta == MoviB.codico_conta){

                if(AUX1 == NULL){

                    gotoxy(2,29);
                    printf("MSG | Conta nao Cadastrada! Tente Novamente..");
                    gotoxy(47,29);
                    getch();
                    gotoxy(2,29);
                    printf("                                                  ");
                    gotoxy(72, 8);
                    printf("            ");
                     
                }

                if(MoviB2.codico_conta == MoviB.codico_conta){

                    gotoxy(2,29);
                    printf("MSG | Conta Origem e destino sao iguais! Tente Novamente..");
                    gotoxy(47,29);
                    getch();
                    gotoxy(2,29);
                    printf("                                                              ");
                    gotoxy(72, 8);
                    printf("            ");

                }
            }

        } while(AUX1 == NULL || MoviB2.codico_conta == MoviB.codico_conta);

        TelaContaemTransferencia2(G, MoviB2.codico_conta);
        
        do{
            do{
                gotoxy(2, 29);
                printf("MSG.. Data __ DD/MM/YYYY");

                gotoxy(59,19);
                fgets(MoviB.dt_movimentacao, 11, stdin);
                fflush(stdin);

                MoviB.dt_movimentacao[strcspn(MoviB.dt_movimentacao, "\n")] = '\0';

                if(formato(MoviB.dt_movimentacao) == 1 || datas(MoviB.dt_movimentacao) == 1){

                    if(formato(MoviB.dt_movimentacao) == 1){
                        gotoxy(2, 29);
                        printf("MSG.. Formato Invalido! Insira Novamente DD/MM/YYYY");
                        gotoxy(55, 29);
                        getch();
                        gotoxy(2, 29);
                        printf("                                                       ");
                        gotoxy(59,19);
                        printf("                           ");
                    }

                    else if(datas(MoviB.dt_movimentacao) == 1){
                        gotoxy(2, 29);
                        printf("MSG.. Data Invalida! Insira Novamente");
                        gotoxy(42, 29);
                        getch();
                        gotoxy(2, 29);
                        printf("                                         ");
                        gotoxy(59,19);
                        printf("                           ");                
                    }
                
                }

                gotoxy(2, 29);
                printf("                               ");

            } while(formato(MoviB.dt_movimentacao) == 1 || datas(MoviB.dt_movimentacao) == 1 );

            if(L->ultimo != NULL){
                UltimaDataMovimentacaoc(L,DataU, MoviB.codico_conta);
                strncpy(DataU2, DataU, 10);
                DataU2[10] = '\0';

                strncpy(dataM, MoviB.dt_movimentacao, 10);
                dataM[10] = '\0';

                InverterData(DataU);
                InverterData(dataM);

                if(strcmp(dataM, DataU) < 0){
                    
                    gotoxy(2, 29);
                    printf("MSG.. Data Invalida! A Data deve ser maior que %s", DataU2);
                    gotoxy(51, 29);
                    getch();
                    gotoxy(2, 29);
                    printf("                                                                ");
                    gotoxy(59,19);
                    printf("                           ");

                }
            }   

        }while (L->ultimo != NULL && strcmp(dataM, DataU) < 0);

        strncpy(MoviB2.dt_movimentacao, MoviB.dt_movimentacao, 10);
        MoviB2.dt_movimentacao[10] = '\0';        

        do{
            gotoxy(59,20);
            scanf("%lf", &MoviB.valor_movimentado);
            fflush(stdin);

            if(MoviB.valor_movimentado > AUX->novoconteudo.saldo + AUX->novoconteudo.limite){
                gotoxy(2, 29);
                printf("O valor inserido excede o saldo e limite da conta! Tente Novamente.. ");
                gotoxy(72, 29);
                getch();
                gotoxy(2, 29);
                printf("                                                                     ");
                gotoxy(59,20);
                printf("                 ");
            }
        } while(MoviB.valor_movimentado > AUX->novoconteudo.saldo + AUX->novoconteudo.limite);

        MoviB2.valor_movimentado = MoviB.valor_movimentado;

        if(MoviB.valor_movimentado <= AUX->novoconteudo.saldo + AUX->novoconteudo.limite){

            MoviB.vlr_saldoAtualizado = AUX->novoconteudo.saldo - MoviB.valor_movimentado;
            AUX->novoconteudo.saldo = MoviB.vlr_saldoAtualizado;

            //----------

            AUX1->novoconteudo.saldo += MoviB.valor_movimentado;
            MoviB2.vlr_saldoAtualizado = AUX1->novoconteudo.saldo;
        }

        gotoxy(30, 16);
        printf("%.2f", AUX->novoconteudo.saldo);

        gotoxy(72, 16);
        printf("%.2f", AUX1->novoconteudo.saldo);

        gotoxy(2,29);
        printf("MSG | Deseja salvar essa Movimentacao? 1-sim 2-nao.. ");
        gotoxy(56,29);
        scanf("%d", &esc);
        fflush(stdin);

        if(esc == 1){
            SalvarMovimentacoes(L, MoviB);
            SalvarT2(L, MoviB2);
        }

        system("cls");
        tela_principal();
        gotoxy(2, 29);
        printf("                                                                        ");
        gotoxy(2, 29);
        printf("Deseja realizar mais uma Movimentacao? 1-sim 2-nao... ");
        gotoxy(56, 29);
        scanf("%d", &x);
        fflush(stdin);

    } while(x == 1);
}