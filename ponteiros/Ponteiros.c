#include <stdio.h>
#include <stdlib.h>



int main(void)
{
    int *vetor, tamanho = 2;

    vetor = calloc(tamanho, sizeof(int));

    if(vetor == NULL){
        printf("Não foi possível alocar memória\n");
        exit(EXIT_FAILURE);
    }
    vetor[0] = 10; vetor[1] = 20;
    tamanho = 4;

    vetor = realloc(vetor,tamanho * sizeof(int));
    vetor[2] = 30; vetor[3] = 40;

    for(int i = 0;i < tamanho; i++){
        printf("%d\n",*(vetor + i));
    }
    free(vetor);

    return 0;
}