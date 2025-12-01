/*6) Escreva um programa que aloque dinamicamente uma matriz de inteiros. As dimensões
da matriz deverão ser lidas do usuário. Em seguida, escreva uma função que receba um
valor e retorne 1, caso o valor esteja na matriz, ou retorne 0, no caso contrário.
*/

#include <stdio.h>
#include <stdlib.h>

int valor_na_matriz(int **matriz, int linhas, int colunas, int valor)
  {
  for (int i = 0; i < linhas; i++)
    {
    for (int j = 0; j < colunas; j++)
    {
    if (matriz[i][j] == valor)
      {
      return 1;
      }
     }
    }
  return 0;
  }

int main()
  {
  int linhas, colunas, valor;
  int **matriz;
  printf("Digite o numero de linhas: ");
  scanf("%d", &linhas);
  printf("Digite o numero de colunas: ");
  scanf("%d", &colunas);
  matriz = (int **) malloc(linhas * sizeof(int *));
  if (matriz == NULL)
    {
    printf("Erro de alocacao!\n");
    return 1;
    }
  for (int i = 0; i < linhas; i++)
    {
    matriz[i] = (int *) malloc(colunas * sizeof(int));
    if (matriz[i] == NULL)
      {
      printf("Erro de alocacao!\n");
      for (int k = 0; k < i; k++)
        {
        free(matriz[k]);
        }
      free(matriz);
      return 1;
      }
     }
  printf("Digite os elementos da matriz:\n");
  for (int i = 0; i < linhas; i++)
    {
    for (int j = 0; j < colunas; j++)
      {
      scanf("%d", &matriz[i][j]);
      }
    }

  printf("Digite o valor a ser buscado: ");
  scanf("%d", &valor);

  if (valor_na_matriz(matriz, linhas, colunas, valor))
    {
    printf("O valor %d esta na matriz.\n", valor);
    }
  else
    {
    printf("O valor %d nao esta na matriz.\n", valor);
    }
  for (int i = 0; i < linhas; i++)
    {
    free(matriz[i]);
    }
  free(matriz);

  return 0;
  }
