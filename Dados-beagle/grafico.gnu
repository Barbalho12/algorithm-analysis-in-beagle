set title 'Desempenho de Algoritmos de Ordenação usando Clock'; 
set key box right bottom outside title 'Algoritmos de Ordenação'; 
set xlabel 'Tamanho do Vetor'; set ylabel 'Tempo Decorrido (Segundos)'; 
plot "clock_bubble.dat" using 1:2 title "BubbleSort" with lines, "clock_quick.dat" using 1:2 title "QuickSort" with lines, "clock_merge.dat" using 1:2 title "MergeSort" with lines; 
set terminal png size 1000,680; 
set output 'clock.png'; 
replot

set title 'Desempenho de Algoritmos de Ordenação usando Time'; 
set key box right bottom outside title 'Algoritmos de Ordenação'; 
set xlabel 'Tamanho do Vetor'; set ylabel 'Tempo Decorrido (Segundos)'; 
plot "time_bubble.dat" using 1:2 title "BubbleSort" with lines, "time_quick.dat" using 1:2 title "QuickSort" with lines, "time_merge.dat" using 1:2 title "MergeSort" with lines; 
set terminal png size 1000,680; 
set output 'time.png'; 
replot