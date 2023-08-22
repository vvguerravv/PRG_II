#include <stdio.h>

int fatorial_indu(int m)
{
    int resultado = 1;
        while(m > 1) {
            resultado_atual = m * (m - 1);
        }

    return resultado;
}

int main (int argc, char *argv[])
{
    int a = 5;
    printf("%d\n", fatorial_indu(a));

    return 0;
}