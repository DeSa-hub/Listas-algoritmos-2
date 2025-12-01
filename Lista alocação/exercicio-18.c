/*18) Escreva uma função que receba como parâmetro duas matrizes, A e B, e seus
tamanhos. A função deve retornar o ponteiro para uma matriz C, em que C é o produto
da multiplicação da matriz A pela matriz B. Se a multiplicação das matrizes não for
possível, retorne um ponteiro nulo.*/

#include <stdio.h>
#include <stdlib.h>

int **multiplicar_matrizes(int **a, int m, int n, int **b, int p, int q)
  {
  if (n != p)
    {
    return NULL;
    }

  int **c = (int **) malloc(m * sizeof(int *));
  if (c == NULL)
    {
    printf("Erro de alocacao!\n");
    return NULL;
    }

  for (int i = 0; i < m; i++)
    {
    c[i] = (int *) malloc(q * sizeof(int));
    if (c[i] == NULL)
      {
      printf("Erro de alocacao!\n");
      for (int k = 0; k < i; k++)
        {
        free(c[k]);
        }
      free(c);
      return NULL;
      }

    for (int j = 0; j < q; j++)
      {
      c[i][j] = 0;
      for (int k = 0; k < n; k++)
        {
        c[i][j] += a[i][k] * b[k][j];
        }
      }
    }

  return c;
  }

int main()
  {
  int m, n, p, q;
  int **a, **b, **c;

  printf("Digite o numero de linhas e colunas da matriz A: ");
  scanf("%d %d", &m, &n);

  printf("Digite o numero de linhas e colunas da matriz B: ");
  scanf("%d %d", &p, &q);
  a = (int **) malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++)
    {
    a[i] = (int *) malloc(n * sizeof(int));
    }
  b = (int **) malloc(p * sizeof(int *));
  for (int i = 0; i < p; i++)
    {
    b[i] = (int *) malloc(q * sizeof(int));
    }
  printf("Digite os elementos da matriz A (%dx%d):\n", m, n);
  for (int i = 0; i < m; i++)
    {
    for (int j = 0; j < n; j++)
      {
      scanf("%d", &a[i][j]);
      }
    }
  printf("Digite os elementos da matriz B (%dx%d):\n", p, q);
  for (int i = 0; i < p; i++)
    {
    for (int j = 0; j < q; j++)
      {
      scanf("%d", &b[i][j]);
      }
    }
  c = multiplicar_matrizes(a, m, n, b, p, q);
  if (c == NULL)
    {
    printf("Nao foi possivel multiplicar as matrizes.\n");

    for (int i = 0; i < m; i++) free(a[i]);
    for (int i = 0; i < p; i++) free(b[i]);
    free(a);
    free(b);
    return 1;
    }
  printf("Resultado da multiplicacao (matriz C):\n");
  for (int i = 0; i < m; i++)
    {
    for (int j = 0; j < q; j++)
      {
      printf("%3d ", c[i][j]);
      }
    printf("\n");
    }
  for (int i = 0; i < m; i++) free(a[i]);
  for (int i = 0; i < p; i++) free(b[i]);
  for (int i = 0; i < m; i++) free(c[i]);
  free(a);
  free(b);
  free(c);

  return 0;
  }