# Analysis of sorting algorithms in BeagleBone Black

This project aims to analyze the execution performance of three sorting algorithms are BubbleSort, QuickSort and MergeSort. With comparative information using graphs on running the algorithms on BeagleBone Black and on another computer.

# Menu

1. The BeagleBone Black
>	* Warnings
2. Connecting to BeagleBone
3. Requirements for doing the analysis
4. Gnuplot Tutorial
>	* Install gnuplot
>	* Generating the statistical graph
5. Running on the Computer
6. Running on BeagleBone Black
> 	* Before (Computer)
> 	* Running (BeagleBone Black)
> 	* After (Computer)
7. Results
>	* Computer 1 (Pentium Dual Core Processor)
>	* Computer 2 (i7 Octa Core Processor)
>	* BeagleBone Black (Single Core)
8. Conclusion
9. Members
10. References

## 1. The BeagleBone Black

BeagleBoard (or simply Beagle) is a single board computer developed by Texas Instruments. The Beagle is classified as free hardware under the **Creative Commons SharedAlike** license.

The BeagleBone Black (BBB) is one of the BeagleBoard versions, this version has 512 Mb of RAM, a Cortex-A8 processor with a clock of 1GHz and 4GB of flash memory, and still comes with Debian GNU installed at the factory.

### i. Avisos 

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

## 2. Connecting to BeagleBone

Para se conectar à BeagleBone Black é necessário conectar o cabo USB no computador e depois enviar o comando shh a seguir:

	shh debian@192.168.7.2

Assim, é necessário fazer o login na BeagleBone Black.

	A senha é: temppwd

Agora já é possível acessar a BeagleBone.

## 3. Requirements for doing the analysis

* Use um computador com alguma distribuição Linux (Indicamos o Ubuntu).
* Instale os seguintes pacotes para atualizar o C++.

		sudo apt-get install gcc-5-multilib g++-5-multilib

