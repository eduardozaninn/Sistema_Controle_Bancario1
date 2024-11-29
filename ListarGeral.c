#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"

void ListarGeral(NovoTipoLista *L) {

  NovoTipoApontador p;
  int opc;

  p = L -> NovoPrimeiro;                    // Atribuindo o ponteiro para o primeiro elemento da lista ligada (L -> NovoPrimeiro)

  system("cls");
  // Laço 'while' que percorre a lista enquanto houver elementos (nós) na lista
  while (p != NULL) {
        
    TelinhaE();
    TelaConta();
    gotoxy(38,10);
    printf("%d", p->novoconteudo.codigoConta);
    gotoxy(38,12);
    printf("%s", p->novoconteudo.banco);
    gotoxy(38,14);
    printf("%s", p->novoconteudo.agencia);
    gotoxy(38,16);
    printf("%d", p->novoconteudo.numeroConta);
    gotoxy(38,18);
    printf("%s", p->novoconteudo.tp_conta);
    gotoxy(38,20);
    printf("%.2f", p->novoconteudo.saldo);
    gotoxy(38,22);
    printf("%.2f", p->novoconteudo.limite);
    gotoxy(38,24);
    printf("%d", p->novoconteudo.status);
        
    p = p -> NovoProximo;
    getch();


    gotoxy(2,29);
    printf(" Para prosseguir para pagina seguinte, Pressione alguma tecla...");
    getch();
    system("cls");

  }
}