/*4 - Faça um procedimento que recebe por parâmetro os valores necessário
para o cálculo da fórmula de báskara e imprima as suas raízes, caso seja
possível calcular.*/

#include <stdio.h>
#include <math.h>

void calcularBhaskara(float a, float b, float c)
  {
  float delta = b * b - 4 * a * c;
  if (a == 0)
    {
    printf("Coeficiente 'a' nao pode ser zero.\n");
    return;
    }

  if (delta < 0)
    {
    printf("Nao existem raizes reais.\n");
    }
  else if (delta == 0)
    {
    float x = -b / (2 * a);
    printf("Raiz unica: x = %.2f\n", x);
    }
  else
    {
    float raiz1 = (-b + sqrt(delta)) / (2 * a);
    float raiz2 = (-b - sqrt(delta)) / (2 * a);
    printf("Raizes reais: x1 = %.2f e x2 = %.2f\n", raiz1, raiz2);
    }
  }

int main()
  {
  float a, b, c;

  printf("Digite os coeficientes a, b e c: ");
  scanf("%f %f %f", &a, &b, &c);

  calcularBhaskara(a, b, c);

  return 0;
  }
