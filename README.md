# Análise de algoritmos de ordenação na BeagleBone Black #

Este projeto tem como objetivo analisar o desempenho da execução de três algoritmos de ordenação são eles o BubbleSort, QuickSort e MergeSort. Com informações comparativas utilizando gráficos sobre a execução dos algoritmos na BeagleBone Black e em um outro computador.

## Índice ##

1. A BeagleBone Black
	1. Avisos
2. Conectando a BeagleBone
3. Requisitos para fazer a análise
4. Programando para a BeagleBone Black
	4. Computador
	4. BeagleBone Black
5. Gnuplot Tutorial
	5. Instalar o gnuplot
	5. Gerando o gráfico
6. Resultados
	6. Resultados no computador
	6. Resultados na BeagleBone
7. Conclusão
8. Membros
9. Fontes

##1. A BeagleBone Black ##

BeagleBoard (ou simplesmente Beagle) é um computador com uma única placa desenvolvido pela Texas Instruments. A Beagle é classificada como hardware livre sob a licença Creative Commons SharedAlike.

A BeagleBone Black (BBB) é uma das versões da BeagleBoard, esta versão possui 512 Mb de memória RAM, um processador Cortex-A8 com um clock de 1GHz e 4GB de memória flash, e ainda vem com o Debian GNU instalado de fábrica.

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

Informação retirada do slide do professor Ivanovitch.

##2. Conectando com a BeagleBone Black ##

Para se conectar à BeagleBone Black é necessário conectar o cabo USB no computador e depois enviar o comando shh a seguir:

	shh debian@192.168.7.2

Assim, é necessário fazer o login na BeagleBone Black.

	A senha é: temppwd

Agora já é possível acessar a BeagleBone.

##3. Requisitos para fazer a análise ##

* Use um computador com alguma distribuição Linux (Indicamos o Ubuntu).
* Instale os seguintes pacotes para atualizar o C++
	sudo apt-get install gcc-5-multilib g++-5-multilib
* [Baixe](http://goo.gl/q8zaor) e instale o SDK Texas Instruments e instale usando os comandos a seguir e avance todas as opções clicando em "Next".
	chmod +x nomedoarquivobaixado
	./nomedoarquivobaixado

##4. Programando para a BeagleBone Black ##

É possível programar e compilar no seu computador e enviar o executável para a BeagleBone. Para fazer os testes deste projeto basta clonar esse projeto e executar os comandos.

###i. Computador ###

Compile com:

	make

E em seguida execute com:

	./analisys_time

###ii. BeagleBone Black ###

Basta executar o script:

	connect.sh

##5. Gnuplot Tutorial ##

O gnuplot é um software que falicita a criação de gráficos (2D e 3D) para vários ambientes (UNIX, Windows, Macintosh, etc.). A seguir teremos alguns comandos básicos para a utilização desta ferramenta.

###i. Instalar o gnuplot ###

	sudo apt-get install gnuplot-x11

###ii. Gerando o gráfico ###

1. Acessa o diretório que contém os arquivos "clock.dat" e "time.dat" (que foram gerados pela execução dos métodos) e "grafico.gnu" (Script de execução do gnuplot) pelo terminal:

		cd data

2. Digita o omando no Terminal:

		gnuplot grafico.gnu

A seguir um exemplo de gráfico gerado utilizando o gnuplot:

Para criar os gráficos basta executar o gnuplot utilizando o script gnuplot deste projeto.

	gnuplot performance.gnuplot

##6. Resultados ##

Nessa seção, temos os resultados dos testes dos algoritmos BubbleSort, QuickSort e MergeSort.

###i. Resultados no computador ###

A seguir o gráfico da função Time e da função Clock para os algortimos de ordenação:

BubbleSort:

QuickSort:

MergeSort:

![Time](data/time.png?raw=true "Gráfico de Time")

![Clock](data/clock.png?raw=true "Gráfico de Clock")

###ii. Resultados na BeagleBone ###

BubbleSort:

QuickSort:

MergeSort:

##7. Conclusão ##

Concluímos assim que a arquitetura do hardware influência muito no desempenho pudemos perceber isso pelos gráficos mostrados nos resultados da análise.

##8. Membros ##

* Breno Maurício de Freitas Viana
* Felipe Barbalho Rocha

##9. Fontes ##

* [BeagleBoard](https://pt.wikipedia.org/wiki/BeagleBoard)
* [Usando Gnuplot para gerar bons gráficos](http://www.dicas-l.com.br/arquivo/usando_gnuplot_para_gerar_bons_graficos.php)
* [Gnuplot - Manual simplificado para iniciantes](http://www.ebah.com.br/content/ABAAAgUS4AF/gnuplot-manual-simplificado-iniciantes?part=1)

