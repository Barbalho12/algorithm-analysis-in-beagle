#ifndef MERGESORT_H
#define MERGESORT_H

#include <cstdlib>
#include <cstdio>

class MergeSort{
public:
    MergeSort();
    void start(int *vetor, int tamanho);

private:
    void merge_sort(int *vetor, int posicaoInicio, int posicaoFim);

};

#endif // MERGESORT_H
