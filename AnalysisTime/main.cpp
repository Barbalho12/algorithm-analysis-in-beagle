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
#include <iostream>
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
 * Método para imprimir um vetor, útil para visualizar se está relmente ordenado.
 */
void imprimeVetor(string nomeVetor, int *vetor, int n){
    cout << nomeVetor << ":  ";
    for(int i = 0; i < n; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
}

void section(string title){
    cout << "------------" << title << "------------" << endl;
}

/**
 * Método principal.
 */
int main(int argc, char *argv[]){
    // Tamanho do vetor
    int size = 10;
    // Criar vetor com elementos aleatórios[0, 100000]
    criarVetor(size);

    section("Vetores Criados");

    //Exibe na tela os 3 vetores criados
    imprimeVetor("BubbleSort",vetorBubbleSort, size);
    imprimeVetor("QuickSort", vetorQuickSort, size);
    imprimeVetor("MergeSort", vetorMergeSort, size);


    section("BubbleSort");

    // Ordenar utilizando BubleSort
    BubbleSort bs = BubbleSort();
    time_t time_bubble;

    clock_t clock_bubble = clock();
    time(&time_bubble);

    bs.start(vetorBubbleSort,size);

    time_t time_bubble_end;
    clock_bubble = clock() - clock_bubble;
    time(&time_bubble_end);

    printf ("Start time: %s", ctime (&time_bubble));
    printf ("End time: %s", ctime (&time_bubble_end));
    printf ("It took me %d clicks (%f seconds).\n",
    clock_bubble, ((float)clock_bubble)/CLOCKS_PER_SEC);



    section("QuickSort");

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



    section("MergeSort");

    // Ordenar utilizando MergeSort
    MergeSort ms = MergeSort();
    time_t time_merge;
    clock_t clock_merge = clock();
    time(&time_merge);

    ms.start(vetorMergeSort, size);

    time_t time_merge_end;
    clock_merge = clock() - clock_merge;
    time(&time_merge_end);

    printf ("Start time: %s", ctime (&time_merge));
    printf ("End time: %s", ctime (&time_merge_end));
    printf ("It took me %d clicks (%f seconds).\n",
    clock_merge, ((float)clock_merge)/CLOCKS_PER_SEC);


    section("Resultado da Ordenação");

    //Exibe na tela os 3 vetores Ordenados
    imprimeVetor("QuickSort", vetorQuickSort, size);
    imprimeVetor("BubbleSort",vetorBubbleSort, size);
    imprimeVetor("MergeSort", vetorMergeSort, size);



    return 0;
}
