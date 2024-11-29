#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"


void remover_posicao(NovoTipoLista *G, TipoLista *L){
    

    if (G->NovoPrimeiro == NULL) {
        gotoxy(2,29);
        printf("A lista esta vazia! Nao ha Conta Cadastrada para remover.");
        getch();
        return;
    }

    NovoTipoApontador R;
    NovoTipoApontador P;
    int cont;
    int posicao;

    do{
    posicao = 0;
    system("cls");
    TelinhaE();

    do{
        gotoxy(55, 29);
        printf("| Digite 0 para sair");
        gotoxy(2,29);
        printf("Digite a posicao da conta a ser removida:  ");
        gotoxy(46,29);
        scanf("%d", &posicao);
        fflush(stdin);

        if(posicao == 0){
            return;
        }

        if(posicao < 1 || posicao > contador(G)){
            gotoxy(55, 29);
            printf("                    ");
            gotoxy(55, 29);
            printf("| Posicao Invalida!");
            getch();
            gotoxy(55, 29);
            printf("                      ");
            gotoxy(46,29);
            printf("       ");
        }
    } while(posicao < 1 || posicao > contador(G));

        if(posicao == 1){
            
            P = G->NovoPrimeiro;
            if(P->novoconteudo.saldo != 0 || verificar_movimentacoes_pendentes(L, P->novoconteudo.codigoConta) == 1){
                gotoxy(2,29);
                printf("MSG | Essa conta nao pode ser Excluida pois contem saldo ou possui Movimentacoes");
                getch();
                gotoxy(2,29);
                printf("                                                                                     ");
                
            } else{

                G->NovoPrimeiro = P->NovoProximo;
                free(P);
                gotoxy(2,29);
                printf("                                                                                      ");
                gotoxy(2,29);
                printf("Conta removida com sucesso!");
                getch();
                return;
            }
            
        }
        else{        
            R = G->NovoPrimeiro;
            P = R->NovoProximo;
            
            cont = 1;

            while(cont < posicao - 1){
                cont = cont + 1;
                P = P->NovoProximo;
                R = R->NovoProximo;
            }

            if(P->novoconteudo.saldo != 0 || verificar_movimentacoes_pendentes(L, P->novoconteudo.codigoConta)== 1){
                gotoxy(2,29);
                printf("MSG | Essa conta nao pode ser Excluida pois contem saldo ou possui Movimentacoes");
                getch();
                gotoxy(2,29);
                printf("                                                                                     ");
                
            }
            else{
                R->NovoProximo = P->NovoProximo;
                free(P);
                gotoxy(2,29);
                printf("                                                                                      ");
                gotoxy(2,29);
                printf("Conta removida com sucesso!");
                getch();
                return;
            }
        }

    } while (P->novoconteudo.saldo != 0 || verificar_movimentacoes_pendentes(L, P->novoconteudo.codigoConta)== 1);

}