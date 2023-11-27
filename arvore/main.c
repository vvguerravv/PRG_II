#include <libprg/libprg.h>

int main()
{

    int tamanho,i = 0;
    tree_t *root = NULL;

    printf("Digite o tamanho da árvore: ");
    scanf("%d",&tamanho);

    srand(time(NULL));
    while(i != tamanho){
        insert_value(root, rand() % 100 + 1);
        i++;
    }


    return 0;
}