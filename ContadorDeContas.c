/*
  AUTOR: EDUARDO BERNARDES ZANIN
*/


#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"

int contador(NovoTipoLista * L) {

    // Declara um ponteiro auxiliar
    NovoTipoApontador aux;         
    int cont = 0;
    
    // Fazendo o ponteiro auxiliar apontar para o primeiro elemento da lista
    aux = L->NovoPrimeiro;         
    while(aux != NULL) {
        cont++;

        // Move o ponteiro auxiliar para o próximo elemento da lista
        aux = aux -> NovoProximo;  
    }
    return cont;
}
      

    

      