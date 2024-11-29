#ifndef CONTA_H
#define CONTA_H
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


#include "funcoes.h"
#include "gotoxy.h"

// Criamos aqui uma estrutura para armazenar os dados da conta

typedef struct ContaBancaria {

    int codigoConta;             // Código da conta (deve ser único)

    char banco[30];                  // Nome do banco   

    char agencia[10];                 // Número da agência

    double limite;            // Limite

    int numeroConta;       // Número da conta

    double saldo;                 // Saldo da conta

    int status;                 // Status da conta

    char tp_conta[20];                   


} ContaBancaria;

typedef struct NovoTipoItem *NovoTipoApontador;

typedef struct NovoTipoItem {

    ContaBancaria novoconteudo;
    NovoTipoApontador NovoProximo;

} NovoTipoItem;

typedef struct {

    NovoTipoApontador NovoPrimeiro;
    NovoTipoApontador NovoUltimo;

} NovoTipoLista;


void TelaConta();

// Tela de Consulta de Conta
int contador(NovoTipoLista *L);

// Tela de Pesquisa de Conta
NovoTipoApontador pesquisa (NovoTipoLista *L, int cod);

// Tela de Cadastro de Conta
void Cadastramento_Conta_Bancaria (NovoTipoLista *L, int opc );

// Tela de Listagem de Contas
void Listar_Contas(NovoTipoLista *L); 

// Função Ordenar por Banco
void OrdenarPorBanco(NovoTipoLista *L);

// Função Ordenar por Codigo
void OrdenarPorCodigo(NovoTipoLista *L);

// Função de ler arquivos
void lerDoArquivoContas(NovoTipoLista *L);

// Função de salvar arquivos
void salvarContas(NovoTipoLista *L);

// Função para alterar dados da conta
void alterar_contas(NovoTipoLista *L);


char *TipoConta();

// Função para consulta por banco e por codigo
void ExibirLista(NovoTipoLista *L, int linhaInicial);

// Função para consulta por Codigo
void BuscarConta(NovoTipoLista *L);

void TelinhaE();

// Função para listar todos
void ListarGeral(NovoTipoLista *L);

void lerDoArquivoContas(NovoTipoLista *L);














/*
    AUTORA: GEOVANA PAULA DA SIVA
*/
//Lista para realziar a Movimentacao Bancaria
typedef struct MovimentacaoBancaria {

    int sequencial;
    int codico_conta;
    char dt_movimentacao[11];
    int tp_movimentacao;
    char decricao[50];
    double valor_movimentado;
    double vlr_saldoAtualizado;
} MovimentacaoBancaria;

typedef struct TipoItem *TipoApontador;

typedef struct TipoItem{
    MovimentacaoBancaria conteudo;
    TipoApontador proximo;
    TipoApontador anterior;
} TipoItem;

typedef struct {
    TipoApontador primeiro;
    TipoApontador ultimo;
} TipoLista;

void Inicializa(TipoLista *L, NovoTipoLista *G);



void tela_principal();

void Telamovimentacao(TipoLista *listaM, NovoTipoLista *lista);

void Movimentacoes(TipoLista *L, NovoTipoLista *G);

void telaRealizarM();

int contadorM(TipoLista *L);

void TelaContaemM(NovoTipoLista *L, int codigo);

void tela_movimentacao();

void DadosCemM();

char* UltimaDataMovimentacaoc(TipoLista *L,char *data, int cod);

int formato(char *data);

int datas(char data[10]);

char *InverterData(char *dt);

void tela_transferencia();

void Transacoes(TipoLista *L, NovoTipoLista *G);

NovoTipoApontador TelaContaemTransferencia1(NovoTipoLista *L, int codigo);

NovoTipoApontador TelaContaemTransferencia2(NovoTipoLista *L, int codigo);

void dadosC_telaTransferencia();

void consultarM(TipoLista *L, int cod);

void ConsultarMovimentacoes(TipoLista *L, NovoTipoLista *G);

void tela_consulta();

void SalvarT2(TipoLista *L, MovimentacaoBancaria M);

void SalvarMovimentacoes(TipoLista *L, MovimentacaoBancaria MoviB);

void SalvarAquivoMovimentacoes(TipoLista *L);

void CarregarMovimentacoes(TipoLista *L);

void remover_conta_final(NovoTipoLista *G, TipoLista *L);

void remover_conta_inicio(NovoTipoLista *G, TipoLista *L);

int verificar_movimentacoes_pendentes(TipoLista *L, int codigoConta);

void remover_posicao(NovoTipoLista *G, TipoLista *L);

void TelaInfo(NovoTipoLista *L, TipoLista *G);

void ContaConsultarM(NovoTipoLista *G, int cod);

#endif
