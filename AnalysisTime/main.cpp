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
//#include <ctime>
#include <time.h>
#include <iostream>
#include "bubblesort.h"
#include "quicksort.h"
#include "mergesort.h"
#include <fstream>

const int BUBBLE_SORT = 1;
const int QUICK_SORT = 2;
const int MERGE_SORT = 3;

const int TIME_FUNCTION = 1;
const int CLOCK_FUNCTION = 2;

const int RAND_RANGE_MAX = 100000;

const int SIZE_VETOR_INIT = 100;
const int SIZE_VETOR_MAX = 4000;
const int INCREASE_SIZE_VETOR = 100;


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
void criarVetor(int tamanhoVetor, int semente) {
    srand(semente);
    vetorQuickSort = new int[tamanhoVetor];
    vetorBubbleSort = new int[tamanhoVetor];
    vetorMergeSort = new int[tamanhoVetor];
    // Preenche os vetores
    for (int i = 0; i < tamanhoVetor; i++) {
        vetorQuickSort[i] =  rand() % RAND_RANGE_MAX;
        vetorBubbleSort[i] = rand() % RAND_RANGE_MAX;
        vetorMergeSort[i] = rand() % RAND_RANGE_MAX;
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


void clearFiles(){
    ofstream init;
    init.open("time.dat",ios_base::in);
    if(!init){
        init.close();
        remove("time.dat");
    }
    init.open("clock.dat",ios_base::in);
    if(!init){
        init.close();
        remove("clock.dat");
    }
}

//http://www.cplusplus.com/reference/fstream/ofstream/open/
void saveInFile(int sizeVetor, double pBubble, double pQuick, double pMerge, string path){
    ofstream out;
    out.open(path, ios::app);
    out << sizeVetor << " " << pBubble << " " << pQuick << " " << pMerge << endl;
    out.close();
}



//Calcula o tempo de ordenação com a função Clock
double ordenaVetorTime(int algorithm, int size){
    clock_t time_init;

    QuickSort qs = QuickSort();
    BubbleSort bs = BubbleSort();
    MergeSort ms = MergeSort();

    switch(algorithm){
        case QUICK_SORT:
            time_init = clock();
            qs.start(vetorQuickSort, size);
            return time(NULL) - time_init;
        case BUBBLE_SORT:
            time_init = clock();
            bs.start(vetorBubbleSort, size);
            return time(NULL) - time_init;
        case MERGE_SORT:
            time_init = clock();
            ms.start(vetorMergeSort, size);
            return time(NULL) - time_init;
    }
    return -1;
}

//Calcula o tempo de ordenação com a função Clock
double ordenaVetorClock(int algorithm, int size){
    clock_t clock_init;

    QuickSort qs = QuickSort();
    BubbleSort bs = BubbleSort();
    MergeSort ms = MergeSort();

    switch(algorithm){
        case QUICK_SORT:
            clock_init = clock();
            qs.start(vetorQuickSort, size);
            return clock() - clock_init;
        case BUBBLE_SORT:
            clock_init = clock();
            bs.start(vetorBubbleSort, size);
            return clock() - clock_init;
        case MERGE_SORT:
            clock_init = clock();
            ms.start(vetorMergeSort, size);
            return clock() - clock_init;
    }
    return -1;
}

double mediaVetor(int *vetor, int size){
    double media = 0;
    for(int i = 0; i < size; i++){
        media += vetor[i];
    }
    if(size > 0){
        return media/size;
    }
    return -1;
}


void performanceAnalysis(int sizeVetor, int function){

    //10 amostras para cada ponto
    int pontoBubble [10];
    int pontoQuick  [10];
    int pontoMerge  [10];

    //executa em cada uma das sementes
    for(int i = 0; i < 10; i++){

        //Cria os 3 vetores, i é semente
        criarVetor(sizeVetor, i);

        //Pega a duração de cada ordenação, o tipo da função (Time ou Clock é especificado em function)
        double durationBubble;
        double durationQuick;
        double durationMerge;

        //Executa se for Time,
        if(function == TIME_FUNCTION){
            //Ordena e captura o tempo de retorno para cada algoritmo
            durationBubble = ordenaVetorTime(BUBBLE_SORT, sizeVetor);
            durationQuick = ordenaVetorTime(QUICK_SORT, sizeVetor);
            durationMerge = ordenaVetorTime(MERGE_SORT, sizeVetor);

        //Executa se for Clock
        }else if(function == CLOCK_FUNCTION){
            //Ordena e captura o tempo de retorno para cada algoritmo
            durationBubble = ordenaVetorClock(BUBBLE_SORT, sizeVetor);
            durationQuick = ordenaVetorClock(QUICK_SORT, sizeVetor);
            durationMerge = ordenaVetorClock(MERGE_SORT, sizeVetor);
        }

        //Armazena para cada amostra de 10
        pontoBubble[i] = durationBubble;
        pontoQuick [i] = durationQuick;
        pontoMerge [i] = durationMerge;
    }

    //Calcula-se uma média aritimética das 10 amostras
    double pointBubbleSort = mediaVetor(pontoBubble, 10);
    double pointQuickSort = mediaVetor(pontoQuick, 10);
    double pointMergeSort = mediaVetor(pontoMerge, 10);

    //testa qual é o tipo de function especificado para salvarno arquivo correto
    if(function == TIME_FUNCTION){
        //essa é a mesma sequencia em que será salva no arquivo
        saveInFile(sizeVetor, pointBubbleSort, pointQuickSort, pointMergeSort, "time.dat");
    }else if(function == CLOCK_FUNCTION){
        //em segundos: ((float)pointBubbleSort)/CLOCKS_PER_SEC
        double b = ((float)pointBubbleSort)/CLOCKS_PER_SEC;
        double q = ((float)pointQuickSort)/CLOCKS_PER_SEC;
        double m = ((float)pointMergeSort)/CLOCKS_PER_SEC;
        saveInFile(sizeVetor, b, q, m, "clock.dat");
    }

}

/**
 * Método principal.
 */
int main(int argc, char *argv[]){
    clearFiles(); //serve para apagar algum arquivo que já exista de uma execução anterior
    clock_t clock_init; //pode apagar, serve só pra ter um feedback em quanto executa


    //vai crescendo o tamanho do vetor para novos testes
    for(int i = SIZE_VETOR_INIT; i <= SIZE_VETOR_MAX; i+=INCREASE_SIZE_VETOR){
        clock_init = clock();//feedback do processo (NÃO É IMPORTANTE)

        //Executa em cada uma das funções separadamente
        performanceAnalysis(i,  TIME_FUNCTION);
        performanceAnalysis(i,  CLOCK_FUNCTION);

        cout << i <<"  -  " << clock() - clock_init << endl;//feedback do processo (NÃO É IMPORTANTE)
    }

    return 0;
}
