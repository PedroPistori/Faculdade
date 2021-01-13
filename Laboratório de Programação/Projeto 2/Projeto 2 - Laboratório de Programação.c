/*
Aluno: Pedro Henrique Pistori Costa
Tema: **Mercado
Projeto 2 - Laboratório de Programação
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//VARIAVEIS GLOBAIS
int qntdMAX;
int proxIndex;

//DEFINIÇÃO DE REGISTROS
typedef struct produtos{
    int codProduto;
    char nome[50];
    int qntd;
}PRODUTOS;


//PROTOTIPAGEM DAS FUNÇÕES
void title();
int menu();
void inicializarVetor(PRODUTOS *produtos); //INICIALIZAR VETOR PARA REMOVER LIXO DE MEMORIA
void verificarVetor(PRODUTOS *produtos); //VERIFICAR PROXIMO INDICE VAZIO
int quantidadeEstoque(PRODUTOS *produtos); //AUXILIAR PARA FUNÇÃO DE VISUALIZAR ESTOQUE
void addProduto(PRODUTOS *produtos); //OP 1 - ADICIONAR PRODUTOS
void subProduto(PRODUTOS *produtos); //OP 2 - REMOVER PRODUTOS
int menuRemoverProduto();
void removerVisualizarEstoque(PRODUTOS *produtos);
void visualizarEstoque(PRODUTOS *produtos); //OP 3 - VISUALIZAR ESTOQUE
void ConsultarEstoquePersonalizado(PRODUTOS *produtos);

int main(int argc, char const *argv[]){

    //INICIALIZAR PROGRAMA!
    printf("Informe a quantidade de produtos que deseja armazenar: ");
    scanf("%d", &qntdMAX);
    fflush(stdin);
    PRODUTOS produtos[qntdMAX]; //VETOR DE REGISTROS (PRODUTOS)
    PRODUTOS *pProdutos = &produtos; //PONTEIRO PARA O VETOR
    inicializarVetor(pProdutos);


    int op = 0; //INICIALIZAR VARIAVEL OP

    while(op != 5){
        op = menu();
        switch (op){
        case 1: //ADICIONAR PRODUTO
            addProduto(pProdutos);
            break;
        case 2: //REMOVER PRODUTO
            subProduto(pProdutos);
            break;
        case 3: //CONSULTAR ESTOQUE
            visualizarEstoque(pProdutos);
            break;
        case 4: //CONSULTAR ESTOQUE PERSONALIZADO
            ConsultarEstoquePersonalizado(pProdutos);
            break;
        case 5:
            printf("\nAte a proxima.. :)\n");
            break;
        default:
            printf("Opcao nao reconhecida.. Favor tente novamente!\n\n");
            break;
        }
    }

    return 0;
}

void title(){
    printf("------------------------------\n");
    printf("-------MERCADO DO PEDRO-------\n");
    printf("------------------------------\n\n");
}

int menu(){
    system("cls");
    title();
    int op;
    printf("OPCAO 1 - CADASTRAR PRODUTO\n");
    printf("OPCAO 2 - REMOVER PRODUTO\n");
    printf("OPCAO 3 - CONSULTAR ESTOQUE\n");
    printf("OPCAO 4 - CONSULTAR ESTOQUE PERSONALIZADO\n");
    printf("OPCAO 5 - SAIR DO PROGRAMA.\n");
    printf("Escolha uma opcao: ");
    scanf("%d",&op);
    fflush(stdin);
    return op;
}

void inicializarVetor(PRODUTOS *produtos){
    for (int i = 0;i < qntdMAX; i++){
        produtos[i].codProduto = NULL;
        strcpy(produtos[i].nome,"");
        produtos[i].qntd = NULL;
    }

}

void verificarVetor(PRODUTOS *produtos){

    proxIndex = -1; //DEFINIR VALOR PARA VETOR CHEIO
    for (int i = 0;i < qntdMAX; i++){
        if(produtos[i].codProduto == 0){
            proxIndex = i;
            return;
        }
    }
}

int quantidadeEstoque(PRODUTOS *produtos){
    int qntdEmEstoque = 0;
    for(int i = 0; i < qntdMAX; i++){
        if(produtos[i].codProduto != 0){
            qntdEmEstoque++;
        }
    }
    return qntdEmEstoque;
}

void addProduto(PRODUTOS *produtos){
    verificarVetor(produtos); //VERIFICAR PROXIMO INDICE VAZIO NO VETOR
    if (proxIndex == -1){
        printf("\nESTOQUE CHEIO!\n");
        printf("Pressione qualquer tecla para Continuar..");
        getchar();
        return;
    }
    
    system("cls");

    title();
    printf("->CADASTRAR PRODUTO\n");
    //CODIGO DO PRODUTO
    printf("Informe o CODIGO do produto: ");
    scanf("%d", &produtos[proxIndex].codProduto);
    fflush(stdin);
    //NOME DO PRODUTO
    printf("Informe o NOME do Produto: ");
    scanf("%s", &produtos[proxIndex].nome);
    fflush(stdin);
    strupr(produtos[proxIndex].nome);
    //ESTOQUE
    printf("Informe o ESTOQUE do produto: ");
    scanf("%d", &produtos[proxIndex].qntd);
    fflush(stdin);


    printf("\n%s Cadastrado com sucesso!\n", produtos[proxIndex].nome); 
    printf("Pressione qualquer tecla para Continuar..");

    getchar();
}

void subProduto(PRODUTOS *produtos){
    
    int qntdEmEstoque = quantidadeEstoque(produtos); //QUANTIDADE DE PRODUTOS NO ESTOQUE
    if(qntdEmEstoque <= 0){ //VERIFICAR SE POSSUI PRODUTOS PARA REMOVER
        printf("\nNenhum produto cadastrado no estoque!\n");
        printf("Pressione qualquer tecla para Continuar..");
        getchar();
        return; //SAIR DA FUNÇÃO
    }

    int codRemover;
    system("cls");
    title();
    printf("->REMOVER PRODUTO\n");
    if (menuRemoverProduto() == 1){
        removerVisualizarEstoque(produtos);
    }

    printf("Informe o codigo do produto que deseja remover: ");
    scanf("%d", &codRemover);
    fflush(stdin);
    
    for(int i = 0; i < qntdMAX; i++){
        if(produtos[i].codProduto == codRemover){
            produtos[i].codProduto = NULL;
            strcpy(produtos[i].nome,"");
            produtos[i].qntd = NULL;

            printf("Produto removido com sucesso!\n");
            printf("Pressione qualquer tecla para Continuar..");
            getchar();
            return;
        }
    }
    printf("\nCodigo nao encontrado no Estoque.. Nenhuma alteracao realizada..\n");
    printf("Pressione qualquer tecla para Continuar..");
    getchar();
}

int menuRemoverProduto(){
    int op = 0;
    while(op < 1 || op > 2){
        printf("Deseja visualizar os produtos?\n");
        printf("OPCAO 1 - SIM\n");
        printf("OPCAO 2 - NAO\n");
        scanf("%d", &op);
        fflush(stdin);
        if(op < 1 && op > 2){
            printf("Opcao nao reconhecida..\n");
        }
    }
    return op;
}

void removerVisualizarEstoque(PRODUTOS *produtos){
    int encontrados = 0;
    for(int i = 0; i < qntdMAX; i++){
        if (produtos[i].codProduto != 0){
            if(encontrados == 0){
                printf("\n---------------------\n"); //SEPARADOR
            }
            printf("CODIGO: %d\n", produtos[i].codProduto);
            printf("NOME: %s\n", produtos[i].nome);
            printf("ESTOQUE: %d\n", produtos[i].qntd);
            printf("---------------------\n"); //SEPARADOR
            encontrados++;
        }
    }
}

void visualizarEstoque(PRODUTOS *produtos){
    int qntdEmEstoque = quantidadeEstoque(produtos); //QUANTIDADE DE PRODUTOS NO ESTOQUE
    
    if(qntdEmEstoque <= 0){ //VERIFICAR SE POSSUI PRODUTOS PARA VISUALIZAR
        printf("\nNenhum produto cadastrado no estoque!\n");
        printf("Pressione qualquer tecla para Continuar..");
        getchar();
        return; //SAIR DA FUNÇÃO
    }
    int encontrados = 0;
    system("cls");
    title();
    printf("->VISUALIZAR ESTOQUE\n");
    
    for(int i = 0; i < qntdMAX; i++){
        if (produtos[i].codProduto != 0){
            if(encontrados == 0){
                printf("\n---------------------\n"); //SEPARADOR
            }
            printf("CODIGO: %d\n", produtos[i].codProduto);
            printf("NOME: %s\n", produtos[i].nome);
            printf("ESTOQUE: %d\n", produtos[i].qntd);
            printf("---------------------\n"); //SEPARADOR
            encontrados++;
        }
    }
    printf("\nProdutos em Estoque: %d\n", qntdEmEstoque); //INFORMAÇÃO DA QUANTIDADE DE PRODUTOS EM ESTOQUE
    printf("Pressione qualquer tecla para Continuar..");
    getchar();
}

void ConsultarEstoquePersonalizado(PRODUTOS *produtos){
    int qntdEmEstoque = quantidadeEstoque(produtos); //QUANTIDADE DE PRODUTOS NO ESTOQUE
    
    if(qntdEmEstoque <= 0){ //VERIFICAR SE POSSUI PRODUTOS PARA VISUALIZAR
        printf("\nNenhum produto cadastrado no estoque!\n");
        printf("Pressione qualquer tecla para Continuar..");
        getchar();
        return; //SAIR DA FUNÇÃO
    }
    
    int qntdMin, qntdMax, encontrou, qntdEncontrados;
    encontrou = 0;
    qntdEncontrados = 0;
    system("cls");
    title();
    printf("->VISUALIZAR ESTOQUE\n");

    printf("Qual a quantidade MINIMA de quantidade que deseja procurar? ");
    scanf("%d", &qntdMin);
    fflush(stdin);
    printf("Qual a quantidade MAXIMA de quantidade que deseja procurar? ");
    scanf("%d", &qntdMax);
    fflush(stdin);

    if(qntdMin>qntdMax){ //EVITAR INFORMACAO ERRADA
        int qntdAux = qntdMax;
        qntdMax = qntdMin;
        qntdMin = qntdAux;
    }
    printf("\nQuantidade MINIMA: %d", qntdMin);
    printf("Quantidade MAXIMA: %d\n", qntdMax);
    
    for(int i = 0; i < qntdMAX; i++){
        if (produtos[i].codProduto > 0 && (produtos[i].qntd > qntdMin && produtos[i].qntd < qntdMax)){
            encontrou = 1;
            if(qntdEncontrados == 0){
                printf("\n---------------------\n"); //SEPARADOR
            }
            printf("CODIGO: %d\n", produtos[i].codProduto);
            printf("NOME: %s\n", produtos[i].nome);
            printf("ESTOQUE: %d\n", produtos[i].qntd);
            printf("---------------------\n"); //SEPARADOR
            qntdEncontrados++;
        }
    }
    if (encontrou == 0){
        printf("Nenhum produto encontrado no estoque com essas configuracoes..");
    }else{
        printf("Produtos encontrados: %d", qntdEncontrados);
    }
        printf("\nPressione qualquer tecla para Continuar..");
        getchar();
}
