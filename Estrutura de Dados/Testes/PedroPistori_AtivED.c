#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Criacao dos tipos de dados constru�dos
// registros (struct) LISTA e INICIO
typedef struct{
    char CPF[11], tel[9];
    char nome[30];
    struct LISTA *ant, *prox;
}LISTA;

typedef struct{
    int nelem;
    LISTA *prox_ini;
}INICIO;

void localizarCPF(INICIO *inicio);
main(){
    INICIO *inicio;
    LISTA *p_aux1, *p_aux2, *p;
    int i = 1, x, cont;

    inicio = (INICIO *) malloc(sizeof(INICIO));
    inicio->nelem = 0;
    inicio->prox_ini = NULL;

    do{
        printf("\nNumero de elementos na Lista: %d\n", inicio->nelem);
        if(inicio->prox_ini == NULL){
                // se nao existir nenhum elemento na lista
                // insercao no inicio
                p_aux1 = (LISTA *) malloc(sizeof(LISTA));

                printf("\nInforme o CPF (somente numeros): ");
                fflush(stdin);
                gets(p_aux1->CPF);

                printf("\nInforme o telefone (somente numeros): ");
                fflush(stdin);
                gets(p_aux1->tel);

                printf("\nInforme o nome: ");
                fflush(stdin);
                gets(p_aux1->nome);

                p_aux1->prox = NULL;
                p_aux1->ant = NULL;
                inicio->prox_ini = p_aux1;
                inicio->nelem++;
        }
        else{
                // se nao, o usuario decide a posicao
                // em que o novo noh serah inserido
                printf("\nTemos [1 ... %i] elementos na lista: \n", inicio->nelem);
                printf("\nEm que posicao deseja inserir um novo elemento?\n");
                fflush(stdin);
                scanf("%i",&x);

                if(x == 1){
                        p_aux1 = (LISTA *) malloc(sizeof(LISTA));

                        printf("\nInforme o CPF (somente numeros): ");
                        fflush(stdin);
                        gets(p_aux1->CPF);

                        printf("\nInforme o telefone (somente numeros): ");
                        fflush(stdin);
                        gets(p_aux1->tel);

                        printf("\nInforme o nome: ");
                        fflush(stdin);
                        gets(p_aux1->nome);

                        p_aux1->prox = inicio->prox_ini;
                        inicio->prox_ini->prox = NULL;
                        inicio->prox_ini->ant = p_aux1;
                        inicio->prox_ini = p_aux1;
                        p_aux1->ant = NULL;

                        inicio->nelem++;
                }
                else{
                    if((x > 1) && (x <= inicio->nelem)){
                        p_aux1 = (LISTA *) malloc(sizeof(LISTA));
                        p = (LISTA *) malloc(sizeof(LISTA));
                        p_aux2 = inicio->prox_ini;

                        // insere no meio
                        printf("\nInforme o CPF (somente numeros): ");
                        fflush(stdin);
                        gets(p_aux1->CPF);

                        printf("\nInforme o telefone (somente numeros): ");
                        fflush(stdin);
                        gets(p_aux1->tel);

                        printf("\nInforme o nome: ");
                        fflush(stdin);
                        gets(p_aux1->nome);

                        cont = 1;
                        do{
                            p_aux2 = p_aux2->prox;
                            cont++;
                        }while(x != cont);
                        printf("\nx = %i, cont = %i, p_aux2->nome: ", x, cont);
                        puts(p_aux2->nome);

                        p_aux1->ant = p_aux2->ant;
                        p_aux1->prox = p_aux2;
                        p = p_aux2->ant;
                        p->prox = p_aux1;
                        p_aux2->ant = p_aux1;

                        inicio->nelem++;
                    }
                    else{
                        if(x > inicio->nelem){
                            // insere no fim
                            p_aux1 = (LISTA *) malloc(sizeof(LISTA));

                            printf("\nInforme o CPF (somente numeros): ");
                            fflush(stdin);
                            gets(p_aux1->CPF);

                            printf("\nInforme o telefone (somente numeros): ");
                            fflush(stdin);
                            gets(p_aux1->tel);

                            printf("\nInforme o nome: ");
                            fflush(stdin);
                            gets(p_aux1->nome);

                            p_aux2 = inicio->prox_ini;

                            if(p_aux2->prox == NULL){
                                p_aux1->prox = inicio->prox_ini;
                                inicio->prox_ini->prox = NULL;
                                inicio->prox_ini->ant = p_aux1;
                                inicio->prox_ini = p_aux1;
                                p_aux1->ant = NULL;
                            }
                            else{
                                while (p_aux2 != NULL)
                                    p_aux2 = p_aux2->prox;

                                p_aux2->prox = p_aux1;
                                p_aux1->ant = p_aux2;
                                p_aux1->prox = NULL;
                            }
                            inicio->nelem++;
                        }
                        else
                            printf("\nEssa posicao nao existe na lista!");
                    }
            }
        }
        printf("\nDeseja inserir mais um elemento na lista? (1 = sim, 0 = nao):\n");
        fflush(stdin);
        scanf("%i", &i);
    }while(i != 0);

    p_aux1 = inicio->prox_ini;
    while(p_aux1 != NULL){
        printf("\nCPF: \n");
        puts(p_aux1->CPF);
        printf("\nTelefone: \n");
        puts(p_aux1->tel);
        printf("\nNome: \n");
        puts(p_aux1->nome);

        p_aux1 = p_aux1->prox;
    }

    localizarCPF(inicio);
}

void localizarCPF(INICIO *inicio){
    fflush(stdin);
    LISTA *pAux = inicio->prox_ini;
    int encontrou = 0;

    char cpfAux[11];
    printf("Localizar qual cpf?\n");
    printf("LOCALIZAR CPF: ");
    scanf("%c", &cpfAux);
    fflush(stdin);
    while (pAux != NULL)
    {
        if ( strcmp(pAux->CPF,cpfAux) == 0 )
        {
            printf("CPF: %s\n", pAux->CPF);
            printf("NOME: %s\n", pAux->nome);
            printf("TELEFONE: %s\n", pAux->tel);
            encontrou = 1;
        }
        pAux = pAux->prox;
    }
    if (encontrou == 0)
    {
        printf("NAO ENCONTROU ESSE CPF NA LISTA!\n\n");
    }
    
}