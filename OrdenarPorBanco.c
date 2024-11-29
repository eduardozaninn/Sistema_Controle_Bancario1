#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"

void OrdenarPorBanco(NovoTipoLista *L) {

    // Declara dois ponteiros para percorrer a lista e uma variável temporária para troca
    NovoTipoApontador atual, proximo;
    ContaBancaria temp;

    // Inicializa o ponteiro 'atual' apontando para o primeiro elemento da lista
    atual = L -> NovoPrimeiro;


    while (atual != NULL) {

        // Ponteiro 'proximo' começa no próximo elemento do atual
        proximo = atual -> NovoProximo;

        // Loop interno: compara o elemento atual com os demais elementos seguintes
        while (proximo != NULL) {

            // Compara os nomes dos bancos dos elementos atuais
            // Se a ordem alfabética está errada, realiza a troca
            if (strcmp(atual -> novoconteudo.banco, proximo -> novoconteudo.banco) > 0) {

                // Realiza a troca dos dados dos elementos
                temp = atual -> novoconteudo;
                atual -> novoconteudo = proximo -> novoconteudo;
                proximo -> novoconteudo = temp;
            }
            // Move o ponteiro 'proximo' para o próximo nó
            proximo = proximo -> NovoProximo;
        }
        // Move o ponteiro 'atual' para o próximo nó
        atual = atual -> NovoProximo;
    }
}

