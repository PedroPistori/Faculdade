#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // BIBLIOTECA PARA USAR BOOL COMO RETORNO DE FUNÇÃO

typedef struct mercadoria
{
    int id; // ID DO PRODUTO
    char nome[20]; // NOME DO PRODUTO
    double qntd; // QUANTIDADE DO PRODUTO EM ESTOQUE
    char unidade[8]; // UNIDADES, CAIXA, LITROS..
    double preco;
} Mercadoria;

typedef struct mercadoriaElemento
{
    Mercadoria mercadoria; // MERCADORIA
    struct mercadoriaElemento *prox; // PRÓXIMA MERCADORIA
}MercadoriaElemento;

typedef struct mercadoriaLista
{
    int tamanho; // TAMANHO DA LISTA
    MercadoriaElemento *inicio; // PRIMEIRO ELEMENTO
    MercadoriaElemento *final; // ULTIMO ELEMENTO
} MercadoriaLista;

MercadoriaLista* criarListaMercadoria(); // FUNÇÃO PARA CRIAR UMA LISTA.. RETORNA UMA LISTA


int main(int argc, char const *argv[])
{

    return 0;
}
