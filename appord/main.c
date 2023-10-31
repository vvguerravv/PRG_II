#include <libprg/libprg.h>

int main()
{
    struct timeval start;
    clock_t comecar;
    ord_t ord;
    printf("Selecione o tamanho do vetor: ");
    scanf("%d",&ord.tamanho);
    criar_vet(&ord);

    printf("=======================\n");
    printf("Bubble:\n");
    povoar(&ord);
    comecar = clock();
    inicio(&start);
    bubble(&ord,true);
    printf("Vetor: ");
    imprimi(&ord);
    printf("CPU:%f\n", fim_CPU(comecar));
    printf("Tempo de relógio de parede: %f\n", fim_relogio_parede(&start));

    printf("=======================\n");

    printf("Insert:\n");
    povoar(&ord);
    comecar = clock();
    inicio(&start);
    insert(&ord);
    printf("CPU:%f\n", fim_CPU(comecar));
    printf("Tempo de relógio de parede: %f\n", fim_relogio_parede(&start));
    printf("Vetor: ");
    imprimi(&ord);
    printf("=======================\n");

    printf("Selection:\n");
    povoar(&ord);
    comecar = clock();
    inicio(&start);
    selection(&ord,true);
    printf("CPU:%f\n", fim_CPU(comecar));
    printf("Tempo de relógio de parede: %f\n", fim_relogio_parede(&start));
    printf("Vetor: ");
    imprimi(&ord);
    printf("=======================\n");

    printf("Merge sort:\n");
    povoar(&ord);
    comecar = clock();
    inicio(&start);
    int left = 0;
    int right = ord.tamanho - 1;
    merge_sort(&ord, left, right);
    printf("CPU:%f\n", fim_CPU(comecar));
    printf("Tempo de relógio de parede: %f\n", fim_relogio_parede(&start));
    printf("Vetor: ");
    imprimi(&ord);
    printf("=======================\n");

    printf("Quick sort:\n");
    povoar(&ord);
    comecar = clock();
    inicio(&start);
    quick_sort(&ord, left, right);
    printf("CPU:%f\n", fim_CPU(comecar));
    printf("Tempo de relógio de parede: %f\n", fim_relogio_parede(&start));
    printf("Vetor: ");
    imprimi(&ord);
    printf("=======================\n");



    return 0;
}
