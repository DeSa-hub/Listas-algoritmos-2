/*12 - Faça um procedimento que recebe 3 valores inteiros por parâmetro e
imprima-os ordenados em ordem crescente. */

#include <stdio.h>

void ordenarCrescente(int a, int b, int c)
  {
  int temp;
  if (a > b)
    {
    temp = a;
    a = b;
    b = temp;
    }
  if (a > c)
    {
    temp = a;
    a = c;
    c = temp;
    }
  if (b > c)
    {
    temp = b;
    b = c;
    c = temp;
    }

  printf("Valores em ordem crescente: %d %d %d\n", a, b, c);
  }

int main()
  {
  int x, y, z;

  printf("Digite tres numeros inteiros: ");
  scanf("%d %d %d", &x, &y, &z);

  ordenarCrescente(x, y, z);

  return 0;
  }
