/*16) Escreva uma função que receba como parâmetro uma matriz A contendo N linhas e
N colunas, e um vetor B de tamanho N. A função deve retornar o ponteiro para um vetor
C de tamanho N alocado dinamicamente, em que C é o produto da matriz A pelo vetor B.*/

#include <stdio.h>
#include <stdlib.h>

int *produto_matriz_vetor(int **a, int *b, int n)
  {
  if (n <= 0)
    {
    return NULL;
    }

  int *c = (int *) malloc(n * sizeof(int));
  if (c == NULL)
    {
    printf("Erro de alocacao!\n");
    return NULL;
    }

  for (int i = 0; i < n; i++)
    {
    c[i] = 0;
    for (int j = 0; j < n; j++)
      {
      c[i] += a[i][j] * b[j];
      }
    }

  return c;
  }

int main()
  {
  int n;
  int **a, *b, *c;

  printf("Digite o valor de N (matriz NxN e vetor de tamanho N): ");
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
  b = (int *) malloc(n * sizeof(int));
  if (b == NULL)
    {
    printf("Erro de alocacao!\n");
    for (int i = 0; i < n; i++)
      {
      free(a[i]);
      }
    free(a);
    return 1;
    }
  printf("Digite os elementos da matriz A (%dx%d):\n", n, n);
  for (int i = 0; i < n; i++)
    {
    for (int j = 0; j < n; j++)
      {
      scanf("%d", &a[i][j]);
      }
    }

  printf("Digite os elementos do vetor B (tamanho %d):\n", n);
  for (int i = 0; i < n; i++)
    {
    scanf("%d", &b[i]);
    }

  c = produto_matriz_vetor(a, b, n);
  if (c == NULL)
    {
    for (int i = 0; i < n; i++)
      {
      free(a[i]);
      }
    free(a);
    free(b);
    return 1;
    }

  printf("Resultado do produto A x B (vetor C):\n");
  for (int i = 0; i < n; i++)
    {
    printf("%d ", c[i]);
    }
  printf("\n");
  for (int i = 0; i < n; i++)
    {
    free(a[i]);
    }
  free(a);
  free(b);
  free(c);

  return 0;
  }