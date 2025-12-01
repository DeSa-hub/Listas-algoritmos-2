/*2) Crie uma estrutura para representar as coordenadas de um ponto no plano (posições X
e Y). Em seguida, declare e leia do teclado um ponto e exiba a distância dele até a origem
das coordenadas, isto é, a posição (0,0).*/

#include <stdio.h>

struct Ponto
  {
  float x;
  float y;
  };


float raizQuadrada(float n)
  {
  float x = n;
  float y = 1.0;
  float erro = 0.0001;

  while (x - y > erro)
    {
    x = (x + y) / 2;
    y = n / x;
    }

  return x;
  }

int main()
  {
  struct Ponto p;
  float distancia;
  printf("Digite a coordenada X: ");
  scanf("%f", &p.x);
  printf("Digite a coordenada Y: ");
  scanf("%f", &p.y);
  distancia = raizQuadrada(p.x * p.x + p.y * p.y);
  printf("Distancia ate a origem: %.2f\n", distancia);

  return 0;
  }
