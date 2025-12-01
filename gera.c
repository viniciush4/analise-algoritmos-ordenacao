#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[])
{
	// verifica se a quantidade de parâmetros está correta
	if(argc == 3) 
	{	
		int n = atoi(argv[2]);
		
		// verifica se é aleatório
		if(strcmp(argv[1], "-a") == 0)
		{
			srand((unsigned)time(NULL));
			int i;
			for(i=0;i<n;i++)
				printf("%d\n",rand()%n);
		}
		else
		{
			// verifica se é crescente
			if(strcmp(argv[1], "-c") == 0)
			{
				int i;
				for(i=0;i<n;i++)
					printf("%d\n",i);			
			}
			else
			{
				// verifica se é decrescente
				if(strcmp(argv[1], "-d") == 0)
				{
					int i;
					for(i=n;i>0;i--)
						printf("%d\n",i);
				}
				else
				{
					// finaliza o programa, retornando uma falha: não é indexação nem busca
					return(EXIT_FAILURE);
				}
			}
		}	
	}
	// se a quantidade de parâmetros não está correta
	else
	{
		// finaliza o programa, retornando uma falha: quantidade de parâmetros não está correta
		return(EXIT_FAILURE);	
	}
	// finaliza o programa com sucesso
	return(EXIT_SUCCESS);	
}

