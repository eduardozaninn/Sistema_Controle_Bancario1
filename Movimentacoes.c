/*
    AUTORA: GEOVANA PAULA DA SIVA
*/

#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void Movimentacoes(TipoLista *L, NovoTipoLista *G){

    int esc = 0;
    int x = 0;
    char UltimaData[11] = {0};
    char Ultimadata2[11] = {0};
    char dataMovimentacao[11] = {0};

    do{
        MovimentacaoBancaria MoviB;
        NovoTipoApontador aux;
        TipoApontador M;
        
        system("cls");
        tela_movimentacao();
        telaRealizarM();
        DadosCemM();
        M = L->primeiro;

        if(M == NULL){
            MoviB.sequencial = 1;
        }
        else{
            MoviB.sequencial = contadorM(L) + 1;
        }

        gotoxy(31,18);
        printf("%d", MoviB.sequencial);

        do{
            gotoxy(2,29);
            printf("MSG | Insira 0 para sair..");
            gotoxy(29,10);
            scanf("%d", &MoviB.codico_conta);
            fflush(stdin);

            if(MoviB.codico_conta == 0){
                return;
            }
            
            aux = pesquisa(G, MoviB.codico_conta);

            if(aux == NULL){
                gotoxy(2, 29);
                printf("MSG | Essa Conta nao Existe!     ");
                gotoxy(25, 29);
                getch();
                gotoxy(2, 29);
                printf("                                 ");
                gotoxy(29,10);
                printf("         ");
            }
        }while(aux == NULL);

        TelaContaemM(G, MoviB.codico_conta);


        do{
            do{
                gotoxy(2, 29);
                printf("MSG.. Data __ DD/MM/YYYY");

                gotoxy(31,20);
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
                        printf("                                                      ");
                        gotoxy(31,20);
                        printf("                           ");
                    }

                    else if(datas(MoviB.dt_movimentacao) == 1){
                        gotoxy(2, 29);
                        printf("MSG.. Data Invalida! Insira Novamente");
                        gotoxy(42, 29);
                        getch();
                        gotoxy(2, 29);
                        printf("                                         ");
                        gotoxy(31,20);
                        printf("                           ");                
                    }

                
                }

                gotoxy(2, 29);
                printf("                          ");

            } while(formato(MoviB.dt_movimentacao) == 1 || datas(MoviB.dt_movimentacao) == 1 );

            if(L->ultimo != NULL){
                UltimaDataMovimentacaoc(L,UltimaData, MoviB.codico_conta);
                strncpy(Ultimadata2, UltimaData, 10);
                Ultimadata2[10] = '\0';

                strncpy(dataMovimentacao, MoviB.dt_movimentacao, 10);
                dataMovimentacao[10] = '\0';

                InverterData(UltimaData);
                InverterData(dataMovimentacao);

                if(UltimaData != NULL && strcmp(dataMovimentacao, UltimaData) < 0){
                    
                    gotoxy(2, 29);
                    printf("MSG.. Data Invalida! A Data deve ser maior que %s", Ultimadata2);
                    gotoxy(51, 29);
                    getch();
                    gotoxy(2, 29);
                    printf("                                                                ");
                    gotoxy(31,20);
                    printf("                           ");

                }
            }   

        }while (L->ultimo != NULL && strcmp(dataMovimentacao, UltimaData) < 0);


        do{
            gotoxy(2, 29);
            printf("MSG.. 1 - Credito | 2 - Debito");
            gotoxy(31, 21);
            scanf("%d", &MoviB.tp_movimentacao);
            fflush(stdin);

            if(!(MoviB.tp_movimentacao == 1 || MoviB.tp_movimentacao == 2)){
                gotoxy(2, 29);
                printf("                                ");
                gotoxy(2, 29);
                printf("MSG.. Tipo de Movimentacao incorreta. Digite novamente");
                gotoxy(57, 29);
                getch();
                gotoxy(2, 29);
                printf("                                                       ");
                gotoxy(31, 21);
                printf("           ");
            }

            gotoxy(2, 29);
            printf("                                  ");

        }while (!(MoviB.tp_movimentacao == 1 || MoviB.tp_movimentacao == 2));



        if(MoviB.tp_movimentacao == 1){
            gotoxy(31, 21);
            printf("1 - Credito");
        }
        else if (MoviB.tp_movimentacao == 2){
            gotoxy(31, 21);
            printf("2 - Debito");
        }

        do{
            gotoxy(31,22);
            scanf("%lf", &MoviB.valor_movimentado);
            fflush(stdin);

            if(MoviB.tp_movimentacao == 1){
                MoviB.vlr_saldoAtualizado = aux->novoconteudo.saldo + MoviB.valor_movimentado;
                aux->novoconteudo.saldo = MoviB.vlr_saldoAtualizado;
                break;
            }

            if(MoviB.tp_movimentacao ==2){
                if(MoviB.valor_movimentado > aux->novoconteudo.saldo + aux->novoconteudo.limite){
                    gotoxy(2, 29);
                    printf("MSG | O Valor excede o limite da conta, insira outro valor!");
                    gotoxy(61, 29);
                    getch();
                    gotoxy(2, 29);
                    printf("                                                            ");
                    gotoxy(31,22);
                    printf("       ");
                }
                else{
                    MoviB.vlr_saldoAtualizado = aux->novoconteudo.saldo - MoviB.valor_movimentado;
                    aux->novoconteudo.saldo = MoviB.vlr_saldoAtualizado;
                    break;
                }
            }
        } while(MoviB.valor_movimentado > aux->novoconteudo.saldo + aux->novoconteudo.limite && MoviB.tp_movimentacao == 2);

        gotoxy(31,23);
        fgets(MoviB.decricao, 50, stdin);

        gotoxy(31,24);
        printf("R$%.2f", MoviB.vlr_saldoAtualizado);

        gotoxy(2,29);
        printf("MSG | Deseja salvar essa Movimentacao? 1-sim 2-nao.. ");
        gotoxy(56,29);
        scanf("%d", &esc);
        fflush(stdin);

        if(esc == 1){
            SalvarMovimentacoes(L, MoviB);
        }

        system("cls");
        tela_principal();
        gotoxy(2, 29);
        printf("                                                                      ");
        gotoxy(2, 29);
        printf("Deseja realizar mais uma Movimentacao? 1-sim 2-nao... ");
        gotoxy(56, 29);
        scanf("%d", &x);
        fflush(stdin);

    } while(x == 1);

}