set encoding iso_8859_1 
set grid 
set key top left 
set title 'Análise de desempenho com a função Clock' 
set xlabel 'Tamanho do vetor' 
set ylabel 'Tempo (segundos)' 
# BubbleSort 
plot 'clock_bubble.dat' using 1:2 notitle with linespoints ls 1 lt 8 
rep 'clock_bubble.dat' using 1:2:3:4 t 'BubbleSort' with yerrorbars ls 1 lt 8 
# QuickSort 
rep 'clock_quick.dat' using 1:2 notitle with linespoints ls 2 lt 6 
rep 'clock_quick.dat' using 1:2:3:4 t 'QuickSort' with yerrorbars ls 2 lt 6 
# Mergesort 
rep 'clock_merge.dat' using 1:2 notitle with linespoints ls 3 lt 5 
rep 'clock_merge.dat' using 1:2:3:4 t 'Mergesort' with yerrorbars ls 3 lt 5 
set terminal png 
set output 'grafico_clock.png' 
replot 


set encoding iso_8859_1 
set grid 
set key top left 
set title 'Análise de desempenho com a função Time'
set xlabel 'Tamanho do vetor' 
set ylabel 'Tempo (segundos)' 
# BubbleSort 
plot 'time_bubble.dat' using 1:2 notitle with linespoints ls 1 lt 8 
rep 'time_bubble.dat' using 1:2:3:4 t 'BubbleSort' with yerrorbars ls 1 lt 8 
# QuickSort 
rep 'time_quick.dat' using 1:2 notitle with linespoints ls 2 lt 6 
rep 'time_quick.dat' using 1:2:3:4 t 'QuickSort' with yerrorbars ls 2 lt 6 
# Mergesort 
rep 'time_merge.dat' using 1:2 notitle with linespoints ls 3 lt 5 
rep 'time_merge.dat' using 1:2:3:4 t 'Mergesort' with yerrorbars ls 3 lt 5 
set terminal png 
set output 'grafico_time.png' 
replot 

