#include <libprg/libprg.h>

int main()
{

    struct timeval start;
    clock_t comecar;
    int tamanho;
    tree_t *root = NULL;

    printf("Digite o tamanho da árvore: ");
    scanf("%d",&tamanho);

    srand(time(NULL));

    comecar = clock();
    inicio(&start);



    for(int i = 0; i < tamanho; i++){
        root = insert_value(root,rand() % 100 + 1);
    }

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
    printf("CPU: %f\n\n", fim_CPU(comecar));

    int level = 0,num_insert;

    printf("Digite o número que deseja inserir: ");
    scanf("%d",&num_insert);

    int num_search;

    comecar = clock();
    inicio(&start);

    num_search = searchTree(root,num_insert);
    printf("Tempo Parede: %f\t", fim_relogio_parede(&start));
    printf("CPU: %f\n", fim_CPU(comecar));
    if(num_search == 1){
        printf("O número %d já está na árvore!\n",num_insert);
        tree_t *aux = son(root,num_insert,&level);
        if(aux->right != NULL){
            printf("Filho da direita "
                   "do  número %d é o número: %d\n",aux->value,aux->right->value);
        } if(aux->left != NULL){
            printf("Filho da esquerda "
                   "do  número %d é o número: %d\n",aux->value,aux->left->value);
        }
        printf("O número %d está no nível %d na árvore.\n",aux->value,level);
    } else{
        root = insert_value(root, num_insert);
        tamanho++;
    }

    printf("Selecione um número para excluir: ");
    scanf("%d",&num_insert);
    if(!searchTree(root,num_insert)){
        printf("Número não encontrado na árvore!\n");
    }else{
        root = removeNum(root,num_insert);
        tamanho--;
    }


//    inOrder(root);
//    preOder(root);
//    posOrder(root);

//    width(root,tamanho);


    printGraph(root);


    return 0;
}