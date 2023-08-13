#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int escolha, num_1 = 1, maior = 0,num_2, sorteado;
    int i,j,num_3, par = 0, impar = 0, positivo = 0, negativo = 0;
    int palpite_do_jogador,num_palpitesm, palpites_possiveis[100] = {0};
    int tamanho_vetor,vetor[100],matriz[10][10] = {0},faltante = 0;
    char palavra[100],inverso[100];
    char frase[1000],minusculo;
    int vogais[5] = {0};

    srand(time(NULL));

    printf("Bem-vindo(a) ao sistema\n");
    printf("Tipos de exercícios:\n1-Ler N números e mostrar o maior entre eles\n"
           "2- Advinhador de números\n3- Números pares, ímpares positivos e negativos\n4-Jogo de azar\n5-vetor de n-1 elementos\n6-Matriz Identidade\n"
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
        case 3:
            printf("Entre com 10 números inteiros positivos:\n");
            for(i=0;i<10;i++){
                scanf("%d",&num_3);
                if(num_3 % 2 == 0){
                    par++;
                } if(num_3 % 2 != 0){
                    impar++;
                } if(num_3 < 0){
                    negativo++;
                } if(num_3 > 0){
                    positivo++;
                }
            }
            printf("Dos 10, %d número(s) é(são) par(es), %d número(s) é(são) impar(es), %d número(s) é(são) positivo(s) e %d número(s) é(são) negativo(s)\n",
                   par, impar, positivo, negativo);
            break;
        case 4:
            sorteado = 1 + rand() %100;
            printf("Advinhe um número de 1 a 100\n");
            for(;palpite_do_jogador != sorteado;){
                printf("Escolha um número: ");
                scanf("%d",&palpite_do_jogador);

                if(palpite_do_jogador < 1 || palpite_do_jogador > 100){
                    printf("Escolha um número de 1 a 100\n");
                }

                if(palpites_possiveis[palpite_do_jogador - 1] != 0){
                    printf("Você já escolheu %d vez(es) o número %d. Escolha outra número.\n", palpites_possiveis[palpite_do_jogador - 1], palpite_do_jogador);
                }

                palpites_possiveis[palpite_do_jogador - 1]++;

                if(palpite_do_jogador == sorteado){
                    printf("Parabéns, você acertou!\n");
                } else{
                    printf("Tente novamente!\n");
                }
            }
            break;
        case 5:
            printf("Escolha o tamanho do vetor(Será o valor escolhido - 1): ");
            scanf("%d", &tamanho_vetor);
            printf("Escolha os valores de 1 até N com um número faltante no vetor: ");
            for (int i = 1; i < tamanho_vetor; i++) {
                scanf("%d", &vetor[i]);
            }

            for (int i = 0; i < tamanho_vetor - 1; i++) {
                if (vetor[i] + 1 != vetor[i + 1]) {
                    faltante = vetor[i] + 1;

                }
            }
            printf("O número que está faltando é o %d\n", faltante);
            break;
        case 6:
            for (int i = 0; i < 10; i++) {
                matriz[i][i] = 1;
            }
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    printf("%d ", matriz[i][j]);
                }
                printf("\n");
            }

            break;
        case 7:
            printf("Digite a palavra ou frase:");
            scanf("%s",palavra);
            j = 1;
            for(i = 0; i < strlen(palavra);i++){
                inverso[i] = palavra[strlen(palavra) - j];
                j++;
            }
            if(strcmp(palavra,inverso) == 0){
                printf("'%s' é uma palavra palindroma.\n", palavra);
            } else{
                printf("'%s' não é uma palavra palindroma.\n",palavra);
            }
            break;
        case 8:
            printf("Digite sua frase:");
            scanf(" %[^\n]s",frase);
            for(i = 0;i < strlen(frase);i++){
                minusculo = tolower(frase[i]);
                switch(minusculo){
                    case 'a':
                        vogais[0]++;
                        break;
                    case 'e':
                        vogais[1]++;
                        break;
                    case 'i':
                        vogais[2]++;
                        break;
                    case 'o':
                        vogais[3]++;
                        break;
                    case 'u':
                        vogais[4]++;
                        break;
                }
            }
            printf("A vogal \"A\" aparece %d vezes\n",vogais[0]);
            printf("A vogal \"E\" aparece %d vezes\n",vogais[1]);
            printf("A vogal \"I\" aparece %d vezes\n",vogais[2]);
            printf("A vogal \"O\" aparece %d vezes\n",vogais[3]);
            printf("A vogal \"U\" aparece %d vezes\n",vogais[4]);

            break;
    }

    return 0;
}