#include <libprg/libprg.h>

int main()
{
    struct timeval inicio;
    ord_t ord;
    printf("Selecione o tamanho do vetor: ");
    scanf("%d",&ord.tamanho);
    criar_vet(&ord);

    printf("=======================\n");
    printf("Bubble: ");
    povoar(&ord);
    inicio_relogio_parede(&inicio);
    bubble(&ord,false);
    imprimi(&ord);
    printf("%f\n", fim_relogio_parede(&inicio));
    printf("=======================\n");

    printf("Insert: ");
    povoar(&ord);
    inicio_relogio_parede(&inicio);
    insert(&ord);
    printf("%f\n", fim_relogio_parede(&inicio));
    imprimi(&ord);
    printf("=======================\n");

    printf("Selection: ");
    povoar(&ord);
    inicio_relogio_parede(&inicio);
    selection(&ord,false);
    printf("%f\n", fim_relogio_parede(&inicio));
    imprimi(&ord);
    printf("=======================\n");

}
