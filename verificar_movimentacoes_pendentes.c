#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"





int verificar_movimentacoes_pendentes(TipoLista *L, int codigoConta) {

    TipoApontador atual = L->primeiro;

    while(atual != NULL) {
        if(atual->conteudo.codico_conta == codigoConta) {
                return 1;
            }
        
        atual = atual -> proximo;
    }
    return 0;
}