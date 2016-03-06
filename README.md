# Análise de algoritmos de ordenação na BeagleBone Black #

Este projeto tem como objetivo analisar o desempenho da execução de três algoritmos de ordenação. Com informações comparativas (Gráficos) para execução na BeagleBone Black e em um outro computador.

## Índice ##

1. A BeagleBone Black
	1. Avisos
2. Conectando a BeagleBone
3.
4.

##1. A BeagleBone Black ##

BeagleBoard (ou simplesmente Beagle) é um computador com uma única placa desenvolvido pela Texas Instruments. A Beagle é classificada como hardware livre sob a licença Creative Commons SharedAlike.

A BeagleBone Black (BBB) é uma das versões da BeagleBoard, esta versão possui 512 Mb de memória RAM, um processador <> com um clock de 1GHz e 4GB de memória flash, e ainda vem com o Debian GNU instalado de fábrica.

###i. Avisos ###

1. Não posicionar a BeagleBone em superfícies metálicas;
2. Desligar com o comando adequado ou usar os botões. NUNCA PUXAR
O CABO DE FORÇA OU O USB POWER;
3. GPIO são 3.3v tolerantes;
	3. Input: 4mA - 6mA
	3. Output: 8mA
4. ADC são 1.8v tolerantes;
5. Não modificar a senha de root do sistema (eMMC);
6. Desconecte todos os fios da placa ao fazer uma mudança na eletrônica.

##2. Conectando com a BeagleBone Black ##

Para se conectar à BeagleBone Black é necessário conectar o cabo USB no computador e depois enviar o comando shh a seguir:

	shh debian@192.168.7.2

Assim, é necessário fazer o login na BeagleBone Black

	A senha é: temppwd

Agora já é possível acessar a BeagleBone.

##3. Utilizando o C++ na BeagleBone ##

É possível programar no seu conputador e enviar o executável para a BeagleBone.

## Gnuplot Tutorial ##

O gnuplot é um software que falicita a criação de gráficos (2D e 3D) para vários ambientes (UNIX, Windows, Macintosh, etc.). A seguir teremos alguns comandos básicos para a utilização desta ferramenta.

### Instalar: ###

	sudo apt-get install gnuplot-x11

### Gerando o gráfico ###

1. Acessa o diretório que contém os arquivos "clock.dat" e "time.dat" (que foram gerados pela execução dos métodos) e "grafico.gnu" (Script de execução do gnuplot) pelo terminal:
		
		cd data
	
2. Digita o omando no Terminal:

		gnuplot grafico.gnu

A seguir um exemplo de gráfico gerado utilizando o gnuplot

### Fontes ###

* [BeagleBoard](https://pt.wikipedia.org/wiki/BeagleBoard)
* [Usando Gnuplot para gerar bons gráficos](http://www.dicas-l.com.br/arquivo/usando_gnuplot_para_gerar_bons_graficos.php)
* [Gnuplot - Manual simplificado para iniciantes](http://www.ebah.com.br/content/ABAAAgUS4AF/gnuplot-manual-simplificado-iniciantes?part=1)

## Resultados ##

### Resultados no computador ###

A seguir o gráfico da função Time e da função Clock para os algortimos de ordenação:

![Time](data/time.png?raw=true "Gráfico de Time")

![Clock](data/clock.png?raw=true "Gráfico de Clock")

### Resultados na BeagleBone ###

## Conclusão ##

## Membros ##

* Breno Maurício de Freitas Viana
* Felipe Barbalho Rocha
