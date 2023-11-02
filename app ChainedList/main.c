#include <libprg/libprg.h>

int main()
{
    no_t *no;
    ChainedList_t list;
    list.size = 0;
    Stackist_t stack;
    stack.size = 0;


    addStack(&stack,&no,10);
    addStack(&stack,&no,20);
    addStack(&stack,&no,110);
    addStack(&stack,&no,1110);

    printNo(no);
    printf("\n");
    printf("Posição do 10: %d\n", searchStack(&no,10));

    printf("\n Retira 1: ");
    removeStack(&stack,&no);
    printNo(no);
    printf("\n");
    printf("Posição do 10: %d\n", searchStack(&no,10));

    printf("\n Retira 2: ");
    removeStack(&stack,&no);
    printNo(no);
    printf("\n");
    printf("Posição do 10: %d\n", searchStack(&no,10));

    printf("\n Retira 3: ");
    removeStack(&stack,&no);
    printNo(no);
    printf("\n");
    printf("Posição do 10: %d\n", searchStack(&no,10));
//    addList(&list,&no,13);
//    addList(&list,&no,35);
//    addList(&list,&no,80);
//
//    printf("Nós: ");
//    printNo(no);
//    printf("Tamanho: %d\n",list.size);
//
//    removeList(&list,&no);
//
//    printf("Nós: ");
//    printNo(no);
//    printf("Tamanho: %d\n",list.size);
//
//    printf("%d",searchList(&no,32));

    return 0;
}