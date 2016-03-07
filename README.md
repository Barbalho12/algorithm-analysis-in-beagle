# Análise de algoritmos de ordenação na BeagleBone Black #

Este projeto tem como objetivo analisar o desempenho da execução de três algoritmos de ordenação são eles o BubbleSort, QuickSort e MergeSort. Com informações comparativas utilizando gráficos sobre a execução dos algoritmos na BeagleBone Black e em um outro computador.

## Índice ##

1. A BeagleBone Black
	1. Avisos
2. Conectando a BeagleBone
3. Requisitos para fazer a análise
4. Gnuplot Tutorial
	4. Instalar o gnuplot
	4. Gerando o gráfico
5. Executando no Computador
6. Executando na BeagleBone Black
	6. Computador
	6. BeagleBone Black
7. Resultados
	7. Resultados no computador (Processador Dual Core)
	7. Resultados no notebook (Processador i7)
	7. Resultados na BeagleBone
8. Conclusão
9. Membros
10. Fontes

##1. A BeagleBone Black ##

BeagleBoard (ou simplesmente Beagle) é um computador com uma única placa desenvolvido pela Texas Instruments. A Beagle é classificada como hardware livre sob a licença Creative Commons SharedAlike.

A BeagleBone Black (BBB) é uma das versões da BeagleBoard, esta versão possui 512 Mb de memória RAM, um processador Cortex-A8 com um clock de 1GHz e 4GB de memória flash, e ainda vem com o Debian GNU instalado de fábrica.

###i. Avisos ###

1. Não posicionar a BeagleBone em superfícies metálicas;
2. Ligar a beagle Bone: segurando o botão de "user" sem soltar até que os leds comecem a piscar, conecte o cabo usb, e espere que os leds fiquem piscando.

2. Desligar com o comando adequado ou usar os botões. NUNCA PUXAR O CABO DE FORÇA OU O USB POWER;
	sudo shutdown -h now
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
* Instale os seguintes pacotes para atualizar o C++.

		sudo apt-get install gcc-5-multilib g++-5-multilib

