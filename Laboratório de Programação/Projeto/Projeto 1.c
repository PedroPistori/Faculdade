#include <stdio.h>
#include <stdlib.h>

int tam = 0;
int nextIndex = 0;


void title();
int menu();
void proxIndex(int *vetor);
void adicionarProduto(int *vetor);
void visualizarEstoque(int *vetor);
void consultarEstoque(int *vetor);
int opConsulta(int qntd);

int main(int argc, char const *argv[])
{
    //USUARIO DEFINIR TAMANHO DO VETOR
    int quantidadeVetor = 0;
    printf("INSIRA O TAMANHO DO VETOR: ");
    scanf("%d", &quantidadeVetor);
    fflush(stdin);
    system("cls");

    int vetor[quantidadeVetor];
    tam = quantidadeVetor;
    //ELIMINAR LIXO DE MEMORIA DO VETOR
    for (int i = 0; i<tam; i++){
        vetor[i] = 0;
    }

    int *ponteiroVetor = vetor;
    int op = 0;
    
    while (op != 4)
    {
        op = menu();
        switch (op)
        {
        case 1: //ADICIONAR ESTOQUE
            system("cls");
            adicionarProduto(ponteiroVetor);
            break;
        case 2: //VISUALIZAR ESTOQUE
            system("cls");
            visualizarEstoque(ponteiroVetor);
            break;
        case 3: //CONSULTAR ESTOQUE BAIXO
            system("cls");
            consultarEstoque(ponteiroVetor);
            break;
        case 4:
            system("cls");
            printf("Finalizando programa.. Ate a proxima :D\n");
            break;                                            
        default:
            system("cls");
            printf("OPCAO NAO RECONHECIDA.. TENTE NOVAMENTE!\n");
            break;
        }
    }
    


    return 0;
}

void title(){
    printf("----------------------------\n");
    printf("------Lojinha do Pedro------\n");
    printf("----------------------------\n\n");

}

int menu(){
    title();
    int op = 0;
    printf("OPCAO 1 - ADICIONAR ESTOQUE\n");
    printf("OPCAO 2 - VISUALIZAR ESTOQUE\n");
    printf("OPCAO 3 - CONSULTAR ESTOQUE BAIXO\n");
    printf("OPCAO 4 - FINALIZAR PROGRAMA!\n\n");
    printf("ESCOLHA UMA OPCAO: ");
    scanf("%d", &op);
    fflush(stdin);
    return op;
}

void proxIndex(int *vetor){
    nextIndex = 0;
    for(int i = 0; i<tam; i++){
        if (vetor[i] == 0){
            nextIndex = i;
            return;
        }
    }
    nextIndex = -1; //LISTA CHEIA
}

void adicionarProduto(int *vetor){
    //VERIFICAR PROXIMO INDICE, OU SE A LISTA SE ENCONTRA CHEIA
    proxIndex(vetor);
    if (nextIndex == -1)
    {
        printf("O Vetor se encontra cheio!\n");
        return;
    }

    title();
    int qntd = 0;
    do
    {
        printf("Informe um valor para ser adicionado: ");
        scanf("%d", &qntd);
        fflush(stdin);
        if (qntd == 0)
        {
            printf("Nao e permitido adicionar produto com estoque 0! Tente novamente..\n");
        } else if (qntd < 0){
            printf("Nao e permitido adicionar produto com estoque negativo! Tente novamente..\n");
        }
    }while (qntd <= 0);
    
    vetor[nextIndex] = qntd;
    system("cls");
    printf("Produto adicionado com sucesso!\n");
}

void visualizarEstoque(int *vetor){
    title();
    proxIndex(vetor);
    if(nextIndex == 0){
        system("cls");
        printf("A Lista se encontra vazia.. Tente novamente mais tarde..\n");
        return;
    }

    int i = 0;
    while(i<tam && vetor[i] >= 0){
        if (vetor[i] > 0)
        {
            printf("Produto %d = %d quantidade em Estoque\n", i,vetor[i]);
            printf("--------------------------------------\n");
        }
        i++;
    }    

    //PAUSAR O SISTEMA PARA LEITURA
    printf("Pressione qualquer tecla para continuar..");
    getch();
    fflush(stdin);
    system("cls");
}

void consultarEstoque(int *vetor){
    title();
    proxIndex(vetor);
    if(nextIndex == 0){
        system("cls");
        printf("A Lista se encontra vazia.. Tente novamente mais tarde..\n");
        return;
    }

    int qntdBaixo;
    int qntdExibida = 0;
    int i = 0;
    int count = 0;
    int op = 0; //INICIALIZADO COM 1 PARA PODER ENTRAR NO WHILE!
    printf("Procurar por estoque abaixo de: ");
    scanf("%d", &qntdBaixo);
    fflush(stdin);

    while (op < 1 || op > 3)
    {
        op = opConsulta(qntdBaixo);
        switch (op)
        {
        case 1:
            qntdExibida = 5;
            break;
        case 2:
            qntdExibida = 10;
            break;
        case 3:
            qntdExibida = tam;
            break;                    
        default:
            printf("OPCAO NAO RECONHECIDA.. TENTE NOVAMENTE..\n");
            break;
        }
    }


    while (i<tam && vetor[i] >= 0)
    {
        if(vetor[i] > 0 && vetor[i] <= qntdBaixo && count < qntdExibida){
            printf("Produto %d = %d quantidade em Estoque\n", i,vetor[i]);
            printf("--------------------------------------\n");
            count++;           
        }
        i++;
    }

    if (qntdExibida > tam)
    {
        printf("Foram exibidos apenas %d produtos, devido ao limite do Vetor!\n\n", count);
    }
    //PAUSAR O SISTEMA PARA LEITURA

    printf("Pressione qualquer tecla para continuar..");
    getch();
    fflush(stdin);
    system("cls");
}

int opConsulta(int qntd){
    int op = 0;
    printf("OPCAO 1 = PRIMEIROS 5 PRODUTOS ABAIXO DE %d QUANTIDADE(S)\n", qntd);
    printf("OPCAO 2 = PRIMEIROS 10 PRODUTOS ABAIXO DE %d QUANTIDADE(S)\n", qntd);
    printf("OPCAO 3 = TODOS OS PRODUTOS ABAIXO DE %d QUANTIDADE(S)\n", qntd);
    printf("ESCOLHA UMA OPCAO: ");
    scanf("%d", &op);
    fflush(stdin);
    return op;
}
