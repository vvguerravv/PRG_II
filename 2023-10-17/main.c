#include <stdio.h>




int main()
{
    int v[10] = {10,7,9,3,42,60,12,35,78,2};
    int k[5] = {10,7,9,3,42};
    int menor,pos,guarda,n;

//    for(int i = 0; i < 10; i++){
//        printf("%d ",v[i]);
//    }
//
//    printf("\n");
//
//    for(int i = 0;i < 10;i++){
//       menor = v[i];
//       pos = i;
//       for(int j = i + 1;j < 10; j++){
//           if(menor > v[j]){
//               menor = v[j];
//               pos = j;
//           }
//       }
//       guarda = v[i];
//       v[i] = menor;
//       v[pos] = guarda;
//    }
//    for(int i = 0; i < 10; i++){
//        printf("%d ",v[i]);
//    }

    for(int i = 0; i < 5; i++){
        printf("%d ",k[i]);
    }

    for(int i = 0; i < 5; i++){
        for (int j = 0; j < 5 - i;j++){
            if(k[j] < k[j + 1]){
                int aux = k[j];
                k[j] = k[j + 1];
                k[ j + 1] = aux;
            }
        }
    }
    printf("\n");
    for(int i = 0; i < 5; i++){
        printf("%d ",k[i]);
    }

    return 0;
}