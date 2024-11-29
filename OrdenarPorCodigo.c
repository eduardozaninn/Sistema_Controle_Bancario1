#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"

void OrdenarPorCodigo(NovoTipoLista *L) {
    
    // Declara dois ponteiros auxiliares para percorrer a lista e uma variável temporária para troca de valores.
    NovoTipoApontador atual, proximo;
    ContaBancaria temp;


    atual = L -> NovoPrimeiro;
    while (atual != NULL) {
        // Define o ponteiro 'proximo' para o elemento seguinte ao atual.
        proximo = atual -> NovoProximo;

        // Loop interno para comparar o elemento 'atual' com todos os outros elementos após ele.
        while (proximo != NULL) {

            // Se o código da conta no nó atual for maior que o do próximo nó:
            if (atual -> novoconteudo.codigoConta > proximo -> novoconteudo.codigoConta) {

                // Troca os conteúdos dos nós 'atual' e 'proximo' usando uma variável temporária.
                temp = atual -> novoconteudo;
                atual -> novoconteudo = proximo -> novoconteudo;
                proximo -> novoconteudo = temp;
            }

            // Avança para o próximo nó no loop interno.
            proximo = proximo -> NovoProximo;
        }

        // Avança para o próximo nó no loop externo.
        atual = atual -> NovoProximo;
    }

}