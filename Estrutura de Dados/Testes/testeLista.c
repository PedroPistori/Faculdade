#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct item //DEIFINIR O ITEM (ID, QUANDIDADE)
{
    int id,qntd;
} Item;

typedef struct elemento //DEFINIR ELEMENTO
{
    Item item; //VARIAVEL DO TIPO ITEM, QUE VAI CONTER OS DADOS EM SI
    struct elemento *proximo; //PONTEIRO DO TIPO ELEMENTO, APONTANDO PARA O PRÓXIMO ELEMENTO DA LISTA
}Elemento;

typedef struct lista //DEFINIR LISTA
{
    int tamanho; //QUANTIDADE DE ELEMENTO QUE A LISTA TEM
    Elemento *inicio , *final; //PONTEIRO DO TIPO ELEMENTO, APONTANDO PARA O PRIMEIRO ELEMENTO DA LISTA, E PRO ULTIMO ELEMENTO DA LISTA
} Lista;


int menu();
Lista* criarLista();
void adicionarItem(Lista *lista, Item item);
Item preencherItem(Item item);
void visualizarLista(Lista *lista);
void removerPorID(Lista *lista);

int main(int argc, char const *argv[])
{
    Lista *lista = criarLista(); // CRIOU A LISTA
    Item item; // CRIAR VARIAVEL STRUCT PRO ITEM
    item.id = 0;
    int op = 0; // VARIAVEL PARA O MENU

    while (op != 4)
    {
         op = menu();
        switch (op)
        {
        case 1: // ADICIONAR ITEM
            item = preencherItem(item);
            adicionarItem(lista, item);
            break;
        case 2: // DELETAR ITEM
            removerPorID(lista);
            break;  
        case 3: // VISUALIZAR LISTA
            visualizarLista(lista);
            break;
        case 4: // SAIR DO PROGRAMA
            printf("Ate a proxima :D\n"); 
        default:
            printf("Opcao nao reconhecida, favor tente novamente..\n");
            break;
        }   
        printf("\n");
    }
    return 0;
}

int menu(){
    int op;
    printf("OPCAO 1 - ADICIONAR ITEM\n");
    printf("OPCAO 2 - REMOVER ITEM\n");
    printf("OPCAO 3 - VISUALIZAR LISTA\n");
    printf("OPCAO 4 - SAIR DO PROGRAMA :(\n\n");

    printf("ESCOLHA UMA OPCAO: ");
    scanf("%d",&op);
    fflush;
    return op;
}

Lista* criarLista(){
    Lista *lista = (Lista*) malloc(sizeof(Lista)); // DEFINIR TAMANHO DA LISTA NA MEMORIA

    lista->tamanho = 0; // TAMANHO (QUANTIDADE DE ELEMENTOS) QUE A LISTA POSSUI.. COMO ACABOU DE SER INICIADA, NAO POSSUI NENHUM ELEMENTO.
    lista->inicio = NULL; // SETAR INICIO DA LISTA PARA NULL.. AINDA NÃO POSSUI NENHUM VALOR (ELEMENTO), ELA ACABOU DE SER CRIADA

    return lista;
}

Item preencherItem(Item item){
    item.id++;
    printf("Insira a Quantidade: ");
    scanf("%d", &item.qntd);
    return item;
}

void adicionarItem(Lista *lista, Item item){ //ADICIONA NO FINAL DA LISTA
    Elemento *elemento = (Elemento*) malloc(sizeof(Elemento));
    elemento->item = item;

    elemento->proximo = NULL; // ULTIMO DA LISTA;
    
    if (lista->tamanho == 0)
    {
        lista->inicio = elemento;
    }else{
        lista->final->proximo = elemento; // O ANTIGO ULTIMO DA LISTA, VAI DIRECIONAR PARA O NOVO ULTIMO DA LISTA
    }
    lista->final = elemento; // SETAR O FINAL COM O ULTIMO DA LISTA ATUALIZADO
    lista->tamanho++;
}

void visualizarLista(Lista *lista){
    if(lista->tamanho == 0){
        printf("LISTA NAO ESTA PREENCHIDA..\n\n");
    }

    Elemento *apontador = lista->inicio;
    while (apontador != NULL)
    {
        printf("ID: %d\n", apontador->item.id);
        printf("Quantidade: %d\n", apontador->item.qntd);
        apontador = apontador->proximo;
    }
}

void removerPorID(Lista *lista){ //REMOVE O ITEM PELA ID FORNCEIDA
    if (lista->tamanho == 0)
    {
        printf("LISTA NÃO PREENCHIDA..\n\n");
        return;
    }
    

    Elemento *apontador = lista->inicio;
    Elemento *apontadorAux;
    Elemento *apontadorAnterior = lista->inicio;
    int idRemover = 0;
    visualizarLista(lista);
    printf("Qual ID deseja remover: ");
    scanf("%d", &idRemover);

    if (apontador->item.id == idRemover) // PRIMEIRO DA LISTA
    {
        lista->inicio = apontador->proximo;
        free(apontador);
    }else 
    { 
         apontador = apontador->proximo;
        while(apontador->proximo != NULL){ // MEIO DA LISTA
            if (apontador->item.id == idRemover )
            {
                apontadorAnterior->proximo = apontador->proximo;
                free(apontador);
            }
            apontador = apontador->proximo;
            apontadorAnterior = apontadorAnterior->proximo;
        }
        if (apontador->proximo == NULL && apontador->item.id == idRemover) // ULTIMO DA LISTA
        {
                apontadorAnterior->proximo = apontador->proximo;
                free(apontador);
                lista->final = apontadorAnterior;
        }
        
    }
    lista->tamanho--;
}
