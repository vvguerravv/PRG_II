#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mul_ite(int m, int n){
    int resultado = 0;
    for(int i =0; i < n; i++){
        resultado +=m;
    }
    return resultado;
}

int mult_rec(int m, int n)
{
    if (n == 0){
        return  0;
    }
    return (m + mult_rec(m,n - 1));
}

void aloca_memoria_pilha(int quantidade)
{
    int tamanho = quantidade * (1 << 20);
    char memoria[tamanho];
    printf("Vetor de tamanho: %d kB\n",tamanho/1024);
    printf("Endereço da variável tamanho: %p\n",(void*)&tamanho);
    printf("Distancia entre o vetor e tamanho: %ld\n",(((char*)&tamanho-memoria))/1024);
    bzero(memoria, tamanho);
    printf("zerou memória\n");
}

void aloca_memoria_heap(int quantidade)
{
    int tamanho = quantidade * (1 << 20);
    char *memoria = calloc(tamanho, sizeof(char));
    printf("Vetor de tamanho: %d kB\n",tamanho/1024);
    printf("Endereço da variável tamanho: %p\n",(void*)&tamanho);
    printf("Distancia entre o vetor e tamanho: %ld\n",(((char*)&tamanho-memoria))/1024);
    bzero(memoria, tamanho);
    printf("zerou memória\n");
    free(memoria);
}

int main(int argc, char *argv[])
{
//    int a = 2,b = 5;
//
//    mul_ite(a,b);
//    printf("%d %d",a,b);
//    mult_rec(a,b);



    if(argc > 0 && strcasecmp(argv[1],"p") == 0){
        aloca_memoria_pilha(strtol(argv[2], NULL, 10));
        return 0;
    }
    if(argc > 0 && strcasecmp(argv[1],"h") == 0){
        aloca_memoria_heap(strtol(argv[2], NULL, 10));
        return 0;
    }
    return 0;
}
