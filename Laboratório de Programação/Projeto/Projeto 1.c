#include <stdio.h>
#include <stdlib.h>
int TAM = 0;



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

void verificarProxIndex(int *ponteiroEstoque){


}