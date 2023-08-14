#include <stdio.h>
#include "ex_1.c"
#include "ex_2.c"
#include "ex_3.c"
#include "ex_4.c"
#include "ex_5.c"
#include "ex_6.c"
#include "ex_7.c"
#include "ex_8.c"

int main(int argc, char *argv[])
{
    int escolha;

    printf("Bem-vindo(a) ao sistema\n");
    printf("Tipos de exercícios:\n1-Ler N números e mostrar o maior entre eles\n"
           "2- Advinhador de números\n3- Números pares, ímpares positivos e negativos\n4-Jogo de azar\n5-vetor de n-1 elementos\n6-Matriz Identidade\n"
           "7-Palindromos\n8-Repetição de vogais\n\n");
    printf("Selecione qual opção de exercício você irá utilizar: ");
    scanf("%d",&escolha);

    printf("\n");

    switch (escolha)
    {
        case 1:maior_num();break;
        case 2:advinhador();break;
        case 3:num_par();break;
        case 4:jogo_azar();break;
        case 5:vetor();break;
        case 6:matriz_identidade();
        case 7:palindromo();break;
        case 8:conta_vogal();break;
    }

    return 0;
}