/*5) Faça um programa que leia um valor inteiro N não negativo. Se o valor de N for
inválido, o usuário deverá digitar outro até que ele seja válido (ou seja, positivo). Em
seguida, leia um vetor V contendo N posições de inteiros, em que cada valor deverá ser
maior ou igual a 2. Esse vetor deverá ser alocado dinamicamente.*/

#include <stdio.h>
#include <stdlib.h>

int* criarVetor(int N)
  {
  int* vetor = (int*) malloc(N * sizeof(int));
  if (vetor == NULL)
    {
    printf("Erro ao alocar memoria.\n");
    exit(1);
    }

  for (int i = 0; i < N; i++)
    {
    do
      {
      printf("Digite o valor da posicao %d (>= 2): ", i);
      scanf("%d", &vetor[i]);
      if (vetor[i] < 2)
        printf("Valor invalido! Deve ser maior ou igual a 2.\n");
      } while (vetor[i] < 2);
    }

  return vetor;
  }

int main()
  {
  int n;

  do
    {
    printf("Digite o valor de N (positivo): ");
    scanf("%d", &n);
    if (n <= 0)
      printf("Valor invaalido! Tente novamente.\n");
    } while (n <= 0);

  int* vetor = criarVetor(n);

  printf("\n--- Valores Digitados ---\n");
  for (int i = 0; i < n; i++)
    {
    printf("V[%d] = %d\n", i, vetor[i]);
    }

  free(vetor);
  return 0;
  }
