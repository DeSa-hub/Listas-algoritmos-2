/*15) Escreva uma função que receba como parâmetro dois vetores, A e B, de tamanho N
cada. A função deve retornar o ponteiro para um vetor C de tamanho N alocado
dinamicamente, em que C[i] = A[i] * B[i].*/

#include <stdio.h>
#include <stdlib.h>

int *multiplicar_vetores(int *a, int *b, int n)
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
    c[i] = a[i] * b[i];
    }

  return c;
  }

int main()
  {
  int n;
  int *a, *b, *c;

  printf("Digite o tamanho dos vetores: ");
  scanf("%d", &n);

  a = (int *) malloc(n * sizeof(int));
  b = (int *) malloc(n * sizeof(int));
  if (a == NULL || b == NULL)
    {
    printf("Erro de alocacao!\n");
    free(a);
    free(b);
    return 1;
    }

  printf("Digite os elementos do vetor A:\n");
  for (int i = 0; i < n; i++)
    {
    scanf("%d", &a[i]);
    }

  printf("Digite os elementos do vetor B:\n");
  for (int i = 0; i < n; i++)
    {
    scanf("%d", &b[i]);
    }

  c = multiplicar_vetores(a, b, n);
  if (c == NULL)
    {
    free(a);
    free(b);
    return 1;
    }

  printf("Vetor C (produto de A e B):\n");
  for (int i = 0; i < n; i++)
    {
    printf("%d ", c[i]);
    }
  printf("\n");

  free(a);
  free(b);
  free(c);

  return 0;
  }
