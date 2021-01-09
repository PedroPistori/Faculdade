/*  ALUNO: PEDRO HENRIQUE PISTORI COSTA
    RGA: 201911640026
    TIPO DE ED: ÁRVORE
    IMPLEMENTAÇÃO DO ALGORITMO

    REFERENCIAS: Youtube UNIVESP -> https://www.youtube.com/channel/UCBL2tfrwhEhX52Dze_aO3zA
                 Youtube Linguagem C Programação Descomplicada -> https://www.youtube.com/user/progdescomplicada
                 Github Rafael Herbert -> https://rafaelherbert.github.io/arvores-binarias-em-c/
*/
#include <stdio.h>
#include <stdlib.h>

//DEFINIÇÃO DA STRUCT DOS NODES DA ARVORE,
typedef struct node{
    int codProduto;
    char nomeProduto[50];
    struct node *esq,*dir;
}Node;
typedef Node* NODE;

//PROTOTIPAGEM DAS FUNÇÕES
//FUNCOES PARA O SISTEMA
void limparTela(); //LIMPAR A TELA
void pausar(); //PAUSAR PROGRAMA PARA LEITURA
void titulo(); //TITULO DO TOPO DA TELA
int menu(); //MENU DE OPCOES DO PROGRAMA.
//FUNÇÕES DO PROGRAMA
NODE inicializar(); //INICIALIZAR A RAIZ, COM VALOR NULL.
NODE criarNo(); //CRIAR NÓ PARA ADICIONA-LO POSTERIORMENTE.
NODE adicionar(NODE raiz, NODE no); //ADICIONAR O NÓ, CRIADO ANTERIORMENTE.
int buscarIDAux(); //RETORNAR O ID QUE O USUÁRIO DESEJA BUSCAR.
void buscarID(NODE raiz,int codBuscar); //BUSCAR O NÓ/PRODUTO, POR ID.
NODE buscaNode(NODE raiz, int chave, NODE *pai);
NODE removerNode(NODE raiz, int chave);

int main(int argc, char const *argv[])
{
    NODE r = inicializar(); //CRIAR NO RAIZ
    int op = 0; //INICIALIZAR op PARA A FUNÇÃO DE MENU
    int nodeRemover = 0;
    while(op != 4){
        op = menu();
        switch (op)
        {
        case 1: //ADICIONAR PRODUTO
            titulo();
            r = adicionar(r,criarNo()); //ADICIONAR O RETORNO DA FUNÇÃO criarNo(), COMO PARAMETRO
            break;
        case 2: //REMOVER PRODUTO
            printf("Qual NODE deseja REMOVER: ");
            scanf("%d", &nodeRemover);
            r = removerNode(r, nodeRemover);
            nodeRemover == 0;
            pausar();
            break;
        case 3: //BUSCAR PRODUTO
            buscarID(r,buscarIDAux());
            break;
        case 4: //SAIR DO PROGRAMA
            printf("Ate a proxima.. :D\n");
            break; 
        default: //DEFAULT
            printf("\nOpcao nao reconhecida.. \n\n");
            pausar();
            break;                               
        }

    }

    free(r); //LIMPAR RAIZ ANTES DE FINALIZAR O PROGRAMA
    return 0;
}

void limparTela(){
    system("cls");
}

void pausar(){
    printf("Pressione qualquer tecla para continuar..");
    getch();
    fflush(stdin);
    system("cls");
}

void titulo(){
    limparTela();
    printf("----------------------------------\n");
    printf("---------Mercado do Pedro---------\n");
    printf("----------------------------------\n");
    printf("\n");
}

int menu(){
    titulo();
    int op;
    printf("OPCAO 1 - ADICIONAR PRODUTO\n");
    printf("OPCAO 2 - REMOVER PRODUTO\n");
    printf("OPCAO 3 - BUSCAR PRODUTO\n");
    printf("OPCAO 4 - SAIR DO PROGRAMA\n");
    printf("\n");
    printf("ESCOLHA UMA OPCAO: ");
    scanf("%d", &op);
    fflush(stdin);
    return op;
}

//INICIALIZAR NÓ
NODE inicializar(){
    return(NULL);
}

//CRIAR NÓ PRA ADICIONAR À ARVORE
NODE criarNo(){
    NODE no = (NODE)malloc(sizeof(Node));
    no->esq = NULL;
    no->dir = NULL;
    //LER CODIGO DO PRODUTO
    printf("Insira o CODIGO do produto: ");
    scanf("%i", &no->codProduto);
    fflush(stdin);
    //LER NOME DO PRODUTO
    printf("Insira o NOME do produto: ");
    fgets(no->nomeProduto,50,stdin);//fgets PARA EVITAR 'ESTOURO DE BUFFER'
    fflush(stdin);
    return no;
}

