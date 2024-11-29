/*
  AUTOR: EDUARDO BERNARDES ZANIN
*/




#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"


void Cadastramento_Conta_Bancaria(NovoTipoLista *L, int opc ) {

    NovoTipoApontador p;
    ContaBancaria cont_banc;
    NovoTipoApontador aux2;
    int resp;
    int x;

    do{
        system("cls");
        gotoxy(18,6);
        printf("CADASTRAMENTO DE CONTAS BANCARIAS");

        gotoxy(50,6);
        if(opc == 1) {
            printf(" - INSERIR CONTA NO FINAL");
        } 
        else if(opc == 2) {
            printf(" - INSERIR CONTA NO INICIO");
        } 
        else if(opc == 3) {
            printf(" - INSERIR CONTA NA POSICAO");
        }
        TelinhaE();
        TelaConta();
        do{


            gotoxy(2,29);
            printf(" Digite 0 para retornar ao menu...");

            gotoxy(38,10);
            scanf("%d", &cont_banc.codigoConta);
            fflush(stdin);

            if(cont_banc.codigoConta == 0) {
                fflush(stdin);
                return;
            }

            // Pesquisa a conta pelo código para verificar se já existe
            aux2 = pesquisa(L, cont_banc.codigoConta);   

            if (aux2 != NULL) {
                gotoxy(2,29);
                printf(" Conta ja cadastrada, nao digite este mesmo codigo!");
                getch();
                gotoxy(2,29);
                printf("                                                   ");
                gotoxy(38,10);
                printf("          ");
            }
        
        } while (aux2 != NULL);

        gotoxy(38,12);
        fgets(cont_banc.banco, 30, stdin);
        fflush(stdin);

        gotoxy(38,14);
        fgets(cont_banc.agencia, 10, stdin);
        fflush(stdin);

        gotoxy(38,16);
        scanf("%d", &cont_banc.numeroConta);
        fflush(stdin);

        gotoxy(38,18);
        strcpy(cont_banc.tp_conta,TipoConta());

        gotoxy(38,20);
        scanf("%lf", &cont_banc.saldo);
        fflush(stdin);

        gotoxy(38,22);
        scanf("%lf", &cont_banc.limite);
        fflush(stdin);

        gotoxy(38,24);
        scanf("%d", &cont_banc.status);
        fflush(stdin);

        gotoxy(2,29);
        printf("                                                          ");
        gotoxy(2,29);
        printf("Deseja Salvar (1) Sim ou (2) Nao: ");
        scanf("%d", &resp);


        if(resp == 1) {
            // Aloca memória para o novo nó da lista
            p = (NovoTipoApontador) malloc(sizeof(NovoTipoItem)); 
            
            // Inicializa o ponteiro para o próximo nó como NULL  
            p->NovoProximo = NULL;                                    
 
            // Atribui os dados da conta bancária ao novo nó
            p->novoconteudo = cont_banc;                              

            if (L ->NovoPrimeiro == NULL) {                          
                L ->NovoPrimeiro = p;
                L ->NovoUltimo = p;
            }
            else if (opc == 1) {                                           
                L -> NovoUltimo -> NovoProximo = p;                
                L -> NovoUltimo = p;
                p->NovoProximo = NULL;                              
            }
            else if (opc == 2) {   
                p -> NovoProximo = L -> NovoPrimeiro;              
                L -> NovoPrimeiro = p;
                if(L->NovoUltimo == NULL){
                    L->NovoUltimo = L->NovoPrimeiro;
                }                       
            }
            else if (opc == 3) {
                do{
                    gotoxy(2,29);
                    printf("                                                   ");
                    gotoxy(2,29);
                    printf("Digite a posicao desejada para inserir a conta: ");
                    gotoxy(51,29);
                    scanf("%d", &resp);


                    if (resp < 1 || resp > contador(L)) {
                        gotoxy(2,29);
                        printf("Posicao invalida! Tente novamente.");
                        getch();
                        gotoxy(2,29);
                        printf("                                    ");
                        // Se a posição fornecida for inválida (fora dos limites da lista),
                        // o programa exibe uma mensagem e aguarda o usuário pressionar uma tecla.                                    
                    }


                } while (resp < 1 || resp > contador(L));               
            
                // Aloca memória para um novo item da lista e atribui a ele o conteúdo da nova conta.
                aux2 =  (NovoTipoApontador) malloc(sizeof(NovoTipoItem));  
                aux2 ->novoconteudo = cont_banc;
                
                if(resp == 1){
                    p->NovoProximo = L->NovoPrimeiro;
                    L->NovoPrimeiro = p;
                    if(L->NovoUltimo == NULL){
                        L->NovoUltimo = L->NovoPrimeiro;
                    }
                }else{
                    p = L -> NovoPrimeiro; 
                    for (x = 0; x < resp - 2; x++) {
                        // Move o ponteiro 'p' até o item da lista que está antes da posição desejada.
                        p = p -> NovoProximo;                                 
                    }

                    aux2 -> NovoProximo = p -> NovoProximo;

                    // Insere o novo item na posição desejada, ajustando os ponteiros da lista.
            
                    p -> NovoProximo = aux2;
                }

                gotoxy(2,29);
                printf("                                                              ");
                gotoxy(2,29);
                printf("Conta cadastrada com sucesso!");
                getch();
                gotoxy(2,29);
                printf("                                                               ");
            }
        }                            

        gotoxy(2,29);
        printf("Deseja cadastrar outra conta, (1) Sim ou (2) Nao: ");
        gotoxy(53,29);
        scanf("%d", &resp);
        fflush(stdin);     
    
    } while (resp == 1);

}        
