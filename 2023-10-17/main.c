#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int imprimi(int *vetor, int tam)
{
    for(int i = 0; i < tam;i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
}

int nosso(int *vetor, int tam)
{
    for(int i = 0;i < tam;i++){
        int menor = vetor[i];
        int pos = i;
        for(int j = i + 1;j < tam; j++){
            if(menor > vetor[j]){
                menor = vetor[j];
                pos = j;
            }
        }
        int guarda = vetor[i];
        vetor[i] = menor;
        vetor[pos] = guarda;
    }
}

int bubble(int *vetor, int tam)
{

    for(int i = 0; i < tam; i++){
        for (int j = tam - 1; j > 0;j--){
            if(vetor[j] < vetor[j - 1]){
                int aux = vetor[j];
                vetor[j] = vetor[j - 1];
                vetor[ j - 1] = aux;
            }
        }
    }

}

int insert(int *vetor, int tam)
{

    for(int i = 0; i < tam; i++){
        int chave = vetor[i];
        int j = i - 1;
        while(j >= 0 && vetor[j] > chave){
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }

    return 1;
}

int selection(int *vetor,int tam)
{
    for(int i = 0; i < tam; i++){
        int min = i;
        for(int j = i+1; j < tam;j++){
            if(vetor[j] < vetor[min]){
                min = j;
            }
        }
        if(i != min){
            int aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
}




int main()
{
    int v[10] = {10,7,9,3,42,60,12,35,78,2};
    int menor,pos,guarda,n;
    int tam,num;

    printf("Digite o tamanho do vetor:");
    scanf("%d",&tam);

    int *vetor = (int*) calloc(tam,sizeof(int));

    srand(time(NULL));



//    ===================================== Nosso =====================================
    for(int j = 0; j < tam; j++){
        vetor[j] = rand() % 100;
    }

    printf("Nosso\n");

    imprimi(vetor,tam);
    nosso(vetor,tam);
    imprimi(vetor,tam);

// ===================================== Bublle =====================================
    for(int j = 0; j < tam; j++){
        vetor[j] = rand() % 100;
    }

    printf("Bubble\n");

    imprimi(vetor,tam);
    bubble(vetor,tam);
    imprimi(vetor,tam);

// ===================================== Insert Sort =====================================
    for(int j = 0; j < tam; j++){
        vetor[j] = rand() % 100;
    }

    printf("Insert\n");

    imprimi(vetor,tam);
    insert(vetor,tam);
    imprimi(vetor,tam);

//     ===================================== Selection Sort =====================================
    for(int j = 0; j < tam; j++){
        vetor[j] = rand() % 100;
    }

    printf("Selection\n");

    imprimi(vetor,tam);
    selection(vetor,tam);
    imprimi(vetor,tam);

    free(vetor);

    return 0;
}