* [Baixe](http://goo.gl/q8zaor) e instale o SDK Texas Instruments e instale usando os comandos a seguir e avance todas as opções clicando em "Next".

		chmod +x nomedoarquivobaixado

		./nomedoarquivobaixado
		
## 5. Gnuplot Tutorial

O gnuplot é um software que falicita a criação de gráficos (2D e 3D) para vários ambientes (UNIX, Windows, Macintosh, etc.). A seguir teremos alguns comandos básicos para a utilização desta ferramenta.

### i. Install gnuplot

	sudo apt-get install gnuplot-x11

### ii. Generating the statistical graph

1. Acessa o diretório que contém os arquivos "clock.dat" e "time.dat" (que foram gerados pela execução dos métodos) e "grafico.gnu" (Script de execução do gnuplot) pelo terminal:

	cd data

2. Digita o comando no Terminal:

	gnuplot grafico.gnu

Para criar os gráficos basta executar o gnuplot utilizando o script gnuplot deste projeto.

	gnuplot performance.gnuplot
	
## 5. Running on the Computer

Na raiz do projeto entre no diretório "dist-64bits" ou "dist-32bits" Conforme seu sistema operacional e execute o programa:
	
	cd dist-64bits
	
	./AnalysisTime

O resultado da execução estará no diretório criado pelo programa "dados-coletados" junto com os gráficos e scripts do gnuplot para personalização

## 6. Running on BeagleBone Black

É possível programar e compilar no seu computador e enviar o executável para a BeagleBone. Para fazer os testes deste projeto basta clonar esse projeto e executar os comandos.

### i. Before (Computer)

Entre na pasta de código fonte "AnalysisTime" abra o arquivo "compila.sh" e veja se o diretório "source" é de fato o endereço do "SDK Texas Instruments" instalado conforme foi especificado em seções anteriores. Exemplo:

	source /opt/ti-processor-sdk-linux-am335x-evm-02.00.01.07/linux-devkit/environment-setup
	
Verifique se o nome do executável é o mesmo especificado no "AnalysisTime.pro" como a seguir:

	sshpass -p 'temppwd' scp AnalysisTime debian@192.168.7.2:~
	
Agora acesse a BeagleBone por ssh (mais informações podem ser visualisadas em seções anteriores):

	ssh debian@192.168.7.2

### ii. Running (BeagleBone Black)

já conectado a Beagle (é preferivel ter o gnuplot instalado na beagle para facilitar o processo, isso pode ser feito na seção de instação do gnuplot) execute o programa:

	./AnalysisTime
	
Após a execução, é criado um diretório "dados-coletados" com arquivos contendo as informações a serem plotadas em gráfico. e se o gnuplot já foi instalado antes, já se tem as imagens com gráficos. Volte ao seu pc:

	exit

### iii. After (Computer)

Na raiz do projeto execute o script "get-results-beagle-scp.sh", coloque a senha conforme solicitar, se não houver permissão forneça com:

	chmod +x get-results-beagle-scp.sh
	./get-results-beagle-scp.sh
	
Após isso os dados da beagle pode ser analisado no diretório "Dados-beagle", se não houver imagens com os gráficos, gere com:

	gnuplot performance.gnuplot

## 7. Results 

Nessa seção, temos os resultados dos testes dos algoritmos BubbleSort, QuickSort e MergeSort.

### i. Computer 1 (Pentium Dual Core Processor)

Configurações:
- Intel Pentium 3GHz x2
- 2 Gb de memória RAM
- 64 bits
- Ubuntu

O programa executou sozinho no computador.

![Time](Dados-pc/grafico_time.png?raw=true "Gráfico de Time")

![Clock](Dados-pc/grafico_clock.png?raw=true "Gráfico de Clock")

### ii. Computer 2 (i7 Octa Core Processor)

Configurações:
- Intel Core i7 2.40GHz x8
- 8 Gb de memória RAM
- 64 bits
- Ubuntu

O programa foi executado paralelamente com outros programas (Spotify, Chrome, Atom, Gerenciador de Arquivos e o Visualizador de PDF).

![Time](Dados-pc-i7/grafico_time.png?raw=true "Gráfico de Time")

![Clock](Dados-pc-i7/grafico_clock.png?raw=true "Gráfico de Clock")

### iii. BeagleBone Black (Single Core)

O programa executou sozinho no computador.

![Time](Dados-beagle/grafico_time.png?raw=true "Gráfico de Time")

![Clock](Dados-beagle/grafico_clock.png?raw=true "Gráfico de Clock")

## 8. Conclusion

We conclude as soon as the hardware architecture greatly influences performance, we can see this by the graphs shown in the results of the analysis.

We noticed that there is a big difference in the graphs between the execution in the computers and the BeagleBone, but there are similarities in relation to the growth of the graphs, these correspond to the complexity of the algorithms.

After these tests how can we answer which function performs the best performance analysis of sorting algorithms?

As we can see, the Clock function allows a more detailed analysis of the data, since the small order that a clock unit represents, however, when we analyze the data with more precision, we can easily reach the representative limit of the numerical unit, and the consequence is the occurrence of Overflow causing an inconsistency in the final data. The Time function is very useful to represent large values, since its representative unit is in seconds, in that way it would analyze in a "magnificent" way the execution of algorithms with years of duration, although there is a growth limit as well the Clock function, the big problem of the Time function is in the performance analysis of algorithms in short time intervals, since it is not possible to measure large ones such as milliseconds or nanoseconds.

Therefore, the best answer to the above question depends on what will be analyzed: algorithms that last a nanosecond, or complex ordering algorithms run on vectors with more than 100,000 elements. The Clock function is most useful for accurate analysis, but not for large-time analysis, and the Time function is most useful in very complex and time-consuming algorithms, but it is much less accurate than the Clock function.

## 9. Members 

* Breno Maurício de Freitas Viana
* Felipe Barbalho Rocha

## 9. References

* BubbleSort - Disponibilizado pelo professor Ivanovitch
* [QuickSort](https://pt.wikipedia.org/wiki/Quicksort)
* [MergerSort](https://pt.wikipedia.org/wiki/Merge_sort)
* [BeagleBoard](https://pt.wikipedia.org/wiki/BeagleBoard)
* [Usando Gnuplot para gerar bons gráficos](http://www.dicas-l.com.br/arquivo/usando_gnuplot_para_gerar_bons_graficos.php)
* [Gnuplot - Manual simplificado para iniciantes](http://www.ebah.com.br/content/ABAAAgUS4AF/gnuplot-manual-simplificado-iniciantes?part=1)

