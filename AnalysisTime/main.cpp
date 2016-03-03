/*
 * Universidade Federal do Rio Grande do Norte
 * Instituto Metrópole Digital
 *
 * copyright: Ivanovitch Silva
 * e-mail: ivan@imd.ufrn.br
 *
 * Tópico: manipulação de tempo em c++
 * Programa: calcular o tempo de execução dos algoritmos
 */

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "bubblesort.h"
#include "quicksort.h"
#include "mergesort.h"

using namespace std;

// Vetores usados pelos metodos de ordenacao
int *vetorQuickSort;
int *vetorBubbleSort;
int *vetorMergeSort;
int tamanho;

/**
 * Observe que os números sao gerados aleatórios baseados
 * em uma semente. Se for passado a mesma semente, os
 * números aleatórios serão os mesmos.
 */
void criarVetor(int tamanhoVetor) {
  srand(time(NULL));
  vetorQuickSort = new int[tamanhoVetor];
  vetorBubbleSort = new int[tamanhoVetor];
  vetorMergeSort = new int[tamanhoVetor];
  // Preenche os vetores
  for (int i = 0; i < tamanhoVetor; i++) {
    vetorQuickSort[i] =  rand() % 100000;
    vetorBubbleSort[i] = rand() % 100000;
    vetorMergeSort[i] = rand() % 100000;
  }
}

/**
 * Método principal.
 */
int main(int argc, char *argv[]){
  // Tamanho do vetor
  int size = 10;
  // Criar vetor com elementos aleatórios[0, 100000]
  criarVetor(size);

  std::cout << vetorQuickSort << std::endl;
  std::cout << vetorBubbleSort << std::endl;
  std::cout << vetorMergeSort << std::endl;

  // Ordenar utilizando BubleSort
  BubbleSort bs = BubbleSort();
  time_t time_buble;
  clock_t clock_buble = clock();
  time(&time_buble);
  bs.start(vetorBubbleSort,size);
  time_t time_buble_end;
  clock_buble = clock() - clock_buble;
  time(&time_buble_end);
  printf ("Start time: %s", ctime (&time_buble));
  printf ("End time: %s", ctime (&time_buble_end));
  printf ("It took me %d clicks (%f seconds).\n",
  clock_buble, ((float)clock_buble)/CLOCKS_PER_SEC);

  // Ordenar utilizando QuickSort
  QuickSort qs = QuickSort();
  time_t time_quick;
  clock_t clock_quick = clock();
  time(&time_quick);
  qs.start(vetorQuickSort, size);
  time_t time_quick_end;
  clock_quick = clock() - clock_quick;
  time(&time_quick_end);
  printf ("Start time: %s", ctime (&time_quick));
  printf ("End time: %s", ctime (&time_quick_end));
  printf ("It took me %d clicks (%f seconds).\n",
  clock_quick, ((float)clock_quick)/CLOCKS_PER_SEC);

  // Ordenar utilizando MergeSort
  MergeSort ms = MergeSort();
  time_t time_merge;
  clock_t clock_merge = clock();
  time(&time_merge) = clock();
  ms.start(vetorMergeSort, size);
  clock_merge = clock() - clock_merge;
  time(&time_merge_end);
  printf ("Start time: %s", ctime (&time_merge));
  printf ("End time: %s", ctime (&time_merge_end));
  printf ("It took me %d clicks (%f seconds).\n",
  clock_merge, ((float)clock_merge)/CLOCKS_PER_SEC);
  return 0;
}
