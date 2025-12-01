/*15 - Escreva uma função que recebe, por parâmetro, dois valores X e Z e
calcula e retorna Xz
. (sem utilizar funções ou operadores de potência
prontos) */

#include <stdio.h>

float potencia(float x, int z)
  {
  float resultado = 1;
  int i;

  if (z == 0)
    {
    return 1;
    }

  for (i = 1; i <= z; i++)
    {
    resultado *= x;
    }

  return resultado;
  }

int main()
  {
  float base;
  int expoente;
  float resultado;

  printf("Digite a base (X): ");
  scanf("%f", &base);

  printf("Digite o expoente inteiro positivo (Z): ");
  scanf("%d", &expoente);

  if (expoente < 0)
    {
    printf("Expoente deve ser inteiro positivo\n");
    return 0;
    }

  resultado = potencia(base, expoente);

  printf("%.2f elevado a %d = %.2f\n", base, expoente, resultado);

  return 0;
  }
