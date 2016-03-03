#include "bubblesort.h"

BubbleSort::BubbleSort(){

}

//Algoritmos de ordenacao bubble sort
void BubbleSort::start(int *vetor, int tamanho) {
    int aux;
    for (int i = 0; i < tamanho-1; i++) {
        for (int j = 0; j < tamanho-1; j++) {
            if (vetor[j] > vetor[j+1]) {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}
