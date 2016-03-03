#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <cstdlib>
#include <cstdio>

class QuickSort{
public:
    QuickSort();
    void start(int *vetor, int tamanho);
private:
    void quick(int *vetor, int esq, int dir);
};

#endif // QUICKSORT_H
