#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"

char *TipoConta() {

    int tp_conta;
    int flag;
    char *tipo_conta;

    tipo_conta = (char*)malloc(sizeof(char) * 60);

    do {
        flag = 0;
        gotoxy(2,29);
        printf("1=Corrente / 2=Poupanca / 3=Cartao Credito");
        gotoxy(38,18);
        scanf("%d", &tp_conta);


        if (tp_conta < 1 || tp_conta > 3) {
            gotoxy(2,29);
            printf("Tipo de conta invalida. Tente novamente.     ");
            getch();
            gotoxy(2,29);
            printf("                                           ");
            gotoxy(38,18);
            printf("         ");
            flag = 1;

        } else {
            switch (tp_conta) {
                case 1:
                    gotoxy(2,29);
                    printf("                                             ");
                    strcpy(tipo_conta, "1=Corrente");
                    gotoxy(38,18); 
                    printf("1 = Corrente\n");
                    break;
                case 2:
                    gotoxy(2,29);
                    printf("                                             ");
                    strcpy(tipo_conta, "2=Poupanca");
                    gotoxy(38,18); 
                    printf("2 = Poupanca\n");
                    break;
                case 3:
                    gotoxy(2,29);
                    printf("                                             ");
                    strcpy(tipo_conta, "3=CartaoCredito");
                    gotoxy(38,18); 
                    printf("3 = Cartao Credito\n");
                    break;
                default:
                    gotoxy(2,29);
                    printf("Tipo de conta invalida. Tente novamente.           ");
                    getch();
                    gotoxy(2,29);
                    printf("                                          ");
                    gotoxy(38,18); 
                    printf("          ");
                    flag = 1;
                    break;
            }
        }
    } while (flag == 1);

    return tipo_conta;
    fflush(stdin);
}


    