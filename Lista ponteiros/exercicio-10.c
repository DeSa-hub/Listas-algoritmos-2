/*10) Considere a seguinte declaração: int a, *b, **c, ***d. Escreva um programa que leia
a variável a e calcule e exiba o dobro, o triplo e o quádruplo desse valor utilizando apenas
os ponteiros b, c e d. O ponteiro b deve ser usado para calcular o dobro, c, o triplo, e d, o
quádruplo.*/

#include <stdio.h>

int main()
  {
  int a;
  int *b;
  int **c;
  int ***d;

  printf("Digite um valor inteiro: ");
  scanf("%d", &a);
  b = &a;
  c = &b;
  d = &c;
  int dobro = 2 * (*b);
  int triplo = 3 * (**c);
  int quadruplo = 4 * (***d);

  printf("Dobro: %d\n", dobro);
  printf("Triplo: %d\n", triplo);
  printf("Quadruplo: %d\n", quadruplo);

  return 0;
  }