#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vetor;
    int tamanho=5;
    vetor=(int*)malloc(tamanho *sizeof(int));
    if (vetor == NULL){
        printf("Erro de alocação de memória\n");
        return 1;
    }
    for (int i=0;i<tamanho;i++){
        vetor[i]=i*2;
        printf("%d",vetor[i]);
    }
    free(vetor);//Liberando a memória alocada
    return 0;
}