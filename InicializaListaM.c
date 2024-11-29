/*
    AUTORA: GEOVANA PAULA DA SIVA
*/

#include "funcoes.h"
#include <stdio.h>

void Inicializa(TipoLista *L, NovoTipoLista *G){
    L->primeiro = NULL;
    L->ultimo = NULL;
    G->NovoPrimeiro = NULL;
    G->NovoUltimo = NULL;
}