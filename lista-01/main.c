#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int escolha, num_1, maior = 0,num_2, sorteado;


    srand(time(NULL));

    printf("Bem-vindo(a) ao sistema\n");
    printf("Tipos de exercícios:\n1-Ler N números e mostrar o maior entre eles\n"
           "2- Advinhador de números\n3- Números pares, ímpares positivos e negativos\n4-Jogo de azar\n5-vetor\n6-Matriz Identidade\n"
           "7-Palindromos\n8-Repetição de vogais\n\n");
    printf("Selecione qual opção de exercício você irá utilizar: ");
    scanf("%d",&escolha);

    printf("\n");

    switch (escolha)
    {
        case 1:
            printf("Entre com os números desejados: ");
            for (;num_1 != 0;){
                scanf("%d",&num_1);
                if(num_1>maior){
                    maior = num_1;
                }
            }
            printf("O maior número é o %d\n", maior);
            break;

        case 2:
            sorteado = 1 + rand() %10;
            printf("Escolha um número de 1 a 10: ");
            scanf("%d",&num_2);
            if(sorteado == num_2){
                printf("Parabéns você acertou\n");
            } else{
                printf("Tente outra vez!\n");
            }
            break;
        case 3: printf("Não implementado\n"); break;
        case 4: printf("Não implementado\n"); break;
        case 5: printf("Não implementado\n"); break;
        case 6: printf("Não implementado\n"); break;
        case 7: printf("Não implementado\n"); break;
        case 8: printf("Não implementado\n"); break;
    }

    return 0;
}