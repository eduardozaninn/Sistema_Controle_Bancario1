/*
    AUTORA: GEOVANA PAULA DA SIVA
*/

#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void dadosC_telaTransferencia(){
    gotoxy(3, 8);
    printf("Codigo Conta_Origem:... ");

    gotoxy(3, 9);
    printf("Banco:................. ");

    gotoxy(3, 10);
    printf("Agencia:............... ");

    gotoxy(3, 11);
    printf("Numero da Conta:....... ");

    gotoxy(3, 12);
    printf("Tipo Conta:............ ");

    gotoxy(3, 13);
    printf("Saldo:................. ");

    gotoxy(3, 14);
    printf("Limite:................ ");

    gotoxy(3, 15);
    printf("Saldo + Limite:........ ");

    gotoxy(3, 16);
    printf("Novo Saldo:............ ");

 //--------------------------------------------

    gotoxy(46, 8);
    printf("Codigo Conta_Destinado: ");

    gotoxy(46, 9);
    printf("Banco:................. ");

    gotoxy(46, 10);
    printf("Agencia:............... ");

    gotoxy(46, 11);
    printf("Numero da Conta:....... ");

    gotoxy(46, 12);
    printf("Tipo Conta:............ ");

    gotoxy(46, 13);
    printf("Saldo:................. ");

    gotoxy(46, 14);
    printf("Limite:................ ");

    gotoxy(46, 15);
    printf("Saldo + Limite:........ ");

    gotoxy(46, 16);
    printf("Novo Saldo:............ ");
    
}