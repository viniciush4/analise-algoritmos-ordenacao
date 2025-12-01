#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"

int main (int argc, char *argv[])
{
	// verifica se a quantidade de parâmetros está correta
	if(argc == 3) 
	{	
		int n = atoi(argv[2]);
		int vetor[n];
		
		ler(vetor, n);
		
		if(strcmp(argv[1], "bubble") == 0)
		{
			bubble(vetor, n);
		}
		else if(strcmp(argv[1], "shake") == 0)
		{
			shake(vetor, n);
		}
		else if(strcmp(argv[1], "insertion") == 0)
		{
			insertion(vetor, n);
		}
		else if(strcmp(argv[1], "shell") == 0)
		{
			shell(vetor, n);
		}
		else if(strcmp(argv[1], "selection") == 0)
		{
			selection(vetor, n);
		}
		else if(strcmp(argv[1], "rank") == 0)
		{
			rank(vetor, n);
		}
		else if(strcmp(argv[1], "quickprimeiro") == 0)
		{
			quickprimeiro(vetor, 0, n-1);
		}
		else if(strcmp(argv[1], "quickcentral") == 0)
		{
			quickcentral(vetor, 0, n-1);
		}
		else if(strcmp(argv[1], "quickrandom") == 0)
		{
			quickrandom(vetor, 0, n-1);
		}
		else if(strcmp(argv[1], "quickmediana3") == 0)
		{
			quickmediana3(vetor, 0, n-1);
		}
		else if(strcmp(argv[1], "merge") == 0)
		{
			merge(vetor, n);
		}
		else if(strcmp(argv[1], "heap") == 0)
		{
			heap(vetor, n);
		}
		else if(strcmp(argv[1], "radix") == 0)
		{
			radix(vetor, n);
		}
		else if(strcmp(argv[1], "radixbin") == 0)
		{
			radixbin(vetor, n);
		}
		else
		{
			return(EXIT_FAILURE);
		}
		
		imprimir(vetor, n);
	}
	else
	{
		return(EXIT_FAILURE);
	}
	return(EXIT_SUCCESS);
}
