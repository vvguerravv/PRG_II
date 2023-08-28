#include <stdio.h>

//void fibo_interativo(int n)
//{
//    int p = 0;
//    int s = 1;
//
//    if(n <= 0){
//        return;
//    }
//
//    if(n == 1){
//        printf("0");
//        return;
//    }
//
//    printf("0 1 ");
//    for(int i = 0; i < n-2; i++){
//        int atual = p + s;
//        printf("%d ",atual);
//        p = s;
//        s = atual;
//    }
//}
//
//int fibo_recursivo(int n)
//{
//    if((n == 0) || (n == 1)){
//        return n;
//    }
//    int atual = fibo_recursivo(n-1) + fibo_recursivo(n-2);
//}
//
//
//int main(int argc, char *argv[]) {
//    fibo_interativo(8);
//    printf("\n");
//    printf("-----------");
//    for(int i = 0;i < 0; ++i){
//        printf("%d", fibo_recursivo(i));
//    }
//    return 0;
//}

long fib_int(int n)
{
    if(n == 0){
        return 0;
    }
    long a = 0;
    long b = 1;

    for(int i = 1;i < n; ++i){
        int k = a + b;
        a = b;
        b = k;
    }
    return b;
}

long fib_rec(int n)
{
    if((n == 0) || (n ==1 )){
        return n;
    }
    return (fib_rec(n - 1) + fib_rec(n - 2));
}

#include <stdio.h>
#include <sys/time.h>


int main(int argc, char **argv) {
    struct timeval inicio, fim;

    // Iniciando tomada de tempo
    gettimeofday(&inicio, 0);

    fib_rec(45);

    // Finalizando tomada de tempo
    gettimeofday(&fim, 0);

    long seg = fim.tv_sec - inicio.tv_sec;
    long mseg = fim.tv_usec - inicio.tv_usec;
    double tempo_total = seg + mseg * 1e-6;

    printf("Tempo gasto: %f segundos.\n", tempo_total);

    return 0;
}
