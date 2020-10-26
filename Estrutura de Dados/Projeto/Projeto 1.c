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
void visualizarLista(ListaProduto *lista, char call[6]);
void visualizarListaDetalhes(ListaProduto *lista);
int removerProdutoID(ListaProduto *lista);
void removerProduto(ListaProduto *lista);
void estoqueBaixo(ListaProduto *lista);

int main(int argc, char const *argv[])
{
    ListaProduto *listaProduto = criarListaProduto();
    ItemProduto itemProduto;
    itemProduto.id = 0;
    strcpy(itemProduto.nome,"");
    strcpy(itemProduto.desc,"");
    itemProduto.qntd = 0;
    itemProduto.preco = 0.0;
    strcpy(itemProduto.unidade,"");

    int op;

    while(op != 5){
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
            removerProduto(listaProduto);          
            break;
        case 3: // VISUALIZAR PRODUTOS
            system("cls");
            title("Visualizar Produto");
            visualizarLista(listaProduto,"menu");
            pausar();
            break;
        case 4: // CONSULTAR ESTOQUE
            system("cls");
            title("Consulta de estoque");
            estoqueBaixo(listaProduto);
            break;
        case 5: // FINALIZAR PROGRAMA
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
    printf("OPCAO 4 - CONSULTAR ESTOQUE BAIXO\n");
    printf("OPCAO 5 - SAIR DO PROGRAMA\n\n");
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
    elemento->proximo = NULL; //NULL POIS É O ULTIMO ELEMENTO DA LISTA
    if (lista->tamanho == 0)
    {
        elemento->anterior = NULL; //NULL POIS É O PRIMEIRO ELEMENTO DA LISTA
        lista->inicio = elemento; //PRIMEIRO ELEMENTO DA LISTA, LOGO INICIO DA LISTA
    }else
    {
        elemento->anterior = lista->final; //O ELEMENTO RECEM CRIADO, TEM COMO O SEU ANTERIOR, O ANTIGO FINAL DA LISTA
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

void visualizarLista(ListaProduto *lista, char call[6]){
    if(listaVazia(lista)){
        printf("A Lista se encontra vazia!\n\n");
        return;
    }
    int op = 0;
    ElementoProduto *apontador = lista->inicio;
    while (apontador != NULL)
    {   
        printf("ID: %d\n", apontador->itemProduto.id);
        printf("NOME: %s\n",  apontador->itemProduto.nome);
        printf("QNTD: %d%s\n", apontador->itemProduto.qntd, apontador->itemProduto.unidade);
        printf("____________________\n");
        apontador = apontador->proximo;
    }

    if(strcmp(call,"menu") == 0){
        while (op < 1 || op > 2){
            op = opcaoSimNao(1);
            switch (op)
            {
                case 1:
                    visualizarListaDetalhes(lista);
                    break;
                case 2:
                    break;           
                default:
                    printf("Opcao nao reconhecida, favor tente novamente..\n");
                    break;
            }
        }
    }
    
    printf("\n");
}

int opcaoSimNao(int call){
    // CALL == 1 -> VISUALIZAR LISTA DETALHADA
    // CALL == 2 -> VISUALIZAR LISTA

    int op = 0;
    
    if (call == 1){
        printf("\nDeseja ver algum item Detalhadamente? (1 - SIM | 2 - NAO)\n");
    }else if (call == 2)
    {
        printf("Deseja ver a lista de produtos? (1 - SIM | 2 - NAO)\n");
    }
    

    printf("Escolha uma opcao: ");
    scanf("%d", &op);
    fflush(stdin);

    return op;
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

int removerProdutoID(ListaProduto *lista){
        int op = 0;
        int idRemover = 0;

        while (op < 1 || op > 2){
            op = opcaoSimNao(2);
            switch (op)
            {
            case 1:
                visualizarLista(lista,"remover");
                break;
            case 2:
                break;           
            default:
                printf("Opcao nao reconhecida, favor tente novamente..\n");
                break;
            }
        }
        
        printf("Insira o ID do produto que deseja remover: ");
        scanf("%d", &idRemover);
        fflush(stdin);

        return idRemover;
}

void removerProduto(ListaProduto *lista){

    if (listaVazia(lista) == true)
    {
        printf("A Lista se encontra VAZIA...\n");
        pausar();
        return;
    }
    int idRemover = 0;
    idRemover = removerProdutoID(lista);
    ElementoProduto *apontador = lista->inicio;
    ElementoProduto *apontadorAux = apontador;
  
    while ((apontador != NULL))
    {
        if (apontador->itemProduto.id == idRemover)
        {
            if(apontador->proximo == NULL && apontador->anterior == NULL){
                lista->inicio = NULL;
                lista->final = NULL;
                free(apontador);
            }else if(apontador->proximo == NULL){ //ULTIMO ELEMENTO
                // CONFIGURAR PARA O ULTIMO ELEMENTO, APONTAR PARA O NULL COMO PRÓXIMO
                apontadorAux = apontador->anterior;
                apontadorAux->proximo = NULL;
                lista->final = apontadorAux;
                free(apontador);
            }else if(apontador->anterior == NULL){ //PRIMEIRO ELEMENTO
                // CONFIGURAR PARA O PRIMEIRO ELEMENTO, RECONHECER QUE NULL É O ANTERIOR A ELE
                apontadorAux = apontador->proximo;
                apontadorAux->anterior = NULL;
                lista->inicio = apontadorAux;
                free(apontador);              
            }else{ //ELEMENTO NO MEIO
                // CONFIGURAR PARA O APONTADOR ANTERIOR, APONTAR PARA O PRÓXIMO
                apontadorAux = apontador->anterior;
                apontadorAux->proximo = apontador->proximo;
                //CONFIGURAR PARA O PRÓXIMO APONTADOR, RECONHECER O ANTERIOR
                apontadorAux = apontador->proximo;
                apontadorAux->anterior = apontador->anterior;
                free(apontador);                             
            }
            printf("\nProduto removido!\n");
            lista->tamanho--;
            pausar();
            return;
        }
        apontador = apontador->proximo;
    }
    printf("Produto nao encontrado..!\n");
    pausar();
}

void estoqueBaixo(ListaProduto *lista){
    if (listaVazia(lista) == true)
    {
        printf("A Lista se encontra VAZIA!\n");
        return;
    }
    ElementoProduto *apontador = lista->inicio;
    int count = 0;
    int qntdBaixo = 0;
    
    while(qntdBaixo <=0){
        printf("Deseja pesquisar produtos abaixo de quantas quantidades em Estoque? (INSIRA UM VALOR MAIOR QUE 0!)\n");
        printf("Exibir produtos abaixo de: ");
        scanf("%d", &qntdBaixo);
        fflush(stdin);
    }

    while (apontador != NULL)
    {
        if((apontador->itemProduto.qntd > 0) && (apontador->itemProduto.qntd <= qntdBaixo) && (count <10)) {
            printf("ID: %d\n", apontador->itemProduto.id);
            printf("NOME: %s\n", apontador->itemProduto.nome);
            printf("QUANTIDADE: %d %s\n", apontador->itemProduto.qntd, apontador->itemProduto.unidade);
            printf("-------------------\n");
            count++;
        }
        apontador = apontador->proximo;
    }  
    printf("\nForam encontrados %d produto(s) com o estoque baixo!\n", count);
    pausar();
}

