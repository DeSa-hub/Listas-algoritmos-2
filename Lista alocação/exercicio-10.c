/*10) Escreva uma função que receba um valor inteiro positivo N por parâmetro e retorne
o ponteiro para um vetor de tamanho N alocado dinamicamente. Esse vetor deverá ter os
seus elementos preenchidos com certo valor, também passado por parâmetro. Se N for
negativo ou igual a zero, um ponteiro nulo deverá ser retornado.*/

#include <stdio.h>
#include <stdlib.h>

int *criar_vetor_com_valor(int n, int valor)
  {
  if (n <= 0)
    {
    return NULL;
    }

  int *vetor = (int *) malloc(n * sizeof(int));
  if (vetor == NULL)
    {
    printf("Erro de alocacao!\n");
    return NULL;
    }

  for (int i = 0; i < n; i++)
    {
    vetor[i] = valor;
    }

  return vetor;
  }

int main()
  {
  int n, valor;
  int *vetor;

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  printf("Digite o valor para preencher o vetor: ");
  scanf("%d", &valor);

  vetor = criar_vetor_com_valor(n, valor);
  if (vetor == NULL)
    {
    printf("Tamanho invalido ou erro de alocacao.\n");
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
