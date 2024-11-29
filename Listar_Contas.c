/*
  AUTOR: EDUARDO BERNARDES ZANIN
*/


#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"

void Listar_Contas(NovoTipoLista *L) {

    int opc;
    NovoTipoApontador P;
    P = L->NovoPrimeiro;

    if(P == NULL){
         system("cls");
         TelinhaE();

         gotoxy(2,29);
         printf("A Lista de Conta esta vazia!");
         gotoxy(67, 29);
         printf("Cadastre uma conta! :)");
         getch();
         return;
    }

    do {
      system("cls");
      tela_principal();
      gotoxy(26,12);
      printf("1 - Consulta Geral Contas Bancarias");
      gotoxy(26,14);
      printf("2 - Consulta por Codigo Conta Bancaria");
      gotoxy(26,16);
      printf("3 - Listar por ordem alfabetica (campo banco)");
      gotoxy(26,18);
      printf("4 - Listar por codigo em ordem crescente");
      gotoxy(26,20);
      printf("5 - Retornar ao menu principal");
      gotoxy(2,29);
      printf("Opcao: ");
      gotoxy(11,29);
      scanf("%d", &opc);
      fflush(stdin);


      switch (opc) {

        case 1:
             ListarGeral(L);

             break;
        
        case 2:
             BuscarConta(L);
             break;
        
        case 3:
             TelinhaE();
             OrdenarPorBanco(L);
             ExibirLista(L, 5);
             break;
        
        case 4:
             TelinhaE();
             OrdenarPorCodigo(L);
             ExibirLista(L, 5);
             break;
        
        case 5:
             
             break;
        default:
              gotoxy(2, 29);
              printf("                                                       ");
              gotoxy(2, 29);
              printf("MSG | Opcao invalida!");
              gotoxy(25, 29);
              getch(); 
              continue;
      }

  } while (opc != 5);
}