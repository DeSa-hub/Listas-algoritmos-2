/*8) Escreva uma função que receba um valor inteiro positivo N por parâmetro e retorne o
ponteiro para um vetor de tamanho N alocado dinamicamente. Se N for negativo ou igual
a zero, um ponteiro nulo deverá ser retornado.*/

#include <stdio.h>
#include <stdlib.h>

int *aloca_vetor(int n)
  {
  if (n <= 0)
    {
    return NULL;
    }

  int *vetor = malloc(n * sizeof(int));
  if (vetor == NULL)
    {
    printf("Erro de alocacao!\n");
    return NULL;
    }

  return vetor;
  }

void limpa_buffer()
  {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
  }

int main()
  {
  int n;
  int *vetor;

  printf("Digite o tamanho do vetor: ");

  while (scanf("%d", &n) != 1)
    {
    printf("Entrada invalida! Digite um numero inteiro: ");
    limpa_buffer();
    }

  vetor = aloca_vetor(n);
  if (vetor == NULL)
    {
    printf("Vetor invalido ou erro de alocacao.\n");
    return 1;
    }

  printf("Vetor alocado com sucesso.\n");

  free(vetor);
  return 0;
  }
