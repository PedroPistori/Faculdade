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
    char unidade[7]; //UNIDADE DE MEDIDA
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
void adicionarItem(ListaProduto *lista, ItemProduto item);

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

            break;
        case 2: // REMOVER PRODUTO
            system("cls");
            title("Remover Produto");            
            break;
        case 3: // VISUALIZAR PRODUTOS
            system("cls");
            title("Visualizar Produto");

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
    fflush;
    system("cls");
}

void title(char opcao[30]){
    printf("-------------------------------\n");
    printf("------Mercadinho do Pedro------\n");
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
    fflush;
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
    item.id++;
    printf("Código do produto: %d\n\n", item.id);
    
    printf("Insira o nome do produto: ");
    scanf("%s",&item.nome);
    fflush;
    printf("Insira uma descricao do produto: ");
    scanf("%s",&item.desc);
    fflush;
    printf("Insira a Quantidade em estoque: ");
    scanf("%d",&item.qntd);
    fflush;
    printf("Qual a unidade de medida?\n");
    op = itemUnidade();

}

int itemUnidade(){
    int op;
    printf("OPCAO 1 - KG\n");
    printf("OPCAO 2 - LT\n");
    printf("OPCAO 3 - Unidades\n");
    printf("OPCAO 4 - Caixas\n\n");
    printf("Insira uma opcao: ");
    scanf("%d",&op);
    fflush;

    return op;
}

void adicionarItem(ListaProduto *lista, ItemProduto item){
    preencherItem(item);

}