#include <libprg/libprg.h>

int main()
{
    int escolha = -1;
    int elemento;
    char op[2] = {};
    lista_t lista;

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
            label:
                printf("Selecione o tamanho do vetor: ");
                scanf("%d",&lista.tamanho);
                if(criar(&lista) == 1){
                    printf("Vetor criado com sucesso!!\n");
                } else{
                    printf("O vetor não foi criado!!\n");
                    goto label;
                }
                printf("Ordenada ou não ordenada? OBS: Selecione \"O\" para ordenada e \"N\" para não ordenada: ");
                scanf("%s",op);
                if(strcmp(op,"O") == 0){
                    povoar_ord(&lista);
                } if(strcmp(op,"N") == 0){
            povoar_nao_ord(&lista);
        }
                break;

            case 2:
                printf("Selecione qual número será inserido: ");
                scanf("%d",&elemento);

                if(strcmp(op,"O") == 0){
                    if(insere_ord(&lista,elemento) == 1){
                        printf("Elemento inserido com sucesso!\n");
                    }else{
                        printf("Elemento não inserido! Verifique o tamanho do vetor e se ele está cheio e tente novamente.\n");
                    }
                } if(strcmp(op,"N") == 0){
            if(insere_nao_ord(&lista,elemento) == 1){
                printf("Elemento inserido com sucesso!\n");
            }else{
                printf("Elemento não inserido! Verifique o tamanho do vetor e se ele está cheio e tente novamente\n");
            }
        }
                break;

            case 3:
                printf("Selecione o número que será removido: ");
                scanf("%d",&elemento);

                if(strcmp(op,"O") == 0){
                    if(remove_num_ord(&lista,elemento) == 1){
                        printf("Elemento removido com sucesso!\n");
                    }else{
                        printf("Elemento não removido! Verifique se ele faz parte do vetor e tente novamente!\n");
                    }
                } if(strcmp(op,"N") == 0){
            if(remove_num_nao_ord(&lista,elemento) == 1){
                printf("Elemento removido com sucesso!\n");
            }else{
                printf("Elemento não removido! Verifique se ele faz parte do vetor e tente novamente!\n");
            }
        }
                break;

            case 4:
                printf("Selecione o número que será buscado: ");
                scanf("%d",&elemento);
                if(busca_linear(&lista,elemento) >= 0){
                    printf("O número %d está na posição %d do vetor!\n",elemento,busca_linear(&lista,elemento));
                } else{
                    printf("O número não foi encotrado!\n");
                }
                break;

            case 5:
                printf("Selecione o número que será buscado: ");
                scanf("%d",&elemento);
                busca_bin_int(&lista,elemento);

                if(busca_bin_int(&lista,elemento) >= 0){
                    printf("O número %d está na posição %d do vetor!\n",elemento,busca_bin_int(&lista,elemento));
                } else{
                    printf("O número não foi encotrado!\n");
                }

                break;

            case 6:
                printf("Selecione o número que será buscado: ");
                scanf("%d",&elemento);

                if( busca_bin_rec(&lista,0,lista.tamanho,elemento) >= 0){
                    printf("O número %d está na posição %d do vetor!\n", elemento,busca_bin_rec(&lista,0,lista.tamanho,elemento));
                } else{
                    printf("O número não foi encotrado!\n");
                }
                break;

            case 7:
                for(int i = 0; i < lista.total; i++){
                    printf("%d\n",lista.vetor[i]);
                }
        }


    }

    libera_memoria(&lista);

    return 0;
}

