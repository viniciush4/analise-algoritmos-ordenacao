# Análise de Algoritmos de Ordenação

Este projeto implementa e analisa 14 algoritmos de ordenação diferentes, comparando seus desempenhos em diversos cenários de entrada.

## 📋 Descrição

O projeto foi desenvolvido como parte de um estudo comparativo sobre algoritmos de ordenação interna, medindo e analisando o tempo de execução de cada algoritmo em diferentes condições: entradas crescentes, decrescentes e aleatórias.

## 🔧 Algoritmos Implementados

### Algoritmos Baseados em Comparação
- **Bubble Sort**: Algoritmo simples que compara elementos adjacentes
- **Shake Sort** (Cocktail Sort): Variação do Bubble que ordena em ambas direções
- **Insertion Sort**: Insere cada elemento na posição correta
- **Shell Sort**: Versão otimizada do Insertion Sort com gaps
- **Selection Sort**: Seleciona o menor elemento a cada iteração
- **Quick Sort** (4 variações):
  - Quick (P): Pivô no primeiro elemento
  - Quick (C): Pivô central (tradicional)
  - Quick (R): Pivô aleatório
  - Quick (M): Pivô como mediana de 3 elementos
- **Merge Sort**: Divide e conquista com intercalação
- **Heap Sort**: Utiliza estrutura de heap

### Algoritmos Sem Comparação
- **Rank Sort** (Counting Sort): Conta ocorrências de cada elemento
- **Radix Sort**: Ordena por dígitos decimais
- **Radix Binary**: Ordena por dígitos binários

## 🚀 Compilação e Execução

### Compilar o projeto
```bash
make
```

Este comando irá:
1. Compilar os algoritmos de ordenação
2. Compilar o programa principal
3. Compilar o gerador de entradas
4. Gerar a documentação PDF (requer LaTeX)

### Gerar entradas de teste

```bash
# Entrada aleatória com N elementos
./gera -a N > entrada.txt

# Entrada crescente com N elementos
./gera -c N > entrada.txt

# Entrada decrescente com N elementos
./gera -d N > entrada.txt
```

### Executar um algoritmo

```bash
# Sintaxe geral
./trab4 <algoritmo> <tamanho> < entrada.txt

# Exemplos
./trab4 bubble 1000 < entrada.txt
./trab4 quickcentral 10000 < entrada.txt
./trab4 merge 100000 < entrada.txt
```

### Medir tempo de execução

```bash
time ./trab4 bubble 10000 < entrada.txt
```

## 📊 Algoritmos Disponíveis

| Nome no Programa | Algoritmo |
|-----------------|-----------|
| `bubble` | Bubble Sort |
| `shake` | Shake Sort |
| `insertion` | Insertion Sort |
| `shell` | Shell Sort |
| `selection` | Selection Sort |
| `rank` | Rank Sort |
| `quickprimeiro` | Quick Sort (pivô primeiro) |
| `quickcentral` | Quick Sort (pivô central) |
| `quickrandom` | Quick Sort (pivô aleatório) |
| `quickmediana3` | Quick Sort (pivô mediana) |
| `merge` | Merge Sort |
| `heap` | Heap Sort |
| `radix` | Radix Sort |
| `radixbin` | Radix Binary |

## 📈 Resultados Principais

### Algoritmos "Rápidos" (< 3 segundos para 1 milhão de elementos)
- Rank, Quick (C), Quick (M), Merge, Heap, Radix, Radix (B)

### Algoritmos "Lentos" (> 100 segundos para entradas grandes)
- Bubble, Shake, Insertion, Shell, Selection, Quick (P)

### Melhores Escolhas por Cenário

**Entrada Aleatória:**
- Melhor: Quick (C), Merge, Heap
- Pior: Bubble, Shake

**Entrada Crescente:**
- Melhor: Bubble, Insertion, Shell (com otimização)
- Pior: Selection, Quick (P)

**Entrada Decrescente:**
- Melhor: Quick (C), Merge, Heap
- Pior: Shake, Bubble

## 🔍 Observações Importantes

### Limitações
- **Rank Sort**: Limitado a números até 1.000.000
- **Radix Sort**: Otimizado para números com até 7 dígitos
- **Radix Binary**: Funciona com números representáveis em 20 bits

### Complexidades de Tempo
- **O(n²)**: Bubble, Shake, Insertion, Selection
- **O(n log n)**: Quick, Merge, Heap (média/melhor caso)
- **O(n)**: Rank, Radix (casos específicos)

## 📁 Estrutura do Projeto

```
.
├── algoritmos.c      # Implementação dos algoritmos
├── algoritmos.h      # Cabeçalhos das funções
├── trab4.c          # Programa principal
├── gera.c           # Gerador de entradas
├── Makefile         # Script de compilação
├── artigo.tex       # Documentação em LaTeX
└── README.md        # Este arquivo
```

## 🛠️ Requisitos

- Compilador GCC
- Sistema Linux/Unix
- (Opcional) LaTeX para gerar documentação PDF

## 📖 Referências

As implementações foram adaptadas de:
- SCHILDT, Herbert. C, completo e total. 3ª Ed. São Paulo: Makron Books, 1996
- CELES, Waldemar; CERQUEIRA, Renato; RANGEL, José Lucas. Introdução a estruturas de dados
- Rosetta Code
- Wikipedia

## 👤 Autor

Vinícius Berger  
Universidade Federal do Espírito Santo

## 📝 Licença

Este projeto foi desenvolvido para fins educacionais.

---

**Nota**: Os tempos de execução variam de acordo com o hardware utilizado. Os resultados apresentados no artigo foram obtidos em condições específicas descritas na documentação.
