#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"


// FUNÇÕES AUXILIARES

void ler(int *vetor, int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d\n",&vetor[i]);
}

void imprimir(int *vetor, int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d\n",vetor[i]);
}

void copiar(int *v1, int *v2, int n)
{
	int i;
	for(i=0;i<n;i++)
		v1[i] = v2[i];
}

void permutar(int *vetor, int i, int j)
{
	int x = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = x;
}

void intercalar(int p, int q, int r, int v[])
{
	int i, j, k, *w;
	w = (int*) malloc ((r-p) * sizeof (int));

	for (i = 0, k = p; k < q; ++i, ++k) w[i] = v[k];
	for (j = r-p-1, k = q; k < r; --j, ++k) w[j] = v[k];
	i = 0; j = r-p-1;
	for (k = p; k < r; ++k)
		if (w[i] <= w[j]) v[k] = w[i++];
		else v[k] = w[j--];
	free (w);
}

int mediana(int x, int y)
{
	int z = (y-x)/2;
	if(x<y)
	{
		if(x<z)
		{
			if(y<z)
			{
				return y;
			}
			else
			{
				return z;
			}
		}
		else
		{
			return x;
		}
	}
	else
	{
		if(x<z)
		{
			return x;
		}
		else
		{
			if(z>y)
			{
				return z;
			}
			else
			{
				return y;
			}
		}
	}
}


// ALGORITMOS DE ORDENAÇÃO

void bubble(int *vetor, int n)
{
	int a, b;
	int trocas=0;
	for(a=1;a<n;++a)
	{
		for(b=n-1;b>=a;--b)
		{
			if(vetor[b-1] > vetor[b])
			{
				permutar(vetor, b-1, b);
				trocas++;
			}
		}
		if(trocas==0) break;
	}
}
 
void shake(int *vetor, int n)
{
	#define try_swap { if (vetor[i] < vetor[i - 1])\
	{ t = vetor[i]; vetor[i] = vetor[i - 1]; vetor[i - 1] = t; t = 0;} }
	
	int i;
	int t = 0;
	while (!t) {
		for (i = 1, t = 1; i < n; i++) try_swap;
		if (t) break;
		for (i = n - 1, t = 1; i; i--) try_swap;
	}
} // http://rosettacode.org/wiki/Sorting_algorithms/Cocktail_sort#C

void insertion(int *vetor, int n)
{
	int a, b, temp;
	for(a=1;a<n;++a)
	{
		temp = vetor[a];
		for(b=a-1; b>=0 && temp<vetor[b]; b--)
		{
			vetor[b+1] = vetor[b];
		}
		vetor[b+1] = temp;
	}
}

void shell(int *vetor, int n)
{
	int i, j, gap, k, x, a[5];
	
	a[0]=9; a[1]=5; a[2]=3; a[3]=2; a[4]=1;
	
	for(k=0;k<5;k++)
	{
		gap = a[k];
		for(i=gap; i<n; ++i)
		{
			x = vetor[i];
			for(j=i-gap; x<vetor[j] && j>=0; j=j-gap)
			{	
				vetor[j+gap] = vetor[j];
			}
			vetor[j+gap] = x;
		}
	}
}

void selection(int *vetor, int n)
{
	int a, b, c, temp, exchange;
	
	for(a=0;a<n-1;++a)
	{
		exchange = 0;
		c = a;
		temp = vetor[a];
		for(b=a+1;b<n;++b)
		{
			if(vetor[b]<temp)
			{
				c = b;
				temp = vetor[b];
				exchange = 1;
			}
		}
		if(exchange)
		{
			vetor[c] = vetor[a];
			vetor[a] = temp;
		}
	}
}

void rank(int *vetor, int n){
	
	int k = 1000001;
	int i;
	int B[n];
	int C[k];
	
	//Passo 1 - Conta a quantidade de ocorrências de cada elemento
	for(i=0;i<n;i++)
		C[vetor[i]]++;
	
	//Passo 2 - Realiza o complemento das ocorrências
	for(i=0;i<k;i++) 
		C[i] += C[i-1];
	
	//Passo 3
	for(i=n-1;i>=0;i--) 
	{
		B[C[vetor[i]]-1] = vetor[i];
		C[vetor[i]]--;
	}

	//Passo 4
	copiar(vetor, B, n);
}

void quickprimeiro(int *vetor, int esquerda, int direita)
{
	int i, j, pivo;
    
	i = esquerda;
	j = direita;
	pivo = vetor[esquerda];

	while(i <= j)
	{
		while(vetor[i] < pivo && i < direita)
		{
			i++;
		}
		while(vetor[j] > pivo && j > esquerda)
		{
			j--;
		}
		if(i <= j)
		{
			permutar(vetor, i, j);
			i++;
			j--;
		}
	}
	if(j > esquerda)
	{
		quickprimeiro(vetor, esquerda, j);
	}
	if(i < direita)
	{
		quickprimeiro(vetor,  i, direita);
	}
}

