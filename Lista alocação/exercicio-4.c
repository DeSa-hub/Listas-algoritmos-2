/*4) Elabore um programa que leia do usuário o tamanho de um vetor a ser lido. Em seguida,
faça a alocação dinâmica desse vetor. Por fim, leia o vetor do usuário e o imprima.*/

#include <stdio.h>
#include <stdlib.h>

int main()
  {
  int n;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  int *vetor = (int*) malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    {
    printf("Digite o elemento %d: ", i);
    scanf("%d", &vetor[i]);
    }
  for (int i = 0; i < n; i++)
    {
    printf("vetor[%d] = %d\n", i, vetor[i]);
    }
  free(vetor);
  return 0;
  }