* [Baixe](http://goo.gl/q8zaor) e instale o SDK Texas Instruments e instale usando os comandos a seguir e avance todas as opções clicando em "Next".

		chmod +x nomedoarquivobaixado

		./nomedoarquivobaixado
		
##5. Gnuplot Tutorial ##

O gnuplot é um software que falicita a criação de gráficos (2D e 3D) para vários ambientes (UNIX, Windows, Macintosh, etc.). A seguir teremos alguns comandos básicos para a utilização desta ferramenta.

###i. Instalar o gnuplot ###

	sudo apt-get install gnuplot-x11

###ii. Gerando o gráfico ###

1. Acessa o diretório que contém os arquivos "clock.dat" e "time.dat" (que foram gerados pela execução dos métodos) e "grafico.gnu" (Script de execução do gnuplot) pelo terminal:

	cd data

2. Digita o omando no Terminal:

	gnuplot grafico.gnu

Para criar os gráficos basta executar o gnuplot utilizando o script gnuplot deste projeto.

	gnuplot performance.gnuplot
	
##4.Executando no Computador##

Na raiz do projeto entre no diretório "dist-64bits" ou "dist-32bits" Conforme seu sistema operacional e execute o programa:
	
	cd dist-64bits
	
	./AnalysisTime

O resultado da execução estará no diretório criado pelo programa "dados-coletados" junto com os gráficos e scripts do gnuplot para personalização

##4.Executando na BeagleBone Black ##

É possível programar e compilar no seu computador e enviar o executável para a BeagleBone. Para fazer os testes deste projeto basta clonar esse projeto e executar os comandos.

###i. Computador ###

Entre na pasta de código fonte "AnalysisTime" abra o arquivo "compila.sh" e veja se o diretório "source" é de fato o endereço do "SDK Texas Instruments" instalado conforme foi especificado em seções anteriores. Exemplo:

	source /opt/ti-processor-sdk-linux-am335x-evm-02.00.01.07/linux-devkit/environment-setup
	
Verifique se o nome do executável é o mesmo especificado no "AnalysisTime.pro" como a seguir:

	sshpass -p 'temppwd' scp AnalysisTime debian@192.168.7.2:~
	
Agora acesse a BeagleBone por ssh (mais informações podem ser visualisadas em seções anteriores):

	ssh debian@192.168.7.2

###ii. BeagleBone Black ###

já conectado a Beagle (é preferivel ter o gnuplot instalado na beagle para facilitar o processo, isso pode ser feito na seção de instação do gnuplot) execute o programa:

	./AnalysisTime
	
Após a execução, é criado um diretório "dados-coletados" com arquivos contendo as informações a serem plotadas em gráfico. e se o gnuplot já foi instalado antes, já se tem as imagens com gráficos. Volte ao seu pc:

	exit

###i. Computador ###

Na raiz do projeto execute o script "get-results-beagle-scp.sh", coloque a senha conforme solicitar, se não houver permissão forneça com:

	chmod +x get-results-beagle-scp.sh
	./get-results-beagle-scp.sh
	
Após isso os dados da beagle pode ser analisado no diretório "Dados-beagle", se não houver imagens com os gráficos, gere com:

	gnuplot performance.gnuplot

##6. Resultados ##

Nessa seção, temos os resultados dos testes dos algoritmos BubbleSort, QuickSort e MergeSort.

###i. Resultados no computador (Processador Pentium) ###

Configurações:
- Intel Pentium 3GHz x2
- 2 Gb de memória RAM
- 64 bits
- Ubuntu

O programa executou sozinho no computador.

![Time](Dados-pc/grafico_time.png?raw=true "Gráfico de Time")

![Clock](Dados-pc/grafico_clock.png?raw=true "Gráfico de Clock")

###ii. Resultados no notebook (Processador i7) ###

Configurações:
- Intel Core i7 2.40GHz x8
- 8 Gb de memória RAM
- 64 bits
- Ubuntu

O programa foi executado paralelamente com outros programas (Spotify, Chrome, Atom, Gerenciador de Arquivos e o Visualizador de PDF).

![Time](Dados-pc-i7/grafico_time.png?raw=true "Gráfico de Time")

![Clock](Dados-pc-i7/grafico_clock.png?raw=true "Gráfico de Clock")

###iii. Resultados na BeagleBone ###

O programa executou sozinho no computador.

![Time](Dados-beagle/grafico_time.png?raw=true "Gráfico de Time")

![Clock](Dados-beagle/grafico_clock.png?raw=true "Gráfico de Clock")

##7. Conclusão ##

Concluímos assim que a arquitetura do hardware influência muito no desempenho, pudemos perceber isso pelos gráficos mostrados nos resultados da análise. 

Percebemos que há uma grande diferença nos gráficos entre a execução nos computadores e a BeagleBone, mas há semelhanças em relação ao crescimento dos gráficos, estas correspondem a complexidade dos algoritmos.

Depois desses testes como podemos responder qual a função que realiza melhor análise de desempenho dos algoritmos de ordenação? 

Como podemos notar a função Clock permite uma análise mais detahadas dos dados, visto a ordem pequena que uma unidade de clock representa, porém, quando analismaos os dados com mais precisão, podemos atingir facilmente o limite representativo da unidade numérica, e a consequência disso é a ocorrencia de Overflow procando uma incoerência nos dados finais. Já a função Time é muito útil para representar grandes valores, já que sua unidade representativa são em segundos, dessa forma ela analisaria de forma "magnífica" a execução de algoritmos com anos de duração, porém, apesar de existir um limite de crescimento assim como a função Clock, o grande problema da função Time é na analise de desempenho de algoritmos em curtos intervalos de tempo, pois não é possivel mensurar grandesas como millisegundos ou nanosegundos. 

Portanto, a melhor resposta para a pergunta acima depende do que será analisado: algoritmos que duram um nanosegundo, ou complexos algoritmos de ordenação executado em vetores com mais de 100.000 elementos. A função Clock é a mais útil para analises precisas, porém não se aplicada em análises de grande intervalo de tempo, e a função Time é mais útil em algoritmos muito complexos e de execução demorada, porém é bem menos precisa que a função Clock.    

##8. Membros ##

* Breno Maurício de Freitas Viana
* Felipe Barbalho Rocha

##9. Fontes ##

* BubbleSort - Disponibilizado pelo professor Ivanovitch
* [QuickSort](https://pt.wikipedia.org/wiki/Quicksort)
* [MergerSort](https://pt.wikipedia.org/wiki/Merge_sort)
* [BeagleBoard](https://pt.wikipedia.org/wiki/BeagleBoard)
* [Usando Gnuplot para gerar bons gráficos](http://www.dicas-l.com.br/arquivo/usando_gnuplot_para_gerar_bons_graficos.php)
* [Gnuplot - Manual simplificado para iniciantes](http://www.ebah.com.br/content/ABAAAgUS4AF/gnuplot-manual-simplificado-iniciantes?part=1)

