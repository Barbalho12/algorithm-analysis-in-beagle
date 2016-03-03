#include "quicksort.h"

QuickSort::QuickSort(){

}

//Algoritmos de ordenacao Quicksort ->>  https://pt.wikipedia.org/wiki/Quicksort
void QuickSort::quick(int *vetor, int esq, int dir){
    int pivo = esq, i, ch, j;
    for(i = esq+1; i <= dir; i++){
        j = i;
        if(vetor[j] < vetor[pivo]){
         ch = vetor[j];
         while(j > pivo){
            vetor[j] = vetor[j-1];
            j--;
         }
         vetor[j] = ch;
         pivo++;
        }
    }
    if(pivo-1 > esq){
        quick(vetor,esq,pivo-1);
    }
    if(pivo+1 < dir){
        quick(vetor,pivo+1,dir);
    }
}

void QuickSort::start(int *vetor, int tamanho){
    quick(vetor,0,tamanho-1);
}


