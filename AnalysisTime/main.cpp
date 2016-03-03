/*
 * Universidade Federal do Rio Grande do Norte
 * Instituto Metropole Digital
 *
 * copyright: Ivanovitch Silva
 * e-mail: ivan@imd.ufrn.br
 *
 * Tópico: manipulação de tempo em c++
 * Programa: calcular o tempo de execução dos algoritmos
 */

#include <cstdlib>
#include <cstdio>
#include <time.h>
#include "bubblesort.h"
#include "quicksort.h"
#include "mergesort.h"

using namespace std;

//Vetores usados pelos metodos de ordenacao
int *vetorQuickSort;
int *vetorBubbleSort;
int *vetorMergeSort;
int tamanho;


//Observe que os numeros sao gerados aleatorios baseados
//em uma semente. Se for passado a mesma semente, os
//numeros aleatarios serao os mesmos
void criarVetor(int tamanhoVetor, int semente){
  srand (semente);
  vetorQuickSort = new int[tamanhoVetor];
  vetorBubbleSort = new int[tamanhoVetor];
  vetorMergeSort = new int[tamanhoVetor];
  for (int i=0;i<tamanhoVetor;i++){
    vetorQuickSort[i] =  rand()%100000;
    vetorBubbleSort[i] = rand()%100000;
    vetorMergeSort[i] = rand()%100000;
  }
}


int main(int argc, char *argv[]){
  //Tamanho do vetor
  int n = 10;
  //Criar vetor com elementos aleatorios[0,100000]
  criarVetor(n,23);

  //Ordenar utilizando bubleSort
  BubbleSort bs = BubbleSort();
  bs.start(vetorBubbleSort,n);

  //Ordenar utilizando quickSort
  QuickSort qs = QuickSort();
  qs.start(vetorQuickSort, n);

  //Ordenar utilizando mergeSort
  MergeSort ms = MergeSort();
  ms.start(vetorMergeSort, n);
  return 0;
}
