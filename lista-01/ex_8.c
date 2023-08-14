#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ex_8.h"

int conta_vogal()
{
    char frase[1000],minusculo;
    int i, vogais[5] = {0};
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

    return 0;
}