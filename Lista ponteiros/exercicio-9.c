/*9) Crie uma função que receba como parâmetro um vetor e o imprima. Não utilize índices
para percorrer o vetor, apenas aritmética de ponteiros.*/

#include <stdio.h>

void imprimir(int *vetor, int tamanho)
  {
  int *fim = vetor + tamanho;
  while (vetor < fim)
    {
    printf("%d ", *vetor);
    vetor++;
    }
  printf("\n");
  }

int main()
  {
  int v[5] = {1, 2, 3, 4, 5};
  imprimir(v, 5);

  return 0;
  }