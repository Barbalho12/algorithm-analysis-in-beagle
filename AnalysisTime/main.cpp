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
#include <iostream>
#include <fstream>
#include <time.h>
#include "bubblesort.h"
#include "quicksort.h"
#include "mergesort.h"

// Algoritmos de busca a serem testados
const int BUBBLE_SORT = 1;
const int QUICK_SORT = 2;
const int MERGE_SORT = 3;

// Funções
const int TIME_FUNCTION = 1;
const int CLOCK_FUNCTION = 2;

// Números para completar o vetor
const int RAND_RANGE_MAX = 100000;

// Tamanhos do vetor
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
 * Inicializa os vetores e os preenche para que
 * sejam feitos os testes dos algoritmos de ordenação.
 */
void criarVetor(int tamanhoVetor, int semente) {
    srand(semente);

    // Inicializa os vetores
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
void imprimeVetor(string nomeVetor, int *vetor, int n) {
    cout << nomeVetor << ":  ";
    for(int i = 0; i < n; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
}

/**
 * Apaga os arquivos da execução anterior, caso existam.
 */
void clearFiles() {
    ofstream init;
    // Abre o arquivo
    init.open("time.dat", ios_base::in);
    // Verifica se o arquivo existe
    if (!init) {
        // Fecha o arquivo
        init.close();
        remove("time.dat");
    }
    // Abre o arquivo
    init.open("clock.dat", ios_base::in);
    // Verifica se o arquivo existe
    if (!init) {
        // Fecha o arquivo
        init.close();
        remove("clock.dat");
    }
}

// http://www.cplusplus.com/reference/fstream/ofstream/open/
/**
 * Sava o arquivo.
 */
void saveInFile(int sizeVetor, double pBubble, double pQuick, double pMerge, string path){
    ofstream out;
    out.open(path, ios::app);
    out << sizeVetor << " " << pBubble << " " << pQuick << " " << pMerge << endl;
    out.close();
}


/**
 * Calcula o tempo de ordenação com a função Clock.
 */
double ordenaVetorTime(int algorithm, int size){
    clock_t time_init;

    // Algoritmos de busca
    QuickSort qs = QuickSort();
    BubbleSort bs = BubbleSort();
    MergeSort ms = MergeSort();

    // Escolhe o algoritmo que deve ser testado
    switch (algorithm) {
        case QUICK_SORT:
            time_init = time();
            qs.start(vetorQuickSort, size);
            return time(NULL) - time_init;
        case BUBBLE_SORT:
            time_init = time();
            bs.start(vetorBubbleSort, size);
            return time(NULL) - time_init;
        case MERGE_SORT:
            time_init = time();
            ms.start(vetorMergeSort, size);
            return time(NULL) - time_init;
    }
    return -1;
}

/**
 * Calcula o tempo de ordenação com a função Clock.
 */
double ordenaVetorClock(int algorithm, int size) {
    clock_t clock_init;

    // Algoritmos de busca
    QuickSort qs = QuickSort();
    BubbleSort bs = BubbleSort();
    MergeSort ms = MergeSort();

    // Escolhe o algoritmo que deve ser testado
    switch (algorithm) {
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

/**
 * Calcula a média do vetor.
 */
double mediaVetor(int *vetor, int size){
    // Média
    double media = 0;
    // Verifica se o tamanho é válido, senão retorna -1
    if (size <= 0) {
        return -1;
    }
    // Calcula a média
    for (int i = 0; i < size; i++) {
        media += vetor[i];
    }
    return media/size;
}

/**
 * Verifiaca a performance dos algoritmos.
 */
void performanceAnalysis(int sizeVetor, int function){

    // 10 amostras para cada ponto
    int pontoBubble [10];
    int pontoQuick  [10];
    int pontoMerge  [10];

    // Executa em cada uma das sementes
    for(int i = 0; i < 10; i++){
        // Cria os 3 vetores, i é a semente
        criarVetor(sizeVetor, i);

        // Recebe a duração de cada ordenação, o tipo da função (Time ou Clock é especificado em function)
        double durationBubble;
        double durationQuick;
        double durationMerge;

        // Executa se for Time
        if (function == TIME_FUNCTION) {
            // Ordena e captura o tempo de retorno para cada algoritmo
            durationBubble = ordenaVetorTime(BUBBLE_SORT, sizeVetor);
            durationQuick = ordenaVetorTime(QUICK_SORT, sizeVetor);
            durationMerge = ordenaVetorTime(MERGE_SORT, sizeVetor);

        // Executa se for Clock
        } else if (function == CLOCK_FUNCTION) {
            // Ordena e captura o tempo de retorno para cada algoritmo
            durationBubble = ordenaVetorClock(BUBBLE_SORT, sizeVetor);
            durationQuick = ordenaVetorClock(QUICK_SORT, sizeVetor);
            durationMerge = ordenaVetorClock(MERGE_SORT, sizeVetor);
        }

        // Armazena para cada amostra de 10
        pontoBubble[i] = durationBubble;
        pontoQuick [i] = durationQuick;
        pontoMerge [i] = durationMerge;
    }

    // Calcula-se uma média aritimética das 10 amostras
    double pointBubbleSort = mediaVetor(pontoBubble, 10);
    double pointQuickSort = mediaVetor(pontoQuick, 10);
    double pointMergeSort = mediaVetor(pontoMerge, 10);

    // Testa qual é o tipo de function especificado para salvarno arquivo correto
    if (function == TIME_FUNCTION) {
        // Essa é a mesma sequencia em que será salva no arquivo
        saveInFile(sizeVetor, pointBubbleSort, pointQuickSort, pointMergeSort, "time.dat");
    } else if (function == CLOCK_FUNCTION) {
        // Converte em segundos: ((float)pointBubbleSort)/CLOCKS_PER_SEC
        double b = ((float)pointBubbleSort)/CLOCKS_PER_SEC;
        double q = ((float)pointQuickSort)/CLOCKS_PER_SEC;
        double m = ((float)pointMergeSort)/CLOCKS_PER_SEC;
        saveInFile(sizeVetor, b, q, m, "clock.dat");
    }

}

/**
 * Método principal.
 */
int main(int argc, char *argv[]) {
    // Apaga arquivos da execução anterior, caso existam
    clearFiles();
    clock_t clock_init; //pode apagar, serve só pra ter um feedback em quanto executa

    // Aumenta o tamanho do vetor para efetuar novos testes
    for (int i = SIZE_VETOR_INIT; i <= SIZE_VETOR_MAX; i += INCREASE_SIZE_VETOR) {
        // Feedback do processo
        clock_init = clock();

        // Executa em cada uma das funções separadamente
        performanceAnalysis(i,  TIME_FUNCTION);
        performanceAnalysis(i,  CLOCK_FUNCTION);

        // Feedback do processo
        cout << i <<"  -  " << clock() - clock_init << endl;
    }

    return 0;
}
