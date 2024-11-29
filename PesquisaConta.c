/*
  AUTOR: EDUARDO BERNARDES ZANIN
*/


#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h"


// Função que pesquisa um nó com código específico na lista ligada.
// Retorna um ponteiro para o nó se encontrado, ou NULL se não encontrado.
NovoTipoApontador pesquisa (NovoTipoLista * L, int cod) {
    
    // Declara um ponteiro auxiliar para percorrer a lista
    NovoTipoApontador aux;      
     
     // Inicializa 'aux' com o primeiro elemento da lista   
    aux = L->NovoPrimeiro;        

    // Loop que percorre a lista até encontrar o código ou chegar ao final
    while(aux!= NULL){

        // Verifica se o código do nó atual é igual ao código procurado
        if(aux->novoconteudo.codigoConta == cod){     
            return aux;
        }
        // Move para o próximo nó da lista
        aux = aux -> NovoProximo; 
    }
    return NULL;                // Retorna NULL se o código não for encontrado na lista
}   