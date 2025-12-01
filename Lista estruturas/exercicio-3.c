/*3) Crie uma estrutura para representar as coordenadas de um ponto no plano (posições X
e Y). Em seguida, declare e leia do teclado dois pontos e exiba a distância entre eles.
*/

#include <stdio.h>

struct Ponto
  {
  float x;
  float y;
  };

float raizQuadrada(float numero)
  {
  float x = numero;
  float y = 1;
  float erro = 0.0001;

    while (x - y > erro)
      {
      x = (x + y) / 2;
      y = numero / x;
      }

  return x;
  }

int main()
  {
  struct Ponto p1, p2;
  float dx, dy, distancia;

  printf("Digite as coordenadas do primeiro ponto (X Y): ");
  scanf("%f %f", &p1.x, &p1.y);

  printf("Digite as coordenadas do segundo ponto (X Y): ");
  scanf("%f %f", &p2.x, &p2.y);

  dx = p2.x - p1.x;
  dy = p2.y - p1.y;

  distancia = raizQuadrada(dx * dx + dy * dy);

  printf("Distancia entre os dois pontos: %.2f\n", distancia);

  return 0;
  }

