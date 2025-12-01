/*7) Faça uma função que retorne o ponteiro para um vetor de N elementos inteiros alocados
dinamicamente. O array deve ser preenchido com valores de 0 a N − 1*/

#include <stdio.h>
#include <stdlib.h>

int *criar_vetor(int n)
  {
  int *vetor = (int *) malloc(n * sizeof(int));
  if (vetor == NULL)
    {
    printf("Erro de alocacao!\n");
    return NULL;
    }

  for (int i = 0; i < n; i++)
    {
    vetor[i] = i;
    }

  return vetor;
  }

int main()
  {
  int n;
  int *vetor;

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  vetor = criar_vetor(n);
  if (vetor == NULL)
    {
    return 1;
    }

  printf("Vetor criado:\n");
  for (int i = 0; i < n; i++)
    {
    printf("%d ", vetor[i]);
    }
  printf("\n");

  free(vetor);
  return 0;
  }
