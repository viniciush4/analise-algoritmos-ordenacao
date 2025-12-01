
all: compila documentacao clean

compila: algoritmos
	gcc -o trab4 algoritmos.o trab4.c
	gcc gera.c -o gera
	
algoritmos:
	gcc -c algoritmos.c

clean:
	rm -rf *.o *.log *.aux

documentacao:
	pdflatex artigo.tex
