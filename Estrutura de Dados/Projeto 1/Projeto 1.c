/*
ALUNO: PEDRO HENRIQUE PISTORI COSTA
UF: UNIVERSIDADE FEDERAL DE RONDONÓPOLIS
ESTRUTURA DE DADOS 2020.1
TEMA: SISTEMA DE MERCADO
PROJETO 1

REFERENCIAS: 
    Youtube.com/user/italogross -> PONTEIROS
    Youtube.com/user/canaldofree -> LISTAS DINAMICAS ENCADEADAS
    Youtube.com/user/progdescomplicada -> LISTAS DINAMICAS ENCADEADAS
*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h> // BIBLIOTECA PARA USAR BOOL COMO RETORNO DE FUNÇÃO

typedef struct itemProduto
{
    int id;
    char nome[30];
    char desc[100]; //DESCRIÇÃO DO PRODUTO
    double preco;
    int qntd;
    char unidade[3]; //UNIDADE DE MEDIDA (KG,L,UND,CX)
}ItemProduto;

typedef struct elementoProduto
{
    ItemProduto itemProduto;
    struct elementoProduto *proximo,*anterior;
}ElementoProduto;

typedef struct listaProduto
{
    int tamanho;
    ElementoProduto *inicio,*final;
}ListaProduto;

void title(char opcao[30]);
int menu();
ListaProduto* criarListaProduto();
ItemProduto preencherItem(ItemProduto item);
int itemUnidade();
void adicionarItem(ListaProduto *lista, ItemProduto item);
bool listaVazia(ListaProduto *lista);
void visualizarLista(ListaProduto *lista);
void visualizarListaDetalhes(ListaProduto *lista);

int main(int argc, char const *argv[])
{
    ListaProduto *listaProduto = criarListaProduto();
    ItemProduto itemProduto;
    itemProduto.id = 0;
    strcpy(itemProduto.nome,"");
    strcpy(itemProduto.desc,"");
    itemProduto.qntd = 0;
    itemProduto.preco = 0,0;
    strcpy(itemProduto.unidade,"");

    int op;

    while(op != 4){
        switch (op = menu()){
        case 1: // ADICIONAR PRODUTO
            system("cls");
            title("Adicionar Produto");
            itemProduto.id++; //CONTROLE DA ID DO PRODUTO!
            adicionarItem(listaProduto,itemProduto);
            break;
        case 2: // REMOVER PRODUTO
            system("cls");
            title("Remover Produto");            
            break;
        case 3: // VISUALIZAR PRODUTOS
            system("cls");
            title("Visualizar Produto");
            visualizarLista(listaProduto);
            pausar();
            break;
        case 4: // FINALIZAR PROGRAMA
            printf("Ate a proxima :D");
            break;
        default:
            printf("Opcao nao reconhecida, favor tente novamente..\n");
            break;
        }
    }
    return 0;
}

void pausar(){ //FUNÇÃO PARA PAUSAR O PROGRAMA
    printf("Pressione qualquer tecla para continuar..");
    getch();
    fflush(stdin);
    system("cls");
}

void title(char opcao[30]){
    printf("-------------------------------\n");
    printf("----- Mercadinho do Pedro -----\n");
    printf("-------------------------------\n");

    if ( !(strcmp(opcao,"") == 0)){
        printf("->%s\n", opcao);
    }
        printf("\n");
}

int menu(){
    system("cls");
    title("");
    int op = 0;
    printf("OPCAO 1 - ADICIONAR PRODUTO\n");
    printf("OPCAO 2 - REMOVER PRODUTO\n");
    printf("OPCAO 3 - VISUALIZAR PRODUTOS\n");
    printf("OPCAO 4 - SAIR DO PROGRAMA\n\n");
    printf("ESCOLHA UMA OPCAO: ");
    scanf("%d", &op);
    fflush(stdin);
    return op;
}

ListaProduto* criarListaProduto(){
    ListaProduto *lista = (ListaProduto*)malloc(sizeof(ListaProduto)); //ALOCAR MEMÓRIA PARA A LISTA, DO TAMANHO DA LISTAPRODUTO
    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->final = NULL;
    return lista;
}

ItemProduto preencherItem(ItemProduto item){
    int op;
    
    printf("Codigo do produto: %d\n\n", item.id);
    
    printf("Insira o nome do produto: ");
    scanf("%s",&item.nome);
    fflush(stdin);
    printf("Insira uma descricao do produto: ");
    scanf("%s",&item.desc);
    fflush(stdin);
    printf("Insira a Quantidade em estoque: ");
    scanf("%d",&item.qntd);
    fflush(stdin);
    printf("\nQual a unidade de medida?\n");
    do{
        op = itemUnidade();
        if (op<1 || op>4)
        {
            printf("Opcao nao reconhecida.. Favor tente novamente\n");
        }
    }while (op<1 || op>4);
    switch (op)
    {
    case 1:
        strcpy(item.unidade,"KG"); //QUILOGRAMAS
        break;
    case 2:
        strcpy(item.unidade,"L"); //LITROS
        break;
    case 3:
        strcpy(item.unidade,"Und"); //UNIDADES
        break;
    case 4:
        strcpy(item.unidade,"Cx"); //CAIXAS
        break;
    }
    printf("Insira o preco do produto: ");
    scanf("%f", &item.preco);
    fflush(stdin);
    return item;
}

int itemUnidade(){
    int op;
    printf("OPCAO 1 - QUILOGRAMAS-(KG)\n");
    printf("OPCAO 2 - LITROS - - -(L)\n");
    printf("OPCAO 3 - UNIDADES - -(UND)\n");
    printf("OPCAO 4 - CAIXAS - - -(CX)\n\n");
    printf("Insira uma opcao: ");
    scanf("%d",&op);
    fflush(stdin);
    return op;
}

void adicionarItem(ListaProduto *lista, ItemProduto item){
    ElementoProduto *elemento = (ElementoProduto*) malloc(sizeof(ElementoProduto));
    item = preencherItem(item);
    elemento->itemProduto = item;
    
    elemento->proximo = NULL;
    if (lista->tamanho == 0)
    {
        lista->inicio = elemento;
    }else
    {
        lista->final->proximo = elemento; // O ELEMENTO QUE SE ENCONTRAVA NO FINAL, VAI APONTAR PARA O ELEMENTO RECEM CRIADO(PROXIMO). 
    }
    lista->final = elemento; //O FINAL VAI APONTAR PARA O ELEMENTO RECEM CRIADO, QUE SE ENCONTRA NO FINAL DA LISTA.
    lista->tamanho++;
}

bool listaVazia(ListaProduto *lista){
    if (lista->tamanho == 0)
    {
        return true;
    }else{
        return false;
    }
    
}

void visualizarLista(ListaProduto *lista){
    if(listaVazia(lista)){
        printf("A Lista se encontra vazia!\n\n");
        return;
    }
    int op;
    ElementoProduto *apontador = lista->inicio;
    while (apontador != NULL)
    {   
        printf("ID: %d\n", apontador->itemProduto.id);
        printf("NOME: %s\n",  apontador->itemProduto.nome);
        printf("QNTD: %d%s\n", apontador->itemProduto.qntd, apontador->itemProduto.unidade);
        printf("____________________\n");
        apontador = apontador->proximo;
    }

    printf("\nDeseja ver algum item Detalhadamente? (1 - SIM | 2 - NAO)\n");
    printf("Escolha uma opcao: ");
    scanf("%d",&op);
    fflush(stdin);
    if (op == 1){
        visualizarListaDetalhes(lista);
    }
    printf("\n");
}

void visualizarListaDetalhes(ListaProduto *lista){
    
    int idPesquisa;
    int count = 0;
    ElementoProduto *apontador = lista->inicio;

    printf("Insira o ID do item para detalhar: ");
    scanf("%d", &idPesquisa);
    fflush(stdin);
    system("cls");

    title("VISUALIZAR DETALHES");

    while(apontador != NULL)
    {
        if (apontador->itemProduto.id == idPesquisa)
        {
            printf("____________________\n");
            printf("ID: %d\n", apontador->itemProduto.id);
            printf("NOME: %s\n", apontador->itemProduto.nome);
            printf("DESCRICAO: %s\n", apontador->itemProduto.desc);
            printf("QUANTIDADE EM ESTOQUE: %d %s\n", apontador->itemProduto.qntd, apontador->itemProduto.unidade);
            printf("PRECO: R$ %.2f\n", apontador->itemProduto.preco);
            printf("____________________\n\n");
        }else
        {
            count++;
        }
      apontador = apontador->proximo;
    }
    if (count == lista->tamanho)
    {
        printf("NAO FOI ENCONTRADO NENHUM ITEM COM O CODIGO: %d!\n\n", idPesquisa);
    }
}