void quickcentral(int *vetor, int esquerda, int direita)
{
	int i, j, pivo;
    
	i = esquerda;
	j = direita;
	pivo = vetor[(esquerda + direita) / 2];

	while(i <= j)
	{
		while(vetor[i] < pivo && i < direita)
		{
			i++;
		}
		while(vetor[j] > pivo && j > esquerda)
		{
			j--;
		}
		if(i <= j)
		{
			permutar(vetor, i, j);
			i++;
			j--;
		}
	}
	if(j > esquerda)
	{
		quickcentral(vetor, esquerda, j);
	}
	if(i < direita)
	{
		quickcentral(vetor,  i, direita);
	}
}

void quickrandom(int *vetor, int esquerda, int direita)
{
	int i, j, pivo;
	srand((unsigned)time(NULL));
    
	i = esquerda;
	j = direita;
	pivo = vetor[rand() % (direita - esquerda + 1) + esquerda];
	
	while(i <= j)
	{
		while(vetor[i] < pivo && i < direita)
		{
			i++;
		}
		while(vetor[j] > pivo && j > esquerda)
		{
			j--;
		}
		if(i <= j)
		{
			permutar(vetor, i, j);
			i++;
			j--;
		}
	}
	if(j > esquerda)
	{
		quickrandom(vetor, esquerda, j);
	}
	if(i < direita)
	{
		quickrandom(vetor,  i, direita);
	}
}

void quickmediana3(int *vetor, int esquerda, int direita)
{
	int i, j, pivo;
    
	i = esquerda;
	j = direita;	
	pivo = vetor[mediana(esquerda, direita)];

	while(i <= j)
	{
		while(vetor[i] < pivo && i < direita)
		{
			i++;
		}
		while(vetor[j] > pivo && j > esquerda)
		{
			j--;
		}
		if(i <= j)
		{
			permutar(vetor, i, j);
			i++;
			j--;
		}
	}
	if(j > esquerda)
	{
		quickmediana3(vetor, esquerda, j);
	}
	if(i < direita)
	{
		quickmediana3(vetor,  i, direita);
	}
}

void merge(int *vetor, int n)
{
	int p, r;
	int b = 1;
	while (b < n) 
	{
		p = 0;
		while (p + b < n) 
		{
			r = p + 2*b;
			if (r > n) r = n;
			intercalar (p, p+b, r, vetor);
			p = p + 2*b; 
		}
	b = 2*b;
	}
}

void heap(int *vetor, int n) 
{
	int i = n / 2, pai, filho, t;

	for (;;)
	{
		if (i > 0)
		{
			i--;
			t = vetor[i];
		}
		else
		{
			n--;
			if (n == 0) return;
			t = vetor[n];
			vetor[n] = vetor[0];
		}

		pai = i;

		//Primeiro será feita a comparação com o filho da esquerda.
		filho = i * 2 + 1;

		while (filho < n) {

		//Se o filho da esquerda for menor do que o filho da direita,então será feita a troca do filho que será comparado.
		if ((filho + 1 < n)  &&  (vetor[filho + 1] > vetor[filho]))
			filho++;
		if (vetor[filho] > t) 
		{
			vetor[pai] = vetor[filho];
			pai = filho;
			filho = pai * 2 + 1;
		} 
		else
		{
			break;
		}
	}
	vetor[pai] = t;
   }
}

void radix(int *vetor, int n)
{
	int i, j=0;
	int *b;
	int exp = 1;
    
	b = (int *)calloc(n, sizeof(int));
 
	while (j < 7) {
		int bucket[10] = { 0 };
		for (i = 0; i < n; i++)
			bucket[(vetor[i] / exp) % 10]++; 
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
		for (i = 0; i < n; i++)
			vetor[i] = b[i];
		exp *= 10;
		j++;
	}
	free(b);
} // https://pt.wikipedia.org/wiki/Radix_sort  &  https://www.cs.usfca.edu/~galles/visualization/RadixSort.html

void radixbin(int *vetor, int n)
{	
	int i, j=0;
	int *b;
	int exp = 0;
    
	b = (int *)calloc(n, sizeof(int));
 	
 	// 1000000 em binario: 11110100001001000000 (20 dígitos)
	while (j < 20) {
		int bucket[2] = { 0 };
		for (i = 0; i < n; i++)
			bucket[(vetor[i] >> exp) % 2]++; 
		for (i = 1; i < 2; i++)
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--bucket[(vetor[i] >> exp) % 2]] = vetor[i];
		for (i = 0; i < n; i++)
			vetor[i] = b[i];
		exp++;
		j++;
	}
	free(b);
} 




