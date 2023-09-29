#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define NUM 101
int main()
{
    int N, M, P;
    scanf("%d %d %d", &N, &M, &P);

    char *palavras[NUM] = {};
    char matriz[M + 1][P + 1];

    char aux[1000];

    for(int i = 0; i < N; i++){
        scanf("%s", &aux);
        palavras[i] = aux;
    }

    for(int i = 0; i < M; i++){
        scanf("%s", &aux);
        for(int j = 0; j < P; j++){
            matriz[i][j] = aux[j];
        }
    }



    //printf("Hello world!\n");
    return 0;
}
