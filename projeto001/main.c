#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"

int main(int argc, char *argv[])
{
    printf("Hello, World!\n");

    if(argc == 3){
        ler_arquivo(argv[1],argv[2]);

        for (int i = 0; i < 3; i++){
            printf("Argumento [%d]: %s\n",i,argv[i]);
       }
   }



    return 0;
}