//ADICIONAR NÓ NA ARVORE
NODE adicionar(NODE raiz, NODE no){
    if(raiz == NULL){
        return(no);
    }
    if(no->codProduto < raiz->codProduto){
        raiz->esq = adicionar(raiz->esq,no);
    }else{
        raiz->dir = adicionar(raiz->dir,no);
    }
    return(raiz);
}

int buscarIDAux(){
    int codBuscar;
    printf("Informe o CODIGO do produto que deseja buscar: ");
    scanf("%d", &codBuscar);
    fflush(stdin);
    return codBuscar;
}

//BUSCAR PRODUTO NA ARVORE
void buscarID(NODE raiz, int codBuscar){
    if(raiz == NULL){
        titulo();
        printf("Nao encontrou o CODIGO %d na lista de produtos!\n\n", codBuscar);
        pausar();
    }else if(raiz->codProduto == codBuscar){
        printf("CODIGO: %d\n", raiz->codProduto);
        printf("NOME: %s\n", raiz->nomeProduto);
        pausar();        
    }else if(codBuscar < raiz->codProduto){
        buscarID(raiz->esq,codBuscar);
    }else if(codBuscar > raiz->codProduto){
        buscarID(raiz->dir,codBuscar);
    }
}

//REMOÇÃO DE NÓ
NODE buscaNode(NODE raiz, int chave, NODE *pai){ //METODO AUXILIAR PARA A REMOÇÃO DE NÓ
    NODE aux = raiz;
    *pai = NULL;
    while(aux){
        if(aux->codProduto == chave){
            return(aux);
        }
        *pai = aux;
        if(chave < aux->codProduto){
            aux = aux->esq;
        }else {
            aux = aux->dir;
        }

    }
    return(NULL);
}

NODE removerNode(NODE raiz, int chave){//FUNCAO PARA A REMOCAO DO NO
    NODE pai, no, p, q;

    no = buscaNode(raiz, chave, &pai); //BUSCAR NÓ QUE DESEJA REMOVER, NA FUNÇÃO AUXILIAR

    //NAO ENCONTROU O NO QUE DESEJA REMOVER
    if(no == NULL){ 
        printf("O No %d, nao foi encontrado..\n",chave);
        printf("Nenhuma alteracao foi realizada..\n\n");
        return(raiz);
    }

    //ENCONTROU O NO QUE DESEJA REMOVER
    if(!no->esq || !no->dir){ //VERIFICAR SE POSSUI FILHOS NA DIREITA E NA ESQUERDA
        if(!no->esq){ //VERIFICAR SE POSSUI FILHO NA ESQUERDA
            q = no->dir; //PEGAR FILHO DA DIREITA
        }else { //VERIFICAR SE POSSUI FILHO NA DIREITA
            q = no->esq; //PEGAR FILHO DA ESQUERDA
        }
    }else{ //POSSUI OS 2 FILHOS
        p = no;
        q = no->esq; 
        while (q->dir){ //IR PARA O NÓ MAIS A DIREITA QUE CONSEGUIR
            p = q;
            q = q->dir;
        }

        if(p != no){ //VERIFICAR SE O PAI DO NÓ QUE VAI SER 'PROMOVIDO', NÃO É O NÓ QUE DESEJAMOS REMOVER
            p->dir = q->esq;
            q->esq = no->esq;
        }
        q->dir = no->dir;
    }

    if(!pai){ //VERIFICAR SE O NÓ A SER REMOVIDO POSSUI PAI
        free(no);
        printf("No %d foi removido!\n\n", chave);
        return(q);
    }

    if(chave < pai->codProduto){ //DESCOBRIR QUAL O LADO DO NÓ PAI, QUE ESTAMOS REMOVENDO O NÓ DESEJADO(ESQUERDA OU DIREITA)
        //SE O NO A SER REMOVIDO FOR MENOR QUE O PAI, ENTAO ESTAMOS NO LADO ESQUERDO
        pai->esq = q;
    }else{
        //SENAO, SE O NO A SER REMOVIDO FOR MAIOR QUE O PAI, ESTAMOS NO LADO DIREITO
        pai->dir = q;
    }

    free(no);
    printf("No %d foi removido!\n\n", chave);
    return(raiz);
}