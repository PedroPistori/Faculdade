#include <stdio.h>
#include <stdlib.h>
int TAM = 0;
int G_proxIndex = 0;


void verificarProxIndex(int *ponteiroEstoque);

int main(int argc, char const *argv[])
{
    int qntd = 0;
    printf("Informe a quantidade de dados que deseja armazenar: ");
    scanf("%d", &qntd);

    int estoque[qntd];
    TAM = qntd;
    int op = 0;

    int *ponteiroEstoque = estoque; 
    for (int i = 0; i<TAM; i++){
        ponteiroEstoque[i] = 0;
    }

    while(op != 5)
    {
        op = menu();
        switch (op)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            printf("Ate a proxima.. :D");
            break;                                            
        default:
            printf("Opcao nao reconhecida.. Tente novamente");
            break;
        }



    }

    return 0;
}


void title(){
    printf("--------------------------------\n");
    printf("--------Lojinha do Pedro--------\n");
    printf("--------------------------------\n\n");
}

int menu(){
    title();
    int op;

    printf("OPCAO 1 - ADICIONAR PRODUTO\n");
    printf("OPCAO 2 - REMOVER PRODUTO\n");
    printf("OPCAO 3 - VISUALIZAR ESTOQUE\n");
    printf("OPCAO 4 - CONSULTAR ESTOQUE\n");
    printf("\n Escolha uma opcao: ");
    scanf("%d", &op);
    fflush(stdin);
    return op;
}

void verificarProxIndex(int *estoque){
    G_proxIndex = 0;
    for(int i = 0; i<TAM; i++){
        if (estoque[i] == 0)
        {
            G_proxIndex = i;
            break;
        }
    }
}

void adicionarProduto(int *estoque){
    title();
    verificarProxIndex(estoque);
    printf("Informe a quantidade em estoque: ");
    scanf("%d", &estoque[G_proxIndex]);
    fflush(stdin);
}

void removerProduto(int *estoque){
    title();
    int op = 0;
    
    while (op<1 || op>2){
        op = opcaoVisualizar();
        if (op < 1 || op > 2){
            printf("Opcao nao reconhecida.. Tente novamente\n");
        }
    }
    if(op == 1){
        visualizarLista(estoque);
    }



    int idRemover = 0;
    printf("Insira o ID do produto que deseja remover:");
    scanf("%d", idRemover);

    estoque[idRemover] = 0;
    printf("Produto ID %d, Deletado com sucesso!", idRemover);


}

int opcaoVisualizar(){
    int op = 0;
    printf("Deseja visualizar a lista de produtos?\n");
    printf("OPCAO 1 - SIM\n");
    printf("OPCAO 2 - NAO\n\n");
    printf("Insira uma opcao: ");
    scanf("%d",&op);
    fflush(stdin);
   
    
    return op;
}
