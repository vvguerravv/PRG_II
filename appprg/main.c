#include <libprg/libprg.h>

int main(int argc, char *argv[])
{
    int escolha = -1;
    int *vetor, tamanho,total,elemento,inicio,fim;
    char op[2] = {};

    printf("Escolha o que você quer fazer!\n");


    while(escolha != 0){
        printf("1 - Criar uma lista povoada de tamanho n\n");
        printf("2 - Inserir um novo número\n");
        printf("3 - Remover um número\n");
        printf("4 - Buscar por um número usando busca linear\n");
        printf("5 - Buscar por um número usando busca binária iterativa\n");
        printf("6 - Buscar por um número usando busca binária recursiva\n");
        printf("7 - Irá imprimir a lista\n");
        printf("Selecione 0 para sair\n");
        scanf("%d",&escolha);

        switch (escolha) {
            case 1:
                printf("Selecione o tamanho do vetor: ");
                scanf("%d",&tamanho);
                criar(&vetor,tamanho);
                printf("Ordenada ou não ordenada? OBS: Selecione \"O\" para ordenada e \"N\" para não ordenada: ");
                scanf("%s",&op);
                if(strcmp(op,"O") == 0){
                    povoar_ord(&vetor,&total,tamanho);
                } if(strcmp(op,"N") == 0){
                    povoar_nao_ord(&vetor,&total,tamanho);
                }
                break;

            case 2:
                printf("Selecione qual número será inserido: ");
                scanf("%d",&elemento);

                if(strcmp(op,"O") == 0){
                    insere_ord(&vetor,&total,tamanho,elemento);
                    printf("%d\n",insere_ord(&vetor,&total,tamanho,elemento));
                } if(strcmp(op,"N") == 0){
                    insere_nao_ord(&vetor,&total,tamanho,elemento);
                    printf("%d\n",insere_nao_ord(&vetor,&total,tamanho,elemento));
                }
                break;

            case 3:
                printf("Selecione o número que será removido: ");
                scanf("%d",&elemento);

                if(strcmp(op,"O") == 0){
                    remove_num_ord(&vetor,&total,tamanho,elemento);
                } if(strcmp(op,"N") == 0){
                    remove_num_nao_ord(&vetor,&total,tamanho,elemento);
        }
                break;

            case 4:
                printf("Selecione o número que será buscado: ");
                scanf("%d",&elemento);
                busca_linear(&vetor,total,elemento);
                break;

            case 5:
                printf("Selecione o número que será buscado: ");
                scanf("%d",&elemento);
                busca_bin_int(&vetor,total,elemento);
                break;

            case 6:
                printf("Selecione o número que será buscado: ");
                scanf("%d",&elemento);
                busca_bin_rec(&vetor,inicio,fim,elemento);
                break;

            case 7:
                for(int i = 0; i <= tamanho; i++){
                    printf("%d\n",&vetor[i]);
                }
        }


    }

    libera_memoria(&vetor,tamanho);

    return 0;
}
