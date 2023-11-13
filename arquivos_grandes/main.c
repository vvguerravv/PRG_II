#include <libprg/libprg.h>

FILE *abrir_arquivo(char *nome_arq)
{
    FILE *arq = fopen(nome_arq,"r");
    if(arq == NULL){
        perror("Não foi possível abrir o arquivo!!\n");
        exit(EXIT_FAILURE);
        }

        return arq;
}

int64_t tamananho_arq(char *nome_arq)
{
    FILE * arq = abrir_arquivo(nome_arq);
    fseek(arq,0,SEEK_END);
    int64_t tam = ftell(arq);
    fclose(arq);
    return tam;
}

int main(int argc, char *argv[])
{

    abrir_arquivo("/home/aluno/Downloads/arq.txt");
    long tam =tamananho_arq("/home/aluno/Downloads/arq.txt");

    long int tam_temp = tam/ 5;
    printf("%ld\n",tam);
    printf("%ld\n\n",tam_temp);

    int i = 0,total = 0;
    char file_name[L_tmpnam];
    long int num;
    FILE *arqu = abrir_arquivo("/home/aluno/Downloads/arq.txt");

    printf("%d\n",total);

    while(i < 5){
        FILE *arq;
        arq = fopen(tmpnam(file_name),"w");
        while(total < tam_temp){
            fscanf(arqu,"%ld",&num);
            total+=4;
            fprintf(arq,"%ld",num);
            long int teste;
            fscanf(arq,"%ld",&teste);
            printf("Teste: %ld ",teste);
        }

        fclose(arq);
        printf("%s\n",file_name);
        i++;
    }


    fclose(arqu);


//    FILE *arq = fopen("/home/aluno/Downloads/arq.txt","w");
//    srand(time(NULL));
//    int i = 0,num;
//    num = 50;
//    while(i < num){
//        int sorteado = rand() %INTMAX_MAX;
//        fprintf(arq,"%ld\n",sorteado);
//        i++;
//    }
//
//    fclose(arq);






//    int num = atoi(argv[1]);
//    int i = 0;
//    srand(time(NULL));
//
//
//    while(i < num){
//        int sorteado = rand() %INTMAX_MAX;
//        printf("%ld\n",sorteado);
//        i++;
//    }

    return 0;
}
