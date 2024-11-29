/*
  AUTOR: EDUARDO BERNARDES ZANIN
*/


#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"


void TelaConta () {

    gotoxy(10,10);
    printf("  Codigo Da Conta.......: ");

    gotoxy(10,12);
    printf("1-Banco.................: ");
    
    gotoxy(10,14);
    printf("2-Agencia...............: ");
    
    gotoxy(10,16);
    printf("3-Conta.................: ");
    
    gotoxy(10,18);
    printf("4-Tipo da Conta.........: ");

    gotoxy(10,20);
    printf("5-Saldo.................: ");

    gotoxy(10,22);
    printf("6-Limite................: ");

    gotoxy(10,24);
    printf("7-Status................: ");

}