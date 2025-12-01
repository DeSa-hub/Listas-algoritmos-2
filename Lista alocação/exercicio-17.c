/*17) Escreva uma função que receba como parâmetro uma matriz A contendo N linhas e
N colunas. A função deve retornar o ponteiro para um vetor B de tamanho N alocado
dinamicamente, em que cada posição de B é a soma dos números daquela coluna da
matriz.*/

#include <stdio.h>
#include <stdlib.h>

int *somar_colunas(int **a, int n)
  {
  if (n <= 0)
    {
    return NULL;
    }

  int *b = (int *) malloc(n * sizeof(int));
  if (b == NULL)
    {
    printf("Erro de alocacao!\n");
    return NULL;
    }

  for (int j = 0; j < n; j++)
    {
    b[j] = 0;
    for (int i = 0; i < n; i++)
      {
      b[j] += a[i][j];
      }
    }

  return b;
  }

int main()
  {
  int n;
  int **a, *b;

  printf("Digite o valor de N (matriz NxN): ");
  scanf("%d", &n);
  a = (int **) malloc(n * sizeof(int *));
  if (a == NULL)
    {
    printf("Erro de alocacao!\n");
    return 1;
    }

  for (int i = 0; i < n; i++)
    {
    a[i] = (int *) malloc(n * sizeof(int));
    if (a[i] == NULL)
      {
      printf("Erro de alocacao!\n");
      for (int k = 0; k < i; k++)
        {
        free(a[k]);
        }
      free(a);
      return 1;
      }
    }
  printf("Digite os elementos da matriz A (%dx%d):\n", n, n);
  for (int i = 0; i < n; i++)
    {
    for (int j = 0; j < n; j++)
      {
      scanf("%d", &a[i][j]);
      }
    }
  b = somar_colunas(a, n);
  if (b == NULL)
    {
    for (int i = 0; i < n; i++)
      {
      free(a[i]);
      }
    free(a);
    return 1;
    }

  printf("Soma das colunas (vetor B):\n");
  for (int i = 0; i < n; i++)
    {
    printf("%d ", b[i]);
    }
  printf("\n");
  for (int i = 0; i < n; i++)
    {
    free(a[i]);
    }
  free(a);
  free(b);

  return 0;
  }