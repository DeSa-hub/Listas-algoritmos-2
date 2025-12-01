/*8) Crie uma função que receba dois parâmetros: um vetor e um valor do mesmo tipo do
vetor. A função deverá preencher os elementos de vetor com esse valor. Não utilize
índices para percorrer o vetor, apenas aritmética de ponteiros.*/

#include <stdio.h>

void funcao(int *vetor, int a, int tamanho)
  {
  int *pv = vetor;

  for(int i = 0; i < tamanho; i++)
    {
    *pv = a;
    pv++;
    }
  }

int main()
  {
  int vetor[5];

  funcao(vetor, 2, 5);

  for (int i = 0; i < 5; i++)
    {
    printf("%d ", vetor[i]);
    }

  return 0;
  }
