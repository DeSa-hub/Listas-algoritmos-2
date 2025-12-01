/*13 - Escreva um procedimento que recebes 3 valores reais X, Y e Z e que
verifique se esses valores podem ser os comprimentos dos lados de um
triângulo e, neste caso, retornar qual o tipo de triângulo formado. Para que
X, Y e Z formem um triângulo é necessário que a seguinte propriedade seja
satisfeita: o comprimento de cada lado de um triângulo é menor do que a
soma do comprimento dos outros dois lados. O procedimento deve
identificar o tipo de triângulo formado observando as seguintes definições:

o Triângulo Equilátero: os comprimentos dos 3 lados são iguais.
o Triângulo Isósceles: os comprimentos de 2 lados são iguais.
o Triângulo Escaleno: os comprimentos dos 3 lados são diferentes.
*/ 

#include <stdio.h>

void tipoTriangulo(float x, float y, float z)
  {
  if (x < y + z && y < x + z && z < x + y)
    {
    if (x == y && y == z)
      {
      printf("Triangulo Equilatero\n");
      }
    else if (x == y || y == z || x == z)
      {
      printf("Triangulo Isosceles\n");
      }
    else
      {
      printf("Triangulo Escaleno\n");
      }
    }
  else
    {
    printf("Nao formam um triangulo\n");
    }
  }

int main()
  {
  float a, b, c;

  printf("Digite tres valores reais: ");
  scanf("%f %f %f", &a, &b, &c);

  tipoTriangulo(a, b, c);

  return 0;
  }