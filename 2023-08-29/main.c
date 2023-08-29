#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int n = 5, m = 5;
    int mat1[n][m];
    int mat2[n][m];
    int soma[n][m];


    srand(time(NULL));

    for(int i = 0; i < n; i++){
        for(int j = 0;j < m; ++j){
            mat1[i][j] = 1 + rand() % 1000;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0;j < m; ++j){
            mat2[i][j] = 1 + rand() % 1000;
        }
    }

    return 0;
}
