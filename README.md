# beagleboneblack #

Projeto para analise de desempenho na execução de algoritmos de ordenação, Com informações comparativas (Gráficos) para execução em diferentes plataformas.

This project have like objective performance analysis in the execution of sorting algorithms, using comparative informational (Charts) to run in a normal PC and in the BeagleBone.

## Summary ##

## The BeagleBone ##

## Gnuplot Tutorial ##

http://www.dicas-l.com.br/arquivo/usando_gnuplot_para_gerar_bons_graficos.php


Instalar:

	sudo apt-get install gnuplot-x11


Gera as 3 linhas:

	1. Acessa o diretório que contém os arquivos "clock.dat" e "clock.dat" (que foram gerados pela execução dos métodos)]

	2. Comando: 

		plot "clock.dat" using 1:2 title "BubbleSort" with lines, "clock.dat" using 1:3 title "QuickSort" with lines, "clock.dat" using 1:4 title "MergeSort" with lines

		plot "time.dat" using 1:2 title "BubbleSort" with lines, "time.dat" using 1:3 title "QuickSort" with lines, "time.dat" using 1:4 title "MergeSort" with lines

salva em imagem:

	set terminal png
	set output 'imagem.png'
	replot

## ##

## ##

## Members ##

* Breno Maurício de Freitas Viana
* Felipe Barbalho Rocha
