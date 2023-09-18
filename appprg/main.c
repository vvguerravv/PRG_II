#include <stdio.h>
#include <libprg/libprg.h>

int main()
{
    int *vetor, tamanho,total,elemento,inicio,fim;
    char op

    printf("Tamanho do vetor:");
    scanf("%d",tamanho);
    criar(vetor,tamanho);
    povoar(vetor,tamanho);
    insere_nao_ord(vetor,total,tamanho,elemento);
    insere_ord(vetor,total,tamanho,elemento);
    busca_linear(vetor,total,tamanho,elemento);
    busca_bin_int(vetor,total,elemento);
    busca_bin_rec(vetor,inicio,fim,elemento);
    remove_num_ord(vetor,total,tamanho,elemento);
    remove_num_nao_ord(vetor,total,tamanho,elemento);
    libera_memoria(vetor,tamanho);

    return 0;
}
