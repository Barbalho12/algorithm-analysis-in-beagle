# beagleboneblack #

Projeto para analise de desempenho na execução de algoritmos de ordenação, Com informações comparativas (Gráficos) para execução em diferentes plataformas.

## Índice ##

## A BeagleBone ##

### Avisos ###

1. Não posicionar a BeagleBone em superfícies metálicas;
2. Desligar com o comando adequado ou usar os botões. NUNCA PUXAR
O CABO DE FORÇA OU O USB POWER;
3. GPIO são 3.3v tolerantes;
	3. Input: 4mA - 6mA
	3. Output: 8mA
4. ADC são 1.8v tolerantes;
5. Não modificar a senha de root do sistema (eMMC);
6. Desconecte todos os fios da placa ao fazer uma mudança na eletrônica.

## Utilizando o C++ na BeagleBone ##

## Gnuplot Tutorial ##

O gnuplot é um software que falicita a criação de gráficos (2D e 3D) para vários ambientes (UNIX, Windows, Macintosh, etc.). A seguir teremos alguns comandos básicos para a utilização desta ferramenta.

### Instalar: ###

	sudo apt-get install gnuplot-x11

### Gerando o gráfico ###

1. Acessa o diretório que contém os arquivos "clock.dat" e "time.dat" (que foram gerados pela execução dos métodos) e "grafico.gnu" (Script de execução do gnuplot) pelo terminal:
		
		cd data
	
2. Digita o omando no Terminal:

		gnuplot grafico.gnu

Os gráficos são gerados, e são criados duas imagens: "time.png" (gráfico da função Time) e "clock.png" (gráfico da função Clock). conforme as imagens a seguir

![Time](data/time.png?raw=true "Gráfico de Time")

![Clock](data/clock.png?raw=true "Gráfico de Clock")

### Fontes ###

[Usando Gnuplot para gerar bons gráficos](http://www.dicas-l.com.br/arquivo/usando_gnuplot_para_gerar_bons_graficos.php)
[Gnuplot - Manual simplificado para iniciantes](http://www.ebah.com.br/content/ABAAAgUS4AF/gnuplot-manual-simplificado-iniciantes?part=1)

## Resultados ##

### Resultados no computador ###

### Resultados na BeagleBone ###

## Conclusão ##

## Membros ##

* Breno Maurício de Freitas Viana
* Felipe Barbalho Rocha
