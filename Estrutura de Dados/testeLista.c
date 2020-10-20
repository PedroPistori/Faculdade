#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//ESSA STRUCT CONTEM O CONTEUDO DA LISTA. AFIM DE TESTES, SO VAI POSSUIR ID.
typedef struct conteudo{
    int id;
} Conteudo;

//ESSA STRUCT CONTEM UM NÓ (NODE) DA LISTA. conteudo = STRUCT DE CIMA. *proximo = PONTEIRO PARA O PRÓXIMO NODE.
typedef struct node{
    Conteudo conteudo;
    struct node *proximo;
} Node;

//ESSA STRUCT CONTEM O TAMANHO TOTAL DA LISTA, E O NODE DE INICIO DA LISTA.
typedef struct lista {
    int tamanho;
    Node *inicio;
} Lista;

Lista* criarLista();
void push(Lista *lista, Conteudo conteudo);
void imprimirLista(Lista *lista);
bool verificaListaVazia(Lista *lista);
void pop(Lista *lista);

int main(int argc, char const *argv[])
{
    Lista *lista = criarLista();
    Conteudo conteudo;

    conteudo.id = 45;
    push(lista, conteudo);

    conteudo.id = 10;
    push(lista, conteudo);

    imprimirLista(lista);

    pop(lista);
    imprimirLista(lista);

    return 0;
}

Lista* criarLista(){
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    
    lista->tamanho = 0;
    lista->inicio = NULL;
    
    return lista;
}

void push(Lista *lista, Conteudo conteudo){
    Node *node = (Node*) malloc(sizeof(Node));
    node->conteudo = conteudo;
    node->proximo = lista->inicio;
    lista->inicio = node;
    lista->tamanho++;
}

void imprimirLista(Lista *lista){
    
    if(verificaListaVazia(lista)){
        printf("Lista Vazia\n");
        return;
    }

    Node *apontador = lista->inicio;

    while(apontador != NULL){
        printf("%d ", apontador->conteudo.id);
        apontador = apontador->proximo;
    }
    printf("\n");
}

bool verificaListaVazia(Lista *lista){
    return (lista->tamanho == 0);
}

void pop(Lista *lista){
    if(verificaListaVazia(lista)){
        printf("Lista Vazia, nao e possivel continuar!");
    }else{
        Node *apontador = lista->inicio;

        lista->inicio = apontador->proximo;
        free(apontador);
        lista->tamanho--;
    }
}

