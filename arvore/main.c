#include <libprg/libprg.h>

int main()
{

    struct timeval start;
    clock_t comecar;
    int tamanho,i = 0;
    tree_t *root = NULL;

    printf("Digite o tamanho da árvore: ");
    scanf("%d",&tamanho);

    srand(time(NULL));

    comecar = clock();
    inicio(&start);

    root = insert_value(root, 10);
    root = insert_value(root, 13);
    root = insert_value(root, 23);
    root = insert_value(root, 21);
    root = insert_value(root, 24);

//    while(i < tamanho - 1){
//        root = insert_value(root, rand() % 100 + 1);
//        i++;
//    }

    printf("\nTempo Parede: %f\n", fim_relogio_parede(&start));
    printf("CPU: %f\n", fim_CPU(comecar));

    comecar = clock();
    inicio(&start);
    printf("Maior Número: %d\t", maxNum(root));
    printf("Tempo Parede: %f\t", fim_relogio_parede(&start));
    printf("CPU: %f\n", fim_CPU(comecar));

    comecar = clock();
    inicio(&start);
    printf("Menor número: %d\t\t", minNum(root));
    printf("Tempo Parede: %f\t", fim_relogio_parede(&start));
    printf("CPU: %f\n", fim_CPU(comecar));

    int level = 0;

    tree_t *aux = teste(root,23,&level);

    if(aux == NULL){
        printf("Número não encontrado\n");
    } else{
        if(aux->right != NULL){
            printf("Filho da direita "
                   "do  número %d é o número: %d\n",aux->value,aux->right->value);
        } if(aux->left != NULL){
            printf("Filho da esquerda "
                   "do  número %d é o número: %d\n",aux->value,aux->left->value);
        }
        printf("O número %d está no nível %d na árvore.\n",aux->value,level);
    }

    return 0;
}